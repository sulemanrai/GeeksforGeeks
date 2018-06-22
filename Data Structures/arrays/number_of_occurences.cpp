#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int number_of_occurences(vector<int> vec, int x)
{
	int ans = 0;
	unordered_map<int,int> um;
	for(int i = 0; i < vec.size(); i++)
	{
		um[vec[i]]++;
	}

	std::unordered_map<int, int>::const_iterator got = um.find(x);

	if(got == um.end())
	{
		return -1;
	}

	return got->second;

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
		int number;
		cin >> number;
		vector<int> vec;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << number_of_occurences(vec, number) << endl;;
	}

	return 0;
}
