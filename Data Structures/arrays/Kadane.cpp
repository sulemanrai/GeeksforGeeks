#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int maxSumContagiousArray(vector<int> vec)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int i : vec)
    {
        max_ending_here = max_ending_here + i;
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    return max_so_far;
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
           	for(int i =0;i< N; i++)
           	{
           	    int element;
           	    cin >> element;
           	    vec.push_back(element);
           	}
           	int sum = maxSumContagiousArray(vec);
           	cout <<  sum << endl;
	}


	return 0;
}
