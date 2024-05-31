/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    Ashlee Hart & Emily Raventos
 * Summary:
 *    The unit tests for board
 ************************************************************************/

#include "testBoard.h"
#include "position.h"
#include "piece.h"
#include "board.h"
#include <cassert>

void TestBoard::run()
{
    // construct
    construct_default();

    // move
    move_pawnSimple();
    move_pawnCapture();
    move_pawnDouble();
    move_pawnEnpassant();
    move_pawnPromotion();
    move_rookSlide();
    move_rookAttack();
    move_bishopSlide();
    move_bishopAttack();
    move_knightMove();
    move_knightAttack();
    move_queenSlide();
    move_queenAttack();
    move_kingMove();
    move_kingAttack();
    move_kingShortCastle();
    move_kingLongCastle();

    // Get Current Move
    getCurrentMove_initial();
    getCurrentMove_second();
    getCurrentMove_middleWhite();
    getCurrentMove_middleBlack();

    // Whites Turn?
    whiteTurn_initial();
    whiteTurn_second();
    whiteTurn_middleWhite();
    whiteTurn_middleBlack();

    // fetch and get
    fetch_a1();
    fetch_h8();
    fetch_a8();
    set_a1();
    set_h8();
    set_a8();


    report("Board");
}

// construct
void TestBoard::construct_default() {}

// move
void TestBoard::move_pawnSimple() {}
void TestBoard::move_pawnCapture() {}
void TestBoard::move_pawnDouble() {}
void TestBoard::move_pawnEnpassant() {}
void TestBoard::move_pawnPromotion() {}
void TestBoard::move_rookSlide() {}
void TestBoard::move_rookAttack() {}
void TestBoard::move_bishopSlide() {}
void TestBoard::move_bishopAttack() {}
void TestBoard::move_knightMove() {}
void TestBoard::move_knightAttack() {}
void TestBoard::move_queenSlide() {}
void TestBoard::move_queenAttack() {}
void TestBoard::move_kingMove() {}
void TestBoard::move_kingAttack() {}
void TestBoard::move_kingShortCastle() {}
void TestBoard::move_kingLongCastle() {}

// Get Current Move
void TestBoard::getCurrentMove_initial() {}
void TestBoard::getCurrentMove_second() {}
void TestBoard::getCurrentMove_middleWhite() {}
void TestBoard::getCurrentMove_middleBlack() {}

// Whites Turn?
void TestBoard::whiteTurn_initial() {}
void TestBoard::whiteTurn_second() {}
void TestBoard::whiteTurn_middleWhite() {}
void TestBoard::whiteTurn_middleBlack() {}

// fetch and get
void TestBoard::fetch_a1() {}
void TestBoard::fetch_h8() {}
void TestBoard::fetch_a8() {}
void TestBoard::set_a1() {}
void TestBoard::set_h8() {}
void TestBoard::set_a8() {}

