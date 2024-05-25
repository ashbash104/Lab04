/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for a rook
 ************************************************************************/


#include "testRook.h" 
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3       p             3
  * 2     p(r)p           2
  * 1       p             1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestRook::getMoves_blocked()
{
  // // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/); // fake news  
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;  // Might need to delete
   White white(PAWN);
   board.board[1][1] = &white;
   board.board[2][0] = &white;
   board.board[2][2] = &white;
   board.board[3][1] = &white;
   set <Move> moves;

   // // EXERCISE
   rook.getMoves(moves, board);

   // // VERIFY
   assertUnit(moves.size() == 0);  // many possible moves

   // // TEARDOWN
   board.board[2][1] = nullptr; // white rook
   board.board[1][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][2] = nullptr;
   board.board[3][1] = nullptr;

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .              8
 * 7       .              7
 * 6       .              6
 * 5       .              5
 * 4       .              4
 * 3       .              3
 * 2   . .(r). . . . .    2
 * 1       .              1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);

   set <Move> moves;

    // EXERCISE
   rook.getMoves(moves, board);

    // VERIFY
   assertUnit(moves.size() == 14);  // many possible moves
   assertUnit(moves.find(Move("c2a2")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2c1")) != moves.end());
   assertUnit(moves.find(Move("c2c2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2")) != moves.end());

    // TEARDOWN
   board.board[2][1] = nullptr; // white rook
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   // // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   White white(PAWN);
   board.board[0][1] = &white;
   board.board[2][0] = &white;
   board.board[3][1] = &white;
   board.board[2][6] = &white;
   set <Move> moves;

   // // EXERCISE
   rook.getMoves(moves, board);

   // // VERIFY
   assertUnit(moves.size() == 5);  // many possible moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());

  //  // TEARDOWN
   board.board[2][1] = nullptr; // white rook
   board.board[0][1] = nullptr; // white pawn
   board.board[2][0] = nullptr; // white pawn
   board.board[3][1] = nullptr; // white pawn
   board.board[2][6] = nullptr; // white pawn
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       P             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r)P           2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   // // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   Black black(PAWN);
   board.board[0][1] = &black;
   board.board[2][0] = &black;
   board.board[3][1] = &black;
   board.board[2][6] = &black;
   set <Move> moves;

   // // EXERCISE
   rook.getMoves(moves, board);

   // // VERIFY
   assertUnit(moves.size() == 9);  // many possible moves
   assertUnit(moves.find(Move("c2a2")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2c1")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());

   // // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[0][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[3][1] = nullptr;
   board.board[2][6] = nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // // SETUP
   Rook rook(0, 0, true);
   // exercise
   PieceType type = rook.getType();
   // verify
   assertEquals(type, ROOK);
   assertEquals(ROOK, type);
} 

