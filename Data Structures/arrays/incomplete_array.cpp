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
int incomplete_array(vector<int> vec)
{
	sort(vec.begin(), vec.end());
	int minimim = vec[0];
	int maximum = vec[vec.size() - 1];
	int ans = 0;
// 	for(int key = minimim + 1 ; key < maximum; key++)
// 	{
// 		if(binarySearch(vec,0,vec.size() - 1,key) == -1)
// 		{
// 			ans++;
// 		}
// 	}
	for (int i = 0; i < vec.size() - 1; i++)
		if (vec[i] != vec[i+1] &&
			vec[i] != vec[i + 1] - 1)
			ans += vec[i + 1] - vec[i] - 1;

	return ans;
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
		for(int i = 0 ; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << incomplete_array(vec) << endl;
	}
	return 0;
}
