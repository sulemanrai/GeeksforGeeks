#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minDifference(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	int minimum = INT_MAX;

	for (int i = 1; i < vec.size(); i = i + 1)
		minimum = min(minimum, abs(vec[i] - vec[i - 1]));
	return minimum;
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
		cout << minDifference(vec) << endl;
	}
	return 0;
}
