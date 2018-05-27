#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	cout << endl;
}
void processarray(int arr[], int n)
{
	// Auxiliary array to hold modified array
	int temp[1000];


	int left = 0;
	int right = n - 1;

	int i = 0;
	while(left <= right)
	{
		//temp[right] = arr[right];
		//temp[left] = arr[left];
		// for(int i=0;i<n;i = i + 2)
		// {
			temp[i] = arr[right];
			temp[i + 1] = arr[left];
		//}
		left++;
		right--;
		i += 2;
	}
	for(int i=0;i < n;i++)
	{
		cout << temp[i] << ' ';
	}
	//printArray(temp,arrSize);
	cout << endl;
}
int main()
{
	//code
	int arr[1000];
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i< N; i++)
		{
			int element;
			cin >> element;
			arr[i] = element;
		}
		processarray(arr,N);
	}
	return 0;
}
