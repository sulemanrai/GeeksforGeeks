#include <iostream>
#include <stdio.h>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;
struct Node
{
		int data;
		struct Node *next;
};
bool areIdentical(struct Node *a, struct Node *b);
void push(struct Node** head_ref, int new_data)
{
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = new_data;
		new_node->next = (*head_ref);
		(*head_ref) = new_node;
	}
	int main()
	{
		int T;
		cin >> T;
		while (T--) {
			int n1, n2, tmp;
			struct Node *a = NULL;
			struct Node *b = NULL;
			cin >> n1;
			while (n1--) {
				cin >> tmp;
				push(&a, tmp);
			}
			cin >> n2;
			while (n2--) {
				cin >> tmp;
				push(&b, tmp);
			}
			areIdentical(a, b) ? cout << "Identical" << endl : cout << "Not identical" << endl;
		}
		return 0;
	}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the linked list is as
struct Node
{
int data;
struct Node *next;
};
*/
// Complete this function
// return true if two list are identical else return false
bool areIdentical(struct Node *head1, struct Node *head2)
{
	// Code here
	struct Node* tmp1 = head1;
	struct Node* tmp2 = head2;
	bool isIdentical = false;

	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1->data != tmp2->data)
		{
			isIdentical = false;
			break;
		} else
		{
			isIdentical = true;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	return isIdentical;
}
