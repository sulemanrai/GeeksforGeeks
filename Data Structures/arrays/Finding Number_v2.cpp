#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int findMaximum(int arr[], int l, int r)
{
	int mid = l + (r - l) / 2;

	if (arr[mid] > arr[mid + 1] && arr[mid - 1] < arr[mid]) {
		return mid;
	}

	if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
	{
		return findMaximum(arr, 0, mid);
	}

	if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
		return findMaximum(arr, mid + 1, r);

	return mid;
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
int printIndex(int arr[], int n, int key)
{
	int max = findMaximum(arr, 0, n - 1);
	int index = -1;
	if (key == arr[max])
		return max;
	if (key < arr[max] && key >= arr[0])
		return binarySearch(arr, 0, max, key);

	if (key < arr[max] && key < arr[0])
		return binarySearch(arr, max,n-1, key);

	return -1;
}
int main()
{
	int T;
	cin >> T;

	while(T--)
	{

		int N;
		cin >> N;
		int *arr  = new int[N];
		int X;
		cin >> X;
		for(int i=0; i < N; i++)
		{
			int element;
			cin >> element;
			arr[i] = element;
		}
		int ans = printIndex(arr, N, X);
		if (ans != -1)
			cout << ans << endl;
		else
			cout << "OOPS! NOT FOUND" << endl;
		//cout << printIndex(arr, N, X) << endl;
		delete[] arr;
	}
}
