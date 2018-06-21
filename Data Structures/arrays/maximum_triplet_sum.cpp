#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maximum_triplet_sum(int a[], int n)
{
		int maxA = INT_MIN, maxB = INT_MIN, maxC = INT_MIN;
		for(int i = 0; i < n; i++)
		{
			if(a[i] > maxA)
			{
				maxC = maxB;
				maxB = maxA;
				maxA = a[i];
			} else if (a[i] > maxB)
			{
				maxC = maxB;
				maxB = a[i];
			} else if (a[i] > maxC)
			{
				maxC = a[i];
			}
		}

		return (maxA + maxB + maxC);
}

int main()
{
	//code
	int T;
	scanf("%i",&T);

	while(T--)
	{
		int N;
		//cin >> N;
		scanf("%i",&N);
		//vector<int> vec;
		int *a = new int[N];
		for(int i = 0; i < N; i++)
		{
			int element;
			scanf("%i",&element);
			//vec.push_back(element);
			a[i] = element;
		}
		cout << maximum_triplet_sum(a, N) << endl;
	}

	return 0;
}
