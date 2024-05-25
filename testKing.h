 /***********************************************************************
  * Header File:
  *    TEST King
  * Author:
  *    <Ashlee Hart and Emily Raventos
  * Summary:
  *    The unit tests for the King
  ************************************************************************/

 #pragma once


 #include "unitTest.h"
  /***************************************************
   * King TEST
   * Test the King class
   ***************************************************/
 class TestKing : public UnitTest
 {
 public:

    void run()
    {
       getMoves_blocked();
       getMoves_slideToEnd();
       getMoves_slideToBlock();
       getMoves_slideToCapture();

       getType();

       report("King");
    }
 private:
    void getMoves_blocked();
    void getMoves_slideToEnd();
    void getMoves_slideToBlock();
    void getMoves_slideToCapture();
    void getType();
 };

