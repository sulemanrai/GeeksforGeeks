#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

void make_distinct_digit_array(vector<int> vec)
{
	map<char, int> um;
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		string tmp = to_string(*it);
		for (int j = 0; j < tmp.size(); j++)
		{
			//int a = tmp[j];
			std::map<char, int>::const_iterator got = um.find(tmp[j]);
			if(got == um.end())
			{
				um[tmp[j]]++;
			}
		}
	}

	for (std::map<char, int>::const_iterator got = um.begin(); got != um.end(); ++got)
		cout << (*got).first << ' ';
	cout << endl;
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
		make_distinct_digit_array(vec);
	}
	return 0;
}
