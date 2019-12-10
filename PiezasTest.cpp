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

TEST(PiezasTest, emptyBoardPeiceCheck)
{
	Piezas game;

	ASSERT_EQ(game.pieceAt(2,3), Blank);
}

TEST(PiezasTest, initBoardPeiceCheck)
{
	Piezas game;
	game.dropPiece(3);

	std::cout << X << std::endl;
	std::cout << O << std::endl;
	std::cout << Blank << std::endl;
	std::cout << game.pieceAt(2,3) << std::endl;


	ASSERT_EQ(game.pieceAt(2,3), X);
}

