#include<iostream>
using namespace std;

// Given an array of numbers, program to arrange the numbers to form the
// largest number
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// A comparison function which is used by sort() in printLargest()
int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);

    return XY.compare(YX) > 0 ? 1: 0;
}

// The main function that prints the arrangement with the largest value.
// The function accepts a vector of strings
void printLargest(vector<string> arr)
{
    sort(arr.begin(),arr.end(),myCompare);

    for (int i=0; i < arr.size() ; i++ )
        cout << arr[i];
}

void printArray(vector<string> arr)
{
    for (string n : arr)
    {
        cout << n << ' ';
    }
    cout << endl;
}

int main()
 {
	//code

	int T;
	cin >> T;

	while(T--)
	{
	    vector<string> arr;
	   int N;
	   cin >> N;
	   for(int i=0; i< N;i++)
	   {
	       int element;
	       cin >> element;
	       arr.push_back(to_string(element));
	   }
	   //printArray(arr);
	   printLargest(arr);
	   cout << endl;
	}
	return 0;
}
