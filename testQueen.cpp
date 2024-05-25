/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for a queen
 ************************************************************************/


#include "testQueen.h" 
#include "pieceQueen.h"     
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
  * 3     p p p           3
  * 2     p(q)p           2
  * 1     p p p            1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestQueen::getMoves_blocked()
{
  // // SETUP
   BoardEmpty board; 
   Queen queen(7, 7, false /*white*/); // fake news  
   queen.fWhite = true;
   queen.position.set(2, 1);
   board.board[2][1] = &queen;  // Might need to delete
   White white(PAWN);
   board.board[1][0] = &white;
   board.board[2][0] = &white;
   board.board[1][1] = &white;
   board.board[3][0] = &white;
   board.board[3][1] = &white;
   board.board[1][2] = &white;
   board.board[2][1] = &white;
   board.board[3][1] = &white;
   set <Move> moves; 

   // // EXERCISE
   queen.getMoves(moves, board);

   // // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // // TEARDOWN // white queen
   board.board[1][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[1][1] = nullptr;
   board.board[3][0] = nullptr;
   board.board[3][1] = nullptr;
   board.board[1][2] = nullptr;
   board.board[2][1] = nullptr;
   board.board[3][1] = nullptr;

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Queen queen(7, 7, false /*white*/);
   queen.fWhite = true;
   queen.position.set(2, 1);

   set <Move> moves;

    // EXERCISE
   queen.getMoves(moves, board);

    // VERIFY
   assertUnit(moves.size() == 23);  // many possible moves
   assertUnit(moves.find(Move("c2a2")) != moves.end());
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2c1")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h2")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());

    // TEARDOWN
   board.board[2][1] = nullptr; // white queen
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p             7
 * 6       .             6
 * 5       .     p       5
 * 4       .   .         4
 * 3     p . .           3
 * 2   p .(q)p           2
 * 1     p p p            1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   // // SETUP
   BoardEmpty board;
   Queen queen(7, 7, false /*white*/);
   queen.fWhite = true;
   queen.position.set(2, 1);
   board.board[2][1] = &queen;
   White white(PAWN);
   board.board[0][1] = &white;
   board.board[1][0] = &white;
   board.board[1][2] = &white;
   board.board[2][0] = &white;
   board.board[2][6] = &white;
   board.board[3][0] = &white;
   board.board[3][1] = &white;
   board.board[5][4] = &white;
   set <Move> moves;

   // // EXERCISE
   queen.getMoves(moves, board);

   // // VERIFY
   assertUnit(moves.size() == 5);  // many possible moves
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   // Need to finish

  //  // TEARDOWN
   board.board[0][1] = nullptr;
   board.board[1][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][6] = nullptr;
   board.board[3][0] = nullptr;
   board.board[3][1] = nullptr;
   board.board[5][4] = nullptr;
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
 * 2   P .(q)P           2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
   // // SETUP
   BoardEmpty board;
   Queen queen(7, 7, false /*white*/);
   queen.fWhite = true;
   queen.position.set(2, 1);
   board.board[2][1] = &queen;
   Black black(PAWN);
   board.board[0][1] = &black;
   board.board[2][0] = &black;
   board.board[3][1] = &black;
   board.board[2][6] = &black;
   set <Move> moves;

   // // EXERCISE
   queen.getMoves(moves, board);

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
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   // // SETUP
   Queen queen(0, 0, true);
   // exercise
   PieceType type = queen.getType();
   // verify
   assertEquals(type, QUEEN);
   assertEquals(QUEEN, type);
} 

