// C++ program to detect loop in a linked list
#include "iostream"
#include<stdio.h>
#include<stdlib.h>

using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// else returns false.
int detectLoop(struct Node * list)
{
	int isLoop = 0;

	struct Node * slowptr = list;
	struct Node * fastptr = list;
	int i = 0;
	while (slowptr && fastptr )
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;

		if(slowptr == fastptr)
		{
			return 1;
		}
	}

	return 0;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	//head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop found\n";
	else
		cout << "No Loop\n";

	return 0;
}
