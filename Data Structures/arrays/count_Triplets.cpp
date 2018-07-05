#include<iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

int count_Triplets(vector<int> vec, int TargetSum)
{
	int count = 0;
	int sum = 0;

	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size() - 2; i++)
	{
		int j = i + 1;
		int k = vec.size() - 1;

		while(j < k)
		{
			if (vec[i] + vec[j] + vec[k] >= TargetSum)
				k--;

			else
			{
				count += (k - j);
				j++;
			}
		}
	}

	return count;
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
		int targetSum;
		cin >> targetSum;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << count_Triplets(vec, targetSum) << endl;
	}

	return 0;
}
