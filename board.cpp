/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
// Constant version for board display
const Piece& Board::operator [] (const Position& pos) const
{
   assert(0 <= pos.getCol() && pos.getCol() < 8);
   assert(0 <= pos.getRow() && pos.getRow() < 8);
   assert(nullptr != board[pos.getCol()][pos.getRow()]);
   return *board[pos.getCol()][pos.getRow()];
}
// Read/Write version if we want to change the board.
Piece& Board::operator [] (const Position& pos)
{
   assert(0 <= pos.getCol() && pos.getCol() < 8);
   assert(0 <= pos.getRow() && pos.getRow() < 8);
   assert(nullptr != board[pos.getCol()][pos.getRow()]);

   return *board[pos.getCol()][pos.getRow()];
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   //Set every initial position to nullptr
  // Need to put actual places here in the future. 
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[r][c] = nullptr;
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{

}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   // move.source;
   // move.dest;

 /*  PieceDerived piece(4,2,true);
   piece.position = board[4][2];
   PieceType pieceType = .getType();*/
   numMoves += 1; 
}

bool Board::isOccupied(const Position& pos) const
{
   int col = pos.getCol();
   int row = pos.getRow();
   return (col >= 0 && col < 8 && row >= 0 && row < 8 && board[col][row] != nullptr);
}

bool Board::isOccupiedByOpponent(const Position& pos, bool isWhite) const
{
   int col = pos.getCol();
   int row = pos.getRow();
   if (col < 0 || col >= 8 || row < 0 || row >= 8 || board[col][row] == nullptr)
      return false;

   return board[col][row]->isWhite() != isWhite;
}

/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}