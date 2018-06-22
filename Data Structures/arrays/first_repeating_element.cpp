#include<iostream>
#include <vector>
using namespace std;

int first_repeating_element(vector<int> vec)
{
	int ans = 0;
	bool found = false;

	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			if(vec[i] == vec[j])
			{
				ans = i + 1;
				found = true;
				break;
			}
		}
		if(found == true)
		{
			break;
		}
	}

    if(found == false)
    {
        ans = -1;
    }

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
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		cout << first_repeating_element(vec) << endl;
	}

	return 0;
}
