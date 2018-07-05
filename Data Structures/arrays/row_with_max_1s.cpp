#include<iostream>
#include <algorithm>
using namespace std;

void printArray(int **arr,int row, int col)
{
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < col; c++)
		{
			cout << arr[r][c] << ' ';
		}
		cout << endl;
	}
}

int row_with_max_1s(int **arr, int row, int col)
{
	int ans = 0;
	int *arrCount = new int[row];
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < col; c++)
		{
			if(arr[r][c] == 1)
			{
				ans++;
			}
		}
		//count = max(ans, count);
		arrCount[r] = ans;
		ans = 0;
	}

	ans = arrCount[0];
	int idx = 0;
	for(int i = 0 ; i < row ; i++)
	{
		//cout << arrCount[i] << ' ' << endl;;
		if(arrCount[i] > ans)
		{
			//ans = i + 1;
			idx = i;
			ans = arrCount[i];
		}
	}

	for(int i = 0; i < row; i++)
	{
		//cout << arrCount[i] << endl;
	}
	return idx;
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
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}
		cout << row_with_max_1s(arr, N, M) << endl;
		//printArray(arr, N, M);
		for (int i = 0; i < N; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}
