#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;
/* A linked list node */
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
void linkdelete(struct node  *head, int M, int N);
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");

}
void insert(int n1)
{
	int n, value, i;
	//scanf_s("%d",&n);
	n = n1;
	struct node *temp = NULL;
	for (i = 0; i<n; i++)
	{
		scanf("%d", &value);
		if (i == 0)
		{
			start = (struct node *) malloc(sizeof(struct node));
			start->data = value;
			start->next = NULL;
			temp = start;
			continue;
		}
		else
		{
			temp->next = (struct node *) malloc(sizeof(struct node));
			temp = temp->next;
			temp->data = value;
			temp->next = NULL;
		}
	}
}
int main()
{

	int m, n;

	int t, n1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n1);
		scanf("%d", &m);
		scanf("%d", &n);
		insert(n1);





		linkdelete(start, m, n);


		printList(start);
	}

	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
delete n nodes after m nodes
The input list will have at least one element
Node is defined as
struct node
{
int data;
struct node *next;
}
*/
void linkdelete(struct node  *head, int M, int N)
{
	struct node *current = head;

	int count;

	// The main loop that traverses through the whole list
	while (current != NULL)
	{
		// Skip M nodes
		int i = 1;
		while (i != M && current != NULL)
		{
			current = current->next;
			i++;
		}

		// If we reached end of list, then return
		if (current == NULL)
			return;

		// Start from next node and delete N nodes
		struct node * prev = current->next;
		int j = 0;
		while(j != N && prev != NULL)
		{
			struct node *next = prev;
			prev = prev->next;
			free(next);
			j++;
		}

		// Link the previous list with remaining nodes
		current->next = prev;

			// Set current pointer for next iteration
		current = prev;
	}
}
