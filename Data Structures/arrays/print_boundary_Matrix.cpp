#include<iostream>
using namespace std;

void print_boundary_Matrix(int **arr, int rows, int cols)
{
	bool check = false;
	for(int r = 0; r < rows; r++ )
	{
		for(int c = 0; c < cols; c++)
		{
			if(r == 0)
			{
				cout << arr[r][c] << ' ';
			} else if(r == rows - 1)
			{
				cout << arr[r][c] << ' ';
			} else if(c == 0)
			{
				cout << arr[r][c] << ' ';
			} else if(c == cols - 1)
			{
				cout << arr[r][c] << ' ';
			} else
			{
			//	cout << ' ' << ' ';
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
		int N;
		cin >> N;
		int **arr = new int *[N];
		for(int i = 0; i < N; i++)
		{
			arr[i] = new int[N];
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}
		print_boundary_Matrix(arr, N, N);
		cout << endl;
	}
	return 0;
}
