#include<iostream>
#include <vector>
using namespace std;

bool sumExists(vector<int> vec, int n)
{
	bool exists = false;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i + 1; j < vec.size(); j++)
		{
			for(int k = j + 1; k < vec.size(); k++)
			{
				for(int l = k + 1; l < vec.size(); l++)
				{
					if(vec[i] + vec[j] +vec[k] +vec[l] == n)
					{
						exists = true;
						break;
					}
				}
				if(exists == true)
				{
					break;
				}
			}
			if (exists == true)
			{
				break;
			}
		}
		if (exists == true)
		{
			break;
		}
	}

	return exists;
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
		int number;
		cin >> number;
		cout << sumExists(vec, number) << endl;
	}
	return 0;
}
