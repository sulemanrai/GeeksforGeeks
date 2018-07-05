#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int smallestSubArray(vector<int> vec, int x)
{
	int len = INT_MAX;
	int sum = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > x)
			return 1;
		sum += vec[i];
		for(int j = i +1; j < vec.size(); j++)
		{
			sum += vec[j];
			if (sum > x) {
				len = min(len, j - i + 1);
				break;
			}
		}
		sum = 0;
	}
	return len;
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
		int x;
		cin >> x;
		vector<int> vec;
		for(int i=0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << smallestSubArray(vec, x) << endl;
	}
	return 0;
}
