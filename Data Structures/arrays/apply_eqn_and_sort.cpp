#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void apply_eqn_and_sort(vector<long long int> vec, vector<long long int> aux)
{
	for(int i = 0; i < vec.size(); i++)
	{
		vec[i] = aux[0] * vec[i] * vec[i] + aux[1] * vec[i] + aux[2];
	}

	sort(vec.begin(), vec.end());

	for (long long int i : vec)
		cout << i << ' ';
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{
		vector<long long int> aux;
		int A;
		cin >> A;
		int B;
		cin >> B;
		int C;
		cin >> C;
		aux.push_back(A);
		aux.push_back(B);
		aux.push_back(C);
		int N;
		cin >> N;
		vector<long long int> vec;
		for(int i = 0 ; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		apply_eqn_and_sort(vec, aux);
		cout << endl;
	}
	return 0;
}
