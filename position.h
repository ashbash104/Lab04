/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = { -1,  0 };
const Delta SUB_C = { 0, -1 };


class PositionTest;
class TestMove;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
   friend class TestMove;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs);// {              }
   Position() : colRow(0x99) { set(0xff); }
   bool isInvalid() const { return (colRow & 0x88) ? true : false; }
   bool isValid()   const { return !isInvalid(); }
   void setValid() {   if (isInvalid()) set(0x00); }
   void setInvalid() {   set(0x00);    }
   bool operator <  (const Position& rhs) const { return colRow < rhs.colRow; }
   bool operator == (const Position& rhs) const; // { return true; } // We define these 2 in the .cpp
   bool operator != (const Position& rhs) const; // { return true; }
   const Position& operator =  (const Position& rhs) { return colRow = rhs.colRow;  }

   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0x99) { setLocation(location); }
   int getLocation() const {return getRow() * 8 + getCol(); }
   void setLocation(int location) {
      if (0 <= location && location < 64)
      {
         set(location % 8 /*col*/, location / 8 /*row*/);
      }
      else
         set(0xff);  
   }


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(0x99) {           }
   virtual int getCol() const { return (isInvalid() ? -1 : (int)((colRow & 0xf0) >> 4)); }
   virtual int getRow() const { return (isInvalid() ? -1 : (int)((colRow & 0x0f) >> 0)); }
   void setRow(int r) {  
      if ( r >= 0 && r < 8) 
      {
         set((colRow & 0xf0) + (char)r);
      }
      else {
         set(0xff); // Invalid position
      }          
   }
   void setCol(int c) {  
      if (c >= 0 && c < 8)
          set((colRow & 0x0f) + ((char)c << 4));
      else
         set(0xff);         
      }
   void set(int c, int r) {   set(0xff); setRow(r); setCol(c);          }

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x99) {
      // Check if the string has at least two characters
      if (s && s[0] && s[1]) {
         // Extract column and row from the string
         int col = s[0] - 'a'; // Assuming lowercase letters for columns ('a' -> 0, 'b' -> 1, ..., 'h' -> 7)
         int row = s[1] - '1'; // Assuming '1' -> 0, '2' -> 1, ..., '8' -> 7

         // Check if column and row values are within valid range
         if (col >= 0 && col < 8 && row >= 0 && row < 8) {
            // Set the colRow value
            colRow = static_cast<uint8_t>((col << 4) | row);
         }
      }
   }
   const Position& operator =  (const char* rhs); // this is in cpp
   const Position& operator =  (const string& rhs) {  *this = rhs.c_str(); return *this; }


   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const { return (int)((double)getCol() * getSquareWidth() + OFFSET_BOARD); }
   int getY()   const { return (int)((double)getRow() * getSquareHeight() + OFFSET_BOARD);}
   void setXY(double x, double y) { set((int)((x - OFFSET_BOARD) / getSquareWidth())),
                                    7 - (int)((y - OFFSET_BOARD) / getSquareHeight());}
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight;}
   void setSquareWidth(double width) { 
      if (width > 0.0)
         squareWidth = width; 
    }
   void setSquareHeight(double height) { 
      if (height > 0.0)
         squareHeight = height; 
    }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1) { set(rhs.getCol() + delta.dCol, rhs.getRow() + delta.dRow); }
   void adjustRow(int dRow) { 
      if (isValid())
         setRow(getRow() + (char)dRow); 
   }
   void adjustCol(int dCol) {
      if (isValid())
         setCol(getCol() + (char)dCol);
    }
   const Position& operator += (const Delta& rhs) {adjustRow(rhs.dRow); adjustCol(rhs.dCol); return *this; }
   Position operator + (const Delta& rhs) const { Position newPos(*this); newPos += rhs; return newPos; }

private:
   void set(uint8_t colRowNew) { this->colRow = colRowNew; }

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

