#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_triplets(vector<int> vec)
{
    bool ispresent = false;
	int count = 0;
	sort(vec.begin(), vec.end());
	int n = vec.size();

	for (int i = n - 1; i >= 0; i--) {
		int j = 0;
		int k = i - 1;
		while (j < k) {
			if (vec[i] == vec[j] + vec[k]) {

				// pair found
				ispresent = true;
				count++;
				j++;
				k--;
			}
			else if (vec[i] > vec[j] + vec[k])
				j += 1;
			else
				k -= 1;
		}
	}
    if(ispresent == false)
    {
        count = -1;
    }

	return count;
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
		cout << count_triplets(vec) << endl;
	}
	return 0;
}
