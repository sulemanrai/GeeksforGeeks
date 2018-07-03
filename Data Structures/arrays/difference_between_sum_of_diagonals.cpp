#include<iostream>
#include <vector>
using namespace std;

int difference_between_sum_of_diagonals(int **arr, int n)
{
	int ans = 0;
	int diag1 = 0;
	int diag2 = 0;

	int size  = n;
	//cout << size << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				diag1 += arr[i][j];
			}
		}
	}

	for (int r = 0; r < size; r++)
	{
		for (int c = size - 1; c >= 0; c--)
		{
			if(r + c == size - 1)
			{
				//cout << arr[r][c];
				diag2 += arr[r][c];
			}
			//diag2 += arr[r][c];
		}
	}

	ans = abs(diag1 - diag2);


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
		//cout << difference_between_sum_of_diagonals(arr, N) << endl;
		cout << difference_between_sum_of_diagonals(arr, N) << endl;
	}

	return 0;
