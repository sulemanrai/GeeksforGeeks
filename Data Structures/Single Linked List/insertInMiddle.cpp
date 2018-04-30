#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* next;
};
// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
		(*tail_ref)->next = new_node;
	*tail_ref = new_node;
}
Node* insertInMiddle(Node* head, int x);
int main()
{
	int n, k, T, l, x;
	cin >> T;
	while (T--)
	{
		struct Node *head = NULL, *tail = NULL;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}
		cin >> x;
		head = insertInMiddle(head, x);
		display(head);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the Node of the linked list is as
struct Node {
int data;
Node* next;
};
*/
// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	struct Node* new_node = new Node;
	new_node->data = x;
	new_node->next = NULL;

	struct Node * prev = NULL;
	struct Node * slowptr = head;
	struct Node * fastptr = head;
	int i = 0;

	while(slowptr != NULL && fastptr != NULL)
	{
		if(i == 0)
		{
			prev = slowptr;
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			i = 1;
		} else if(i == 1)
		{
			fastptr = fastptr->next;
			i = 0;
		}
	}
	prev->next = new_node;
	new_node->next = slowptr;

	return head;
}
