#include<stdio.h>
#include "iostream"


using namespace std;

// Linked List Node
struct Node
{
	int data;
	struct Node* next;
};

// A utility function to print a linked list
void printlist(Node * node)
{
	while (node != NULL)
	{
		cout << node->data << "->";
		node = node->next;
	}
	cout << "NULL" << endl;
}

// A utility function to create a new node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}






// Rearranges given linked list such that all even
// positioned nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
	if (head == NULL)
		return head;

	if (head->next == NULL || head->next->next == NULL)
		return head;

	Node * oddptr = head;
	Node * evenptr = oddptr->next;

	Node * evenListHead = evenptr;

	while(true)
	{
		if (oddptr->next == NULL || evenptr->next == NULL)
		{
			oddptr->next = evenListHead;
			break;
		}



		if(oddptr->next->next != NULL && evenptr->next->next != NULL)
		{
			oddptr->next = evenptr->next;
			evenptr->next = evenptr->next->next;


			oddptr = oddptr->next;
			evenptr = evenptr->next;
		} else if(oddptr->next->next != NULL && evenptr->next->next == NULL)
		{
			oddptr->next = evenptr->next;
			oddptr = oddptr->next;
			evenptr->next = NULL;
		}

	}
	return head;
}




int main()
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	//head->next->next->next->next = newNode(56);
	//head->next->next->next->next->next = newNode(70);

	cout << "Given Linked List\n";
	printlist(head);

	head = rearrangeEvenOdd(head);

	cout << "\nModified Linked List\n";
	printlist(head);

    return 0;
}
