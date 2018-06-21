#include<iostream>
#include <vector>
using namespace std;

void value_equal_to_index(vector<int> vec)
{
	vector<int> ans;
	for(int i = 0 ; i < vec.size(); i++)
	{
		if (vec[i] == i + 1) {
		//	cout << vec[i] << ' ';
			ans.push_back(vec[i]);
		}
	}

	if(ans.size() == 0)
	{
		cout << "Not Found";
	} else
	{
		for (int i : ans)
			cout << i << ' ';
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
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		value_equal_to_index(vec);
		cout << endl;
	}

	return 0;
}
