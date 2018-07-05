#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void min_petrol_required(vector<int> vec, int K)
{
	int minimum = INT_MAX;
	int temp = -1;
	for(int i = 0; i < vec.size(); i++)
	{
		temp = K - vec[i];
		minimum = min(minimum, temp);
	}
	if (minimum > 0) {
		cout << -1 << endl;
	}
	else {
		cout << abs(minimum) << endl;
	}

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
		int K;
		cin >> K;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		min_petrol_required(vec, K);
	}
	return 0;
}
