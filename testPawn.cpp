/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert> 
using namespace std;

 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3                 .   3
  * 2               P .   2
  * 1                (p)  1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_end() ////////////////////////////////
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(7, 7, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(7, 0);
   board.board[7][0] = &pawn;
   Black black(PAWN);
   board.board[6][1] = &black;
   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);  // many possible moves
   assertUnit(moves.find(Move("h1h2")) != moves.end());
   assertUnit(moves.find(Move("h1h3")) != moves.end());
   assertUnit(moves.find(Move("h1g2")) != moves.end());

   // TEARDOWN
   board.board[7][0] = nullptr; // white pawn
   board.board[6][2] = nullptr; // black pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p P p         6
 * 5        (p)          5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(7, 7, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(3, 4);
   board.board[3][4] = &pawn;
   Black black(PAWN);
   board.board[3][5] = &black;
   White white(PAWN);
   board.board[2][5] = &white;
   board.board[4][5] = &white; 
   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // TEARDOWN
   board.board[3][4] = nullptr; // white pawn
   board.board[3][5] = nullptr; // black pawn
   board.board[2][5] = nullptr; // white pawn
   board.board[4][5] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P . P         6
 * 5        (p)          5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_capture() 
{
      // SETUP
   BoardEmpty board;
   Pawn pawn(7, 7, false /*white*/);
   pawn.fWhite = true;
   pawn.position.set(3, 4);
   board.board[3][4] = &pawn;
   Black black(PAWN);
   board.board[2][5] = &black; 
   board.board[4][5] = &black; 
   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);  // many possible moves
   assertUnit(moves.find(Move("h1c6")) != moves.end());
   assertUnit(moves.find(Move("h1d6")) != moves.end());
   assertUnit(moves.find(Move("h1e6")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white pawn
   board.board[2][5] = nullptr; // black pawn
   board.board[4][5] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2        (p)          2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
//void TestPawn::getMoves_enpassant() //////////////////////////////////////////////// HOW??
//{
//   // SETUP
//   BoardEmpty board;
//   Pawn pawn(7, 7, false /*black*/);
//   Black black(PAWN);
//   pawn.fWhite = true;
//   pawn.position.set(3, 4);
// 
//   board.board[2][6] = board.board[4][6] = &black;
//   board.board[1][5] = board.board[5][5] = &black;
//   board.board[1][3] = board.board[5][3] = &black;
//   board.board[2][2] = board.board[4][2] = &black;
//
//   set <Move> moves;
//
//   // EXERCISE
//   pawn.getMoves(moves, board);
//
//   // VERIFY
//   assertUnit(moves.size() == 8);  // many possible moves
//   assertUnit(moves.find(Move("d5b6p")) != moves.end());
//   assertUnit(moves.find(Move("d5c7p")) != moves.end());
//   assertUnit(moves.find(Move("d5e7p")) != moves.end());
//   assertUnit(moves.find(Move("d5f6p")) != moves.end());
//   assertUnit(moves.find(Move("d5b4p")) != moves.end());
//   assertUnit(moves.find(Move("d5c3p")) != moves.end());
//   assertUnit(moves.find(Move("d5e3p")) != moves.end());
//   assertUnit(moves.find(Move("d5f4p")) != moves.end());
//
//   // TEARDOWN
//   board.board[2][6] = board.board[4][6] = nullptr;
//   board.board[1][5] = board.board[5][5] = nullptr;
//   board.board[1][3] = board.board[5][3] = nullptr;
//   board.board[2][2] = board.board[4][2] = nullptr;
//}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6         .           6
 * 5        (p)          5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_free() 
{
   // SETUP
   BoardEmpty board; 
   Pawn pawn(7, 7, false /*white*/); 
   pawn.fWhite = true; 
   pawn.position.set(3, 4); 

   set <Move> moves;

   // EXERCISE 
   pawn.getMoves(moves, board); 

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("d5d6")) != moves.end());

   // TEARDOWN
}



/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // setup
   Pawn pawn(0, 0, true);
   // exercise
   PieceType type = pawn.getType();
   // verify
   assertEquals(type, PAWN);
   assertEquals(PAWN, type);
}  // TEARDOWN
