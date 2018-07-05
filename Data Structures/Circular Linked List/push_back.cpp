#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

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

int main()
{
	/* Initialize lists as empty */
	struct Node *head = NULL;
	push_back(&head, 1);


	return 0;
}
