/***********************************************************************
 * Header File:
 *    King
 * Author:
*    Ashlee Hart & Emily Raventos
 * Summary:
 *    The King class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * King
  * The King
  ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~King() {                }
   PieceType getType()            const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
};