/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include "piece.h"
#include "board.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype> // for tolower()

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

string Move::getText() const {
    vector<string> colLetter = { "a", "b", "c", "d", "e", "f", "g", "h"};

    string sCol = colLetter[source.getCol()];
    int sRow = source.getRow() + 1;

    string dCol = colLetter[dest.getCol()];
    int dRow = dest.getRow() + 1;

    string moveText = sCol + to_string(sRow) + dCol + to_string(dRow);
    Board board;

    string mType = " ";

    if (moveType == MOVE && board.isOccupiedByOpponent(dest, isWhite)) {
        char mType = letterFromPieceType(capture);
        moveText += mType;
    }
    else if (moveType == ENPASSANT) {
        mType = "E";
    } 
    else if (moveType == CASTLE_KING) {
        mType = "c";
    }
    else if (moveType == CASTLE_QUEEN) {
        mType = "C";
    }

    moveText += mType;

    // // Check if the destination contains an opponent's piece
    // if (capture != ' ') {
    //    moveText += capture;
    // }

    return moveText;
}

void Move::read(const string & rhs) {
    // Check if the string has at least two characters
      if (rhs[0] && rhs[1] && rhs[2]) {
         // Extract column and row from the string
         int col = rhs[0] /* - 'a'*/; // Assuming lowercase letters for columns ('a' -> 0, 'b' -> 1, ..., 'h' -> 7)
         int row = rhs[1]/* - '1'*/; // Assuming '1' -> 0, '2' -> 1, ..., '8' -> 7

         // Check if column and row values are within valid range
         if (col >= 0 && col < 8 && row >= 0 && row < 8) { 
            // Set the colRow value
            dest.setCol(col << 4);
            dest.setRow(row);  
            
            static_cast<uint8_t>((col << 4) | row); 
         }
      }
}