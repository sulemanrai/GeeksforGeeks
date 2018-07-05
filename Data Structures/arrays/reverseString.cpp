#include<iostream>
#include <string>

using namespace std;
int main()
{
	//code
	int T;
	cin >> T;

	while (T--)
	{
		//char * str = new char[1000];
		string str1;
		cin >> str1;
		//str1 = str;
		string rstr = "";
		string::iterator strIterator = str1.begin();
		string::reverse_iterator reverseItr = str1.rbegin();

		while(reverseItr != str1.rend())
		{
			rstr += *reverseItr;
			reverseItr++;
		}
		cout << rstr << endl;
	}
	return 0;
}
