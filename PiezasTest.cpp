/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, checkXatRow0Col0)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.pieceAt(0,0);
	ASSERT_EQ(actual,X);
} 

TEST(PiezasTest, checkOatRow1Col0)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.pieceAt(1,0);
	ASSERT_EQ(actual,O);
} 

TEST(PiezasTest, checkXatRow2Col0)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.pieceAt(2,0);
	ASSERT_EQ(actual,X);
} 

TEST(PiezasTest, dropPieceTestOutOfBoundsColLeft)
{
	Piezas test;
	Piece actual = test.dropPiece(-1);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, dropPieceTestOutOfBoundsColRight)
{
	Piezas test;
	Piece actual = test.dropPiece(3);
	actual = test.dropPiece(4);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, dropPiececheckColFull)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	ASSERT_EQ(actual,Blank);
} 


TEST(PiezasTest, pieceAtOutofBoundLowerLeftCorner)
{
	Piezas test;
	Piece actual = test.pieceAt(-1,-1);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundLeft)
{
	Piezas test;
	Piece actual = test.pieceAt(0,-1);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundRight)
{
	Piezas test;
	Piece actual = test.pieceAt(0,4);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundDownLeft)
{
	Piezas test;
	Piece actual = test.pieceAt(-1,0);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundDownRight)
{
	Piezas test;
	Piece actual = test.pieceAt(-1,3);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundLowerRightCorner)
{
	Piezas test;
	Piece actual = test.pieceAt(-1,4);
	ASSERT_EQ(actual,Invalid);
} 
TEST(PiezasTest, pieceAtOutofBoundUpRight)
{
	Piezas test;
	Piece actual = test.pieceAt(3,3);
	ASSERT_EQ(actual,Invalid);
} 
TEST(PiezasTest, pieceAtOutofBoundUpLeft)
{
	Piezas test;
	Piece actual = test.pieceAt(3,0);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, pieceAtOutofBoundUpperRightCorner)
{
	Piezas test;
	Piece actual = test.pieceAt(3,4);
	ASSERT_EQ(actual,Invalid);
}
 
TEST(PiezasTest, pieceAtOutofBoundUpperLeftCorner)
{
	Piezas test;
	Piece actual = test.pieceAt(3,-1);
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, resetBoardCheck)
{
	Piezas test;
	Piece actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	test.reset();
	actual = test.pieceAt(2,1);
	ASSERT_EQ(actual,Blank);
} 

TEST(PiezasTest, gameStateBoardNotFull)
{
	Piezas test;
	Piece actual = test.dropPiece(2);
	actual = test.dropPiece(2);
	actual = test.dropPiece(2);
	actual = test.gameState();
	ASSERT_EQ(actual,Invalid);
} 

TEST(PiezasTest, gameStateBoardFullNoWinner)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	actual = test.dropPiece(2);
	actual = test.dropPiece(2);
	actual = test.dropPiece(2);
	actual = test.dropPiece(3);
	actual = test.dropPiece(3);
	actual = test.dropPiece(3);
	actual = test.gameState();
	ASSERT_EQ(actual,Blank);
} 

TEST(PiezasTest, gameStateBoardFullNoWinnerRow0EQRow1)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	actual = test.dropPiece(2);
	actual = test.dropPiece(2);
	actual = test.dropPiece(3);
	actual = test.dropPiece(3);
	actual = test.dropPiece(0);
	actual = test.dropPiece(1);
	actual = test.dropPiece(2);
	actual = test.dropPiece(3);
	actual = test.gameState();
	ASSERT_EQ(actual,Blank);
} 

TEST(PiezasTest, gameStateBoardXWinner)
{
	Piezas test;
	Piece actual = test.dropPiece(0);
	actual = test.dropPiece(0);
	actual = test.dropPiece(1);
	actual = test.dropPiece(1);
	actual = test.dropPiece(0);
	actual = test.dropPiece(1);
	actual = test.dropPiece(2);
	actual = test.dropPiece(3);
	actual = test.dropPiece(2);
	actual = test.dropPiece(3);
	actual = test.dropPiece(3);
	actual = test.dropPiece(2);
	actual = test.gameState();
	ASSERT_EQ(actual,X);
} 
