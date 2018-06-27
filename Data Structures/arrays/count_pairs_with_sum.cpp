#include<iostream>
#include <vector>
using namespace std;

int count_pairs_with_sum(vector<int> vec, int K)
{
	int ans = 0;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i + 1 ; j < vec.size(); j++)
		{
			if(vec[i] + vec[j] == K)
			{
				ans++;
			}
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
		int K;
		cin >> K;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << count_pairs_with_sum(vec, K) << endl;
	}

	return 0;
}
