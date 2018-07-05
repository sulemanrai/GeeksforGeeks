#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list and
an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = new_data;
	newNode->next = *head_ref;
	*head_ref = newNode;

}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = new_data;

	struct Node *after_prev = prev_node->next;

	prev_node->next = newNode;
	newNode->next = after_prev;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = new_data;

	struct Node* tail = *head_ref;

	if (*head_ref == NULL)
	{
		*head_ref = newNode;
		newNode->next = NULL;
		return;
	}



	while(tail->next != NULL)
	{
		tail = tail->next;
	}

	tail->next = newNode;
	newNode->next = NULL;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node)
{

	while(node != NULL)
	{
		printf("%i ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL
	push(&head, 7);
//
//	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
	push(&head, 1);
//
//	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
	append(&head, 4);
//
//	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);

	printf("\n Created Linked list is: ");
	printList(head);

	return 0;
}
