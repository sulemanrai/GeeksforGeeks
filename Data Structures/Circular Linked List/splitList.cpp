#include<stdio.h>
#include<stdlib.h>
#include <iostream>

/* structure for a node */
struct Node
{
	int data;
	struct Node *next;
};

/* Function to insert a node at the begining of a Circular
linked list */
void push(struct Node **head_ref, int data)
{
	struct Node * current = *head_ref;
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode;

	if(!newNode)
	{
		printf("Memory Error");
		return;
	}

	if(*head_ref == NULL)
	{
		*head_ref = newNode;
	} else
	{
		while (current->next != *head_ref)
		{
			current = current->next;
		}

		newNode->next = *head_ref;
		current->next = newNode;
		*head_ref = newNode;
	}

}

/* Function to split a list (starting with head) into two lists.
head1_ref and head2_ref are references to head nodes of
the two resultant linked lists */
void splitList(struct Node *head, struct Node **head1_ref,
	struct Node **head2_ref)
{

	/* Check the size of the list*/
	int count = 1;
	//struct Node *temp = head;
	struct Node *tail1 = head;
	struct Node *tail2 = head;

	int i = 0;
	while(tail2->next != head)
	{
		if(i == 0)
		{
			tail2 = tail2->next;
			i = 1;
		} else if (i == 1)
		{
			tail1 = tail1->next;
			tail2 = tail2->next;
			i = 0;
		}
	}

	/* Set the head pointer of first half */
	*head1_ref = head;

	/* Set the head pointer of second half */
	if (head->next != head)
		*head2_ref = tail1->next;

	/* Make second half circular */
	tail2->next = tail1->next;

	/* Make first half circular */
	tail1->next = head;

}

int main()
{
	/* Initialize lists as empty */
	struct Node *head = NULL;

	/* Created linked list will be 11->2->56->12 */
	push(&head, 12);
	push(&head, 56);
	push(&head, 2);
	push(&head, 11);

	struct Node *first_half = NULL;
	struct Node *second_half = NULL;

	splitList(head, &first_half, &second_half);

	return 0;
}
