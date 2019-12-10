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

	std::cout << "X: " << X << std::endl;
	std::cout << "O: " << O << std::endl;
	std::cout << "Blank: " << Blank << std::endl;

	ASSERT_TRUE(true);
}

TEST(PiezasTest, emptyBoardPeiceCheck)
{
	Piezas game;

	ASSERT_EQ(game.pieceAt(2,3), Blank);
}

TEST(PiezasTest, initBoardPeiceCheck)
{
	Piezas game;
	game.dropPiece(3);

	ASSERT_EQ(game.pieceAt(2,3), X);
}

TEST(PiezasTest, sameBoardPeiceCheck)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);

	ASSERT_EQ(game.pieceAt(1,3), O);
}

TEST(PiezasTest, sameBoardColumn31)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);

	ASSERT_EQ(game.pieceAt(0,3), X);
}

TEST(PiezasTest, sameBoardColumn32)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);

	ASSERT_EQ(game.pieceAt(0,3), X);
}

TEST(PiezasTest, sameBoardColumn20)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);


	ASSERT_EQ(game.pieceAt(2,2), O);
}

TEST(PiezasTest, boardReset)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);

	game.reset();

	ASSERT_EQ(game.pieceAt(0,3), Blank);
}

TEST(PiezasTest, boardInvalid)
{
	Piezas game;

	ASSERT_EQ(game.gameState(), Invalid);
}

TEST(PiezasTest, winnerBlank)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);



	ASSERT_EQ(game.gameState(), Blank);
}

TEST(PiezasTest, winnerX)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);




	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, winnerO)
{
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);




	ASSERT_EQ(game.gameState(), O);
}

TEST(PiezasTest, winnerX2)
{
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);

	ASSERT_EQ(game.gameState(), X);
}