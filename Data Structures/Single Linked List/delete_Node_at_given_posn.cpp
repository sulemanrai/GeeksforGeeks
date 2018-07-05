// A complete working C program to demonstrate deletion in singly
// linked list
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
and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position)
{
	struct Node * prev = NULL;
	struct Node * current = *head_ref;
	struct Node * tmp = NULL;

	int count = 1;

	if(position == 1)
	{
		(*head_ref) = (*head_ref)->next;
	}

	while(current->next != NULL)
	{
		count++;
		prev = current;
		current = current->next;
		if(count == position)
		{
			tmp = current;
			//printf("prev %i current %i", prev->data, current->data);
			prev->next = current->next;
			break;
		}

	}

	free(tmp);
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

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 8);

	puts("Created Linked List: ");
	printList(head);
	deleteNode(&head, 4);
	puts("\nLinked List after Deletion at position 4: ");
	printList(head);
	return 0;
}
