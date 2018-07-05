#include<iostream>
#include <vector>
using namespace std;

void least_avg(vector<int> vec, int K)
{
	int res_index = 0;
	int curr_sum = 0;

	if (vec.size() < K)
		return;

	for (int i = 0; i < K; i++)
		curr_sum += vec[i];

	int min_sum = curr_sum;
	for(int i = K; i < vec.size(); i++)
	{
		curr_sum = curr_sum + vec[i] - vec[i - K];
		if (curr_sum < min_sum) {
			min_sum = curr_sum;
			res_index = i - K + 1;
		}
	}
	cout << res_index + 1 << ' ' << res_index + K;
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
		least_avg(vec, K);
		cout << endl;
	}
	return 0;
}
