// C program to find n'th Node in linked list
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
struct Node* SortedMerge(struct Node* a, struct Node* b);
void MoveNode(struct Node** destRef, struct Node** sourceRef);
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
/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}
/* Driver program to test above function*/
int main()
{
	int T, i, n1, n2, l, k;
	cin >> T;
	while (T--)
	{
		struct Node *head1 = NULL, *tail1 = NULL;
		struct Node *head2 = NULL, *tail2 = NULL;
		cin >> n1 >> n2;
		for (i = 1; i <= n1; i++)
		{
			cin >> l;
			append(&head1, &tail1, l);
		}
		for (i = 1; i <= n2; i++)
		{
			cin >> l;
			append(&head2, &tail2, l);
		}
		Node *head = SortedMerge(head1, head2);
		printList(head);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node {
int data;
Node* next;
}; */
Node* SortedMerge(Node* head1, Node* head2)
{
	// Your Code Here
	struct Node * list1 = head1;
	struct Node * list2 = head2;

	struct Node * sorting = NULL;
	struct Node * new_head = NULL;

	if(list1->data < list2->data)
	{
		sorting = list1;
		list1 = sorting->next;
	} else
	{
		sorting = list2;
		list2 = sorting->next;
	}
	new_head = sorting;
	while(list1 && list2)
	{
		if(list1->data < list2->data)
		{
			sorting->next = list1;
			sorting = list1;
			list1 = sorting->next;
		} else if(list2->data < list1->data)
		{
			sorting->next = list2;
			sorting = list2;
			list2 = sorting->next;
		}
	}

	if(list1 == NULL)
	{
		sorting->next = list2;
	}

	if(list2 == NULL)
	{
		sorting->next = list1;
	}
	return new_head;
}
