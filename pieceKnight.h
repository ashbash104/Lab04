/***********************************************************************
 * Header File:
 *    KNIGHT
 * Author:
*    Ashlee Hart & Emily Raventos
 * Summary:
 *    The KNIGHT class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KNIGHT
  * The knight, aka the "Horse"
  ***************************************************/
class Knight : public Piece
{
public:
   Knight(const Position& pos, bool isWhite) : Piece(pos,true) { }
   Knight(int c, int r, bool isWhite) : Piece(10, 10, true) { }
   ~Knight() {                }
   PieceType getType()            const { return KNIGHT; } //
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};