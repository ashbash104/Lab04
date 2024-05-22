/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
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
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end() ////////////////////////////////
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   knight.fWhite = true;
   knight.position.set(6, 0);
   board.board[6][0] = &knight;
   Black black(PAWN);
   board.board[4][1] = &black;
   White white(PAWN);
   board.board[5][2] = &white;
   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(Move("g1e2p")) != moves.end());
   assertUnit(moves.find(Move("g1h3")) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*white*/);
   White white;
   knight.fWhite = true;
   knight.position.set(3, 4);
   //board.board[3][4] = &knight;
   //White white(PAWN);
   board.board[2][6] = board.board[4][6] = &white;
   board.board[1][5] = board.board[5][5] = &white;
   board.board[1][3] = board.board[5][3] = &white;
   board.board[2][2] = board.board[4][2] = &white; 

   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // TEARDOWN
   board.board[2][6] = board.board[4][6] = nullptr;
   board.board[1][5] = board.board[5][5] = nullptr;
   board.board[1][3] = board.board[5][3] = nullptr;
   board.board[2][2] = board.board[4][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture() ////////////////////////////////
{
   // SETUP
   BoardEmpty board;
   Knight knight(7, 7, false /*black*/);
   Black black(PAWN);
   knight.fWhite = true;
   knight.position.set(3, 4);
 
   board.board[2][6] = board.board[4][6] = &black;
   board.board[1][5] = board.board[5][5] = &black;
   board.board[1][3] = board.board[5][3] = &black;
   board.board[2][2] = board.board[4][2] = &black;

   set <Move> moves;

   // EXERCISE
   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // many possible moves
   assertUnit(moves.find(Move("d5b6p")) != moves.end());
   assertUnit(moves.find(Move("d5c7p")) != moves.end());
   assertUnit(moves.find(Move("d5e7p")) != moves.end());
   assertUnit(moves.find(Move("d5f6p")) != moves.end());
   assertUnit(moves.find(Move("d5b4p")) != moves.end());
   assertUnit(moves.find(Move("d5c3p")) != moves.end());
   assertUnit(moves.find(Move("d5e3p")) != moves.end());
   assertUnit(moves.find(Move("d5f4p")) != moves.end());

   // TEARDOWN
   board.board[2][6] = board.board[4][6] = nullptr;
   board.board[1][5] = board.board[5][5] = nullptr;
   board.board[1][3] = board.board[5][3] = nullptr;
   board.board[2][2] = board.board[4][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free() ////////////////////////////////
{
   // SETUP
   BoardEmpty board; 
   Knight knight(7, 7, false /*white*/); 
   knight.fWhite = true; 
   knight.position.set(3, 4); 

   set <Move> moves;

   // EXERCISE 
   knight.getMoves(moves, board); 

   // VERIFY
   assertUnit(moves.size() == 8);
   cout << "Line 181: Size: " << moves.size() << endl;
   assertUnit(moves.find(Move("d5b6")) != moves.end());
   assertUnit(moves.find(Move("d5c7")) != moves.end());
   assertUnit(moves.find(Move("d5e7")) != moves.end());
   assertUnit(moves.find(Move("d5f6")) != moves.end());
   assertUnit(moves.find(Move("d5b4")) != moves.end());
   assertUnit(moves.find(Move("d5c3")) != moves.end());
   assertUnit(moves.find(Move("d5e3")) != moves.end());
   assertUnit(moves.find(Move("d5f4")) != moves.end());

   // TEARDOWN
}



/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // setup
   Knight knight(0, 0, true);
   // exercise
   PieceType type = knight.getType();
   // verify
   assertEquals(type, KNIGHT);
   assertEquals(KNIGHT, type);
}  // TEARDOWN
