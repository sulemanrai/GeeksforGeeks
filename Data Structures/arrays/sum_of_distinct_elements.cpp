#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum_of_distinct_elements(vector<int> vec)
{
	int ans = 0;
	sort(vec.begin(), vec.end());

	vector<int> uniqueArr(vec.size());

	auto last = std::unique(vec.begin(), vec.end());
	vec.erase(last, vec.end());


	 for(int i = 0; i < vec.size(); i++)
	 {
		 ans += vec[i];
	 }

	return ans;
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
		cout << sum_of_distinct_elements(vec) << endl;
	}

	return 0;
}
