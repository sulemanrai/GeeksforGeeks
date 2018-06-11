#include<iostream>
#include <vector>
using namespace std;

int findMinOps(vector<int> vec)
{
	int ans = 0;
	int i = 0;
	int j = vec.size() - 1;

	while(i<=j)
	{
		if(vec[i] == vec[j])
		{
			i++;
			j--;
		}
		else if(vec[i] > vec[j])
		{
			vec[j - 1] += vec[j];
			j--;
			ans++;
		} else if(vec[j] > vec[i])
		{
			vec[i + 1] += vec[i];
			i++;
			ans++;
		}
	}

	return ans;
}

int main()
{
	//code
	int T;
	cin >> T;
	while (T--)
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
		cout << findMinOps(vec) << endl;
	}
	return 0;
}
