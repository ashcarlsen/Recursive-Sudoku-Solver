#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

/******************************************************************************
*
*	Name: printGrid
* 
*	Function: print's the layout of a 9 by 9 grid in a Sudoku object
* 
*	Inputs/Outputs: none
* 
* 
*******************************************************************************
*Begin
*	Loop through all x and y's using special characters and spacing for 
*		a nice looking format
******************************************************************************/
void Sudoku::printGrid()
{
	//	Loop through all x and y's using special characters and spacing for 
	//	a nice looking format
	for (int x = 0; x < 9; x++)
	{
		if (x != 0)
		{
			std::cout << "            |              |            "
				<< std::endl;
		}
		if (x == 3 || x == 6)
		{
			std::cout << "------------+--------------+------------"
				<< std::endl;
		}
		for (int y = 0; y < 9; y++)
		{
			if (y == 3 || y == 6)
			{
				std::cout << "|  ";
				std::cout << " " << grid[x][y] << "  ";
			}
			else
			{
				std::cout << " " << grid[x][y] << "  ";
			}
		}
		std::cout << std::endl;
	}
}



/******************************************************************************
*
*	Name: check_row
*
*	Function: checks a row of an array for any matching characters
*	
*	Inputs: x for x coordinate and c for character to look for
* 
*	Outputs: 1 if character is found 0 if not found
* 
*******************************************************************************
*
*Begin
*	declare variables
*		For loop through all y's
*			if grid of x y matches the character
*			return 1
*
*	return 0 at end of function if character wasn't found
* End
******************************************************************************/
int Sudoku::check_row(int x, char c)
{
	//declare variables
	int y = 0;
	//For loop thorugh all y's
	for (y = 0; y < 9; y++)	
	{		//if grid of x y matches the character
		if (grid[x][y] == c)
		{	//return true
			return 1;
		}
	}		
	return 0;	//return 0 at end of function if character wasn't found
}


/******************************************************************************
*
*	Name: check_column
*
*	Function: look through a column and see if a character is already in it
*
*	Inputs: y for column number and c for character to check for
*
*	Outputs: 1 if character is found 0 if not
* 
*******************************************************************************
*
*Begin
*	For loop through all x coordinates with same y column
*		if grid of x y is the same as input character
*			return 1
*
*	return 0 if end of loop is reached
*End
******************************************************************************/
int Sudoku::check_column(int y, char c)
{
	//For loop through all x coordinates with the same y column
	for (int x = 0; x < 9; x++)
	{	// if grid of x y is the same as input character
		if (grid[x][y] == c)
		{	//return true
			return 1;
		}
	}
	return 0;	//return 0 if end of loop is reached
}


/******************************************************************************
*
*	Name: check_square
*
*	Function: takes an x y coordinate and a character and checks the 
*			  appropriate region surrounding for that character
*
*	Inputs: x coord y coord and a character c
* 
*	Outputs: 1 if character is found 0 if not found
*
*******************************************************************************
*
*Begin
*	determine range of x and y 
*		run a for loop through that range x9
*End
******************************************************************************/
int Sudoku::check_square(int x, int y, char c)
{
	int check = 0;
	//determine range of x and y 
	//run a for loop through that range
	if (x < 3 && y < 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x > 2 && x < 6) && (y < 3))
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if (x > 5 && y < 3)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x < 3) && (y > 2 && y < 6))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x > 2 && x < 6) && (y > 2 && y < 6))
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x > 5) && (y > 2 && y < 6))
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x < 3) && (y > 5))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if ((x > 2 && x < 6) && (y > 5))
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	}
	//determine range of x and y 
	//run a for loop through that range
	else if((x > 5) && (y > 5))
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (grid[i][j] == c)
				{
					check = 1;
				}
			}
		}
	 }
	else
		{	//if you get this to actually happen I will venmo you a dollar
			// signed Ashton Carlsen
			std::cout << "somehow got here" << std::endl;
		}

	return check;
}


/******************************************************************************
*
*	Name: isValid
*
*	Function: checks if an x y coord is empty
*
*	Inputs: x coord and y coord
*
*	Outputs: 1 if empty 0 if not
*
*******************************************************************************
*
*Begin
*	if x y is * 
*		then return a 1
*	else return 0
* End
******************************************************************************/
int Sudoku::isValid(int x, int y)
{	//if x y is a *
		if (grid[x][y] == '*')
		{	//return true
			return 1;
		}
	else
		return 0; //else return false
}


/******************************************************************************
*
*	Name: isSafe
*
*	Function: compact version to check if a row, column, and square are safe
*			  to insert an input character
*
*	Inputs: takes in x coord y coord and a character c to check against
*
*	Outputs: outputs 1 if it is safe or 0 if not safe
* 
*******************************************************************************
*Begin
*	define variables
*	set one variable to the row check
*	set another bariables to the column check
*	set a third variable to the square check
*	final variable is equal to all three added together
*	if final variable is greater than one meaning a row, column or square was
*	false
*		return false
*	else
*		return true
*End
******************************************************************************/
int Sudoku::isSafe(int x, int y, char c)
{
	//define variables
	int check, check1, check2, fcheck;
	check = check_row(x, c);	//set one variable to the row check
	check1 = check_column(y, c); //set another variable to the column check
	check2 = check_square(x, y, c);	//set a third variable to the square check
	fcheck = check + check1 + check2; //final variable is equal to all three
									  //added together
	if (fcheck > 0)	//if final variable is greater than one, meaning a row, 
					//column or square was false
	{
		return 0;	//return false
	}
	else
	{	//else return true
		return 1;
	}
		//End
}

