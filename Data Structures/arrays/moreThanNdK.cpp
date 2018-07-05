{
// A C ++ program to print elements with count more than n/k
#include<iostream>
using namespace std;
long long int totalcount=0;
void moreThanNdK(long long int arr[], long long int n, long long int k);
// A structure to store an element and its current count
struct eleCount
{
    long long int e;  // Element
    long long int c;  // Count
};
/* Driver program to test above function */
int main()
{
    long long int t ,k;
    cin>>t;
    while(t--)
    {
    long long int n,i;
    cin>>n;
    long long int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    cin>>k;
    moreThanNdK(arr, n, k);
    totalcount=0;
    }
    return 0;
}

}
#include <algorithm>
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// A structure to store an element and its current count
/* struct eleCount
{
    long long int e;  // Element
    long long int c;  // Count
};
*/
// Prints elements with more than n/k occurrences in arr[] of
// size n. If there are no such elements, then it prints nothing.
struct eleCount tmp[100000];
void moreThanNdK(long long int arr[], long long int n, long long int k)
{
// Your code goes here
	sort(arr, arr + n);

	int count = 0;
	int j = 0;
	bool flag = false;
	for(int i=0 ; i < n; i++)
	{
		tmp[j].e = arr[i];
		//tmp[j].c += 1;
		if(arr[i] == arr[i+1])
		{
			//count++;
			flag = true;
			tmp[j].c += 1;
		} else if(arr[i] != arr[i+1])
		{
			count++;
			tmp[j].c += 1;
			flag = false;
		}

		if(flag == false)
		{
			j++;
		}
	}
	int cnt = n / k;
	int cmt = 0;
	for(int i= 0; i < count; i++)
	{
		if (tmp[i].c > cnt) {
			//cout << tmp[i].e << ' ';
			cmt++;
		}
	}
    cout << cmt <<endl;
    for(int i= 0; i < count; i++)
	{
		tmp[i].c = 0;
		tmp[i].e = 0;
	}
}