//
///********************************************************
// *    e5c6
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6       .             6       6       n             6
// * 5          (n)        5       5           .         5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_knightMove()
//{  // SETUP
//   Move move;
//   move.source.set(4, 4);
//   move.dest.set(2, 5);
//   move.capture = SPACE;
//   move.promote = SPACE;
//   move.isWhite = true;
//   move.moveType = Move::MOVE;
//   Board board(nullptr, true /*noreset*/);
//   board.numMoves = 17;
//   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
//   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, SPACE);
//   board.board[4][4]->nMoves = 17;
//   PieceSpy::reset() {}
//
//   // EXERCISE
//   board.move(move);
//
//   // VERIFY
//   assertUnit(18 == board.numMoves); //
//   assertUnit(SPACE == (board.board[4][4])->getType()); //
//   assertUnit(KNIGHT == (board.board[2][5])->getType()); //
//   assertUnit(PieceSpy::numConstruct == 0);
//   assertUnit(PieceSpy::numCopy == 0);
//   assertUnit(PieceSpy::numDelete == 0);   
//   assertUnit(PieceSpy::numAssign == 0);
//   assertUnit(PieceSpy::numMove == 0);
//
//   // TEARDOWN
//   delete board.board[2][5];
//   delete board.board[4][4];
//   board.board[2][5] = board.board[4][4] = nullptr;
//}
//
// /********************************************************
// *    e5c6r
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7       R             7       7                     7
// * 6                     6       6       n             6
// * 5          (n)        5       5           .         5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
//  ********************************************************/
//void TestBoard::move_knightAttack()
//{  // SETUP
//   Move move;
//   move.source.set(4, 4);
//   move.dest.set(2, 5);
//   move.capture = ROOK;
//   move.promote = SPACE;
//   move.isWhite = true;
//   move.moveType = Move::MOVE;
//   Board board(nullptr, true /*noreset*/);
//   board.numMoves = 17;
//   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
//   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, ROOK);
//   board.board[4][4]->nMoves = 17;
//   PieceSpy::reset() {}
//
//   // EXERCISE
//   board.move(move);
//   // VERIFY
//   assertUnit(18 == board.numMoves); //
//   assertUnit(SPACE == (board.board[4][4])->getType()); //
//   assertUnit(KNIGHT == (board.board[2][5])->getType()); //
//   assertUnit(PieceSpy::numConstruct == 0);
//   assertUnit(PieceSpy::numCopy == 0);
//   assertUnit(PieceSpy::numDelete == 0);
//   assertUnit(PieceSpy::numAssign == 0);
//   assertUnit(PieceSpy::numMove == 0);
//
//   // TEARDOWN
//   delete board.board[2][5];
//   delete board.board[4][4];
//   board.board[2][5] = board.board[4][4] = nullptr;
//}
//
/////////////////////////////////////////////////////////////////////////////////////////////
//#include "testBoard.h"
//#include "position.h"
//#include "piece.h"
//#include "board.h"
//#include <cassert>
//
//
//
// /********************************************************
//  *   a2a3
//  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
//  * |                     |       |                     |
//  * 8                     8       8                     8
//  * 7                     7       7                     7
//  * 6                     6       6                     6
//  * 5                     5       5                     5
//  * 4                     4  -->  4                     4
//  * 3   .                 3       3   p                 3
//  * 2  (p)                2       2   .                 2
//  * 1                     1       1                     1
//  * |                     |       |                     |
//  * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
//  ********************************************************/
//void TestBoard::move_pawnSimple()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *     a6b7r
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7     R               7       7    (p)              7
// * 6  (p)                6       6   .                 6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_pawnCapture()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e2e4
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4           .         4  -->  4          (p)        4
// * 3                     3       3                     3
// * 2          (p)        2       2           .         2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_pawnDouble()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
//*     a5b6E
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6     .               6       6     p               6
// * 5  (p)P               5       5   . .               5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_pawnEnpassant()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    a7a8Q
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8   .                 8       8  (r)                8
// * 7  (p)                7       7   .                 7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_pawnPromotion()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e5a5
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5   .      (r)        5       5  (r)      .         5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_rookSlide()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e5a5b
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5   B      (r)        5       5  (r)      .         5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_rookAttack()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e5g3
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5          (b)        5       5           .         5
// * 4                     4  -->  4                     4
// * 3               .     3       3               b     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_bishopSlide()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e5g3q
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5          (b)        5       5           .         5
// * 4                     4  -->  4                     4
// * 3               Q     3       3               b     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_bishopAttack()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///********************************************************
// *    e5g3
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5          (q)        5       5                     5
// * 4                     4  -->  4           .         4
// * 3                .    3       3               q     3
// * 2                     2       2                     2
// * 1                     1       1                     1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_queenSlide()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
//*    e5a5b
//* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
//* |                     |       |                     |
//* 8                     8       8                     8
//* 7                     7       7                     7
//* 6                     6       6                     6
//* 5   B      (q)        5       5  (q)      .         5
//* 4                     4  -->  4                     4
//* 3                     3       3                     3
//* 2                     2       2                     2
//* 1                     1       1                     1
//* |                     |       |                     |
//* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
//********************************************************/
//void TestBoard::move_queenAttack()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *  e1f1
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1          (k).       1       1           . k       1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_kingMove()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
///********************************************************
// *    e1f1r
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1          (k)R       1       1           . k       1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_kingAttack()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///********************************************************
// *    e1g1c
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1          (k). . r   1       1           . r k .   1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_kingShortCastle()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
//
///********************************************************
// *    e1c1C
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// * |                     |       |                     |
// * 8                     8       8                     8
// * 7                     7       7                     7
// * 6                     6       6                     6
// * 5                     5       5                     5
// * 4                     4  -->  4                     4
// * 3                     3       3                     3
// * 2                     2       2                     2
// * 1   r . . .(k)        1       1   . . k r .         1
// * |                     |       |                     |
// * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::move_kingLongCastle()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
//
//
//
//
///********************************************************
// *        +---a-b-c-d-e-f-g-h---+
// *        |                     |
// *        8   R N B Q K B N R   8
// *        7   P P P P P P P P   7
// *        6                     6
// *        5                     5
// *   -->  4                     4
// *        3                     3
// *        2   p p p p p p p p   2
// *        1   r n b q k b n r   1
// *        |                     |
// *        +---a-b-c-d-e-f-g-h---+
// ********************************************************/
//void TestBoard::construct_default()
//{
//   assertUnit(NOT_YET_IMPLEMENTED);
//}
