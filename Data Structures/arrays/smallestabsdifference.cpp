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

int smallestabsdifference(vector<int> vec, int K)
{
	vector<int> absdiff;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j<vec.size();j++)
		{
			int diff = abs(vec[i] - vec[j]);
			absdiff.push_back(diff);
		}
	}
	sort(absdiff.begin(), absdiff.end());
	//print(absdiff);
	return absdiff[K-1];
}
int main()
{
	//code
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		vector<int> vec;
		cin >> N;
		for(int i=0; i<N;i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		int K;
		cin >> K;
		//print(vec);
		int num = smallestabsdifference(vec, K);
		cout << num << endl;
	}
	return 0;
}
