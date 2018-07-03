#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseSpriralPoint(int **arr, int m, int n)
{
	int i, k = 0, l = 0;

	/*  k - starting row index
	m - ending row index
	l - starting column index
	n - ending column index
	i - iterator
	*/

	vector<int> vec;

	while (k < m && l < n)
	{
		/* Print the first row from the remaining rows */
		for (i = l; i < n; ++i)
		{
			//printf("%d ", arr[k][i]);
			vec.push_back(arr[k][i]);
		}
		k++;

		/* Print the last column from the remaining columns */
		for (i = k; i < m; ++i)
		{
			//printf("%d ", arr[i][n - 1]);
			vec.push_back(arr[i][n-1]);
		}
		n--;

		/* Print the last row from the remaining rows */
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				//printf("%d ", arr[m - 1][i]);
				vec.push_back(arr[m-1][i]);
			}
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				//printf("%d ", arr[i][l]);
				vec.push_back(arr[i][l]);
			}
			l++;
		}
	}
	reverse(vec.begin(), vec.end());
	for (int i : vec)
		cout << i << ' ';
}


int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int m;
		cin >> m;
		int n;
		cin >> n;

		int **arr = new int*[m];

		for(int i = 0; i < m; i++)
		{
			arr[i] = new int[n];
		}

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int element;
				cin >> element;
				arr[i][j] = element;
			}
		}
		reverseSpriralPoint(arr, m, n);
		cout << endl;
	}

	return 0;
}
