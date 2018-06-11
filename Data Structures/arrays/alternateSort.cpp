#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	int i = 0;
	int j = vec.size() - 1;

	while(i <= j)
	{
		if(i == j)
		{
			cout << vec[j];
		}
		else {
			cout << vec[j] << ' ' << vec[i] << ' ';
		}
		i++;
		j--;
	}
}

int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		vector<int> vec;
		for(int i = 0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		printArray(vec);
		cout << endl;
	}
	return 0;
}
