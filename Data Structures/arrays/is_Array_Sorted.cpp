#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_Array_Sorted(vector<int> vec)
{
	return is_sorted(vec.begin(), vec.end());
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
		for(int i = 0 ; i < N ; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << is_Array_Sorted(vec) << endl;
	}
	return 0;
