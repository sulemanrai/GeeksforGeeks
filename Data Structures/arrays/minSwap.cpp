#include<iostream>
using namespace std;
int minSwap(int *arr, int n, int k)
{
	// Find count of elements which are
	// less than equals to k
	int count = 0;
	for(int i = 0;i<n;i++)
	{
		if(arr[i] <=k)
		{
			count++;
		}
	}

	// Find unwanted elements in current
    // window of size 'count'
	int bad = 0;
	for(int i=0;i<count;i++)
	{
		if(arr[i] > k)
		{
			bad++;
		}
	}

	// Initialize answer with 'bad' value of
	// current window
	int ans = bad;
	for(int i= 0, j = count; j < n; ++i, ++j)
	{
		//cout << " i " << i << " j " << j << endl;
		// Decrement count of previous window
		if (arr[i] > k)
			bad--;
		// Increment count of current window
		if (arr[j] > k)
			bad++;

		// Update ans if count of 'bad'
		// is less in current window
		ans = min(bad, ans);

	}
	return ans;
}

int main()
{
	//code
	int arr[100];
	int T;
	cin >> T;
	while (T--)
	{
		int ARRAY_SIZE;
		cin >> ARRAY_SIZE;
		int element;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cin >> element;
			arr[i] = element;
		}
		int k;
		cin >> k;
		cout << minSwap(arr, ARRAY_SIZE, k) << endl;
	}
	return 0;
}
