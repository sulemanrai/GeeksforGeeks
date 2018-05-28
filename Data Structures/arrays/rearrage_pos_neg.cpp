#include<iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	cout << endl;
}

void processarray(int arr[],int n)
{
	vector<int> arrPos;
	vector<int> arrNeg;


	for(int i =0 ; i < n; i++)
	{
		if(arr[i] < 0)
		{
			arrNeg.push_back(arr[i]);
		} else if(arr[i] >=0)
		{
			arrPos.push_back(arr[i]);
		}
	}
	vector<int> rearranged;
	rearranged.reserve(arrPos.size() + arrNeg.size());
	rearranged.insert(rearranged.end(), arrPos.begin(), arrPos.end());
	rearranged.insert(rearranged.end(), arrNeg.begin(), arrNeg.end());

	for(int i : rearranged)
	{
		cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	//code
	int T;
	int arr[2000];
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		for(int i=0; i< N;i++)
		{
			int element;
			cin >> element;
			arr[i] = element;
		}
		//printArray(arr, N);
		processarray(arr, N);
	}

	return 0;
}
