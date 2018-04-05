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
void push_front(struct Node **head_ref, int data)
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

/* Function to insert a node at the end of a Circular linked list */
void push_back(struct Node **head_ref, int data)
{
	struct Node* current = *head_ref;
	struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode;

	if (*head_ref == NULL)
	{
		*head_ref = newNode;
	}

	else
	{
		while (current->next != *head_ref)
		{
			current = current->next;
		}

		current->next = newNode;
		newNode->next = *head_ref;
	}

}

/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head)
{
	struct Node * current = head;

	if (head != NULL)
	{
		do
		{
			printf("%i ", current->data);
			current = current->next;
		} while (current != head);
	}
	printf("\n");
}
/* function to insert a new_node in a list in sorted way.
Note that this function expects a pointer to head node
as this can modify the head of the input linked list */
void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	/*If list is empty create new node*/
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		new_node->next = new_node;
		return;
	}

	struct Node * prev = NULL;
	struct Node * head = *head_ref;
	struct Node * current = *head_ref;
	struct Node * tail = *head_ref;

	while(tail->next != head)
	{
		tail = tail->next;
	}

	if( new_node->data < head->data)
	{
		push_front(head_ref, new_node->data);

	} else if(new_node->data > tail->data)
	{
		push_back(head_ref, new_node->data);
	} else
	{
		while(current->next != head)
		{
			prev = current;
			current = current->next;

			if(new_node->data > prev->data && new_node->data < current->data)
			{
				prev->next = new_node;
				new_node->next = current;
				break;
			}
		}
	}




}

int main()
{
	int arr[] = { 12, 56, 2, 11, 1, 90 , 54};
	int list_size, i;

	/* start with empty linked list */
	struct Node *start = NULL;
	struct Node *temp;
	struct Node *temp1;
	struct Node *temp2;

	/* Create linked list from the array arr[].
	Created linked list will be 1->2->11->12->56->90 */
	for (i = 0; i< 7; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = arr[i];
		sortedInsert(&start, temp);

	}
	printList(start);

	return 0;
}
