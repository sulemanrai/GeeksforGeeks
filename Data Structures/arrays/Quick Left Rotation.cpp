#include<iostream>
using namespace std;

void leftRotate(int arr[], int n, int k)
{
	// Print array after k rotations
	for (int i = k; i < k + n; i++) {
		cout << arr[i%n] << " ";
	  //arr[k] = arr[i % n];
	}
	cout << endl;
}

int main()
 {
	//code
	int T;
	cin>>T;

	while(T--)
	{
	    int N;
	    cin >> N;
	    int rotations;
	    cin >> rotations;
	    int *arr = new int[N];
	    int element;
	    for (int i=0;i<N;i++)
	    {
	        cin >> element;
	        arr[i] = element;
	    }
	    leftRotate(arr,N,rotations);
	    delete [] arr;
	}
	return 0;
}
