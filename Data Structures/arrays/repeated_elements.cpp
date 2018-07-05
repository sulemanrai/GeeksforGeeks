#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void repeated_elements(vector<int> vec)
{
	vector<int> ans;
	unordered_map<int,int> unorderedmap;

	for(int i : vec)
	{
		//unorderedmap.insert(make_pair(i,1));
	}


	for(int i : vec)
	{
		unordered_map<int, int>::iterator got = unorderedmap.find(i);
		if(got == unorderedmap.end())
		{
			unorderedmap.insert(make_pair(i, 1));
		} else
		{
			ans.push_back(i);
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
		int N;
		cin >> N;
		vector<int> vec;
		for(int i = 0; i < N + 2; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		repeated_elements(vec);
		cout << endl;
	}

	return 0;
}
