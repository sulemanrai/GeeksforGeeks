#include <stdio.h>
#include <stdlib.h>
#include "iostream"

using namespace std;
/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Function to get the middle and set at
beginning of the linked list*/
void setMiddleHead(struct Node** head)
{
	struct Node * slowptr = *head;
	struct Node * fastptr = *head;
	struct Node * prev = NULL;

	int i = 0;
	while(slowptr && fastptr && fastptr->next)
	{
		if( i == 0)
		{
			prev = slowptr;
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			i = 1;
		} else if(i == 1)
		{
			fastptr = fastptr->next;
			i = 0;
		}
	}
	prev->next = slowptr->next;


	slowptr->next = *head;
	*head = slowptr;

}

// To insert a node at the beginning of linked
// list.
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// A  function to print a given linked list
void printList(struct Node* ptr)
{
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

/* Driver function*/
int main()
{
	// Create a list of 5 nodes
	struct Node* head = NULL;
	int i;
	for (i = 5; i > 0; i--)
		push(&head, i);

	printf(" list before: ");
	printList(head);

	setMiddleHead(&head);

	printf(" list After:  ");
	printList(head);

	return 0;
}
