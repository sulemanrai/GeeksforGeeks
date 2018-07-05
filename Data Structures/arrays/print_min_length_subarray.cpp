#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void print_min_length_subarray(vector<int> vec)
{
	int s = 0;
	int e = 0;
	bool  sflag = true;
	int minimum = INT_MAX;
	int maximum = INT_MIN;
	for(int i = 0; i < vec.size() - 1; i++)
	{
		if(vec[i+1] > vec[i] && sflag == true)
		{
			s++;
		} else if (vec[i+1] < vec[i])
		{
			if (e == 0)
			{
				sflag = false;
			}
			e = i + 1;
		}
	}
	for(int i = s; i<= e; i++)
	{
		maximum = max(maximum, vec[i]);
		minimum = min(minimum, vec[i]);
		//maximum = max(minimum, vec[i]);
	}
	while(s > 0 && minimum < vec[s-1])
	{
		s--;
	}

	while(e != vec.size() - 1 && maximum > vec[e+1])
	{
		e++;
		if (e == vec.size() - 1)
			break;
	}
	cout << s << ' ' << e;
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
		print_min_length_subarray(vec);
		cout << endl;
	}
	return 0;
}
