#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct node
{
	int data;
	struct node* next;
};
void append(struct node** headRef, int newData)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
		*headRef = new_node;
		return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}
void printList(struct node *node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef);
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	while (test--)
	{
		struct node* head = NULL;
		struct node* a = NULL;
		struct node* b = NULL;
		int n, k;
		cin >> n;
		while (n--)
		{
			cin >> k;
			append(&head, k);
		}
		alternatingSplitList(head, &a, &b);
		printList(a);
		printList(b);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of node is as
struct node
{
int data;
struct node* next;
};
*/
void alternatingSplitList(struct node* headRef, struct node** aRef, struct node** bRef)
{
	// Code here
	struct node * prev = headRef;
	struct node * curr = headRef->next;

	while(prev != NULL)
	{
		//printf("prev %i \n", prev->data);
		append(aRef, prev->data);

		if (prev->next == NULL)
			break;

		prev = prev->next->next;
	}

	while (curr != NULL)
	{
		//printf("prev %i \n", curr->data);
		append(bRef, curr->data);

		if (curr->next == NULL)
			break;

		curr = curr->next->next;
	}

}
