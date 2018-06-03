#include<iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
}
void printKLargest(vector<int> &vec, int K)
{
	int i = 0;

	int max;
	for(i = 0; i <= vec.size() - K; i++)
	{
		max = vec[i];
		for(int j = 1; j < K; j++)
		{
			if (vec[i + j] > max) {
				max = vec[i + j];
			}

		}
		cout << max << ' ';
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
		printKLargest(vec, K);
		cout << endl;
	}

	return 0;
}
