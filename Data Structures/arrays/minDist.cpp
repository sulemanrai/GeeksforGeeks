#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVec(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
}

int minDistance(vector<int> &vec, int x, int y)
{
	int minimum = INT_MAX;
	int xIndex = -1;
	int yIndex = -1;
	/*Search for x*/
	for(int i = 0; i < vec.size(); i++)
	{
		for(int j = i+1; j < vec.size(); j++)
		{
			if((vec[i] == x && vec[j] == y) || (vec[j] == x && vec[i] == y))
			{
				xIndex = i;
				yIndex = j;
				minimum = min(minimum, abs(xIndex - yIndex));
			}
		}
	}

	return minimum;

}

int main()
{
	//code
	int T;
	cin >> T;
	int N;
	cin >> N;
	vector<int> vec;
	for(int i = 0; i< N; i++)
	{
		int element;
		cin >> element;
		vec.push_back(element);
	}
	int x;
	cin >> x;
	int y;
	cin >> y;
	cout << minDistance(vec, x, y) << endl;

	return 0;
}
