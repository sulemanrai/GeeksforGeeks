#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include<iostream>
#include<climits>
using namespace std;

#include<iostream>
using namespace std;

// A class for Min Heap
class MinHeap
{
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of max heap
	int heap_size; // Current number of elements in max heap
public:
	MinHeap(int a[], int size); // Constructor
	void minHeapify(int i);  //To maxHeapify subtree rooted with index i
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMin();  // extracts root (maximum) element
	int getMin() { return harr[0]; } // Returns maximum

									 // to replace root with new node x and heapify() new root
	void replaceMin(int x) { harr[0] = x;  minHeapify(0); }
	static void printArray(int a[], int size);
	void swap(int *a, int *b);
};
MinHeap::MinHeap(int a[], int size)
{
	harr = a;
	heap_size = size;
	int i = (heap_size - 1) / 2;
	while(i >=0)
	{
		minHeapify(i);
		i--;
	}
}


void MinHeap::minHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l < heap_size && harr[l] > harr[i])
	{
		smallest = l;
	} else
	{
		smallest = i;
	}
	if(r < heap_size && harr[r] > harr[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		minHeapify(smallest);
	}
}

static void printArray(int a[], int size)
{
	for (int i = 0; i< size; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

int MinHeap::extractMin()
{
	if (heap_size < 1)
		return -1;

	int min = harr[0];
	harr[0] = harr[heap_size - 1];
	minHeapify(0);
	heap_size--;

	return min;
}

void MinHeap::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Function to return k'th largest element in a given array
void kthsmallest(int arr[], int n, int k)
{
	MinHeap a = MinHeap(arr, n);
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		ans.push_back(a.extractMin());
	}

	for(int i = 0; i< ans.size();i++)
	{
	    cout << ans[i] <<' ';
	}
	cout << endl;
}

int main()
 {
	//code
	int T;
	cin >> T;
	int arr[1000];
	while(T--)
	{
	    int N;
	    cin >> N;
	    int K;
	    cin >> K;
	    for(int i=0; i< N; i++)
	    {
	        int element;
	        cin >> element;
	        arr[i] = element;
	    }

	    kthsmallest(arr, N, K);
	}

	return 0;
}
