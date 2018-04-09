#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node *head_ref, int key)
{
	struct Node * previous = NULL;
	struct Node * current = head_ref;
	struct Node *tmp = NULL;

	if (current->data == key)
	{
		*head_ref = *head_ref->next;
		return;
	}


	while(current->next != NULL)
	{
		previous = current;
		current = current->next;
		if(current->data == key)
		{
			tmp = current;
			previous->next = current->next;
			break;
		}

	}

	if (tmp != NULL)
	{
		free(tmp);
	}

}


// This function prints contents of linked list starting from
// the given node
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 9);
	push(&head, 3);
	push(&head, 6);
	push(&head, 1);

	puts("Created Linked List: ");
	printList(head);
	deleteNode(head, 6);
	puts("\nLinked List after Deletion of 1: ");
	printList(head);
	return 0;
}
