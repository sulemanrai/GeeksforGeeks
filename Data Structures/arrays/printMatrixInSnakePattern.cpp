#include<iostream>
using namespace std;

void printMatrixInSnakePattern(int **arr, int rows, int cols)
{
	for(int r = 0; r < rows; r++)
	{
		if (r % 2 == 0) {
			for (int c = 0; c < cols; c++)
			{
				cout << arr[r][c] << ' ';
			}
		} else if (r % 2 != 0)
		{
			for (int c = cols - 1; c >= 0; c--)
			{
				cout << arr[r][c] << ' ';
			}
		}
		//cout << endl;
	}

}

int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;

		int ** arr = new int * [n];

		for(int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}
		printMatrixInSnakePattern(arr, n, n);
		cout << endl;
	}
	return 0;
}
