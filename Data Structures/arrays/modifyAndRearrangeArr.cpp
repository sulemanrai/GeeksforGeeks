#include<iostream>

using namespace std;

// function to print the array elements
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}

// function which pushes all zeros to end of
// an array.
void pushZerosToEnd(int arr[], int n)
{
	int count = 0;

	// Traverse the array. If element encountered
	// is non-zero, then replace the element at
	// index 'count' with this element
	for(int i= 0; i<n;i++)
	{
		if(arr[i] != 0)
		{
			arr[count++] = arr[i];
		}
	}

	// Now all non-zero elements have been shifted
	// to front and 'count' is set as index of
	// first 0. Make all elements 0 from count
	// to end.
	while(count < n - 1)
	{
		arr[count++] = 0;
	}
}

// function to rearrange the array elements
// after modification
void modifyAndRearrangeArr(int arr[], int n)
{
	// if 'arr[]' contains a single element
	// only
	if (n == 1)
		return;

	// traverse the array

	for (int i = 0; i < n - 1; i++) {
		// if true, perform the required modification
		if ((arr[i] != 0) && (arr[i] == arr[i + 1])) {
			// double current index value
			arr[i] = 2 * arr[i];

			// put 0 in the next index
			arr[i + 1] = 0;

			// increment by 1 so as to move two
			// indexes ahead during loop iteration
			i++;
		}
	}
	pushZerosToEnd(arr, n);
}

// Driver program to test above
int main()
{
	int arr[] = { 2 ,2, 0, 4, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original array: ";
	printArray(arr, n);

	modifyAndRearrangeArr(arr, n);

	cout << "\nModified array: ";
	printArray(arr, n);

	return 0;
}
