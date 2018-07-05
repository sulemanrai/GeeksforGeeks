#include<stdio.h>
#include<stdlib.h>
#include<cmath>

// Linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Function to get the sqrt(n)th
// node of a linked list
int printsqrtn(struct Node* head)
{
	int size = 0;
	int nodeCount = 0;

	struct Node* tmp = head;
	struct Node * sqrtNode = NULL;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}

	tmp = head;

	while (tmp != NULL)
	{
		nodeCount++;
		if (nodeCount == floor(sqrt(size)))
		{
			sqrtNode = tmp;
			break;
		}
		tmp = tmp->next;
	}

	return sqrtNode->data;
}



void print(struct Node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

// function to add a new node at the
// begining of the list
void push(struct Node** head_ref, int new_data)
{
	// allocate node
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	// put in the data
	new_node->data = new_data;

	// link the old list off the new node
	new_node->next = (*head_ref);

	// move the head to point to the new node
	(*head_ref) = new_node;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	push(&head, 90);
	push(&head, 80);
	push(&head, 70);
	push(&head, 60);
	push(&head, 50);
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);
	printf("Given linked list is:");
	print(head);
	printf("\nsqrt(n)th node is %d \n", printsqrtn(head));

	return 0;
}
