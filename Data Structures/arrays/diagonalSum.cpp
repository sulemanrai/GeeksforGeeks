#include<iostream>
using namespace std;

int diagonalSum(int **arr, int rows, int cols)
{
	int ans = 0;

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			if(r == c)
			{
				ans += arr[r][c];
			}
		}
	}
	//cout << ans << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = cols - 1; c >= 0; c--)
		{
			if (r + c == cols - 1)
			{
				ans += arr[r][c];
				//cout << arr[r][c] << ' ';
			}
			//cout << arr[r][c] << ' ';
		}
	}


	return ans;
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
		int **arr = new int*[N];
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
		cout << diagonalSum(arr, N, N) << endl;
	}

	return 0;
}
