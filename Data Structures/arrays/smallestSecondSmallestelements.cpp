#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

void print(vector<int>& vec)
{
	cout << " vec size" << vec.size() << endl;
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

void smallestSecondSmallestelements(vector<int>& vec)
{
	sort(vec.begin(), vec.end());
	vector<int> ans(2);
	if (vec.size() == 1) {
		cout << "-1" << endl;
		return;
	}

	if(vec.size() == 2)
	{
		if (vec[0] == vec[1]) {
			cout << "-1" << endl;
			return;
		} else if(vec[0] != vec[1])
		{
			cout << vec[0] << ' ' << vec[1] << endl;
			return;
		}

	}

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it == vec.back())
		{
			cout << "-1" << endl;
			return;
		}
		if (*it != *(it + 1) && it != vec.end())
		{
			cout << *it << ' ' << *(it + 1) << endl;
			return;
		}
	}

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

		//cout << secondLargestelement(vec) << endl;
		 smallestSecondSmallestelements(vec);
		//print(ans);
	}
}
