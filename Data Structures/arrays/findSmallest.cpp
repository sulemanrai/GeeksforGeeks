#include<iostream>
#include <vector>
using namespace std;


int findSmallest(vector<int> vec)
{
	int result = 1;
	for(int i = 0; i < vec.size() && vec[i] <= result; i++)
	{
		result = result + vec[i];
	}
	return result;
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
		cout << findSmallest(vec) << endl;
	}
	return 0;
}
