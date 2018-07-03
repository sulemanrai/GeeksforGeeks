#include<iostream>
#include <vector>
using namespace std;

void printArray(int **arr,int rows, int cols)
{
	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			cout << arr[r][c] << ' ';
		}
		cout << endl;
	}
}

void kronecker_product(int **a, int **b, int m, int n, int p, int q)
{
	int **C = new int*[(m * p)];
	for(int i = 0 ; i < (m*p); i++)
	{
		C[i] = new int[(n*q)];
	}

	for(int r1 = 0; r1 < m; r1++)
	{
		for(int r2 = 0; r2 < p; r2++)
		{
			for(int c1 = 0; c1 < n; c1++)
			{
				for(int c2 = 0; c2 < q; c2++)
				{
					C[r1 + c2 + 1][c1 + r2 + 1] = a[r1][c1] * b[r2][c2];
					cout << C[r1 + c2 + 1][c1 + r2 + 1] <<"\t";
				}
			}
			printf("\n");
		}
	}
}

int main()
{
	//code
	int T;
	cin >> T;

	while(T--)
	{



		int m;
		cin >> m;
		int n;
		cin >> n;
		int **A = new int*[m];

		for(int i = 0; i < m; i++)
		{
			A[i] = new int[n];
		}
		int p;
		cin >> p;
		int q;
		cin >> q;
		int **B = new int*[p];
		for (int i = 0; i < p; i++)
		{
			B[i] = new int[q];
		}

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int element;
				cin >> element;
				A[i][j] = element;
			}
		}

		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < q; j++)
			{
				int element;
				cin >> element;
				B[i][j] = element;
			}
		}
		//printArray(B, p,q);
		kronecker_product(A, B, m, n, p, q);
		//cout << endl;
	}

	return 0;
}
