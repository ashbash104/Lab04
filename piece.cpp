/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;

/************************************************
* FACTORY
* Create a piece
************************************************/
Piece * factory(PieceType pt, int c, int r, bool isWhite) {
   switch (pt)
   {
      case KING:
      case QUEEN:
      case ROOK:
      case BISHOP:
      case PAWN:
         assert(false);
      case SPACE:
         return new Space (c,r);
      case KNIGHT:
         return new Knight(c, r, isWhite);
   }
   assert(false);
   return nullptr;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece& Piece::operator=(const Piece& rhs) {
    if (this != &rhs) {
        // Copy properties from rhs to lhs
        this->fWhite = rhs.fWhite;
        this->lastMove = rhs.lastMove;
        this->nMoves = rhs.nMoves;
    }
    return *this;
}

/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}





/***********************************************
 * Row Column
 * Simple row/column pair
 ************************************************/
struct CR
{
   int col;
   int row;
};

/****************************************************
 * IS NOT WHITE
 * Is the current location valid and the piece is either
 * black (uppercase) or space
 ***************************************************/
inline bool isNotWhite(const char* board, int col, int row)
{
   // not white if we are off the board or if we are looking at a space
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return piece == ' ' || (piece >= 'A' && piece <= 'Z');
}

/****************************************************
 * IS  WHITE
 * Is the current location valid and the piece is white
 ***************************************************/
inline bool isWhite(const char* board, int col, int row)
{
   // not white if we are off the board or if we are looking at a space
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return (piece >= 'a' && piece <= 'z');
}

/****************************************************
 * IS NOT BLACK
 * Is the current location valid and the piece is either
 * white (lowercase) or space
 ***************************************************/
inline bool isNotBlack(const char* board, int col, int row)
{
   // not white if we are off the board or if we are looking at a space
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return piece == ' ' || (piece >= 'a' && piece <= 'z');
}

/****************************************************
 * IS  BLACK
 * Is the current location valid and the piece is black
 ***************************************************/
inline bool isBlack(const char* board, int col, int row)
{
   // not white if we are off the board or if we are looking at a space
   if (row < 0 || row >= 8 || col < 0 || col >= 8)
      return false;
   char piece = board[row * 8 + col];

   return (piece >= 'A' && piece <= 'Z');
}
/*********************************************************
 * GET POSSIBLE MOVES
 * Determine all the possible moves for a given chess piece
 *********************************************************/
set <int> getMoves(const char* board, int location)
{
   set <int> possible;

   // return the empty set if there simply are no possible moves
   if (location < 0 || location >= 64 || board[location] == ' ')
      return possible;
   int row = location / 8;  // current location row
   int col = location % 8;  // current location column
   int r;                   // the row we are checking
   int c;                   // the column we are checking
   bool amBlack = isBlack(board, col, row);

   //
   // PAWN
   //
   if (board[location] == 'P')
   {
      c = col;
      r = row - 2;
      if (row == 6 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward two blank spaces
      r = row - 1;
      if (r >= 0 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward one black space
      c = col - 1;
      if (isWhite(board, c, r))
         possible.insert(r * 8 + c);    // attack left
      c = col + 1;
      if (isWhite(board, c, r))
         possible.insert(r * 8 + c);    // attack right
      // what about en-passant and pawn promotion
   }
   if (board[location] == 'p')
   {
      c = col;
      r = row + 2;
      if (row == 1 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);  // forward two blank spaces
      r = row + 1;
      if (r < 8 && board[r * 8 + c] == ' ')
         possible.insert(r * 8 + c);    // forward one blank space
      c = col - 1;
      if (isBlack(board, c, r))
         possible.insert(r * 8 + c);      // attack left
      c = col + 1;
      if (isBlack(board, c, r))
         possible.insert(r * 8 + c);      // attack right
      // what about en-passant and pawn promotion
   }

   //
   // KNIGHT
   //
   if (board[location] == 'N' || board[location] == 'n')
   {
      CR moves[8] = 
      {
               {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      {-2, -1},                    { 2, -1},
               {-1, -2}, { 1, -2}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         if ( amBlack && isNotBlack(board, c, r))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, c, r))
            possible.insert(r * 8 + c);
      }
   }

   //
   // KING
   //
   if (board[location] == 'K' || board[location] == 'k')
   {
      CR moves[8] =
      {
         {-1,  1}, {0,  1}, {1,  1},
         {-1,  0},          {1,  0},
         {-1, -1}, {0, -1}, {1, -1}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         if ( amBlack && isNotBlack(board, c, r))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, c, r))
            possible.insert(r * 8 + c);
      }
      // what about castling?
   }

   //
   // QUEEN
   //
   if (board[location] == 'Q' || board[location] == 'q')
   {
      CR moves[8] =
      {
         {-1,  1}, {0,  1}, {1,  1},
         {-1,  0},          {1,  0},
         {-1, -1}, {0, -1}, {1, -1}
      };
      for (int i = 0; i < 8; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 && 
                board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if ( amBlack && isNotBlack(board, c, r))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, c, r))
            possible.insert(r * 8 + c);
      }
   }

   //
   // ROOK
   //
   if (board[location] == 'R' || board[location] == 'r')
   {
      CR moves[4] =
      {
                  {0,  1},
         {-1, 0},         {1, 0},
                  {0, -1}
      };
      for (int i = 0; i < 4; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
            board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if (amBlack && isNotBlack(board, c, r))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, c, r))
            possible.insert(r * 8 + c);
      }
   }

   //
   // BISHOP
   //
   if (board[location] == 'B' || board[location] == 'b')
   {
      CR moves[4] =
      {
         {-1,  1}, {1,  1},
         {-1, -1}, {1, -1}
      };
      for (int i = 0; i < 4; i++)
      {
         r = row + moves[i].row;
         c = col + moves[i].col;
         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
            board[r * 8 + c] == ' ')
         {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
         }
         if (amBlack && isNotBlack(board, c, r))
            possible.insert(r * 8 + c);
         if (!amBlack && isNotWhite(board, c, r))
            possible.insert(r * 8 + c);
      }
   }

   return possible;
}