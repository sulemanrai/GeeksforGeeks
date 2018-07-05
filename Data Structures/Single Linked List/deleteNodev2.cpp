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
struct Node* deleteNode(struct Node *head, int);
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
	// TO BE REMOVED
	for (int i = 0; i<2000; i++);
	cin >> T;
	while (T--) {
		struct Node *head = NULL, *tail = NULL;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}
		int kk;
		cin >> kk;
		head = deleteNode(head, kk);
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
Node* next;
};*/
/*You are required to complete below method*/

int getSize(Node *head)
{
	struct Node * temp = head;
	int count = 0;

	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

Node* deleteNode(Node *head, int x)
{
	//Your code here
	int index = x;





	//cout << "Size " << getSize(head) << endl;

	/*Delete Head*/
	if(index == 1)
	{
		struct Node * curr = head;
		head = curr->next;
		free(curr);
	}
	/*Delete Last Node*/
	else if(index == getSize(head))
	{
		struct Node * temp = head;
		struct Node * prev = NULL;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
	}
	/*Delete intermediate Node*/
	else
	{
		struct Node * prev = NULL;
		struct Node * curr = head;
		int count = 1;

		while(count != index)
		{
			prev = curr;
			curr = prev->next;
			count++;
		}
		prev->next = curr->next;
		free(curr);
	}
	return head;
}
