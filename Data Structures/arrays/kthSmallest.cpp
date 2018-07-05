#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec)
{
	for(int i : vec)
	{
		cout << i << ' ';
	}
	cout << endl;
}
int main()
{
	//code
	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		vector<int> v;
		for (int i = 0; i< N; i++)
		{
			int element;
			cin >> element;
			v.push_back(element);
		}
		int K;
		cin >> K;
		sort(v.begin(),v.end());
		//print(v);
		cout << v[K - 1] << endl;
	}
	return 0;
}
