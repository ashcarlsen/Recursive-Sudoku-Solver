#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <limits>

/******************************************************************************
*
*	Name: main
* 
*	Function: take an input and create a sudoku game using the input as number
*			  of fixed positions to start with.
* 
*	Inputs/Outputs: none
* 
*	Compile Instructions: VS
*
* *****************************************************************************
* 
*Begin 
*	define variables
*	ask for input
*	scan input
*		while input is bad	
*			clear flags
*			clear buffer until a new line
*			get new input
*	create Sudoku object with variable
*	print it
*	if game is solvable
*		then solve and print
*	else
*		print unsolvable
*End
******************************************************************************/

int main(int argc, char* argv[])
{
	int fixed;	//define variables
	//ask for input
	std::cout << "Welcome to Sudoku Solver!" << std::endl;
	std::cout << "Enter number of squares to prepopulate: ";
	std::cin >> fixed;	//scan input
	while (std::cin.fail())		//while input is bad
	{
		std::cin.clear();			//clear flags
		//clear buffer until a new line
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		std::cout << "Invalid Input" << std::endl;	//get new input
		std::cin >> fixed;
	}
	Sudoku my_game(fixed);	//create Sudoku object with variable
	my_game.printGrid();	//print it
	std::cout << std::endl << std::endl;
	if (my_game.solve())	//if game is solvable
	{		//then solve and print
		my_game.printGrid();
	}
	else
	{			//else print unsolvable
		std::cout << "Sorry.. Unsolvable Board" << std::endl;
	}
		return 0;	//End
}