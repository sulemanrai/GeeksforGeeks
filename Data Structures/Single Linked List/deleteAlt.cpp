#include <cstdlib>
#include "iostream"


using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
void deleteAlt(struct Node *head);
/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;  /* used in step 5*/

									/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so make next
	of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}
void printList(struct Node *node)
{
	while (node != NULL)
	{
		cout << node->data << ' ';
		node = node->next;
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, tmp;
		struct Node* head = NULL;
		cin >> n;
		while (n--) {
			cin >> tmp;
			append(&head, tmp);
		}
		deleteAlt(head);
		printList(head);
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the binary tree
struct Node
{
int data;
struct Node *next;
};
*/
// Complete this function
void deleteAlt(struct Node *head) {
	// Code here

	struct Node * prev = NULL;
	struct Node * current = head;
	struct Node * tmp = NULL;


	if (head == NULL || head->next == NULL)
		return;

	while (current != NULL )
	{

		prev = current;
		current = prev->next->next;


		tmp = prev->next;
		//free(tmp);
		prev->next = current;

		//printf("prev %i current %i\n", prev->data, current->data);
		if (current->next == NULL || current->next->next == NULL)
		{
			//cout << "i am here" << endl;
			current->next = NULL;
			break;
		}
			//break;
	}

}
