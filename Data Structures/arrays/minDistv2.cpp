#include <stdio.h>
#include<iostream>
#include <stdlib.h> // for abs()
#include <limits.h> // for INT_MAX
#include <algorithm>
using namespace std;
int minDist(int arr[], int n, int x, int y);
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		//int a[n];
		int *a = new int [n];
		for (int i = 0; i<n; i++)
			cin >> a[i];
		int x, y;
		cin >> x >> y;
		cout << minDist(a, n, x, y) << endl;
		delete[] a;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below*/
int minDist(int arr[], int n, int x, int y)
{
	//add code here.
	int min_distance = INT_MAX;

	int x_Index = 0;
	int y_index = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((arr[i] == x && arr[j] == y))
			{
				min_distance = min(min_distance, abs(i - j));
			}
		}
	}
	if (min_distance == INT_MAX)
		min_distance = -1;

	return min_distance;
}
