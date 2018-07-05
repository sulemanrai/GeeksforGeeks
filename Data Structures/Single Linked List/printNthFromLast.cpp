// Simple C program to find n'th node from end
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};


/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n)
{
	struct Node * mainptr = head;
	struct Node * referenceptr = head;

	int pos = 0;
	while(head->next != NULL)
	{
		pos++;
		if(pos == n )
		{
			break;
		}
		referenceptr = referenceptr->next;

	}
	if (referenceptr != NULL)
	{
		while (referenceptr->next != NULL)
		{
			referenceptr = referenceptr->next;
			mainptr = mainptr->next;
		}
	} else
	{
		return ;
	}
	printf("%i\n\n", mainptr->data);
}

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);

	printNthFromLast(head, 4);
	return 0;
}
