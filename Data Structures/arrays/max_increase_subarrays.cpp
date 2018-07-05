#include<iostream>
#include <vector>
using namespace std;

int max_increase_subarrays(vector<int> vec)
{
	int sum = 0;
	int len = 1;
	for(int i = 0; i < vec.size() - 1; i++)
	{
		if(vec[i+1] > vec[i])
		{
			len++;
		} else
		{
			sum += (((len * (len - 1))) / 2);
			len = 1;
		}
	}
	if(len > 1)
	{
		sum += (((len * (len - 1))) / 2);
	}

	return sum;
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
		cout << max_increase_subarrays(vec) << endl;
	}

	return 0;
}
