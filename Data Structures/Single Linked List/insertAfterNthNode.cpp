#include <cstdlib>
#include "iostream"
// C program to find n'th Node in linked list
using namespace std;

// structure of a node
struct Node {
	int data;
	Node* next;
};

// function to get a new node
Node* getNode(int data)
{
	// allocate memory for the node
	Node* newNode = (Node*)malloc(sizeof(Node));

	// put in the data
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// function to insert a node after the
// nth node from the end
void insertAfterNthNode(Node* head, int n, int x)
{
	struct Node * slowptr = head;
	struct Node * fastptr = head;

	int count = 0;

	while(count <= n - 1)
	{
		count++;
		fastptr = fastptr->next;
	}

	while(fastptr->next)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}

	struct Node * next = slowptr->next;
	struct Node * temp = getNode(x);
	slowptr->next = temp;
	temp->next = next;
}

// function to print the list
void printList(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver program to test above
int main()
{
	// Creating list 1->3->4->5
	Node* head = getNode(1);
	head->next = getNode(3);
	head->next->next = getNode(4);
	head->next->next->next = getNode(5);

	int n = 2, x = 2;

	cout << "Original Linked List: ";
	printList(head);

	insertAfterNthNode(head, n, x);

	cout << "\nLinked List After Insertion: \n";
	printList(head);
	cout << "\n" << endl;

	return 0;
}
