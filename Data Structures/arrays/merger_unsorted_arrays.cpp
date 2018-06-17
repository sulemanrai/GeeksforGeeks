#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merger_unsorted_arrays(vector<int> v1, vector<int> v2)
{
	vector<int> ans;
	copy(v1.begin(), v1.end(), back_inserter(ans));
	copy(v2.begin(), v2.end(), back_inserter(ans));

	sort(ans.begin(), ans.end());

	for (int i : ans)
		cout << i << ' ';
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
		int M;
		cin >> M;
		vector<int> veca;
		vector<int> vecb;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			veca.push_back(element);
		}
		for (int i = 0; i < M; i++)
		{
			int element;
			cin >> element;
			vecb.push_back(element);
		}
		merger_unsorted_arrays(veca, vecb);
		cout << endl;
	}

	return 0;
}
