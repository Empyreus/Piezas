#include "Piezas.h"
#include <vector>
#include <iostream>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	board = std::vector < std::vector<Piece> >(3, std::vector<Piece>(4, Blank));
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	board = std::vector < std::vector<Piece> >(3, std::vector<Piece>(4, Blank));
	turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{

	if(board[2][column] == Blank){
		board[2][column] = turn;
		// std::cout << "Piece at: " << 2 << " " << column << std::endl;
	}
	else if(board[1][column] == Blank){
		board[1][column] = turn;
		// std::cout << "Piece at: " << 1 << " " << column << std::endl;
	}
	else if(board[0][column] == Blank){
		board[0][column] = turn;
		// std::cout << "Piece at: " << 0 <<  " " << column << std::endl;
	}

	Piece old_turn = turn;

	if(turn == O){
		turn = X;
	}
	else if (turn == X){
		turn = O;
	}

	// std::cout << "Old Turn: " << old_turn << std::endl;
	// std::cout << "New Turn: " << turn << std::endl;

    return old_turn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
	int longestX = 0;
	int longestO = 0;

	for(int i = 0; i < 4; i++){
		int countX = 0;
		int countO = 0;
		
		for(int j = 1; j < 3; j++){
			if(board[j][i] == board[j-1][i]){
				if(board[j][i] == X){
					countX++;
				}
				else if(board[j][i] == O){
					countO++;
				}
				else if(board[j][i] == Blank){
					return Invalid;
				}
			}

			std::cout << board[j][i] << " | ";
		}

		std::cout << std::endl;

		if(countX > longestX){
			longestX = countX;
		}
		if(countO > longestO){
			longestO = countO;
		}

	}

	for(int j = 0; j < 3; j++){
		int countX = 0;
		int countO = 0;
		
		for(int i = 1; i < 4; i++){
			if(board[j][i] == board[j][i-1]){
				if(board[j][i] == X){
					countX++;
				}
				else if(board[j][i] == O){
					countO++;
				}
			}
		}

		if(countX > longestX){
			longestX = countX;
		}
		if(countO > longestO){
			longestO = countO;
		}

	}

	if(longestX > longestO){
		return X;
	}
	else if(longestO > longestX){
		return O;
	}

    return Blank;
}

