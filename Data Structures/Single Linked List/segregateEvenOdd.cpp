/* C/C++ program to merge two sorted linked lists */
// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>

/* a node of the singly linked list */
struct Node
{
	int data;
	struct Node *next;
};

bool checkAllNodesEven(struct  Node **head_ref)
{
	bool isEven = false;
	/*If all nodes are even*/
	struct Node *current = *head_ref;
	while (current != NULL)
	{
		if (current->data % 2 == 0)
		{
			isEven = true;
		} else
		{
			isEven = false;
		}
		current = current->next;
	}
	return isEven;
}

bool checkAllNodesOdd(struct  Node **head_ref)
{
	bool isOdd = false;
	/*If all nodes are even*/
	struct Node *current = *head_ref;
	while (current != NULL)
	{
		if (current->data % 2 == 0)
		{
			isOdd = false;
		}
		else
		{
			isOdd = true;
		}
		current = current->next;
	}
	return isOdd;
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
void segregateEvenOdd(struct Node **head_ref)
{
	struct Node *oddList = NULL;
	struct Node *evenList = NULL;
	struct Node *oddListEnd = NULL;
	struct Node *evenListEnd = NULL;
	struct Node * current = *head_ref;

	if (*head_ref == NULL)
	{
		return;
	} else
	{
		while(current != NULL)
		{
			if(current->data % 2 == 0)
			{
				if(evenList == NULL)
				{
					evenList = evenListEnd = current;
				} else
				{
					evenListEnd->next = current;
					evenListEnd = current;
				}
			} else if(current->data % 2 != 0)
			{
				if(oddList == NULL)
				{
					oddList = oddListEnd = current;
				} else
				{
					oddListEnd->next = current;
					oddListEnd = current;
				}
			}
			current = current->next;
		}
		evenListEnd->next = oddList;
		oddListEnd->next = NULL;
	}
	*head_ref = evenList;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
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



/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Let us create a sample linked list as following
	0->2->4->6->8->10->11 */

	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	push(&head, 5);
	push(&head, 10);
	push(&head, 12);
	push(&head, 8);
	push(&head, 15);
	push(&head, 17);

	printf("\nOriginal Linked list \n");
	printList(head);

	segregateEvenOdd(&head);

	printf("\nModified Linked list \n");
	printList(head);

	return 0;
}
