#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_sorted_array(vector<int> vec)
{
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
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
		print_sorted_array(vec);
		cout << endl;
	}
	return 0;
}
