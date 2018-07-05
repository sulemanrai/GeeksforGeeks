#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
}
int binarySearch(vector<int> vec,int l,int r, int x)
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
		if (vec[mid] >= x)
			return binarySearch(vec, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(vec, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
void smallestGreater(vector<int> vec)
{
	vector<int> sorted_vec(vec.size());
	copy(vec.begin(), vec.end(), sorted_vec.begin());
	sort(sorted_vec.begin(),sorted_vec.end());

	// int temp = binarySearch(sorted_vec, 0, sorted_vec.size(), 15);
	// cout << temp << endl;
	for(int i = 0; i < vec.size(); i++)
	{
		int temp = binarySearch(sorted_vec, 0, sorted_vec.size() - 1, vec[i]);
		if(temp != -1)
		{
			if (temp == sorted_vec.size() - 1 || vec[i] == sorted_vec[sorted_vec.size() - 1])
			{
				cout << '_';
				cout << ' ';
			}
			for(int j = temp+1; j < sorted_vec.size(); j++)
			{
				if (sorted_vec[j] > vec[i]) {
					cout << sorted_vec[j] << ' ';
					break;
				}
			}
		}
		else
		{
			cout << '_';
			cout << ' ';
		}
	}
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
		smallestGreater(vec);
		cout << endl;

	}

	return 0;
}
