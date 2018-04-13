/* C Program to move last element to front in a given linked list */
#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

/* We are using a double pointer head_ref here because we change
head of the linked list inside this function.*/
void moveToFront(struct Node **head_ref)
{
	struct Node * current = *head_ref;
	struct Node * newtail = NULL;

	while(current->next != NULL)
	{
		newtail = current;
		current = current->next;
		if(current->next == NULL)
		{
			current->next = *head_ref;
			newtail->next = NULL;
			*head_ref = current;
			break;
		}
	}
}

/* UTILITY FUNCTIONS */
/* Function to add a node at the begining of Linked List */
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


/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Druver program to test above function */
int main()
{
	struct Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("\n Linked list before moving last to front\n");
	printList(start);

	moveToFront(&start);

	printf("\n Linked list after removing last to front\n");
	printList(start);

	return 0;
}
