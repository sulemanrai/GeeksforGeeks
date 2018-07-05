#include<iostream>
#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

int smallestInt(vector<int> &vec)
{
	sort(vec.begin(), vec.end());

	if(vec.size() == 1)
	return 1;

	int i = 0;

	if (vec[i] <= 0) {
		while (vec[i] <= 0) {
			i++;
		}
		if(vec[i - 1] <= 0 && vec[i] != 1)
		{
			return 1;
		}
		int diff = 0;
		while (i != vec.size() - 1)
		{
			diff = vec[i + 1] - vec[i];
			if(diff > 1)
			{
				break;
			}
			i++;
		}
		if (i == vec.size() - 1 && (diff == 1 || diff == 0))
		{
			return vec[i] + 1;
		} else if(diff > 1)
		{
			return vec[i] + 1;
		}
	} else
	{
		int diff = 0;
		while(i != vec.size() - 1)
		{
			diff = vec[i + 1] - vec[i];
			i++;
		}
		if(i == vec.size() -1 && diff == 1)
		{
			return vec[i] + 1;
		}
	}
	return -1;
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
		for(int i=0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << smallestInt(vec) << endl;
	}

	return 0;
}
