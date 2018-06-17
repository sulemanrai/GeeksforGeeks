#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MODO 1000000007

int maximize(vector<int> v)
{
	int ans = 0;

	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		ans += (i * v[i]);
	}

	ans = (ans % MODO);
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
		for(int i = 0; i < N ;i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << maximize(vec) << endl;
	}
	return 0;
}
