#include<stdio.h>
#include<stdlib.h>
#include <iostream>

/* structure for a node */
struct Node
{
	int data;
	struct Node *next;
};

// Utility function to create a new node.
Node *newNode(int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}


/* This function returns true if given linked
list is circular, else false. */
bool isCircular(struct Node *head)
{
	struct Node * current = head;
	bool isCircular;

	while(true)
	{
		current = current->next;

		if(current == NULL)
		{
			isCircular = false;
			break;
		} else if (current->next == head)
		{
			isCircular = true;
			break;
		}
	}

	return isCircular;
}

int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	isCircular(head) ? std::cout << "Yes\n" : std::cout << "No\n";

	// Making linked list circular
	head->next->next->next->next = head;

	isCircular(head) ? std::cout << "Yes\n" : std::cout << "No\n";

	return 0;
}
