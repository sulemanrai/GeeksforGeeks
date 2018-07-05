#include <iostream>
#include <algorithm>


using namespace std;
int max_path_sum(int[], int[], int, int);
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		fflush(stdin);
		//int a[N], b[M];
		int *a = new int[N];
		int *b = new int[N];
		for (int i = 0; i<N; i++)
			cin >> a[i];
		for (int i = 0; i<M; i++)
			cin >> b[i];
		int result = max_path_sum(a, b, N, M);
		cout << result << endl;
	}
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/

int binarySearch(int arr[], int low, int high, int key)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == key)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > key)
			return binarySearch(arr, low, mid - 1, key);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, high, key);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int returnSum(int arr[], int startIndex, int endIndex)
{
	int sum = 0;
	for(int i = startIndex; i != endIndex+1; i++)
	{
		sum += arr[i];
	}

	return sum;
}
int max_path_sum(int A[], int B[], int l1, int l2)
{
	//Your code here
	int sizeA = l1;
	int sizeB = l2;
	int ans = 0;

	int i = 0;
	int j = 0;

	int sumA = 0;
	int sumB = 0;
	bool flagA = true;
	bool flagB = true;
	int prevA = -1;
	int prevB = -1;
	int index = -1;

	while (1)
	{
		if (A[i] >= B[j])
		{
			index = binarySearch(B, j, sizeB, A[i]);
			if (index != -1) {
				if(B[index] == B[index - 1])
				{
					index = index - 1;
				}
				sumA = returnSum(A, prevA+1, i);
				sumB = returnSum(B, prevB+1, index);
				ans += max(sumA, sumB);
				prevA = i;
				prevB = index;
				j = index;
				sumA = 0;
				sumB = 0;
			} else
			{
				sumA += A[i];
				// if(sumA == 0)
				// {
				// 	sumA = returnSum(A, prevA + 1, i);
				// } else
				// {
				// 	sumA += A[i];
				// }
			}
		} else if (B[j] >= A[i])
		{
			index = binarySearch(A, i, sizeA, B[j]);
			if (index != -1) {
				if (A[index] == A[index - 1])
				{
					index = index - 1;
				}
				sumA = returnSum(A, prevA+1, index);
				sumB = returnSum(B, prevB+1, j);
				ans += max(sumA, sumB);
				prevA = index;
				prevB = j;
				i = index;
				sumA = 0;
				sumB = 0;
			} else
			{
				sumB += B[j];
			}
		}
		i++;
		j++;
		if (i == sizeA || j == sizeB) {
			break;
		}
	}
	if (i == sizeA && j == sizeB) {
		sumA = returnSum(A, prevA + 1, sizeA - 1);
		sumB = returnSum(B, prevB + 1, sizeB - 1);
		ans += max(sumA, sumB);
	} else if(i != sizeA && j == sizeB)
	{
		sumA = returnSum(A, prevA + 1, sizeA - 1);
		sumB = returnSum(B, prevB + 1, sizeB - 1);
		ans += (max(sumA,sumB));
	} else if (j != sizeB && i == sizeA)
	{
		sumA = returnSum(A, prevA + 1, sizeA - 1);
		sumB = returnSum(B, prevB + 1, sizeB - 1);
		//cout << " sumB " << sumB << endl;
		ans += (max(sumA, sumB));
	}



	return ans;
}
