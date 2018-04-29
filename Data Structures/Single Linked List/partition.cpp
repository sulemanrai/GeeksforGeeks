#include "iostream"
#include<stdio.h>
// Program to check if linked list is empty or not
using namespace std;

/* Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
Node *newNode(int data);
void printList(struct Node *head);

void append(struct Node * head, int data)
{
		struct Node * temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		//cout << "temp" << temp->data << endl;
		temp->next = newNode(data);

}

// A utility function to create a new node
Node *newNode(int data)
{
	struct Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

Node * concatenateLists(struct Node * head1, struct Node* head2, struct Node* head3)
{
	struct Node * head = NULL;
	if(head1 == NULL && head2 != NULL && head3 != NULL)
	{
		struct Node * temp = head2;
		while (temp->next)
			temp = temp->next;
		temp->next = head3;
		head = temp;
	} else if(head1 != NULL && head2 != NULL && head3 != NULL)
	{
		struct Node * temp = head1;
		while (temp->next)
			temp = temp->next;
		temp->next = head2;
		temp = head2;
		while (temp->next)
			temp = temp->next;
		temp->next = head3;
		head = temp;
	} else if(head1 != NULL && head2 == NULL && head3 != NULL)
	{
		struct Node * temp = head1;
		while (temp->next)
			temp = temp->next;
		temp->next = head3;
		temp = head1;
		head = temp;
		printList(temp);
	} else if(head1 != NULL && head2 != NULL && head3 == NULL)
	{
		struct Node * temp = head1;
		while (temp->next)
			temp = temp->next;
		temp->next = head2;
		head = temp;
	}

	return head;
}
// Function to make two separate lists and return
// head after concatinating
struct Node *partition(struct Node *head, int x)
{

	/* Let us initialize first and last nodes of
	three linked lists
	1) Linked list of values smaller than x.
	2) Linked list of values equal to x.
	3) Linked list of values greater than x.*/
	struct Node *smallerHead = NULL, *smallerLast = NULL;
	struct Node *greaterLast = NULL, *greaterHead = NULL;
	struct Node *equalHead = NULL, *equalLast = NULL;

	// Now iterate original list and connect nodes
	// of appropriate linked lists.
	while (head != NULL)
	{
		// If current node is equal to x, append it
		// to the list of x values
		if (head->data == x)
		{
			if (equalHead == NULL)
				equalHead = equalLast = head;
			else
			{
				equalLast->next = head;
				equalLast = equalLast->next;
			}
		}

		// If current node is less than X, append
		// it to the list of smaller values
		else if (head->data < x)
		{
			if (smallerHead == NULL)
				smallerLast = smallerHead = head;
			else
			{
				smallerLast->next = head;
				smallerLast = head;
			}
		}
		else // Append to the list of greater values
		{
			if (greaterHead == NULL)
				greaterLast = greaterHead = head;
			else
			{
				greaterLast->next = head;
				greaterLast = head;
			}
		}

		head = head->next;
	}

	// Fix end of greater linked list to NULL if this
	// list has some nodes
	if (greaterLast != NULL)
		greaterLast->next = NULL;

	// Connect three lists

	// If smaller list is empty
	if (smallerHead == NULL)
	{
		if (equalHead == NULL)
			return greaterHead;
		equalLast->next = greaterHead;
		return equalHead;
	}

	// If smaller list is not empty
	// and equal list is empty
	if (equalHead == NULL)
	{
		smallerLast->next = greaterHead;
		return smallerHead;
	}

	// If both smaller and equal list
	// are non-empty
	smallerLast->next = equalHead;
	equalLast->next = greaterHead;
	return  smallerHead;
}

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Driver program to run the case
int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(10);
	head->next = newNode(4);
	head->next->next = newNode(5);
	head->next->next->next = newNode(30);
	head->next->next->next->next = newNode(2);
	head->next->next->next->next->next = newNode(50);

	int x = 3;
	head = partition(head, x);
	printList(head);
	return 0;
}
