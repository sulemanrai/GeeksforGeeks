#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printLeaders(vector<int> vec)
{
	bool isgreater = false;
	vector<int> ans;
	std::vector<int>::iterator it;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			if(vec[j] > vec[i])
			{
				isgreater = false;
				break;
			} else
			{
				isgreater = true;
			}
		}
		it = find(ans.begin(), ans.end(), vec[i]);
		if ((isgreater == true && it == ans.end())) {
			//cout << vec[i] << ' ';
			ans.push_back(vec[i]);
		}
		isgreater = false;
	}
	it = find(ans.begin(), ans.end(), vec[vec.size() - 1]);
	if(it == ans.end())
	{
		ans.push_back(vec[vec.size() - 1]);
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
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		printLeaders(vec);
		cout << endl;
	}
	return 0;
}
