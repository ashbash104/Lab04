/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h" 
#include "pieceBishop.h"     
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
  * 3     p   p           3
  * 2      (b)            2
  * 1     p   p           1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestBishop::getMoves_blocked()
{
   //SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/); // fake news  
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   //board.board[2][1] = &bishop;  // Might need to delete
   White white(PAWN);
   board.board[1][0] = &white;
   board.board[1][2] = &white;
   board.board[3][0] = &white;
   board.board[3][2] = &white;
   set <Move> moves;

   //EXERCISE
   bishop.getMoves(moves, board);

   //VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   //TEARDOWN
   board.board[2][1] = nullptr; // white bishop
   board.board[1][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[3][0] = nullptr;
   board.board[3][2] = nullptr;

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   //SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);


   set <Move> moves;

   //EXERCISE
   bishop.getMoves(moves, board);

   //VERIFY
   assertUnit(moves.size() == 9);  // many possible moves
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());

   //TEARDOWN
   board.board[2][1] = nullptr; // white bishop
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   //SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   White white(PAWN);
   board.board[0][3] = &white;
   board.board[1][0] = &white;
   board.board[3][0] = &white;
   board.board[7][6] = &white;
   set <Move> moves;

   //EXERCISE
   bishop.getMoves(moves, board);

   //VERIFY
   assertUnit(moves.size() == 5);  // many possible moves
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());

   //TEARDOWN
   board.board[6][0] = nullptr; // white bishop
   board.board[0][3] = nullptr; // white pawn
   board.board[1][0] = nullptr; // white pawn
   board.board[3][0] = nullptr; // white pawn
   board.board[7][6] = nullptr; // white pawn
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   //SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;
   Black black(PAWN);
   board.board[0][3] = &black;
   board.board[1][0] = &black;
   board.board[3][0] = &black;
   board.board[7][6] = &black;
   set <Move> moves;

   //EXERCISE
   bishop.getMoves(moves, board);

   //VERIFY
   assertUnit(moves.size() == 5);  // many possible moves
   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());

   //TEARDOWN
   board.board[2][1] = nullptr; // white bishop
   board.board[0][3] = nullptr; // black pawn
   board.board[1][0] = nullptr; // black pawn
   board.board[3][0] = nullptr; // black pawn
   board.board[7][6] = nullptr; // black pawn
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // setup
   Bishop bishop(0, 0, true);
   // exercise
   PieceType type = bishop.getType();
   //verify
   assertEquals(type, BISHOP);
   assertEquals(BISHOP, type);
}

