#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void first_K_natural_numbers(vector<int> vec, vector<int> naturalNumbers, int K)
{
	std::vector<int>::iterator it;

	 //for (int i : naturalNumbers)
	 //	cout << i << ' ';
	int count = 0;

	 for(int i = 0; i < naturalNumbers.size(); i++)
	 {
	 	it = find(vec.begin(), vec.end(), naturalNumbers[i]);

	 	if(it == vec.end())
	 	{
	 		cout << naturalNumbers[i] << ' ';
			count++;
	 	}
		if (count == K)
			break;
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
		int K;
		cin >> K;

		vector<int> vec;
		vector<int> naturalNumbers;
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}

		for(int i = 0; i < N+K; i++)
		{
			naturalNumbers.push_back(i + 1);
		}

		first_K_natural_numbers(vec, naturalNumbers, K);
		cout << endl;
	}

	return 0;
}
