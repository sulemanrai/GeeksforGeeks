#include<iostream>
#include <vector>
#include <algorithm>    // std::find
using namespace std;

void print_common_elements(vector<int> veca, vector<int> vecb, vector<int> vecc)
{
	bool flag = false;
	vector<int> ans;

	for(int i = 0; i < veca.size(); i++)
	{
		for(int j = 0 ; j < vecb.size(); j++)
		{
			for(int k = 0; k < vecc.size(); k++)
			{
				if(veca[i] == vecb[j]  && vecb[j] == vecc[k])
				{
					flag = true;
					int temp = veca[i];
					vector<int>::iterator it = find(ans.begin(), ans.end(), veca[i]);
					if(it == ans.end())
					{
						ans.push_back(veca[i]);
					}
					//cout << veca[i] << ' ';
				}
			}
		}
	}

	if(flag == false)
	{
		cout << -1 << ' ';
	} else if (flag == true)
	{
		for (int i : ans)
			cout << i << ' ';
	}
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		int N1;
		cin >> N1;
		int N2;
		cin >> N2;
		int N3;
		cin >> N3;

		vector<int> vec1;
		vector<int> vec2;
		vector<int> vec3;

		for(int i = 0; i < N1; i++)
		{
			int element;
			cin >> element;
			vec1.push_back(element);
		}

		for (int i = 0; i < N2; i++)
		{
			int element;
			cin >> element;
			vec2.push_back(element);
		}

		for (int i = 0; i < N3; i++)
		{
			int element;
			cin >> element;
			vec3.push_back(element);
		}

		print_common_elements(vec1, vec2, vec3);
		cout << endl;
	}

	return 0;
}
