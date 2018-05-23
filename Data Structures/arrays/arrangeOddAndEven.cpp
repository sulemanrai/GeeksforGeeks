#include<iostream>
#include <algorithm>
using namespace std;


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printArray(int arr[], int Size)
{
	for (int i = 0; i< Size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void arrangeOddAndEven(int arr[],int n)
{
	int evenIndex = 0;
	int oddIndex = 1;

	while(true)
	{
		while (evenIndex < n && arr[evenIndex] % 2 == 0)
			evenIndex += 2;

		while (oddIndex < n && arr[oddIndex] % 2 == 1)
			oddIndex += 2;


		if (evenIndex < n && oddIndex < n) {
			swap(arr[evenIndex], arr[oddIndex]);
		} else
		{
			break;
		}



	}
}
int main()
{
	int arr[] = { 10, 9 , 18, 10, 13,78};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Array: ";
	printArray(arr, n);

	arrangeOddAndEven(arr, n);

	cout << "\nModified Array: ";
	printArray(arr, n);

	return 0;
}
