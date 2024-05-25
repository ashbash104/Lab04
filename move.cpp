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
    read(rhs);
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

    Board board;

    string mType = "";

    if (moveType == MOVE && capture != SPACE && capture != INVALID) {
        char mType1 = tolower(letterFromPieceType(capture));
        string s{ mType1 };
        mType = s;
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

    string moveText = sCol + to_string(sRow) + dCol + to_string(dRow) + mType;

    return moveText;
}

void Move::read(const std::string& moveStr) {

    // Reset to defaults
    source.set(0,0);
    dest.set(0,0);
    promote = SPACE;
    capture = SPACE;
    moveType = MOVE;
    isWhite = false;
    text = moveStr;

    if (moveStr.size() < 4) {
        moveType = MOVE_ERROR;
        return;
    }

    // Parse the move string
    source.setCol(moveStr[0] - 'a');
    source.setRow(moveStr[1] - '1');
    dest.setCol(moveStr[2] - 'a');
    dest.setRow(moveStr[3] - '1');

    // Default to MOVE
    moveType = MOVE;

    // Determine if it's a special move
    if (moveStr.size() == 5) {
        char special = moveStr[4];
        switch (special) {
        case 'r':  // Capture
            capture = ROOK;
            break;
        case 'b':
            capture = BISHOP;
            break;
        case 'n':
            capture = KNIGHT;
            break;
        case 'q':
            capture = QUEEN;
            break;
        case 'k':
            capture = KING;
            break;
        case 'p':
            capture = PAWN;
            break;
        case 'E':  // En passant
            moveType = ENPASSANT;
            break;
        case 'c':  // King-side castle
            moveType = CASTLE_KING;
            break;
        case 'C':  // Queen-side castle
            moveType = CASTLE_QUEEN;
            break;
        default:
            moveType = MOVE_ERROR;
            return;
        }
    }

}