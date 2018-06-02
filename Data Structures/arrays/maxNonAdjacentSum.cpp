#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxNonAdjacentSum(vector<int> &vec)
{
	int temp = 0;
	int inclusive = 0;
	int exclusive = 0;

	for(int i=0; i< vec.size(); i++)
	{
		temp = inclusive;
		inclusive = max(inclusive, exclusive + vec[i]);
		exclusive = temp;
	}

	return inclusive;

}

int main()
{
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
		cout << maxNonAdjacentSum(vec) << endl;
	}
}
