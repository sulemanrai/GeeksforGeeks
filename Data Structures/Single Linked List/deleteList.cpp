// C program to delete a linked list
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
	if(*head_ref == NULL)
	{
		printf("List is Empty");
	} else
	{
		struct Node * current = *head_ref;
		(*head_ref)->next = NULL;
		deleteList(&(current->next));
		free(current);
	}

}

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
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

/* Drier program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Use push() to construct below list
	1->12->1->4->1  */
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	printf("\n Deleting linked list\n");
	deleteList(&head);

	printf("\n Linked list deleted\n");
}
