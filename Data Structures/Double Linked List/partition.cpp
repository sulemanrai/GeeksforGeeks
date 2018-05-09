#include "iostream"
#include <stdio.h>
#include <stdlib.h>

/* a node of the doubly linked list */
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node* partition(struct node *l, struct  node *h);
struct node *lastNode(struct node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
void swap(int* a, int* b)
{
	int t = *a;      *a = *b;       *b = t;
}

void _quickSort(struct node* l, struct node *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		struct node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}

void quickSort(struct node *head)
{
	// Find last node
	struct node *h = lastNode(head);

	// Call the recursive QuickSort
	_quickSort(head, h);
}
// A utility function to print contents of arr
void printList(struct node *head)
{
	while (head)
	{
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("");
}
struct node* newNode(int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;

}


/* Driver program to test above function */
int main()
{
	int t, x, n, i;
	scanf("%d", &t);
	while (t--)
	{
		/* Start with the empty list */
		struct node *p, *temp, *head = NULL;
		scanf("%d", &n);
		scanf("%d", &x);
		head = newNode(x);
		p = head;
		for (i = 0; i<n - 1; i++) {
			scanf("%d", &x);
			/* Let us create the doubly linked list 10<->8<->4<->2 */
			temp = newNode(x);
			p->next = temp;
			temp->prev = p;
			p = p->next;
		}
		//printList(head);
		/* delete nodes from the doubly linked list */

		quickSort(head);
		/* Modified linked list will be NULL<-8->NULL */
		printList(head);
		while (head->next != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		free(head);
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* a node of the doubly linked list */
/*struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node *lastNode(struct node *root)
{
while (root && root->next)
root = root->next;
return root;
}
void _quickSort(struct node* l, struct node *h)
{
if (h != NULL && l != h && l != h->next)
{
struct node *p = partition(l, h);
_quickSort(l, p->prev);
_quickSort(p->next, h);
}
}

void quickSort(struct node *head)
{
// Find last node
struct node *h = lastNode(head);

// Call the recursive QuickSort
_quickSort(head, h);
}*/
struct node* partition(node *l, node *h)
{
	//Your code goes here
	int x = h->data;
	node * i = l->prev;

	for (node * j = l; j != h; j = j->next)
	{
		if (j->data <= x)
		{
			//i++;
			i = (i == NULL) ? l : i->next;
			swap(&i->data, &j->data);
		}
	}
	i = (i == NULL) ? l : i->next;
	swap(&i->data, &h->data);

	return i;
}
