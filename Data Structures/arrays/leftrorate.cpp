#include <iostream>

using namespace std;
/* utility function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	cout << endl;
}

/*Function to left Rotate arr[] of
size n by 1*/
void leftRotatebyOne(int arr[], int n)
{
	int i = arr[0];

	for(int j = 0; j < n - 1; j++)
	{
		arr[j] = arr[j+1];
	}
	arr[n - 1] = i;
}

/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
	int i = 0;
	while(i != d)
	{
		leftRotatebyOne(arr, n);
		i++;
	}
}
int main()
{
	//int arr[] = { 1, 2, 3, 4, 5, 6};
	//int arr[] = { 6,1,2,3,4 };
	//int arr[] = { 3,4,6,1 };
	//int arr[] = { 4,6,1 };
	int arr[] = { 1, 2 ,3 ,4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	//leftRotatebyOne(arr, n);
	// Function calling
	leftRotate(arr, 2, n);
	printArray(arr, n);

    return 0;
}

