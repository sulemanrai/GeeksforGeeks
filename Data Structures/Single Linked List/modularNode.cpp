#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

// C++ program to find modular node in a linked list
/* Linked list node */
struct Node {
	int data;
	Node* next;
};

/* Function to create a new node with given data */
Node* newNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to find modular node in the linked list */
Node* modularNode(Node* head, int k)
{
	Node * prev = NULL;
	Node * current = head;
	Node * modularNode = NULL;

	int count = 0;

	while(current != NULL)
	{
		count++;
		if(count % k == 0 )
		{
			modularNode = current;
		}
		current = current->next;
	}
	return modularNode;
}

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(7);
	int k = 3;
	Node* answer = modularNode(head, k);
	printf("\nModular node is ");
	if (answer != NULL)
		printf("%d\n", answer->data);
	else
		printf("null\n");
    return 0;
}
