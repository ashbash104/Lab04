/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    Ashlee Hart and Emily Raventos
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
   friend TestMove;
   friend TestBoard;
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   // constructor
   Move();
   Move(const string & rhs);
  
   void read(const string & rhs);
   string getText() const;
   // getters
   //string getText()                 const;
   const Position& getDes()         const { return dest; }
   const Position& getSrc()         const { return source; }
   PieceType getPromotion()         const { return promote; }
   PieceType getCapture()           const { return capture; }
   bool getEnPassant()              const { return moveType == ENPASSANT; }
   bool getCastleK()                const { return moveType == CASTLE_KING; }
   bool getCastleQ()                const { return moveType == CASTLE_QUEEN; }
   bool getWhiteMove()              const { return isWhite; }
   Move::MoveType getMoveType()     const { return moveType; }
   bool operator == (const Move& rhs)   const;
   bool operator == (const string& rhs) const { return getText() == rhs; }
   bool operator != (const string& rhs) const { return getText() != rhs; }
   bool operator != (const Move& rhs)   const { return !(*this == rhs); }
   bool operator < (const Move& rhs) const {
      return dest.getLocation() < rhs.dest.getLocation();
   }

   // setters
   void update() { text = getText(); }
   void setCapture(PieceType pt) { capture = pt; update(); }
   void setWhiteMove(bool f) { isWhite = f; update(); }
   void setSrc(const Position& src) { source = src; update(); }
   void setDes(const Position& des) { dest = des; update(); }
   void setEnPassant() { moveType = ENPASSANT; update(); }
   void setPromote(PieceType pt) { promote = pt; update(); }
   void setCastle(bool isKing) {
      moveType = isKing ? CASTLE_KING : CASTLE_QUEEN;
      update();
   }

   // for file I/O though only file input is currently implemented
   friend ostream& operator << (ostream& out, Move& rhs);
   friend istream& operator >> (istream& in, Move& rhs);

   //const Move& operator = (const Move& rhs);
   const Move& operator = (const string& s) {
      read(s);
      return *this;
   }
   const Move& operator = (const char* s) {
      read(string(s));
      return *this;
   }


private:
   char letterFromPieceType(PieceType pt)     const; // { return 'z'; }
   PieceType pieceTypeFromLetter(char letter) const; // { return SPACE; }

   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};