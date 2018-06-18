#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int friendliness_of_array(vector<int> vec)
{
	int ans = INT_MAX;
	int tmp = 0;

	sort(vec.begin(), vec.end());
	tmp = vec[1] - vec[0];
	for(int i = 1 ; i < vec.size() - 1; i++)
	{
		ans = min(abs(vec[i - 1] - vec[i]), abs( vec[i] - vec[i + 1]));
		tmp += ans;
	}
	tmp += vec[vec.size() - 1] - vec[vec.size() - 2];

	return tmp;
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
		cout << friendliness_of_array(vec) << endl;
	}
	return 0;
}
