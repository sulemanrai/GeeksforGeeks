// C/C++ program to count occurrences in a linked list
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

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

/* Counts the no. of occurences of a node
(search_for) in a linked list (head)*/
int count(struct Node* head, int search_for)
{
	int count = 0;

	while(head != NULL)
	{
		if(head->data == search_for)
		{
			count++;
		}
		head = head->next;
	}

	return count;
}

/* Drier program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Use push() to construct below list
	1->2->1->3->1  */
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);

	/* Check the count function */
	printf("count of 1 is %d\n", count(head, 1));
	return 0;
}
