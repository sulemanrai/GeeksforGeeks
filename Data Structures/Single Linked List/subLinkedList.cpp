#include<iostream>
#include <cstdlib>
using namespace std;
#include<stdio.h>
#include<iostream>
	using namespace std;
	/* Linked list Node */
	struct Node
	{
		int data;
		struct Node* next;
	};
Node *reverse(Node **r)
{
		Node *prev = NULL;
		Node *cur = *r;
		Node *nxt;
		while (cur != NULL)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		*r = prev;
		return *r;
}
	/* Function to create a new Node with given data */
	struct Node *newNode(int data)
	{
		struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
		new_Node->data = data;
		new_Node->next = NULL;
		return new_Node;
	}
	struct Node* addTwoLists(struct Node* first, struct Node* second);
	/* Function to insert a Node at the beginning of the Doubly Linked List */
	void push(struct Node** head_ref, int new_data)
	{
		/* allocate Node */
		struct Node* new_Node = newNode(new_data);
		/* link the old list off the new Node */
		new_Node->next = (*head_ref);
		/* move the head to point to the new Node */
		(*head_ref) = new_Node;
	}
	void printList(struct  Node *Node)
	{
		while (Node != NULL)
		{
			printf("%d ", Node->data);
			Node = Node->next;
		}
		printf("\n");
	}
	Node* subLinkedList(Node* l1, Node* l2);
	/* Driver program to test above function */
	int main(void)
	{
		int t, n, m, i, x;
		cin >> t;
		while (t--)
		{
			struct Node* res = NULL;
			struct Node* first = NULL;
			struct Node* second = NULL;
			cin >> n;
			for (i = 0; i<n; i++)
			{
				cin >> x;
				push(&first, x);
			}
			cin >> m;
			for (i = 0; i<m; i++)
			{
				cin >> x;
				push(&second, x);
			}
			reverse(&first);
			reverse(&second);
			res = subLinkedList(first, second);
			printList(res);
		}
		return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of linked list Node
struct Node
{
int data;
struct Node* next;
};
*/
/*You are required to complete this method*/

void swapPointers(Node** head1, Node** head2)
{
	struct Node * temp = NULL;
	temp = *head1;
	*head1 = *head2;
	*head2 = temp;

}

int getSize(Node * head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

Node *SUBLinkedList(Node* l1,Node* l2, int* borrow)
{

	//swapPointers(&l1, &l2);

	if (l1 == NULL && l2 == NULL)
		return NULL;

	struct Node * result = (struct Node*) malloc(sizeof(struct Node));
	result = SUBLinkedList(l1->next, l2->next, borrow);

	if (l1->data < l2->data && *borrow == 0)
	{
		int subtraction = (10 + l1->data) - l2->data;
		if(subtraction % 10 == 0)
		{
			subtraction = subtraction - 1;
		}
		push(&result, subtraction);
		*borrow = 1;
	} else if(l1->data > l2->data)
	{
		if (*borrow == 1)
		{
			l1->data = l1->data - 1;
		}
		int subtraction = (l1->data - l2->data);
		push(&result, subtraction);
		*borrow = 0;
	} else if(l1->data == l2->data && *borrow == 0)
	{
		push(&result, 0);
	}
	else if (l1->data == l2->data && *borrow == 1)
	{
		int subtraction = (10 + l1->data) - l2->data;
		if (subtraction % 10 == 0)
		{
			subtraction = subtraction - 1;
		}
		push(&result, subtraction);
		//push(&result, 0);
	} else if(l1->data < l2->data && *borrow == 1)
	{
		int subtraction = (10 + l1->data - 1) - l2->data;
		if (subtraction % 10 == 0)
		push(&result, subtraction);
		*borrow = 1;
	}

	return result;
}

Node* subLinkedList(Node* l1, Node* l2)
{
	if (getSize(l2) < getSize(l1))
	{
		int diff = getSize(l1) - getSize(l2);

		for (int i = 0; i < diff; i++)
		{
			push(&l2, 0);
		}
	}
	else if (getSize(l1) < getSize(l2))
	{
		swapPointers(&l1, &l2);
		int diff = getSize(l1) - getSize(l2);

		for (int i = 0; i < diff; i++)
		{
			push(&l2, 0);
		}
	}
	//printList(l1);
	//printList(l2);
	//Your code here
	int  borrow = 0;
	struct Node * result = NULL;
	result = SUBLinkedList(l1, l2, &borrow);
	//printList(result);

	return result;
}
