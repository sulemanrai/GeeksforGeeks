#include<iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> printSmallestSecondSmalles(vector<int> &vec)
{
	vector<int> v;
	int smallest = INT_MAX;
	int secondsmallest = INT_MAX;

	if (vec.size() <= 2) {
		v.push_back(-1);
		return v;
	}
	for(int i=0; i< vec.size(); i++)
	{
		if(vec[i] < smallest)
		{
			secondsmallest = smallest;
			smallest = vec[i];
		} else if(vec[i] < secondsmallest && vec[i] != smallest)
		{
			secondsmallest = vec[i];
		}
	}
	if (smallest != INT_MAX && secondsmallest != INT_MAX) {
		v.push_back(smallest);
		v.push_back(secondsmallest);
	}
	else {
		v.push_back(-1);
	}


	return v;
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
		vector<int> vec;
		for (int i = 0; i<N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		vector<int> ans = printSmallestSecondSmalles(vec);
		if (ans[0] != -1) {
			cout << ans[0] << ' ' << ans[1] << endl;
		} else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
