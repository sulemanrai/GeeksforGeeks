#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

void print(vector<int> vec)
{
	for(int i: vec)
	{
		cout << i << ' ';
	}
	cout << endl;
}
int secondLargestelement(vector<int>& vec)
{

	sort(vec.begin(), vec.end());
	//print(vec);
	if (vec.size() == 1 )
		return -1;
	std::vector<int>::reverse_iterator rit = vec.rbegin();
	int ans = -1;
	//cout << "rit" << *(rit + 1) << endl;
	for (; rit != vec.rend(); ++rit)
	{
		if (rit == vec.rend() - 1)
			break;

		if(*rit != *(rit+1))
		{
			ans = *(rit + 1);
			break;
		}

	}
	return ans;

}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;
		vector<int> vec;
		for(int i=0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << secondLargestelement(vec) << endl;
	}
}
