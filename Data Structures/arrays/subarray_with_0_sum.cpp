#include<iostream>
#include <vector>
using namespace std;

bool subarray_with_0_sum(vector<int> vec)
{
	bool present = false;

	for(int i = 0; i < vec.size(); i++)
	{
		int sum = 0;

		for(int j = i; j < vec.size(); j++)
		{
			sum += vec[j];
			if(sum == 0)
			{
				present = true;
				break;
			}
		}
		if(present == true)
		{
			break;
		}
	}

	return present;
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
		if(subarray_with_0_sum(vec) == true)
		{
			cout << "Yes";
		} else
		{
			cout << "No";
		}
		cout << endl;
	}

	return 0;
}
