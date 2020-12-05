/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <stdio.h>

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)	
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, Togle_test)
{

	TicTacToeBoard obj;
	Piece object = X;
	Piece Changed = X;
	Changed = obj.toggleTurn();
	ASSERT_NE(object, Changed);
}


TEST(TicTacToeBoardTest, double_toggle)
{

	TicTacToeBoard obj;
	Piece goal = X;
	Piece Changed = X;
	Changed = obj.toggleTurn();
	Changed = obj.toggleTurn();

	ASSERT_EQ(goal, Changed);
}

TEST(TicTacToeBoardTest, placement_test)
{

	TicTacToeBoard obj;
	Piece goal = O;
	Piece end = obj.placePiece(1,1);
	ASSERT_EQ(goal, end);
}

TEST(TicTacToeBoardTest, placement_test_sameplacement)
{

	TicTacToeBoard obj;
	Piece goal = O;
	obj.placePiece(1,1);
	Piece end = obj.placePiece(1,1);
	ASSERT_NE(goal, end);
}

TEST(TicTacToeBoardTest, placement_outofboundsFail)
{

	TicTacToeBoard obj;
	Piece goal = O;
	Piece end = obj.placePiece(-1,1);
	ASSERT_NE(goal, end);
}

TEST(TicTacToeBoardTest, getPiece_outofboundsFail)
{

	TicTacToeBoard obj;
	Piece goal = O;
	Piece end = obj.getPiece(-1,1);
	ASSERT_NE(goal, end);
}

TEST(TicTacToeBoardTest, getPiece)
{

	TicTacToeBoard obj;
	Piece goal = X;
	obj.placePiece(1, 1);
	Piece end = obj.getPiece(1,1);
	ASSERT_EQ(goal, end);
}

TEST(TicTacToeBoardTest, getPiece_blank)
{

	TicTacToeBoard obj;
	Piece goal = Blank;
	Piece end = obj.getPiece(1,1);
	ASSERT_EQ(goal, end);
}

TEST(TicTacToeBoardTest, getWinner_invalid)
{

	TicTacToeBoard obj;
	Piece goal = Invalid;
	Piece end = obj.getWinner();
	ASSERT_EQ(goal, end);
}

TEST(TicTacToeBoardTest, getWinner_blank)
{

	TicTacToeBoard obj;
	Piece goal = Blank;
	obj.placePiece(0, 0);
	obj.placePiece(1, 1);
	obj.placePiece(2, 2);
	obj.placePiece(0, 2);
	obj.placePiece(2, 0);
	obj.placePiece(1, 0);
	obj.placePiece(0, 1);
	obj.placePiece(2, 1);
	obj.placePiece(1, 2);


	Piece end = obj.getWinner();
	ASSERT_EQ(goal, end);
}


