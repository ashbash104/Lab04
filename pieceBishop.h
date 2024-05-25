/***********************************************************************
 * Header File:
 *    Bishop
 * Author:
*    Ashlee Hart & Emily Raventos
 * Summary:
 *    The Bishop class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * Bishop
  * The bishop
  ***************************************************/
class Bishop : public Piece
{
public:
   Bishop(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Bishop() {                }
   PieceType getType()            const { return BISHOP; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
   set <Move> getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const;
};