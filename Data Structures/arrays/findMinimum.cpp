#include<iostream>
using namespace std;

int findMinimum(int arr[], int low, int high)
{
	if (high < low)
	{
		return -1;
	}
	if (high == low)
		return arr[low];

	int middle = (low + high) / 2;
	if (middle < high && arr[middle] > arr[middle + 1])
		return arr[middle + 1];
	if (middle > low && arr[middle] < arr[middle - 1])
		return arr[middle];
	if (arr[low] >= arr[middle] )
		return findMinimum(arr, low, middle);
	return  findMinimum(arr, middle+1, high);


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
		int * arr = new int[N];
		int element;
		for(int i = 0; i < N; i++ )
		{
			cin >> element;
			arr[i] = element;
		}
		if (arr[0] < arr[N - 1]) {
			cout << arr[0];
		}
		else {
			cout << findMinimum(arr, 0, N - 1);
		}
		cout << endl;
		delete[] arr;
	}

	return 0;
}
