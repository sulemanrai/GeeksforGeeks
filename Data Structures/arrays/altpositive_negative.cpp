#include<iostream>
#include <algorithm>
using namespace std;


void printArray(int arr[], int Size)
{
	for (int i = 0; i< Size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Utility function to right rotate all elements between [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
	//printArray(arr, n);

	int temp = arr[cur];
	for(int i = cur;i>outofplace;i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[outofplace] = temp;

	//printArray(arr, n);
}

int negativeInstance(int arr[],int n,int low, int high)
{
	int index = -1;
	for(int i=low;i< high; i++)
	{
		if(arr[i] < 0)
		{
			index = i;
			break;
		}
	}
	return index;
}
int positiveInstance(int arr[], int n, int low, int high)
{
	int index = -1;
	for (int i = low; i< high; i++)
	{
		if (arr[i] > 0)
		{
			index = i;
			break;
		}
	}
	return index;
}
void rearrange(int arr[], int n)
{
	int evenIndex = 0;
	int oddIndex = 1;
	int currIndex = 0;
	int outofplaceIndex = 0;


	while(true)
	{
		if (oddIndex > n)
		{
			break;
		}
		if(arr[evenIndex] > 0)
		{
			outofplaceIndex = evenIndex;
			//search for the first negative instance
			currIndex = negativeInstance(arr, n,outofplaceIndex,n);
			 if(currIndex != -1)
			 {
			 	rightrotate(arr, n, outofplaceIndex, currIndex);
			 }
		} else if(arr[evenIndex] < 0)
		{
			outofplaceIndex = oddIndex;
			//search for the first negative instance
			currIndex = positiveInstance(arr, n, outofplaceIndex, n);
			if (currIndex != -1)
			{
				rightrotate(arr, n, outofplaceIndex, currIndex);
			}
		}
		//printArray(arr, n);
		evenIndex += 2;
		oddIndex += 2;

	}
}

// Driver program to test abive function
int main()
{
	//int arr[n] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
	//int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
	//int arr[] = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
	//int arr[] = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
	//int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	//int arr[] = { 1, 2, 3, -4, 1, 4 };
	int arr[] = { 1, 2, -3,  4 ,-5};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);


	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
