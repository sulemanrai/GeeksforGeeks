#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
#define MAX 1000
void printMat(int M[MAX][MAX], int row, int col);

/*You are required to complete this function*/
void printMat(int **M, int row, int col)
{


	//Your code here
	unordered_map<string, int> vecMap;
	unordered_map<string, int>::iterator itr;

	for (int r = 0; r < row; r++)
	{
		string str = "";

		for (int c = 0; c < col; c++)
		{
			str.append(to_string(M[r][c]));
		}
	
		itr = vecMap.find(str);
		//vecMap[r] = str;
		 //itr = find(vecMap.begin(), vecMap.end(), '2');
		 if(itr == vecMap.end())
		 {
			 vecMap[str]++;
		 	for (int i = 0; i < str.size(); i++)
		 		cout << str[i] << ' ';
		 	cout << "$";
		 }
		
		str.clear();
	}


}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;

		int **a = new int*[MAX];
		for(int i = 0; i < MAX; i++)
		{
			a[i] = new int[MAX];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int element;
				cin >> element;
				a[i][j] = element;
			}
		printMat(a, n, m);
		cout << endl;
	}

}