// C program to find n'th Node in linked list
#include "iostream"
#include <cstdlib>

using namespace std;
struct Node {
	int data;
	struct Node* next;
};
void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
		*headRef = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
int sumOfLastN_Nodes(struct Node* head, int n);
// Driver program to test above
int main()
{
	int t;
	cin >> t;
	while (t--) {
		struct Node* head = NULL;
		int n, m, tmp;
		cin >> m >> n;
		while (m--) {
			cin >> tmp;
			append(&head, tmp);
		}
		cout << sumOfLastN_Nodes(head, n) << endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the node of the linled list is as
struct Node {
int data;
struct Node* next;
};*/
// your task is to complete this function
// function should return sum of last n nodes
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void printList(struct Node * head)
{
	struct Node * tmp = head;
	while(tmp)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

int sumOfLastN_Nodes(struct Node* head, int n)
{
	// Code here
	//printList(head);

	reverse(&head);

	//printList(head);

	struct Node * tmp = head;

	int count = 0;
	int sum = 0;
	while(tmp)
	{
		count++;
		sum += tmp->data;
		if (count == n)
			break;
		tmp = tmp->next;
	}

	return sum;
}
