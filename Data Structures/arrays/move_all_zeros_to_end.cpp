#include<iostream>
using namespace std;

void printArray(int arr[], int Size)
{
	for (int i = 0; i< Size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rotateRight(int arr[], int Size, int outofplace, int curr)
{
	//cout << " outofplace " << outofplace << " curr " << curr << endl;
	int temp = arr[curr];
	for (int i = curr; i>outofplace; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[outofplace] = temp;
}

void moveAllZerosToBack(int arr[], int Size)
{
	int zeroindex = -1;
	int non_zero_index = -1;
	int evenindex = 0;
	int oddindex = 1;
	int i = 0;
	//int j = 0;
	while (true)
	{


		for (; i < Size; i++)
		{
			if (arr[i] == 0)
			{
				zeroindex = i;
				break;
			}
		}
		if (zeroindex != -1) {
			for (int j = zeroindex; j < Size; j++)
			{
				if (arr[j] != 0)
				{
					non_zero_index = j;
					break;
				}
			}

		}
		//cout << " zeroindex " << zeroindex << " element " << arr[zeroindex] <<" nonzeroindex " << non_zero_index << " element " << arr[non_zero_index] <<" oddindex " << oddindex<<endl;
		if (oddindex > Size)
		{
			//cout << "non_zero_index " << non_zero_index << endl;
			i = non_zero_index;
			evenindex = 0;
			oddindex = 1;
		} else
		{
			i = 0;
		}
		if(non_zero_index == -1)
		{
			//cout << "zeroindex" << zeroindex << endl;
			break;
		}

		if (zeroindex != -1 && non_zero_index != -1)
		{
			rotateRight(arr, Size, zeroindex, non_zero_index);
			//printArray(arr, Size);
		}



		evenindex += 2;
		oddindex += 2;
		zeroindex = -1;
		non_zero_index = -1;
	}
}

int main()
{
	//code
	int T;
	cin >> T;
	int arr[1000];
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i<N; i++)
		{
			int element;
			cin >> element;
			arr[i] = element;
		}
		//rotateRight(arr,N,2,N-1);
		moveAllZerosToBack(arr, N);
		printArray(arr, N);
	}
	return 0;
}
