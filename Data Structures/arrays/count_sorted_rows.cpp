#include<iostream>
#include <algorithm>
using namespace std;

void printArray(int**arr,int N,int M)
{
	for (int row = 0; row < N; row++)
	{
		for(int col = 0; col < M; col++)
		{
			cout << arr[row][col] << ' ';
		}
		cout << endl;
	}
}
int countSortedrows(int**arr, int N, int M)
{
	int ans = 0;

	if(N == 1 && M != 1)
	{
		for (int col = 1; col < M; col++)
		{
			if (arr[N-1][col] > arr[N-1][col - 1])
			{
				ans++;
			}
		}
			if(ans == M - 1)
		{
			ans = 0;
		}
		return ans + 1;

	} else if(M == 1 && N != 1)
	{		
		for (int row = 1; row < N; row++)
		{
			if(arr[row][M - 1] > arr[row - 1][M - 1])
			{
				ans++;
			}
		}
		return ans + 1;
	}
	else if (N != 1 && M != 1)
	{

		for (int row = 0; row < N; row++)
		{
			int left = 0;
			int right = M - 1;
			bool leftflag = false;
			bool rightFlag = false;

			while (left <= right)
			{
				if (arr[row][left + 1] > arr[row][left] && arr[row][right] > arr[row][right - 1])
				{
					leftflag = true;
				}
				else if (arr[row][left + 1] < arr[row][left] && arr[row][right] < arr[row][right - 1])
				{
					rightFlag = true;
				}
				else {
					leftflag = false;
					rightFlag = false;
					break;
				}
				left++;
				right--;
			}
			if (leftflag == true || rightFlag == true)
			{
				ans++;
				leftflag = false;
				rightFlag = false;
			}
		}
	}

	return ans;
}

int main()
{
	//code
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		int M;
		cin >> M;
		int **arr = new int*[N];
		for (int i = 0; i < N; i++)
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
		int ans = countSortedrows(arr, N, M);
		cout << ans << endl;
		//printArray(arr, N, M);
		//Free each sub-array
		for (int i = 0; i < N; ++i) {
			delete[] arr[i];
		}
		//Free the array of pointers
		delete[] arr;
	}

	return 0;
}