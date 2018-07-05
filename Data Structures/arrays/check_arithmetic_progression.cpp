#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_arithmetic_progression(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	int difference = vec[1] - vec[0];
	bool isSame = true;

	for(int i = 2; i < vec.size(); i++)
	{
		if(vec[i] - vec[i-1] != difference)
		{
			isSame = false;
			break;
		}
	}
	return isSame;
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
		if (check_arithmetic_progression(vec) == true) {
			cout << "YES" << endl;
		}else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
