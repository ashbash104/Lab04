/**********************************************************************
* Source File:
*    Lab 04: Chess
* Author:
*    Ashlee Hart and Emily Raventos
* Summary:
*    Play the game of chess
************************************************************************/


#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for OGSTREAM
#include "position.h"     // for POSITION
#include "piece.h"        // for PIECE and company
#include "board.h"        // for BOARD
#include "test.h"
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "piece.h" 
using namespace std;


/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void draw(const char* board, const Interface & ui, const set <int> & possible)
{
   ogstream gout;
   
   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   set <int> :: iterator it;
   for (it = possible.begin(); it != possible.end(); ++it)
      gout.drawPossible(*it);

   // draw the pieces
   for (int i = 0; i < 64; i++)
      switch (board[i])
      {
      case 'P':
         gout.drawPawn(i, true);
         break;
      case 'p':
         gout.drawPawn(i, false);
         break;
      case 'K':
         gout.drawKing(i, true);
         break;
      case 'k':
         gout.drawKing(i, false);
         break;
      case 'Q':
         gout.drawQueen(i, true);
         break;
      case 'q':
         gout.drawQueen(i, false);
         break;
      case 'R':
         gout.drawRook(i, true);
         break;
      case 'r':
         gout.drawRook(i, false);
         break;
      case 'B':
         gout.drawBishop(i, true);
         break;
      case 'b':
         gout.drawBishop(i, false);
         break;
      case 'N':
         gout.drawKnight(i, true);
         break;
      case 'n':
         gout.drawKnight(i, false);
         break;
      }
}

/*********************************************
 * MOVE 
 * Execute one movement. Return TRUE if successful
 *********************************************/
//bool move(char* board, int positionFrom, int positionTo)
//{
//   // do not move if a move was not indicated
//   if (positionFrom == -1 || positionTo == -1)
//      return false;
//   assert(positionFrom >= 0 && positionFrom < 64);
//   assert(positionTo >= 0 && positionTo < 64);
//
//
//   // find the set of possible moves from our current location
//   set <int> possiblePrevious = getPossibleMoves(board, positionFrom);
//
//   // only move there is the suggested move is on the set of possible moves
//   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
//   {
//      board[positionTo] = board[positionFrom];
//      board[positionFrom] = ' ';
//      return true;
//   }
//
//   return false;
//
//}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   set <int> possible;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   char * board = (char *)p;  

   // move 
   //if (move(board, pUI->getPreviousPosition(), pUI->getSelectPosition()))
      //pUI->clearSelectPosition();
   //else
      //possible = getPossibleMoves(board, pUI->getSelectPosition());

   // if we clicked on a blank spot, then it is not selected
   //if (pUI->getSelectPosition() != -1 && board[pUI->getSelectPosition()] == ' ')
      //pUI->clearSelectPosition();

   // draw the board
   draw(board, *pUI, possible);

}

/********************************************************
 * PARSE
 * Determine the nature of the move based on the input.
 * This is the only function understanding Smith notation
 *******************************************************/
void parse(const string& textMove, int& positionFrom, int& positionTo)
{
   string::const_iterator it = textMove.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   positionFrom = row * 8 + col;

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   positionTo = row * 8 + col;

   // capture and promotion information
   char capture = ' ';
   char piecePromotion = ' ';
   bool castleK = false;
   bool castleQ = false;
   bool enpassant = false;
   for (; it != textMove.end(); ++it)
   {
      switch (*it)
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = tolower(*it);
         break;

      case 'c':  // short castling or king's castle
         castleK = true;
         break;
      case 'C':  // long castling or queen's castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enpassant = true;
         break;

      case 'N':  // Promote to knight
      case 'B':  // Promote to Bishop
      case 'R':  // Promote to Rook
      case 'Q':  // Promote to Queen
         piecePromotion = *it;
         break;

      }
   }

   // error checking
   if (positionFrom < 0 || positionFrom >= 64 ||
       positionTo   < 0 || positionTo   >= 64)
      positionFrom = positionTo = -1;
}

/********************************************************
 * READ FILE
 * Read a file where moves are encoded in Smith notation
 *******************************************************/
void readFile(const char* fileName, char* board)
{
   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return;

   // read the file, one move at a time
   string textMove;
   bool valid = true;
   while (valid && fin >> textMove)
   {
      int positionFrom;
      int positionTo;
      parse(textMove, positionFrom, positionTo);
      //valid = move(board, positionFrom, positionTo);
   }

   // close and done
   fin.close();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int __argc, char** __argv)
#endif // !_WIN32
{
   testRunner(); 
   Interface ui("Chess");    

   // Initialize the game class
   // note this is upside down: 0 row is at the bottom
   char board[64] = {
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      //' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
   };
   
   if (__argc == 2)
      readFile(__argv[1], board);

   // set everything into action
   ui.run(callBack, board);     
     

   return 0;
}
