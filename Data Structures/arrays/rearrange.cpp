#include<iostream>
using namespace std;

void Print(int arr[], int N)
{
	for (int i = 0; i<N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void rearrange(int arr[], int N)
{
	int middle = N / 2;
	int * positive_array = new int[middle];
	int * negative_array = new int[N - middle];

	int negative_index = 0;
	int positive_index = 0;
	if (arr[0] > 0) {
		for (int i = 0; i < N; i++)
		{
			if (arr[i] < 0)
			{
				negative_array[negative_index] = arr[i];
				negative_index++;
			}
			else {
				positive_array[positive_index] = arr[i];
				positive_index++;
			}
		}
	}
	else if (arr[0] < 0) {
		for (int i = 0; i < N; i++)
		{
			if (arr[i] >= 0)
			{
				positive_array[positive_index] = arr[i];
				positive_index++;

			}
			else {
				negative_array[negative_index] = arr[i];
				negative_index++;
			}
		}
	}

	if (arr[0] > 0 && positive_index == negative_index)
	{
		int even_temp = 0;
		int odd_temp = 1;
		for (int i = 0; i < negative_index; i++)
		{
			arr[even_temp] = positive_array[i];
			arr[odd_temp] = negative_array[i];
			even_temp += 2;
			odd_temp += 2;
		}
	}
	else if (arr[0] < 0 && positive_index == negative_index)
	{
		int even_temp = 0;
		int odd_temp = 1;
		for (int i = 0; i < negative_index; i++)
		{

			arr[even_temp] = positive_array[i];
			arr[odd_temp] = negative_array[i];
			even_temp += 2;
			odd_temp += 2;
		}
	} else if(negative_index > positive_index)
	{
		int even_temp = 0;
		int odd_temp = 1;

		for (int i = 0; i < negative_index; i++)
		{
			if (i < positive_index) {
				arr[even_temp] = positive_array[i];
				arr[odd_temp] = negative_array[i];
				even_temp += 2;
				odd_temp += 2;
			} else
			{
				arr[odd_temp] = negative_array[i];
				odd_temp += 1;
			}

		}
	} else if(negative_index < positive_index)
	{
		int even_temp = 0;
		int odd_temp = 1;

		for (int i = 0; i < positive_index; i++)
		{
			arr[even_temp] = positive_array[i];
			if (i < negative_index) {
				arr[odd_temp] = negative_array[i];
				even_temp += 2;
				odd_temp += 2;
			} else
			{
				even_temp += 1;
			}

		}

	}
}

int main()
{
	//code
	int T;
	cin >> T;
	int * arr = new int[100];
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
		rearrange(arr, ARRAY_SIZE);
		Print(arr, ARRAY_SIZE);
	}
	return 0;
}
