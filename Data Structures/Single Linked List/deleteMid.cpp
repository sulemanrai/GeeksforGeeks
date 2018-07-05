#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
	int new_data)
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
/* Function to get the middle of the linked list*/
struct Node* deleteMid(struct Node *head);
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
/* Driver program to test above function*/
int main()
{
	int T, i, n, l;
	cin >> T;
	while (T--) {
		struct Node *head = NULL, *tail = NULL;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}
		head = deleteMid(head);
		printList(head);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node
{
int data;
struct Node* next;
}; */
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node *head)
{
	// Your Code Here
	struct Node * slowptr = head;
	struct Node * fastptr = head;
	struct Node * prev = NULL;

	int i = 0;
	while(fastptr->next)
	{
		if(i == 0)
		{
			prev = slowptr;
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			i = 1;
		} else if( i == 1)
		{
			fastptr = fastptr->next;;
			i = 0;
		}
	}

	//cout << " slowptr " << slowptr->data << " prev " << prev->data << " fastptr " << fastptr->data << endl;

	/*Delete Node*/
	prev->next = slowptr->next;
	free(slowptr);

	return head;
}
