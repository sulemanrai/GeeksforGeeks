#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_the_median(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	if (vec.size() % 2 != 0)
		cout << vec[vec.size() / 2] << endl;
	else
		cout << (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2 << endl;
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
		find_the_median(vec);
	}
	return 0;
}