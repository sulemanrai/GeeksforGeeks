#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};
void printList(struct Node *node);

/* Reverses alternate k nodes and
returns the pointer to the new head node */
struct Node *kAltReverse(struct Node *head, int k)
{
	struct Node* current = head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	struct Node * tmp = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	//printf("current %i previous %i next %i\n", current->data, prev->data, next->data);
	if (head != NULL)
		head->next = current;
		//head = head->next;


	count = 0;
	while(current != NULL && count < k -1)
	{
		//printf("current %i\n", tmp->data);
		current = current->next;
		count++;
	}


	if (current != NULL)
	{
		current->next = kAltReverse(current->next, k);
	}


	return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
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

/* Function to print linked list */
void printList(struct Node *node)
{
	int count = 0;
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
		count++;
	}
	printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct Node* head = NULL;
	int i;
	// create a list 1->2->3->4->5...... ->20
	for (i = 20; i > 0; i--)
		push(&head, i);

	printf("\n Given linked list \n");
	printList(head);
	head = kAltReverse(head, 3);

	printf("\n Modified Linked list \n");
	printList(head);

	getchar();
	return(0);
}
