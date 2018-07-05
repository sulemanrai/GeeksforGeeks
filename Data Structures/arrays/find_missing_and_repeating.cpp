#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void find_missing_and_repeating(vector<int> vec)
{
	unordered_map<int, int> um;
	vector<int> ans;
	for(int i = 0; i < vec.size(); i++)
	{
		um[vec[i]]++;
	}
	unordered_map<int, int>::const_iterator got;
	for (int i = 1; i <= vec.size(); i++) {
		 got = um.find(i);
		if(got == um.end())
		{
			ans.push_back(i);
		} else if(got != um.end() && got->second == 2)
		{
			//ans.push_back(got->first);
			ans.insert(ans.begin(), got->first);
		}
	}
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
		int n;
		cin >> n;
		vector<int> vec;
		for(int i = 0; i < n; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		find_missing_and_repeating(vec);
		cout << endl;
	}

	return 0;
}
