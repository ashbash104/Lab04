/***********************************************************************
 * Header File:
 *    Pawn
 * Author:
*    Ashlee Hart & Emily Raventos
 * Summary:
 *    The Pawn class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * Pawn
  * The Pawn
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Pawn() {                }
   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
};