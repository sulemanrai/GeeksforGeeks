/* This program swaps the nodes of linked list rather
than swapping the field from the nodes.*/

#include<stdio.h>
#include<stdlib.h>

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

/* Checks whether the value x is present in linked list */
bool search(struct Node* head, int x)
{
	bool isPresent = false;
	if (head == NULL)
	{
		return isPresent;
	}

	isPresent = search(head->next, x);

	if (head->data == x)
	{
		isPresent = true;
	}

	return isPresent;
}

/* Function to swap nodes x and y in linked list by
changing links */
void swapNodes(struct Node **head_ref, int x, int y)
{
	/*If head is NULL*/
	if (*head_ref == NULL)
		return;
	/*If x and Y are same*/
	if (x == y)
		return;

	if(search(*head_ref, x) == false)
	{
		return;
	}
	if(search(*head_ref, y) == false)
	{
		return;
	}


	struct Node* prevX = NULL;
	struct Node* currentX = *head_ref;
	struct Node* nextX = NULL;
	struct Node* prevY = NULL;
	struct Node* currentY = *head_ref;
	struct Node* nextY = NULL;

		while (currentX != NULL)
		{

			if((*head_ref)->data == x)
			{
				break;
			}

			prevX = currentX;
			currentX = currentX->next;
			if (currentX->data == x)
			{
				break;
			}
		}

		while (currentY != NULL)
		{
			if ((*head_ref)->data == y)
			{
				break;
			}
			prevY = currentY;
			currentY = currentY->next;
			if (currentY->data == y)
			{
				break;
			}
		}

		nextX = currentX->next;
		nextY = currentY->next;

	if((prevY == currentX && nextX == currentY))
	{
		prevX->next = currentY;
		currentY->next = currentX;
		currentX->next = nextY;
	} else if ((prevX == currentY && nextY == currentX))
	{
		prevY->next = currentX;
		currentX->next = currentY;
		currentY->next = nextX;
	}
	else if(prevX != NULL && prevY != NULL)
	{
			prevX->next = currentY;
			currentY->next = nextX;
			prevY->next = currentX;
			currentX->next = nextY;
	} else if (prevX == NULL)
	{
			if((prevY == currentX && nextX == currentY))
			{
				currentY->next = currentX;
				currentX->next = nextY;
				(*head_ref) = currentY;
			}
			else {
				prevY->next = currentX;
				currentX->next = nextY;
				currentY->next = nextX;
				*head_ref = currentY;
			}
	} else if( prevY == NULL)
	{
		if ((prevX == currentY && nextY == currentX))
		{
					currentX->next = currentY;
					currentY->next = nextX;
					*head_ref = currentX;
		}
		else {
			prevX->next = currentY;
			currentY->next = nextX;
			currentX->next = nextY;
			*head_ref = currentX;
		}
	}
}

/* Function to add a node at the begining of List */
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
}

/* Druver program to test above function */
int main()
{
	struct Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5->6->7 */
	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("\n Linked list before calling swapNodes() \n");
	printList(start);

	swapNodes(&start, 6, 7);

	printf("\n Linked list after calling swapNodes() \n");
	printList(start);
	printf("\n");
	return 0;
}
