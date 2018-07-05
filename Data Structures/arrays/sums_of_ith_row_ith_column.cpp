#include<iostream>
using namespace std;

bool sums_of_ith_row_ith_column(int **arr, int rows, int cols)
{
	bool ans = false;

	int *sumRow = new int[rows];
	int *sumCol = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		sumRow[i] = 0;
	}

	for (int i = 0; i < cols; i++)
	{
		sumCol[i] = 0;
	}

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			sumRow[r] += arr[r][c];
			sumCol[c] += arr[r][c];
			//cout << arr[r][c] << ' ';
		}
		//cout << endl;
	}

		//cout << sumRow[0] << ' ';

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if(sumRow[r] == sumCol[r])
			{
				ans = true;
				break;
			}
		}
		if (ans == true) {
			break;
		}
	}

	// for(int r = 0; r < rows; r++)
	// {
	// 	cout << sumRow[r] << ' ';
	// }
	// cout << endl;
	// for (int c = 0; c < cols; c++)
	// {
	// 	cout << sumCol[c] << ' ';
	// }

	return ans;
}

int main()
{
	//code
	int T;
	cin >> T;

	while (T--)
	{
		int R;
		cin >> R;
		int C;
		cin >> C;
		int **arr = new int*[R];
		for (int i = 0; i < R; i++)
		{
			arr[i] = new int[C];
		}

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				int element;
				cin >> element;
				arr[r][c] = element;
			}
		}
		//cout << sums_of_ith_row_ith_column(arr, R, C) << endl;
		if (sums_of_ith_row_ith_column(arr, R, C) == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
