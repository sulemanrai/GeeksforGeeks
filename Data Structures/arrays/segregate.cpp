#include<iostream>
#include <algorithm>
using namespace std;


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Print(int arr[], int Size)
{
	for (int i = 0; i< Size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void segrate(int arr[], int Size)
{
	int left = 0;
	int right = Size - 1;


	while (left < right)
	{

		while (left < right && arr[left] % 2 == 0) {
			left++;
		}

		while (left < right && arr[right] % 2 == 1) {
			right--;
		}
		//cout << " left " << left << " right " << right;

		if (left < right )
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	if (left == right && arr[left] % 2 == 0) {
		sort(arr, arr + left + 1);
		sort(arr + left+1, arr + Size);
	} else if(left == right && arr[left] % 2 == 1)
	{
		sort(arr, arr + left);
		sort(arr + left, arr + Size);
	}
	else {
		sort(arr, arr + left);
		sort(arr+left, arr + Size);
	}
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
		//Print(arr, ARRAY_SIZE);
		segrate(arr, ARRAY_SIZE);
		Print(arr, ARRAY_SIZE);
	}
	return 0;
}
