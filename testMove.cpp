/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    Emily Raventos and Ashlee Hart
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>
using namespace std;

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
	// exercise
	Move moveTest; // default constructor
    // verify
	assertUnit(0xff == moveTest.source.colRow);
	assertUnit(0xff == moveTest.dest.colRow);
	assertUnit(SPACE == moveTest.promote);
	assertUnit(SPACE == moveTest.capture);
	assertUnit(Move::MOVE == moveTest.moveType);
	assertUnit(true == moveTest.isWhite);
}

/*************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =2,5
 *         type  =MOVE
 **************************************/
void TestMove::constructString_simple()
{
   // setup
	Move move("e5e6");
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(true == move.isWhite);
}


/*************************************
 * READ simple move
 * Input:  e5d6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{
   // setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move.read("e5d6");
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(false == move.isWhite);
}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move.read(string("e5e6r"));
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(false == move.isWhite);
   }

/*************************************
 * READ enpassant move
 * Input:  e5d6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move.read(string("e5f6E"));
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x55 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::ENPASSANT == move.moveType);
	assertUnit(false == move.isWhite);
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move.read(string("e1g1c"));
	// verify
	assertUnit(0x40 == move.source.colRow);
	assertUnit(0x60 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::CASTLE_KING == move.moveType);
	assertUnit(false == move.isWhite);}


/*************************************
 * READ queen side castle
 * Input:  e1g1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move.read(string("e5e6"));
	// verify
	assertUnit(0x40 == move.source.colRow);
	assertUnit(0x20 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::CASTLE_QUEEN == move.moveType);
	assertUnit(false == move.isWhite);
}

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_simple()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = true;
	move.text = "ERROR";
	// exercise
	move = string("e5e6");
	// verify
	assertUnit(0x40 == move.source.colRow);
	assertUnit(0x20 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move = string("e5d6r");
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x35 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(ROOK == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(false == move.isWhite);}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5d6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move = string("e5d6E");
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x55 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::ENPASSANT == move.moveType);
	assertUnit(false == move.isWhite);}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move = string("e1g1c");
	// verify
	assertUnit(0x40 == move.source.colRow);
	assertUnit(0x60 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(ROOK == move.capture);
	assertUnit(Move::CASTLE_KING == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1g1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
	// setup
	Move move;
	move.source.colRow = 0xff;
	move.dest.colRow = 0xff;
	move.promote = KNIGHT;
	move.capture = BISHOP;
	move.moveType = Move::MOVE_ERROR;
	move.isWhite = false;
	move.text = "ERROR";
	// exercise
	move = string("e1g1C");
	// verify
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x35 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(ROOK == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(false == move.isWhite);}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output: e5e6
 **************************************/
void TestMove::getText_simple()
{
	// setup
	Move move;
	move.source.colRow = 0x44;
	move.dest.colRow = 0x45;
	move.promote = SPACE;
	move.capture = SPACE;
	move.moveType = Move::MOVE;
	move.isWhite = true;
	move.text = "";
	string s;
	// exercise 
	//string s;
	s = move.getText();
	
	// verify
	assertUnit("e5e6" == move.getText());
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Input:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
	// setup
	Move move;
	move.source.colRow = 0x44;
	move.dest.colRow = 0x45;
	move.promote = SPACE;
	move.capture = ROOK;
	move.moveType = Move::MOVE;
	move.isWhite = true;
	move.text = "";
	string s;
	// exercise 
	s = move.getText();
	// verify
	assertUnit(s == string("e5e6r"));
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(ROOK == move.capture);
	assertUnit(Move::MOVE == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =4,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Input:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
	// setup
	Move move;
	move.source.colRow = 0x44;
	move.dest.colRow = 0x45;
	move.promote = SPACE;
	move.capture = SPACE;
	move.moveType = Move::ENPASSANT;
	move.isWhite = true;
	move.text = "";
	string s;
	// exercise 
	s = move.getText();
	// verify
	assertUnit(s == string("e5f6E"));
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::ENPASSANT == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Input:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
	// setup
	Move move;
	move.source.colRow = 0x40;
	move.dest.colRow = 0x60;
	move.promote = SPACE;
	move.capture = SPACE;
	move.moveType = Move::CASTLE_KING;
	move.isWhite = true;
	move.text = "";
	string s;
	// exercise 
	s = move.getText();
	// verify
	assertUnit(s == string("e1g1c"));
	assertUnit(0x40 == move.source.colRow);
	assertUnit(0x60 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::CASTLE_KING == move.moveType);
	assertUnit(true == move.isWhite);}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Input:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
	Move move;
	move.source.colRow = 0x40;
	move.dest.colRow = 0x20;
	move.promote = SPACE;
	move.capture = SPACE;
	move.moveType = Move::CASTLE_QUEEN;
	move.isWhite = true;
	move.text = "";
	string s;
	// exercise 
	s = move.getText();
	// verify
	assertUnit(s == string("e1c1C"));
	assertUnit(0x44 == move.source.colRow);
	assertUnit(0x45 == move.dest.colRow);
	assertUnit(SPACE == move.promote);
	assertUnit(SPACE == move.capture);
	assertUnit(Move::ENPASSANT == move.moveType);
	assertUnit(true == move.isWhite);
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(SPACE);
   // verify
   assertUnit(type = ' ');
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(PAWN);
   // verify
   assertUnit(type = 'p');
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(BISHOP);
   // verify
   assertUnit(type = 'b');
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(KNIGHT);
   // verify
   assertUnit(type = 'n');
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(ROOK);
   // verify
   assertUnit(type = 'r');
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   Move m;
   // exercise
   char type = m.letterFromPieceType(QUEEN);
   // verify
   assertUnit(type = 'q');
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
	Move m;
	// exercise
	char type = m.letterFromPieceType(KING);
	// verify
	assertUnit(type = 'k');
	assertEquals(type, 'k');
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('p');
	//verify
	assertUnit(type = PAWN);
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('b');
	//verify
	assertUnit(type = BISHOP);
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Input:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('n');
	//verify
	assertUnit(type = KNIGHT);
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Input:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('r');
	//verify
	assertUnit(type = ROOK);
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Input:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('q');
	//verify
	assertUnit(type = QUEEN);
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Input:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
	Move m;
	PieceType p;
	// exercise
	PieceType type = m.pieceTypeFromLetter('k');
	//verify
	assertUnit(type = KING);
}
