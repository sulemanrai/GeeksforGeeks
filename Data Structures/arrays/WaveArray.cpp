#include<iostream>
#include <algorithm>
using namespace std;

void Print(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {
        cout <<arr[i] <<" ";
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
 {
	//code
	int T;
	cin >> T;

	int arr[1000];
	while(T--)
	{
	    int ARRAY_SIZE;
	    cin >> ARRAY_SIZE;
	    int element;

	    for(int i = 0; i < ARRAY_SIZE;i++)
	    {
	        cin >> element;
	        arr[i] = element;
	    }


	     sort(arr,arr+ARRAY_SIZE);
	    if(ARRAY_SIZE != 1 &&  (ARRAY_SIZE % 2 == 0)) {
	        for(int i = 0;i < ARRAY_SIZE; i = i+2)
	        {
    	        swap(arr[i],arr[i+1]);
	        }
	    } else {
	        for(int i = 0; i < ARRAY_SIZE -1; i = i+2)
	        {
    	        swap(arr[i],arr[i+1]);
	        }
	    }
	     Print(arr,ARRAY_SIZE);
	}

	return 0;
}
