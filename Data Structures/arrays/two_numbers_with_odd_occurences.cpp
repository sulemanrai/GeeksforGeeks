#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

void two_numbers_with_odd_occurences(vector<int> vec)
{
	unordered_map<int, int> um;
	for(int i = 0; i < vec.size(); i++)
	{
		um[vec[i]]++;
	}

	// for (auto i : um)
	// 	cout << i.first << " " << i.second << endl;
	unordered_map<int, int>::const_iterator got;
	vector<int> ans;
	for(auto i : um)
	{
		got = um.find(i.first);
		if(got->second % 2 != 0)
		{
			ans.push_back(got->first);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());

	for (int i : ans)
		cout << i << ' ';
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		vector<int> vec;
		for(int i = 0; i < n ; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		two_numbers_with_odd_occurences(vec);
		cout << endl;
	}

	return 0;
}
