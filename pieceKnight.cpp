/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   static const int dC[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
   static const int dR[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

   for (int i = 0; i < 8; i++)
   {
      ;
      /*Position newPos(position.getCol() + dC[i], position.getRow() + dR[i]);
      if (newPos.isValid() && (!board.isOccupied(newPos) || board.isOccupiedByOpponent(newPos, fWhite)))
      {
         moves.insert(Move(position, newPos, board.getPiece(newPos)));
      }*/
   }
}