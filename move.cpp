/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
    promote = SPACE;
    capture = SPACE;
    moveType = MOVE;
    isWhite = true;
}

Move::Move(const string & rhs) {
    promote = SPACE;
    capture = SPACE;
    moveType = MOVE;
    isWhite = true;
}

char Move::letterFromPieceType(PieceType pt) const{
    switch (pt) {
    case PAWN:   return 'P';
    case ROOK:   return 'R';
    case KNIGHT: return 'N';
    case BISHOP: return 'B';
    case QUEEN:  return 'Q';
    case KING:   return 'K';
    default:     return ' '; // Handle unknown piece types or empty squares
    }
}

PieceType Move::pieceTypeFromLetter(char letter) const {
    switch (letter) {
    case 'P': return PAWN;
    case 'R': return ROOK;
    case 'N': return KNIGHT;
    case 'B': return BISHOP;
    case 'Q': return QUEEN;
    case 'K': return KING;
    default:  return SPACE; // Assuming 'SPACE' is a type representing an empty square
    }
}


