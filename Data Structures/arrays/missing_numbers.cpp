#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> vec, int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (vec[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (vec[mid] > x)
			return binarySearch(vec, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(vec, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void missing_numbers(vector<int> vec1, vector<int> vec2)
{
	vector<int> ans;
	//sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	for(int i = 0 ; i < vec1.size(); i++)
	{
		if(binarySearch(vec2,0,vec2.size() - 1, vec1[i]) == -1)
		{
			ans.push_back(vec1[i]);
		}
	}

	for (int i : ans)
		cout << i << ' ';
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<int> vec1, vec2;
		for(int i = 0; i < n ; i++)
		{
			int element;
			cin >> element;
			vec1.push_back(element);
		}
		for (int i = 0; i < m; i++)
		{
			int element;
			cin >> element;
			vec2.push_back(element);
		}
		missing_numbers(vec1, vec2);
		cout << endl;
	}

	return 0;
}
