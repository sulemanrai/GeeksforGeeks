#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_the_odd_occurrence(vector<int> vec)
{
	vector<int>::iterator it;
	int ans = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		int count = std::count(vec.begin(), vec.end(), vec[i]);
		if(count % 2 != 0)
		{
			ans = vec[i];
			break;
		}
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
		for(int i = 0 ; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << find_the_odd_occurrence(vec) << endl;
	}

	return 0;
}
