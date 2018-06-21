#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missing_number_in_array(vector<int> vec, int n)
{
	int ans = 0;

	sort(vec.begin(), vec.end());

	for(int i = 0; i < n - 1; i++)
	{
		if(vec[i] != (i+1))
		{
			ans = i + 1;
			break;
		}
	}

	if(ans == 0)
	{
		ans = n;
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
		for(int i = 0; i < N - 1; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << missing_number_in_array(vec, N) << endl;

	}
	return 0;
}
