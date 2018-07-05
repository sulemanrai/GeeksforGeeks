#include<iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void Print(int arr[], int N)
{
	for (int i = 0; i< N; i++)
	{
		cout <<arr[i] <<" ";
	}
}

void reorganise(int arr[], unordered_set<int> N,int SIZE)
{

	unordered_set<int> ::iterator itr = N.begin();
	for(int i = 0; i< SIZE;i++)
	{
		itr = N.find(i);
		if (itr != N.end())
		{
			arr[i] = i;
		} else
		{
			arr[i] = -1;
		}
	}


}

int main()
{
	//code
	int T;
	cin >> T;

	int arr[100000];

	while (T--)
	{
		int ARRAY_SIZE;
		cin >> ARRAY_SIZE;
		int element;
		unordered_set<int> intSet;
		for (int i = 0; i< ARRAY_SIZE; i++)
		{
			cin >> element;
			arr[i] = element;
			intSet.insert(arr[i]);
		}
		reorganise(arr, intSet, ARRAY_SIZE);
		Print(arr, ARRAY_SIZE);
		cout << endl;
	}
	return 0;
}
