#include<stdio.h>
#include "iostream"
#include <cmath>
using namespace std;
// C++ program to find fractional node in a linked list


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


/* Function to find fractional node in the linked list */
Node* fractionalNodes(Node* head, int k)
{
	int size = 0;
	int nodeCount = 0;

	struct Node* tmp = head;
	struct Node * FractionalNode = tmp;

	while(tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	float fractionalNode = (float) size / k;
    tmp = head;

	while(tmp != NULL)
	{
		nodeCount++;
		if(nodeCount == ceil(fractionalNode))
		{
			FractionalNode = tmp;
			break;
		}
		tmp = tmp->next;
	}

	return FractionalNode;
}

// A utility function to print a linked list
void printList(Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}


int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	int k = 4;

	printf("List is ");
	printList(head);

	Node* answer = fractionalNodes(head, k);
	printf("\nFractional node is ");
	printf("%d\n", answer->data);

    return 0;
}
