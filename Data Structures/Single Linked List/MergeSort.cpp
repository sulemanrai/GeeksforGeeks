// C++ program to detect loop in a linked list
// C code for linked list merged sort
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* function prototypes */
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
	struct Node** frontRef, struct Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef)
{
	/* If head is NULL or there is only one element in the Linked List
    then return.*/
	if (*headRef == NULL || (*headRef)->next == NULL)
	{
		return;
	}
	else
	{
		/*Else divide the linked list into two halves.
		FrontBackSplit(head, &a, &b); /* a and b are two halves */

		struct Node* a = (struct Node*) malloc(sizeof(struct Node));;;
		struct Node* b = (struct Node*) malloc(sizeof(struct Node));;;

		FrontBackSplit(*headRef, &a, &b);
		MergeSort(&a);
		MergeSort(&b);

		*headRef = SortedMerge(a, b);
	}

}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
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


/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct Node* source,
	struct Node** frontRef, struct Node** backRef)
{
	struct Node * slowptr = source;
	struct Node * fastptr = source;

	int i = 0;
	while(fastptr->next != NULL)
	{
		if(i == 0)
		{
			fastptr = fastptr->next;
			i = 1;
		} else if(i == 1)
		{
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			i = 0;
		}
	}
	*backRef = slowptr->next;
	*frontRef = source;
	slowptr->next = NULL;

	//printf("slowPtr %i fastPtr %i\n", (*backRef)->data, (*frontRef)->data);
	//printf("slowPtr %i fastPtr %i\n", (*backRef)->data, (*frontRef)->data);

	//printf("slowPtr %i fastPtr %i\n", slowptr->data, fastptr->data);

	//printList(*frontRef);
	//printList(*backRef);
}


/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* res = NULL;
	struct Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
	Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	printf("Original Linked List is: \n");
	printList(a);

	//struct Node* f = (struct Node*) malloc(sizeof(struct Node));;
	//struct Node* g = (struct Node*) malloc(sizeof(struct Node));;

	//FrontBackSplit(a, &f, &g);

	/* Sort the above created Linked List */
	MergeSort(&a);

	printf("\nSorted Linked List is: \n");
	printList(a);

	//getchar();
	return 0;
}
