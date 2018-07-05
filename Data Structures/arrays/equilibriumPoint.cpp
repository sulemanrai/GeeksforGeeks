#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int returnSumright(vector<int> vec, int index)
{
	int ans = 0;

	for(int i = vec.size() - 1; i > index; i--)
	{
		ans += vec[i];
	}
	return ans;
}

int equilibriumPoint(vector<int> vec)
{
	int ans = 1;
	int left = 0;
	int right = vec.size() - 1;
	 int sumLeft = vec[0];
	 int sumRight = 0;

	bool flag = false;
	if (vec.size() == 1) {
		return ans;
	}


	int i = 1;
	for(; i < vec.size(); i++)
	{
		sumLeft += vec[i];
		sumRight = returnSumright(vec, i - 1);
		//cout << " sumLeft " << sumLeft << " sumRight " << sumRight << endl;
		if(sumLeft == sumRight)
		{
			flag = true;
			ans = i + 1;
			break;
		}
	}

	if(flag == false)
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
		cout << equilibriumPoint(vec) << endl;
	}
	return 0;
}
