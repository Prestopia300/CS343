// Sudoku Implimentation. Can take from cin, and cout. Can get and set 2d arrays. Has helper methods.

#include "sudoku.h"

void Sudoku::print(ostream& where) const
{
	int count1 = 0; // seperate columns by 3
	int count2 = 0; // seperate rows by 3

	where << "+-------+-------+-------+" << endl;
	for (int i = 0; i < 9; i++) // may need to modify the size on this
	{
		where << "| ";
		for (int j = 0; j < 9; j++)
		{
			where << sudoku_array[i][j] << " ";  //sudokuValue(i, j) << " ";
			count1++;
			if (count1 == 3)
			{
				where << "| ";
				count1 = 0;
			}
		}
		where << endl;
		count2++;
		if (count2 == 3)
		{
			where << "+-------+-------+-------+" << endl;
			count2 = 0;
		}
	}
}

void Sudoku::input(istream& input)
{
	// accounts for spaces in cin input
	string str, out;
	stringstream ss;
	getline(cin, str);
	ss << str;
	while (ss >> out)
	{
		cout << out << endl;
	}

	fillSuduko(str);
}

void Sudoku::fillSuduko(string str)
{
	// Clean string of all non-digits
	// Clean string of all spaces
	int count = 0;
	int index = 0;
	for (auto it = str.begin(); it < str.end(); ++it, ++index)
	{
		if (!isdigit(str.at(index)))
		{
			str.erase(index, 1); 
			index--;
		} 
	}

	// Check if there are 81 digits
	// Add digits to sudoku_array

	cout << "current string : " << str << endl;
	if (str.size() == 81)
	{
		int index = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char c = str[index];
				//cout << "c : " << c << endl;
				int inum = c-48; // in ASCII codes, 48 is 0
				//cout << "inum : " << inum << endl;
				
				sudoku_array[i][j] = inum;
				
				if (inum == 0)
				{
					fixed[i][j] = 0;
				}
				else
				{
					fixed[i][j] = 1;
				}
				
				index++;
			}
		}
	}
	else
	{
		cout << "The sudoku entered does not have 81 digits, or has numbers other than 0-9" << endl;
	}
}

// getters and setters 

int Sudoku::getArr(int row, int column)
{
	return sudoku_array[row][column];  // do I need * ?
}

bool Sudoku::getFixed(int row, int column)
{
	return fixed[row][column];
}

void Sudoku::setArr(int row, int column, int value)
{
	sudoku_array[row][column] = value;
		
}

void Sudoku::setFixed(int row, int column, bool value)
{
	fixed[row][column] = value;
}
