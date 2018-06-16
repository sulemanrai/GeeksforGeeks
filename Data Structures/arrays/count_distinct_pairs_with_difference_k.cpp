#include<iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <map>

using namespace std;


int count_distinct_pairs_with_difference_k(vector<int> vec , int K)
{
	int ans = 0;
	//std::unordered_map<pair<int,int>, int> um;
	map<pair<int, int>, int> pairs;
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			pairs[{ vec[i], vec[j] }]++;
		}
	}

	for(map<pair<int, int>, int>::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if ((abs((*it).first.first - (*it).first.second)) == K)
			ans++;
	}

	return ans;
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
		int K;
		cin >> K;
		cout << count_distinct_pairs_with_difference_k(vec, K) << endl;
	}
	return 0;
}
