#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int roofTop(vector<int> vec)
{
	int count = 0;
	int maximum = 0;
	for(int i = 1; i < vec.size(); i++)
	{
		if(vec[i] > vec[i-1])
		{
			count++;
		} else
		{
			maximum = max(maximum, count);
			count = 0;
		}
	}
	return  max(maximum, count);
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
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << roofTop(vec) << endl;
	}

	return 0;
}
