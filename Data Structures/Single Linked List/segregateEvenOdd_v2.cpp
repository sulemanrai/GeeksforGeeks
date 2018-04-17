// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* a node of the singly linked list */
struct Node
{
	int data;
	struct Node *next;
};
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);
void reverseUtil(Node *curr, Node *prev, Node **head);

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(Node **head)
{
	if (*head == NULL)
		return;
	reverseUtil(*head, NULL, head);
}

// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(Node *curr, Node *prev, Node **head)
{
	if (*head == NULL)
	{
		return;
	}

	if (curr->next == NULL)
	{
		*head = curr;
		return;
	}


	reverseUtil(curr->next, prev, head);
	prev = curr;
	curr = curr->next;
	curr->next = prev;
	prev->next = NULL;
}



void segregateEvenOdd(struct Node **head_ref)
{

	struct Node* evenTemp = *head_ref;
	struct Node* oddTemp = *head_ref;
	struct Node* evenList = NULL;
	struct Node* oddList = NULL;

	while(evenTemp != NULL && oddTemp != NULL)
	{
		if (evenTemp->data % 2 == 0) {
			push(&evenList, evenTemp->data);
		} else if (oddTemp->data % 2 != 0)
		{
			push(&oddList, evenTemp->data);
		}
		evenTemp = evenTemp->next;
		oddTemp = oddTemp->next;
	}

	if (evenList == NULL)
		return;

	if (oddList == NULL)
		return;


	reverse(&oddList);
	reverse(&evenList);

	*head_ref = evenList;
	evenTemp = evenList;

	while(evenTemp->next != NULL)
	{
		evenTemp = evenTemp->next;
	}


	evenTemp->next = oddList;

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

/* Drier program to test above functions*/
int main()
{
	int TestCases;

	cin >> TestCases;

	while(TestCases --)
	{
		int N;
		cin >> N;

		/* Start with the empty list */
		struct Node* head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			//cout << "data" <<data <<endl;
			push(&head, data);
		}
		reverse(&head);
		//printList(head);
		segregateEvenOdd(&head);
		printList(head);
		cout << endl;
	}
	return 0;
}
