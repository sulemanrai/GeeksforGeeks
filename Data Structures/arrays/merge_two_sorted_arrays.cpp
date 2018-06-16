#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
using namespace std;

void merge_two_sorted_arrays(vector<int> a, vector<int> b)
{
	int tmp1 = 0;
	int tmp2 = 0;

	vector<int> ans;
	copy(a.begin(), a.end(), back_inserter(ans));
	copy(b.begin(), b.end(), back_inserter(ans));
	sort(ans.begin(), ans.end(), std::greater<int>());

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
		int X;
		cin >> X;
		int Y;
		cin >> Y;
		vector<int> x;
		vector<int> y;
		for(int i = 0; i < X; i++)
		{
			int element;
			cin >> element;
			x.push_back(element);
		}
		for(int i = 0; i < Y; i++)
		{
			int element;
			cin >> element;
			y.push_back(element);
		}
		merge_two_sorted_arrays(x, y);
		cout << endl;
	}
	return 0;
}
