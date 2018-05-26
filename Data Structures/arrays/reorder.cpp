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

void func(int arr[], int Size)
{
    if (Size == 1)
    {
         printArray(arr,Size);
        return;
    }
    int left = 0;
    int right = Size - 1;
    int array[Size];
    int evenindex = 0;
    int oddindex = 1;
    while(left <= right)
    {
        array[evenindex] = arr[left];
        array[oddindex] = arr[right];
        left++;
        right--;
        evenindex += 2;
        oddindex += 2;
    }

    printArray(array,Size);
}
int main()
 {
	//code
	int arr[1000];
	int T;
	cin >> T;

	while(T--)
	{
	    int N;
	    cin >> N;
	    for(int i = 0; i < N; i++)
	    {
	        int element;
	        cin >> element;
	        arr[i] = element;
	    }
	    sort(arr,arr+N);
	    //printArray(arr,N);
	    func(arr,N);
	}
	return 0;
}
