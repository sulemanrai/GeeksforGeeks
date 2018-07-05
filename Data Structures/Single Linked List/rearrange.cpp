#include<iostream>
using namespace std;

/* function prototypes */
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
	struct Node** frontRef, struct Node** backRef);
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef);

struct Node
{
	int data;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to the head of a list and
an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = new_data;
	newNode->next = *head_ref;
	*head_ref = newNode;

}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct Node* source,
	struct Node** frontRef, struct Node** backRef)
{
	struct Node * slowptr = source;
	struct Node * fastptr = source;

	int i = 0;
	while (fastptr->next != NULL)
	{
		if (i == 0)
		{
			fastptr = fastptr->next;
			i = 1;
		}
		else if (i == 1)
		{
			slowptr = slowptr->next;
			fastptr = fastptr->next;
			i = 0;
		}
	}
	*backRef = slowptr->next;
	*frontRef = source;
	slowptr->next = NULL;

}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

void reverselist(Node *&head)
{

	Node* prev = NULL, *curr = head, *next;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct Node** headRef)
{
	/* If head is NULL or there is only one element in the Linked List
	then return.*/
	if (*headRef == NULL || (*headRef)->next == NULL)
	{
		return;
	}
	else
	{
		/*Else divide the linked list into two halves.
		FrontBackSplit(head, &a, &b); /* a and b are two halves */

		struct Node* a = (struct Node*) malloc(sizeof(struct Node));;;
		struct Node* b = (struct Node*) malloc(sizeof(struct Node));;;

		FrontBackSplit(*headRef, &a, &b);
		MergeSort(&a);
		MergeSort(&b);

		*headRef = SortedMerge(a, b);
	}

}

void printList(struct Node *node)
{

	while (node != NULL)
	{
		printf("%i ", node->data);
		node = node->next;
	}
	printf("\n");
}

Node* pop_back(struct Node * head)
{
	struct Node * prev = NULL;
	struct Node * curr = head;

	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	struct Node * temp = curr;
	prev->next = NULL;

	return temp;
}

void rearrange(struct Node * head)
{
	//cout << "lastelement " << lastelement->data << endl;
	struct Node * prev = NULL;
	struct Node * curr = head;

	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
		Node * lastelement = pop_back(head);
		prev->next = lastelement;
		if (curr != lastelement) {
			lastelement->next = curr;
		}
	}
}

int main()
{
	//code
	int test_cases;
	int number_of_elements;
	int element;

	cin >> test_cases;


	while(test_cases != 0)
	{
		cin >> number_of_elements;
		struct Node * head = NULL;
		for(int i = 0; i < number_of_elements; i++)
		{
			cin >> element;
			push(&head, element);
		}
		reverselist(head);
		//printList(head);
		MergeSort(&head);
		rearrange(head);
		printList(head);
		test_cases--;
	}


	return 0;
}
