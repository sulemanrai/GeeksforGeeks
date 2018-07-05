#include<iostream>
#include <vector>
using namespace std;

int inversionCnt(vector<int> vec)
{
	int cnt = 0;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = 0; j < vec.size(); j++)
		{
			if (vec[i] > vec[j] && i < j)
				cnt++;
		}
	}
	return cnt;
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
		cout << inversionCnt(vec) << endl;
	}
	return 0;
}
