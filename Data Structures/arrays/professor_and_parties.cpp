#include<iostream>
#include <vector>
using namespace std;

bool professor_and_parties(vector<int> vec)
{
	bool flag = false;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i + 1; j < vec.size(); j++)
		{
			if(vec[i] == vec[j])
			{
				flag = true;
				break;
			}
		}
		if(flag == true)
		{
			break;
		}
	}

	return flag;
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
		if(professor_and_parties(vec) == true)
		{
			cout << "BOYS";
		} else
		{
			cout << "GIRLS";
		}
		cout << endl;
	}

	return 0;
}
