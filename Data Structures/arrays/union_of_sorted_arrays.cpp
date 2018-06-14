#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void union_of_sorted_arrays(vector<int> a, vector<int> b)
{
	vector<int> ans;
	for(int i = 0; i < a.size(); i++)
	{
		ans.push_back(a[i]);
	}
	vector<int>::iterator it;
	vector<int>::iterator findit;
	for(it = b.begin(); it != b.end(); ++it)
	{
		findit = find(ans.begin(), ans.end(), *it);
		if(findit != ans.end())
		{
			continue;
		} else
		{
			ans.push_back(*it);
		}
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
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
		vector<int> vecA;
		vector<int> vecB;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vecA.push_back(element);
		}
		for (int i = 0; i < M; i++)
		{
			int element;
			cin >> element;
			vecB.push_back(element);
		}
		union_of_sorted_arrays(vecA, vecB);
		cout << endl;
	}
	return 0;
}
