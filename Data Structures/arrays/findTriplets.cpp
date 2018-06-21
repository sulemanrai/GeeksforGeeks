#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int * arr = new int[n];
		for (int i = 0; i<n; i++)
			cin >> arr[i];
		if (findTriplets(arr, n))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete the function below*/
bool findTriplets(int arr[], int n)
{
	//Your code here
	int sum = INT_MIN;
	bool isPresent = false;
	for(int i = 0; i < n - 2; i++)
	{
		for(int j = i + 1; j < n - 1; j++)
		{
			for(int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if(sum == 0)
				{
					isPresent = true;
					break;
				}
			}
		}
	}
	return isPresent;
}
