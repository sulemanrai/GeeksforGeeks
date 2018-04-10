#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};
void reverseUtil(Node *curr, Node *prev, Node **head);

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(Node **head)
{
	if (*head == NULL)
		return;
	reverseUtil(*head, NULL, head);
}

// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(Node *curr, Node *prev, Node **head)
{
	if(*head == NULL)
	{
		return;
	}

	if(curr->next == NULL)
	{
	    *head = curr;
		return;
	}


	reverseUtil(curr->next, prev, head);
	prev = curr;
	curr = curr->next;
	curr->next = prev;
	prev->next = NULL;
}


// A utility function to create a new node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// A utility function to print a linked list
void printlist(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// Driver program to test above functions
int main()
{
	Node *head1 = newNode(1);
	head1->next = newNode(2);
	head1->next->next = newNode(3);
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(5);
	head1->next->next->next->next->next = newNode(6);
	head1->next->next->next->next->next->next = newNode(7);
	head1->next->next->next->next->next->next->next = newNode(8);
	cout << "Given linked list\n";
	printlist(head1);
	reverse(&head1);
	cout << "\nReversed linked list\n";
	printlist(head1);
	return 0;
}
