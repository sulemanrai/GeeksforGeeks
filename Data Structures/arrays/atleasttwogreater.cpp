#include<iostream>
#include<algorithm>
using namespace std;



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
	    for(int i=0; i< N; i++)
	    {
	        int element;
	        cin >> element;
	        vec.push_back(element);
	    }
	    sort(vec.begin(),vec.end());
	    for(int i=0; i< vec.size() -2; i++)
	    {
	        cout << vec[i] <<' ';
	    }
	    cout << endl;
	}
	return 0;
}
