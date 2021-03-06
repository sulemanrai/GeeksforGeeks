#include<stdio.h>
#include<stdlib.h>
#include "iostream"

using namespace std;

/* Link list Node */

using namespace std;

/* Link list node */
struct Node
{
	int data;
	Node* next, *arbit;
};

/* Function to reverse the linked list */
Node* reverse(Node *head)
{
	Node *prev = NULL, *current = head, *next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

// This function populates arbit pointer in every
// node to the greatest value to its right.
Node* populateArbit(Node *head)
{
	/* 1). Reverse the Linked list*/
	head = reverse(head);

	/* 2). Start traversing linked list and store
	 *     maximum value node encountered so far.
	 *     Make arbit of every node to point to max.
	 *     If the data in current node is more than
	 *     max node so far, update max.*/

	Node * max = head;
	Node * tmp = head;

	while(tmp != NULL)
	{

		if(tmp == head)
		{
			tmp->arbit = NULL;
		} else
		{
			tmp->arbit = max;
		}
		if (tmp->data > max->data)
		{
			max = tmp;
		}
		tmp = tmp->next;
	}
	head = reverse(head);
	return head;
}

// Utility function to print result linked list
void printNextArbitPointers(Node *node)
{
	printf("Node\tNext Pointer\tArbit Pointer\n");
	while (node != NULL)
	{
		cout << node->data << "\t\t";

		if (node->next)
			cout << node->next->data << "\t\t";
		else cout << "NULL" << "\t\t";

		if (node->arbit)
			cout << node->arbit->data;
		else cout << "NULL";

		cout << endl;
		node = node->next;
	}
}

/* Function to create a new node with given data */
Node *newNode(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Driver program to test above functions*/
int main()
{
	Node *head = newNode(5);
	head->next = newNode(10);
	head->next->next = newNode(2);
	head->next->next->next = newNode(3);

	head = populateArbit(head);

	printf("Resultant Linked List is: \n");
	printNextArbitPointers(head);

	return 0;
}
