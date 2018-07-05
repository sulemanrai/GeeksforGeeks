#include<stdio.h>
#include<stdlib.h>

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

	if (!newNode)
	{
		printf("Memory Error");
		return;
	}

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

		newNode->next = *head_ref;
		current->next = newNode;
		*head_ref = newNode;
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

void deleteFirstNode(struct Node **head)
{
	struct Node * temp = *head;
	struct Node * current = *head;

	if (*head == NULL)
		return;

	if(temp->next == *head)
	{
		*head = NULL;
		free(*head);
	}
	else
	{

		while (temp->next != *head)
		{
			temp = temp->next;
		}


		current = current->next;
		temp->next = current;

		//printf("%i \n\n", current->data);
		temp = *head;
		*head = current;

		//printf("%i ", temp->data);
		free(temp);
	}
}

int main()
{
	/* Initialize lists as empty */
	struct Node *head = NULL;
	push_front(&head, 12);
	push_front(&head, 56);
	push_front(&head, 2);
	push_front(&head, 11);

    printList(head);

    deleteFirstNode(&head);

    printList(head);

	return 0;
}
