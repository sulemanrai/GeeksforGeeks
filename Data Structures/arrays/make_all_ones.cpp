#include<iostream>
using namespace std;

void printArray(int **arr, int rows, int cols)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << arr[r][c] << ' ';
		}
		//cout << endl;
	}
}

void make_all_ones(int **arr, int row, int col)
{
	for(int r = row - 1 ; r >=0 ; r--)
	{
		arr[r][col] = 1;
	}

	for (int c = col - 1; c >= 0; c--)
	{
		arr[row][c] = 1;
	}
}

void boolean_matrix_problem(int **arr, int rows, int cols)
{
	int **tmpArr = new int*[rows];

	for(int i = 0; i < rows; i++)
	{
		tmpArr[i] = new int[cols];
	}

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			//
			if(arr[i][j] == 1)
			{
				tmpArr[i][j] = 0;
			} else if(arr[i][j] == 0)
			{
				tmpArr[i][j] = 1;
			}
		}
	}

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(arr[r][c] == 1 && tmpArr[r][c] == 0)
			{
				int tmpR = r;
				int tmpC = c;
				//make_all_ones(arr, r, c);
				for (int rr = 0; rr < rows; rr++)
				{
					arr[rr][c] = 1;
					//tmpArr[rr][c] = 1;
				}

				for (int cc = 0; cc < cols; cc++)
				{
					arr[r][cc] = 1;
					//tmpArr[r][cc] = 1;
				}

			}
		}
	}
	printArray(arr, rows, cols);

	//Free each sub-array
	for (int i = 0; i < rows; ++i) {
		delete[] tmpArr[i];
	}
	//Free the array of pointers
	delete[] tmpArr;
}



int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int r;
		cin >> r;

		int c;
		cin >> c;

		int **arr = new int*[r];

		for(int i = 0; i < r; i++)
		{
			arr[i] = new int[c];
		}

		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}

		//printArray(arr, r, c);

		boolean_matrix_problem(arr, r, c);
		cout << endl;

		//Free each sub-array
		for (int i = 0; i < r; ++i) {
			delete[] arr[i];
		}
		//Free the array of pointers
		delete[] arr;
	}

	return 0;
}