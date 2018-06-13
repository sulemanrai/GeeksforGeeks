#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void wave_array(vector<int> vec)
{
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size() - 1; i+=2)
	{
		swap(&vec[i], &vec[i + 1]);
	}
	for (int i = 0; i < vec.size(); i+=1)
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
		wave_array(vec);
		cout << endl;
	}
	return 0;
}
