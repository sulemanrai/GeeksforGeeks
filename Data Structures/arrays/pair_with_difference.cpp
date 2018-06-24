#include<iostream>
#include <vector>
using namespace std;

int pair_with_difference(vector<int> vec, int n)
{
	int ans = -1;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			if(abs(vec[i] - vec[j]) == n)
			{
				ans = 1;
				break;
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
		int L;
		cin >> L;
		int N;
		cin >> N;
		vector<int> vec;
		for(int i = 0; i < L; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << pair_with_difference(vec, N) << endl;
	}
	return 0;
}
