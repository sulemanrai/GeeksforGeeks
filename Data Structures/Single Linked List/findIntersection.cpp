#include <iostream>
#include <algorithm>
#include<stdio.h>

using namespace std;
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node)
{
	while (node != NULL) {
		cout << node->data << ' ';
		node = node->next;
	}
	printf("");
}
void push(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
struct node* findIntersection(struct node* head1, struct node* head2);
int main()
{
	long test;
	cin >> test;
	while (test--)
	{
		struct node* a = NULL;
		struct node* b = NULL;
		int n, m, tmp;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> tmp;
			push(&a, tmp);
		}
		cin >> m;
		for (int i = 0; i<m; i++)
		{
			cin >> tmp;
			push(&b, tmp);
		}
		printList(findIntersection(a, b));
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node is as
struct node
{
int data;
struct node* next;
};
*/
/* function to insert a new_node in a list. Note that this
function expects a pointer to head_ref as this can modify the
head of the input linked list (similar to push())*/
void sortedInsert(struct node** head_ref, struct node* new_node)
{
	struct node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->next != NULL &&
			current->next->data < new_node->data)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
// function to sort a singly linked list using insertion sort
void insertionSort(struct node **head_ref)
{
	// Initialize sorted linked list
	struct node *sorted = NULL;

	// Traverse the given linked list and insert every
	// node to sorted
	struct node *current = *head_ref;
	while (current != NULL)
	{
		// Store next for next iteration
		struct node *next = current->next;

		// insert current in sorted linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted linked list
	*head_ref = sorted;
}

void push_back(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
//	new_node->data = new_data;
//	new_node->next = (*head_ref);
//	(*head_ref) = new_node;
	new_node->data = new_data;
	struct node * tail = *head_ref;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new_node;
	new_node->next = NULL;
}

int countFreq(struct node* head, int data)
{
	int count = 0;
	struct node* temp = head;

	while(temp != NULL)
	{
		if (temp->data == data)
		{
			count++;
		}
		temp = temp->next;
	}
	return count;
}

struct node* findIntersection(struct node* head1, struct node* head2)
{
	// code here
	struct node * tmp1 = head1;
	struct node * tmp2 = head2;
	bool intersection = false;
	struct node * list = NULL;
	int i = 0;
	while (tmp1 != NULL)
	{
		while (tmp2 != NULL)
		{
			//printf("tmp1 %i tmp2 %i \n", tmp1->data, tmp2->data);
			if (tmp1->data == tmp2->data && list == NULL)
			{
				//push(&list, tmp1->data);
				intersection = true;
			}
			else if (tmp1->data == tmp2->data && list != NULL)
			{
				struct node * tmp = list;
				//push(&list, tmp1->data);
				intersection = true;
			}
			tmp2 = tmp2->next;
		}
		if (intersection == true)
		{
			//struct node * tmp = list;
			push(&list, tmp1->data);
			intersection = false;
		}
		tmp1 = tmp1->next;
		tmp2 = head2;
		insertionSort(&list);
	}

	return list;
}
