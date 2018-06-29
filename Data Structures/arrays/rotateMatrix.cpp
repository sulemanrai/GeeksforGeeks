#include<iostream>
using namespace std;

void printArray(int **a, int n)
{
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << ' ';
		}
		//cout << endl;
	}
}

void rotateMatrix(int ** mat, int N)
{
	// Consider all squares one by one
	for (int x = 0; x < N / 2; x++)
	{
		// Consider elements in group of 4 in
		// current square
		for (int y = x; y < N - x - 1; y++)
		{
			// store current cell in temp variable
			int temp = mat[x][y];

			// move values from right to top
			mat[x][y] = mat[y][N - 1 - x];

			// move values from bottom to right
			mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

			// move values from left to bottom
			mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

			// assign temp to left
			mat[N - 1 - y][x] = temp;
		}
	}
}

int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		int** arr = new int*[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}
		//printArray(arr, N);
		rotateMatrix(arr, N);
		//cout << endl;
		printArray(arr, N);
		cout << endl;
	}

	return 0;
}
