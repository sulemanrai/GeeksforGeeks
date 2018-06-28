#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int count_pairs_with_max_difference(vector<int> vec)
{
	int count = 0;
	int mini = INT_MAX;
	int maxi = INT_MIN;
	int max_difference = 0;
	//sort(vec.begin(), vec.end());

	for(int i=  0; i < vec.size(); i++)
	{
		mini = min(mini, vec[i]);
		maxi = max(maxi, vec[i]);
	}

	//max_difference = vec[vec.size() - 1] - vec[0];
	max_difference = maxi - mini;

	// to find the count of minimum and
    // maximum elements
    int c1 = 0;
    int c2 = 0; // Count variables
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == mini)
            c1++;
        if (vec[i] == maxi)
            c2++;
    }

    // condition for all elements equal
    int n = vec.size();
    if (mini == maxi)
        return n * (n - 1) / 2;
    else
        return c1 * c2;

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

		cout << count_pairs_with_max_difference(vec) << endl;
	}

	return 0;
}
