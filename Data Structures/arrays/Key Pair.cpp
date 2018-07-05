#include <iostream>
#include <unordered_set>

using namespace std;

// Function to check if array has 2 elements
// whose sum is equal to the given value
bool hasArrayTwoCandidates(int A[], int arr_size,
	int sum)
{
	unordered_set<int> s;
	bool hasPair = false;
	for(int i = 0; i <= arr_size; i++)
	{
		int temp = sum - A[i];
		//cout << " temp " << temp << endl;
		if (temp > 0 && s.find(temp) != s.end()) {
			hasPair = true;
			break;
		}
		s.insert(A[i]);
	}

	return hasPair;
}

int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;
		int element;
		int K;
		cin >> N;
		cin >> K;
		int *array = NULL;
		array = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> element;
			array[i] = element;
		}
		if (hasArrayTwoCandidates(array, N - 1, K) == true)
			cout << "YES";
		else
			cout << "NO";
		delete[] array;
		cout << endl;
	}

	return 0;
}
