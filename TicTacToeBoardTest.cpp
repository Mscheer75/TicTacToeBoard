/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
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
	Piece turn = X;
	Piece Changed = X;
	Changed = obj.toggleTurn();
	Changed = obj.toggleTurn();
	ASSERT_EQ(turn, Changed);
}


