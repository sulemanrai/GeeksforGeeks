#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int pairs_with_difference_less_than_k(vector<int> vec, int K)
{
	int ans = 0;
	map<pair<int, int>, int> Map;
	sort(vec.begin(), vec.end());



	for (int i = 0; i < vec.size(); i++)
	{
		 for (int j = i + 1; j < vec.size(); j++)
		 {

			 Map.insert(make_pair(make_pair(vec[i], vec[j]), abs(vec[i] - vec[j])));
			// Map.insert(make_pair(make_pair(vec[j], vec[i]), abs(vec[i] - vec[j])));
		 }
	}
 //
	// 		// if(abs(vec[i] - vec[j]) < K)
	// 		// {
	// 		// 	ans++;
	// 		// }
	// 		//Map.insert(make_pair(make_pair(vec[i], vec[j]), abs(vec[i] - vec[j])));
	// 	}
	//
	// }

	for(map<pair<int, int>, int>::iterator it = Map.begin(); it != Map.end(); ++it)
	{
		if((*it).second < K)
		{
			ans++;
		}
	}


	return ans;
}

int countPairs(vector<int> a, int n, int k)
{
    // to sort the array.
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; i++) {

        // Keep incrementing result while
        // subsequent elements are within
        // limits.
        int j = i+1;
        while (j < n && a[j] - a[i] < k) {
            res++;
            j++;
        }
    }
    return res;
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
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
	//	cout << pairs_with_difference_less_than_k(vec, K) << endl;
	    cout << countPairs(vec,vec.size(),K) << endl;
	}
	return 0;
}
