#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_product(vector<int> v1, vector<int> v2)
{
	int ans = 0;
	int minimum = INT_MAX;
	int maximum = INT_MIN;

	for(int i = 0; i < v1.size(); i++)
	{
		maximum = max(maximum, v1[i]);
	}

	for (int i = 0; i < v2.size(); i++)
	{
		minimum = min(minimum, v2[i]);
	}

	ans = minimum * maximum;
	return ans;
}

int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int N1;
		cin >> N1;
		vector<int> v1;
		for(int i = 0 ; i < N1; i++)
		{
			int element;
			cin >> element;
			v1.push_back(element);
		}
		int N2;
		cin >> N2;
		vector<int> v2;
		for(int i = 0; i < N2; i++)
		{
			int element;
			cin >> element;
			v2.push_back(element);
		}
		cout << max_product(v1, v2) << endl;
	}
	return 0;
}
