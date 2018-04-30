// C program to find n'th Node in linked list

// C program to count number of nodes
// in loop in a linked list if loop is
// present
#include<stdio.h>
#include<stdlib.h>
#include "iostream"

using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

// Returns count of nodes present in loop.
int countNodes(struct Node *n)
{
	int count = 1;
	struct Node * tmp = n;

	while(tmp->next != n)
	{
		count++;
		tmp = tmp->next;
	}

	return count;
}

/* This function detects and counts loop
nodes in the list. If loop is not there
in then returns 0 */
int countNodesinLoop(struct Node *list)
{
	struct Node * slowptr = list;
	struct Node * fastptr = list;

	while(slowptr && fastptr && fastptr->next)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;

		if (slowptr == fastptr)
			break;
	}
	return countNodes(slowptr);

}

struct Node *newNode(int key)
{
	struct Node *temp =
		(struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

/* Drier program to test above function*/
int main()
{
	struct Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* Create a loop for testing */
	head->next->next->next->next->next = head->next;

	printf("%d \n", countNodesinLoop(head));

	return 0;
}
