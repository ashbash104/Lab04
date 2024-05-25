/***********************************************************************
 * Header File:
 *    TEST PAWN
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The unit tests for Pawn
 ************************************************************************/

#pragma once

#include "unitTest.h"


/***************************************************
 * PAWN TEST
 * Test the Pawn class
 ***************************************************/
class TestPawn : public UnitTest
{
public:

   void run()
   {
      getMoves_blocked();
      getMoves_capture();
      getMoves_free();
      getMoves_end();
      //getMoves_enpassant();

      getType();
      
      report("Pawn");
   }
private:
   void getMoves_blocked();
   void getMoves_capture();
   void getMoves_free();
   void getMoves_end();
   void getType();
};
