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

    // Parse the string to extract source and destination positions
    if (rhs.size() >= 4) {
        // Get source position (first two characters)
        source.setCol(rhs[0] - 'a');
        source.setRow('8' - rhs[1]);

        // Get destination position (next two characters)
        dest.setCol(rhs[2] - 'a');
        dest.setRow('8' - rhs[3]);
    }
    // Update the text representation
    update();
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


