#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
void push(struct Node ** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << "\n";
}
void mergeList(struct Node **head1, struct Node **head2);
// Driver program to test above functions
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n1, n2, tmp;
		struct Node *a = NULL;
		struct Node *b = NULL;
		cin >> n1;
		while (n1--) {
			cin >> tmp;
			push(&a, tmp);
		}
		cin >> n2;
		while (n2--) {
			cin >> tmp;
			push(&b, tmp);
		}
		mergeList(&a, &b);
		printList(a);
		printList(b);
	}
	return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node of the linked list is
struct Node
{
int data;
struct Node *next;
};
*/
// complete this function

int getSize(struct Node* head)
{
	int count = 0;
	struct Node * temp = head;

	while(temp!= NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
Node * pop_front(struct Node **head)
{
	struct Node * tmp = *head;
	*head = (*head)->next;
	return tmp;
}
void swap(struct Node ** p, struct Node ** q)
{
	struct Node * tmp = *p;
	*p = *q;
	*q = tmp;
}
void mergeList(struct Node **p, struct Node **q)
{
	// Code here

	if (*p == NULL || *q == NULL)
		return;

	struct Node * prev_listA = NULL;
	struct Node * curr_listA = *p;

	struct Node * prev_listB = NULL;
	struct Node * curr_listB = *q;
	struct Node * tmp = NULL;

	while (curr_listA != NULL)
	{
		prev_listA = curr_listA;
		curr_listA = curr_listA->next;
		tmp = pop_front(q);

		prev_listA->next = tmp;
		tmp->next = curr_listA;
		if (getSize(*q) == 0)
			break;
	}
}
