#include <iostream>

using namespace std;

/*Function to reverse arr[] from index start to end*/
void revereseArray(int arr[], int start, int end)
{
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n)
{
	revereseArray(arr, 0, d - 1);
	revereseArray(arr, d, n - 1);
	revereseArray(arr, 0, n - 1);
}

// Function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int T;
	int N;
	int d;
	int element;
	cin >> T;

	int *array = NULL;
	while (T--)
	{
	    cin >> N;
		array = new int[N];

		for(int i = 0; i< N; i++)
		{
			cin >> element;
			array[i] = element;
		}
		cin >> d;
		leftRotate(array, d, N);
		printArray(array, N);
	}

    return 0;
}
