#include<iostream>
#include <vector>
using namespace std;

void printVec(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}

int countMinOperations(vector<int> vec)
{
	vector<int> target(vec.size());

	int result = 0;
	int evencnt = 0;
	int zero_cnt = 0;
	while(1)
	{
		if (zero_cnt >= vec.size())
			break;
		zero_cnt = 0;
		evencnt = 0;
		for(int i = 0; i< vec.size(); i++)
		{
			if(vec[i] % 2 == 0)
			{
				//vec[i] = vec[i] / 2;
				evencnt++;
			} else if(vec[i] % 2 != 0)
			{
				vec[i] = vec[i] - 1;
				result++;
				//oddcnt++;
			}
		}
		if(evencnt == vec.size())
		{
			for(int i = 0; i< vec.size(); i++)
			{
				vec[i] = vec[i] / 2;
			}
			result++;
		}

		target.assign(vec.begin(), vec.end());
		for(int i = 0; i< target.size(); i++)
		{
			if (target[i] == 0) {
				zero_cnt++;
			}
		}
		//printVec(target);
	}

	return result;
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
		cout << countMinOperations(vec) << endl;
	}

	return 0;
}
