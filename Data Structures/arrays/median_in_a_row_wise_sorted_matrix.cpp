#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median_in_a_row_wise_sorted_matrix(int **arr, int row, int col)
{
	int ans = 0;
	vector<int> tmp;

	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < col; c++)
		{
			tmp.push_back(arr[r][c]);
		}
	}

	sort(tmp.begin(), tmp.end());
	int size = tmp.size();

	ans = tmp[size / 2];


	return ans;
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int r;
		cin >> r;
		int c;
		cin >> c;
		int **arr = new int*[r];
		for(int i = 0; i < r; i++)
		{
			arr[i] = new int[c];
		}

		for(int row = 0; row < r; row++)
		{
			for(int col = 0; col < c; col++)
			{
				int element;
				cin >> element;
				arr[row][col] = element;
			}
		}

		cout << median_in_a_row_wise_sorted_matrix(arr, r, c) << endl;

		for (int i = 0; i < r; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}
