#include<iostream>
#include <algorithm>
#include <vector>
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

int find_Kth_Element_in_spiral_form(int **arr, int N, int M, int K)
{
	int ans = 0;
	vector<int> tmp;
	int index = 0;
	int i;
	int j;
	int row = 0;
	int col = 0;
	int last_row = N - 1;
	int last_col = M - 1;

	bool flag = false;

	while(row <= last_row && col <=last_col)
	{

		for (i = col; i <= last_col; i++)
		{
		
			tmp.push_back(arr[row][i]);
		}
		row++;		

		for (i = row; i <= last_row; i++)
		{
			tmp.push_back(arr[i][last_col]);
		}
		last_col--;
		
		if(row <= last_row)
		{
			for(i = last_col; i >= col; i--)
			{
				tmp.push_back(arr[last_row][i]);
			}
			last_row--;
		}

		if(col <= last_col)
		{
			for (i = last_row; i >= row; i--)
			{
				tmp.push_back(arr[i][col]);
			}
			col++;
		}

		if(flag == true)
		{
			break;
		}
	}
	ans = tmp.at(K - 1);

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

		int K;
		cin >> K;

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

		cout << find_Kth_Element_in_spiral_form(arr, N, M, K) << endl;
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