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
		cout << endl;
	}
}

bool searrchElement(int **arr, int rows, int cols, int x)
{
	bool found = false;

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(arr[r][c] == x)
			{
				found = true;
				break;
			}
		}
	}

	return found;
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
		int M;
		cin >> M;
		int **arr = new int*[N];
		for(int i = 0; i < N; i++)
		{
			arr[i] = new int[M];
		}

		for(int n = 0; n < N; n++)
		{
			for(int m = 0; m < M; m++)
			{
				int element;
				cin >> element;
				arr[n][m] = element;
			}
		}
		int x;
		cin >> x;
		//printArray(arr, N, M);
		cout << searrchElement(arr, N, M, x) << endl;
	}

	return 0;
}
