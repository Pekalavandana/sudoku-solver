
#include <bits/stdc++.h>
using namespace std;

int sudoko[9][9];

/*
1.using backtracking we solve the sudoko
 fun(solve_sudoko)
*check the position value if 0 assign if not equal to 0 skip 
else 1.check place a digit and check its fealisble to keep or not and move to next
if something wrong move back  check other digits if possible move forward
2. if it reaches and return 
3. if it is possible print the result value*/

bool if_zero(int sudoko[9][9],int& row, int& col)
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (sudoko[row][col] == 0)
				return 1;
	return 0;
}

bool checkInRow(int sudoko[9][9], int row, int num)// if  the value exist in that row other than that place 
{
	for (int col = 0; col < 9; col++)
		if (sudoko[row][col] == num)
			return 1;
	return 0;
}

bool checkInCol(int sudoko[9][9], int col, int num){//if  the value exist in that row other than that place
	for (int row = 0; row < 9; row++){
		if (sudoko[row][col] == num)
			return 1;
	}
	return 0;
}

bool checkInBox(int sudoko[9][9], int boxStartRow,int boxStartCol, int num)//if  the value exist in that 3x3 box other than that place
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (sudoko[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return 1;
	return 0;
}


bool isSafe(int sudoko[9][9], int row,int col, int num)// by above three checks we see its safe to place the num in that position
{
	
	return !checkInRow(sudoko, row, num)
		&& !checkInCol(sudoko, col, num)
		&& !checkInBox(sudoko, row - row % 3,
						col - col % 3, num)
		&& sudoko[row][col] == 0;
}
/* now by use the checkcondition functions we write  a backtracking algo and iterate on the elements of sudoko*/

bool Solve_Sudoku(int sudoko[9][9])
{
	int row, col;

	
	if (!if_zero(sudoko, row, col))
		
		return 1;

	for (int num = 1; num <= 9; num++)
	{
		
		
		if (isSafe(sudoko, row, col, num))
		{
			
			
			sudoko[row][col] = num;

			
			if (Solve_Sudoku(sudoko))
				return 1;

			
			sudoko[row][col] = 0;
		}
	}
	
	
	return 0;
}

void print_solvedsudoko(int sudoko[9][9])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
			cout << sudoko[row][col] << " ";
		cout << endl;
	}
}

int main()
{
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			int x;cin>>x;
			sudoko[i][j]=x;
		}
	}
//print the sudoko if possible 
	if (Solve_Sudoku(sudoko) == 1)
		print_solvedsudoko(sudoko);
	else
		cout << "No solution exists";

	return 0;
}


