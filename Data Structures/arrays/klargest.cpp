#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void klargest(vector<int> v, int K)
{
	sort(v.begin(), v.end(), greater<int>());
	for (int i=0 ; i< K ; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;


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
		int K;
		cin >> K;
		vector<int> vec;
		for(int i = 0; i< N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		klargest(vec,K);
	}
	return 0;
}
