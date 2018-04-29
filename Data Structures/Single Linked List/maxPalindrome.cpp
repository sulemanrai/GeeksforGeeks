#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <algorithm>
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
int maxPalindrome(Node *);
/* Driver program to test above function*/
int main()
{
	int T, n, l;
	cin >> T;
	while (T--)
	{
		struct Node *head = NULL, *tail = NULL;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}

		cout << maxPalindrome(head) << endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The Node is defined
struct Node
{
int data;
Node *next;
} */
/*The function below returns an int denoting
the length of the longest palindrome list. */
int comman(Node* a, Node* b)
{
	int result = 0;

	for(;a != NULL && b != NULL; a = a->next, b = b = b->next)
	{
		if (a->data == b->data) {
			result++;
		}
		else {
			break;
		}
	}
	return result;
}

int maxPalindrome(Node *head)
{
	//Your code here
	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;

	int result = 0;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;

		result = max(result, 2 * comman(curr, next));

		result = max(result, 2 * comman(prev, next) + 1);

		prev = curr;
		curr = next;
	}

	return result;
}
