
/***********************************************************************
 * Source File:
 *    Pawn
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()
#include <set>
#include <vector>

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !isWhite());
}

/***************************************************
* PIECE : GEN MOVES NO SLIDE
*         From a list of deltas, finds all the 
*         possible moves.
***************************************************/
set <Move> Pawn::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
{
   set <Move> moves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
   // capture if there is a piece at the end of the slide
      if (posMove.isValid() &&
         (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         if (board[posMove] != SPACE)
            move.setCapture(board[posMove].getType());
         moves.insert(move);
      }
   }
   return moves;
}

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{

   // the 8 possible positions relative to the current position
   const Delta delta[] = 
   {
            {-1, 2}, {1, 2},
      {-2, 1},               {2, 1},
            {-1, -2}, {1, -2}
   };

   // moves = getMovesNoslide(board, delta, sizeof(delta) /*/ sizeof(delta[0]))*/);
}