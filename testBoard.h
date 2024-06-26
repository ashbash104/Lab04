 /***********************************************************************
  * Header File:
  *    TEST BOARD
  * Author:
  *    Emily Raventos and Ashlee Hart
  * Summary:
  *    The unit tests for Board
  ************************************************************************/

 #pragma once

 #include "unitTest.h"

 class Board;

 /***************************************************
  * BOARD TEST
  * Test the Board class
  ***************************************************/
 class TestBoard : public UnitTest
 {
 public:
     void run();
 private:
    void move_knightMove();
    void move_knightAttack();
    void createDummyBoard(Board& board);
    void construct_default();
    void getCurrentMove_initial();
    void getCurrentMove_second();
    void getCurrentMove_middleWhite();
    void getCurrentMove_middleBlack();

    void whiteTurn_initial();
    void whiteTurn_second();
    void whiteTurn_middleWhite();
    void whiteTurn_middleBlack();

    void move_pawnSimple();
    void move_pawnCapture();
    void move_pawnDouble();
    void move_pawnEnpassant();
    void move_pawnPromotion();
    void move_rookSlide();
    void move_rookAttack();
    void move_bishopSlide();
    void move_bishopAttack();
    //void move_knightMove();
    //void move_knightAttack();
    void move_queenSlide();
    void move_queenAttack();
    void move_kingMove();
    void move_kingAttack();
    void move_kingShortCastle();
    void move_kingLongCastle();

    void fetch_a1();
    void fetch_h8();
    void fetch_a8();
    void set_a1();
    void set_h8();
    void set_a8();
 };