/******************************************************************************
*
*	Name: set_fixed
*
*	Function: sets a fixed number of spots in a 9 by 9 grid of a Sudoku object
*
*	Inputs: none
*
*	Outputs: none
* 
*******************************************************************************
*Begin
*	define variables
*	set a modifiable variable to the fixed Sudoku value
*	seed random number generator
*	For loop while our modifiable variable is greater than 0
*		if we iterate through the process over 1000 times
*			restart	(safe guard against too high input ie: 70+)
*		get a random x between 0-8
*		get a random y between 0-8
*		get a random number between 1-9
*		convert number to a character for array
*		if it is safe to put that character in the random x y coords
*			then if the character in that spot is an asterik
*				set that spot to the character
*				reduce modifiable variable by 1 to lower spots needed to set
*			else 
*				add one to the iterations
*		else
*			add one to the iterations variable
* End
******************************************************************************/
void Sudoku::set_fixed()
{
	//define variable
	int randx, randy, num;
	int f = fixed; //set a modifiable variable to the fixed Sudoku value
	int iterations = 0;
	char c;
	srand(time(NULL)); //seed random number generator
	for (; f > 0;) //For loop while our modifiable variable is greater than 0
	{
		//if we iterate through the process over 1000 times
		if (iterations > 1000)
		{
			//restart	(safe guard against too high input ie: 70+)
			iterations = 0;
			f = fixed;
			for (int x = 0; x < 9; x++)
			{
				for (int y = 0; y < 9; y++)
				{
					grid[x][y] = '*';
				}
			}
		}
		randx = rand() % 9; //get a random x between 0-8
		randy = rand() % 9; //get a random y between 0-8
		num = (rand() % 9) + 1;	//get a random number between 1-9
		c = (num + 48);		//convert number to a character
		//if it is safe to put that character in the random x y coords
		if (isSafe(randx, randy, c))
		{
			//then if the character in that spot is an asterik
			if (grid[randx][randy] == '*')
			{
				//set that spot to the character
				grid[randx][randy] = c;
				f--; //reduce modifiable variable by 1 to lower spots needed to set
			}
			else { 
				//else add one to the iterations
				iterations++;
			}
		}
		else{
			//else add one to the iterations
			iterations++;
		}
	}
}		//End

/******************************************************************************
* 
*	Name: solve (no paramters, overloaded)
* 
*	Function: calls the other solve function from the start point 0, 0
* 
*	Inputs: none
* 
*	Outputs: outputs 1 if solve function suceeded 0 if failed
* 
*******************************************************************************
* 
* Begin
*	call solve starting at x = 0 and y = 0
*	return whatever value that comes up with
*End 
******************************************************************************/
int Sudoku::solve()
{
	//call solve starting at x = 0 and y = 0
	std::cout << "Solving..." << std::endl << std::endl;
	return Sudoku::solve(0, 0); //return whatever value that comes up with
}	//End


/******************************************************************************
*
*	Name; solve (two paramaters, overloaded)
*
*	Function: start at 0, 0 and use backtracking to solve a Sudoku grid
*
*	Inputs: takes in two integers for starting point (usually 0, 0)
*
*	Outputs: returns 1 if solved 0 if unsolvable
* 
*******************************************************************************
*Begin	
*	if we hit the end of our 2d array
*		return true (yay we did it)		
*	if our y coord goes off the edge
*		increment to the next row
*		reset y
*	if x, y is not a valid place to put a number
*		While it isn't a valid place increment y
*			if y goes off the edge
*				increment x and reset y
*			if we hit the end of the array
*				return true(yay we did it)
*	For loop through characters 1-9
*		if it's safe to place that character at x,y
*			set it
*			if solve of x, y + 1 returns true 
*				then return true
*				(lots and lots of recursion)
*			if it doesn't return true reset grid to an astrik
*	return false if it hit's the end of the recursion and is not solvable
******************************************************************************/
int Sudoku::solve(int x, int y)
{
	//if we hit the end of our 2d array
	if (x == 8 && y == 9)
	{
		//return true (yay we did it)	
		return 1;
	}
	//if our y coord goes off the edge
	if (y == 9)
	{
		//increment to the next row
		x++;
		//reset y
		y = 0;
	}
	//if x, y is not a valid place to put a number
	if (!isValid(x, y))
	{
		//
		while (!isValid(x, y))
		{
			//While it isn't a valid place increment y
			y++;
			//if y goes off the edge
			if (y == 9)
			{
				//increment x and reset y
				x++;
				y = 0;
			}
			//if we hit the end of the array
			if (x == 8 && y == 9)
			{
				//return true(yay we did it)
				return 1;
			}
		}
	}
	//For loop through characters 1-9
	for (char c = 49; c < 58; c++)
	{
		//if it's safe to place that character at x,y
			if (isSafe(x, y, c))
			{
				//set it
				grid[x][y] = c;
				//if solve of x, y + 1 returns true 
				if (solve(x, y + 1))
				{
					//return true
					return 1;	//(lots and lots of recursion)
				}
				//if it doesn't return true reset grid to an astrik
				grid[x][y] = '*';
			}
	}
	
	return 0;	
	//return false if it hit's the end of the recursion and is not solvable
}

