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

void Rearrange(int arr[],int Size)
{
    int left = 1;
    int right = Size - 1;

    int ans[Size];
    ans[0] = arr[0];
    for(int i = 1; i < Size; i++)
    {
        if(((i) % 2) == 0)
        {
            ans[i] = arr[left++];
        } else {
            ans[i] = arr[right--];
        }
    }
    printArray(ans,Size);
}
int main()
 {
	//code
	int arr[100];
	int T;
	cin >> T;

	while(T--)
	{
	    int N;
	    cin >> N;
	    int element;
	    for(int i=0; i< N;i++)
	    {
	        cin >> element;
	        arr[i] = element;
	    }
	    //printArray(arr,N);
	    sort(arr,arr+N);
	   // printArray(arr,N);
	    Rearrange(arr,N);
	}

	return 0;
}
