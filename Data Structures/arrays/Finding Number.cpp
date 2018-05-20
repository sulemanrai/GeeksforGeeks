#include <iostream>

using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
	int high, int key)
{
	if (high < low)
	{
		return -1;
	}

	int middle = (low + high) / 2;
	if (key == arr[middle])
		return middle;

	int index;
	if (arr[middle] < key)
	{
		index = binarySearch(arr, middle + 1, high, key);
	}
	else
	{
		index = binarySearch(arr, low, middle, key);
	}

	return index;
}
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
	if (high < low)
		return -1;
	if (high == low)
		return low;

	int middle = (low + high) / 2;
	//cout << " middle " << middle << endl;
	if (middle < high && arr[middle] > arr[middle + 1])
		return middle;
	if (middle > low && arr[middle] < arr[middle - 1])
		return middle - 1;
	if (arr[low] >= arr[middle]) {
		return findPivot(arr, low, middle - 1);
	}
	return findPivot(arr, middle + 1, high);


}

// Function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* Searches an element key in a pivoted
sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
	int pivot = findPivot(arr, 0, n - 1);
	if (pivot == -1)
		return binarySearch(arr, 0, n - 1, key);

	int middle = (n - 1) / 2;
	if (arr[pivot] == key)
		return pivot;
	if (arr[0] <= key) {
		return binarySearch(arr, 0, pivot, key);
	}
	return binarySearch(arr, pivot, n - 1, key);


}

int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;
		int element;
		int K;
		cin >> N;
		cin >> K;
		int *array = NULL;
		array = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> element;
			array[i] = element;
		}
		if (pivotedBinarySearch(array, N, K) != -1)
			cout << pivotedBinarySearch(array, N, K) << endl;
		else
			cout << "OOPS! NOT FOUND" << endl;
		delete[] array;
	}

	return 0;
}
