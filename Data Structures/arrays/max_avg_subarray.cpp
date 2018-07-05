#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdint.h>
#include <float.h>
using namespace std;

void max_avg_subarray(vector<int> vec, int K)
{
	double avg = numeric_limits<double>::lowest();
	double sum = 0;
	vector<int> tmp;
	int j = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		if (i + K > vec.size())
			break;
		for(j = i; j < (i+K); j++)
		{
			sum += vec[j];
		}
		if((sum/K) > avg)
		{
			//cout << (sum / K) << endl;
			//copy(vec.begin() + i, vec + (i+K-1), tmp.begin());
			tmp.assign(vec.begin() + i, vec.begin() + j);
		}
		avg = max(sum/K, avg);
		//cout << avg << endl;
		sum = 0;
		j = 0;
	}

	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << ' ';
}

int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int K;
		cin >> K;
		int N;
		cin >> N;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		max_avg_subarray(vec, K);
		cout << endl;
	}
	return 0;
}
