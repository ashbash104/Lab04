 /***********************************************************************
  * Header File:
  *    TEST Queen
  * Author:
  *    Ashlee Hart and Emily Raventos
  * Summary:
  *    The unit tests for the Queen
  ************************************************************************/

 #pragma once


 #include "unitTest.h"
  /***************************************************
   * Queen TEST
   * Test the Queen class
   ***************************************************/
 class TestQueen : public UnitTest
 {
 public:

    void run()
    {
       getMoves_blocked();
       getMoves_slideToEnd();
       getMoves_slideToBlock();
       getMoves_slideToCapture();

       getType();

       report("Queen");
    }
 private:
    void getMoves_blocked();
    void getMoves_slideToEnd();
    void getMoves_slideToBlock();
    void getMoves_slideToCapture();
    void getType();
 };

