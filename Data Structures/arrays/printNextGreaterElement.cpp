#include<iostream>
#include <vector>
using namespace std;

void printNextGreaterElement(vector<int> vec)
{
	bool greater = true;
	for(int i = 0; i < vec.size(); i++)
	{
		if(i == vec.size() - 1)
			cout << -1 << ' ';
		for(int j = i+1; j < vec.size(); j++)
		{
			if (vec[j] > vec[i])
			{
				cout << vec[j] << ' ';
				break;
			}
			if (j == vec.size() - 1)
				cout << -1 << ' ';
		}
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
		for(int i = 0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		printNextGreaterElement(vec);
		cout << endl;
	}
	return 0;
}
