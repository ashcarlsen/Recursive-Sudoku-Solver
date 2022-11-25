#ifndef SUDOKU
#define SUDOKU

class Sudoku {		//class definition
private:
	char grid[9][9];	//private variables
	int fixed;
	int solve(int x, int y);		//private methods
	int check_row(int x, char c);
	int check_column(int y, char c);
	int check_square(int x, int y, char c);
	int isSafe(int x, int y, char c);
	void set_fixed();
	int isValid(int x, int y);
public:
	Sudoku(int n)			//Constructor method
	{
		fixed = n;			//paramter n goes into the fixed private variable
		
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)		//set everything to astriks
			{
				grid[x][y] = '*';
			}
		}
		set_fixed();	//call function to set fixed posititons
	}
	void printGrid();	//public methods
	int solve();
};

#endif