#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

 Node *zigZack(Node* head);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
		Node *ans = zigZack(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
int size(Node *head)
{
	struct Node* tmp = head;
	int count = 0;

	while(tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}

	return count;
}
Node *zigZack(Node* head)
{
 // your code goes here
 	struct Node * tmp = head;
	struct Node * Next = tmp->next;
	// Flag true indicates relation "<" is expected,
	// else ">" is expected.  The first expected relation
	// is "<"
	bool flag = true;

	while(tmp != NULL && Next != NULL)
	{
		if (flag) /* "<" relation expected */
		{
			/* If we have a situation like A > B > C,
			we get A > B < C by swapping B and C */
			if (tmp->data > Next->data)
			{
				int var = tmp->data;
				tmp->data = Next->data;
				Next->data = var;
			}
		}
			else /* ">" relation expected */
			{
				/* If we have a situation like A < B < C,
				we get A < C > B by swapping B and C */
				if (tmp->data < Next->data)
				{
					int var = tmp->data;
					tmp->data = Next->data;
					Next->data = var;
				}
			}

		flag = !flag; /* flip flag */
		tmp = tmp->next;
		Next = Next->next;
	}
	return head;
}
