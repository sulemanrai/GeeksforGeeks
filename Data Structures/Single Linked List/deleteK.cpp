#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
Node *deleteK(Node *, int);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL)
		*head_ref = new_node;
	else
		(*tail_ref)->next = new_node;
	*tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);
/* Driver program to test above function*/
int main()
{
	int T, i, n, l;
	cin >> T;
	while (T--) {
		struct Node *head = NULL, *tail = NULL;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> l;
			append(&head, &tail, l);
		}
		int K;
		cin >> K;
		Node *res = deleteK(head, K);
		Node *temp = res;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	return 0;
}
/* Function to get the middle of the linked list*/
/*K will always be in range */

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node
{
int data;
struct Node* next;
};*/
/*You are required to complete this method*/
Node * deleteK(Node *head, int K)
{
	//Your code here
	struct Node * prev = NULL;
	struct Node * ptr = head;
	struct Node * dummy = NULL;

	int count = 0;

	if(K == 1)
	{
		while(ptr)
		{
			struct Node * tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
		return NULL;
	}
	else {

		while (ptr)
		{
			dummy = prev;
			prev = ptr;
			ptr = ptr->next;
			count++;

			if (count == K)
			{
				//cout << "dummy" << dummy->data << endl;
				//cout << " inside prev " << prev->data << " ptr " << ptr->data << endl;
				struct Node * tmp = prev;
				dummy->next = ptr;
				free(tmp);
				//dummy->next = ptr;
				//cout << "prev " << prev->data << endl;
				//cout << "prev " << prev->data << "next" << next->data << endl;
				//cout << " prev " << prev->data << " curr " << curr->data << endl;
				count = 0;
			}
			//cout << " prev " << prev->data << " ptr " << ptr->data << endl;
		}
	}

	return head;
}
