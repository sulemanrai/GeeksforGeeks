#include<iostream>
#include <vector>
using namespace std;

bool key_pair(vector<int> vec, int x)
{
	bool keyPair = false;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			if((vec[i] + vec[j]) == x)
			{
				keyPair = true;
				break;
			}
		}
	}

	return keyPair;
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
		int X;
		cin >> X;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		if(key_pair(vec,X) == true)
		{
			cout << "Yes" << endl;
		} else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
