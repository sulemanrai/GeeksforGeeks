#include<iostream>
#include <vector>
using namespace std;

void printSmaller(vector<int> &vec)
{
	vector<int> smallerElements;
	for(int i=0; i< vec.size(); i++)
	{
		int count = 0;
		for(int j = i+1; j < vec.size(); j++)
		{
			if(vec[j] < vec[i])
			{
				count++;
			}
		}
		smallerElements.push_back(count);
	}

	for (int k = 0; k < smallerElements.size(); k++)
		cout << smallerElements[k] << ' ';
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
		printSmaller(vec);
		cout << endl;
	}

	return 0;
}
