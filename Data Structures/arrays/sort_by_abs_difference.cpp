#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using namespace std;


void sort_by_abs_difference(vector<int> vec, int K)
{
	multimap<int, int> Multimap;
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		//hashtable.insert(*i, abs(*i - K));
		//cout << *i << endl;
		Multimap.insert(make_pair(abs(*i - K), *i ));
		//cout << " Key " << *i << " Value " << hashtable.at(*i) << endl;
	}
	for(std::multimap<int,int>::const_iterator i = Multimap.begin(); i != Multimap.end(); ++i)
	{
		cout << (*i).second << " ";
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
		for(int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			vec.push_back(element);
		}
		sort_by_abs_difference(vec, K);
		cout << endl;
	}
	return 0;
}
