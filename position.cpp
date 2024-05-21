/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

 /******************************************
  * POSITION INSERTION OPERATOR
  ******************************************/
// ostream& operator << (ostream& out, const Position& rhs)
// {
//    out << "error";
//    return out;
// }

// /*************************************
//  * POSITION EXTRACTION OPERATOR
//  **************************************/
// istream& operator >> (istream& in, Position& rhs)
// {
//    return in;
// }

Position::Position(const Position & rhs) : colRow(0)
{
   set(rhs.colRow);
}

bool Position::operator != (const Position & rhs) const
{
   if (isInvalid())
      return rhs.isValid();
   else
      return rhs.colRow != colRow;
}

bool Position::operator == (const Position & rhs) const
{
   if (isInvalid())
      return rhs.isInvalid();
   else
      return rhs.colRow == colRow;
}

/************************************
* POSITION : ASSIGNMENT
*************************************/
const Position & Position::operator = (const char * rhs)
{

   if (rhs == NULL)
      set(0xff);
   else if (rhs[0] < 'a' || rhs[0] > 'h' || rhs[1] < '1' || rhs[1] > '8')
      set(0xff);
   else
      set(rhs[0] - 'a', rhs[1] - '1');
   return *this;
}
 /******************************************
  * POSITION INSERTION OPERATOR
  ******************************************/
ostream& operator << (ostream& out, const Position& rhs)
{
   if (rhs.isValid())
      out << (char)(rhs.getCol() + 'a') << (char)(rhs.getRow() + '1');
   else 
      out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream& operator >> (istream& in, Position& rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
   {
      rhs = text;
   }
   return in;
}