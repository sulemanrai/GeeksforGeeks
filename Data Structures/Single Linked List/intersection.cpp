#include "iostream"
#include <unordered_set>


using namespace std;
struct Node
{
	int val;
	struct Node *next;
};
void push(struct Node **root, int data)
{
	Node *newnode = new Node();
	struct Node *prev;
	prev = *root;
	newnode->val = data;
	newnode->next = NULL;
	if (*root == NULL)
	{
		*root = newnode;
		return;
	}
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = newnode;
}
void print(struct Node *ptr)
{
	if (ptr == NULL)
	{
		cout << "NO" << endl;
		return;
	}
	while (ptr != NULL)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
void intersection(struct Node **head1, struct Node **head2, struct Node **head3);
int main()
{
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	struct Node *head3 = NULL;
	int t, n1, n2;
	cin >> t;
	while (t--)
	{
		struct Node *head1 = NULL;
		struct Node *head2 = NULL;
		struct Node *head3 = NULL;
		cin >> n1 >> n2;
		int k;
		for (int i = 0; i<n1; i++)
		{
			cin >> k;
			push(&head1, k);
		}
		for (int i = 0; i<n2; i++)
		{
			cin >> k;
			push(&head2, k);

		}

		intersection(&head1, &head2, &head3);
		print(head3);

	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the Linked list Node is as follows:
struct Node {
int val;
struct Node* next;
}; */

int ListSize(Node **head)
{
	int size = 0;
	struct Node * temp = *head;

	while(temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}


Node *removeDuplicates(Node *root)
{
	// your code goes here
	unordered_set<int> set;
	struct Node * previous = NULL;
	struct Node * current = root;
	struct Node * tmp = NULL;
	bool isDuplicate = false;

	while (current != NULL)
	{
		if (isDuplicate == false)
		{
			previous = current;
			current = previous->next;
			set.insert(previous->val);
			isDuplicate = true;
		}
		else if (isDuplicate == true)
		{
			auto search = set.find(current->val);
			if (search != set.end()) {
				//std::cout << "Found " << (*search) << '\n';
				previous->next = current->next;
				tmp = current;
				//previous = current->next;
				//current = previous->next;
				current = current->next;
				isDuplicate = true;
			}
			else
			{
				isDuplicate = false;
			}
		}
	}
	return root;
}

void intersection(Node **head1, Node **head2, Node **head3)
{
	// Your Code Here
	int List1Size = ListSize(head1);
	int List2Size = ListSize(head2);

	struct Node* tmp1 = *head1;
	struct Node* tmp2 = *head2;

	if (head1 == NULL && head2 == NULL)
		return;
	if (head1 == NULL && head2 != NULL)
	{
		*head3 = *head2;
		return;
	} else if (head2 == NULL && head1 != NULL)
	{
		*head3 = *head1;
		return;
	} else if(head2 != NULL && head1 != NULL)
	{
		if(List1Size >= List2Size)
		{

			while(tmp1 != NULL)
			{
				while(tmp2 != NULL)
				{
					if(tmp1->val == tmp2->val)
					{
						push(head3, tmp1->val);
					}

					tmp2 = tmp2->next;
				}
				tmp2 = *head2;
				tmp1 = tmp1->next;
			}
		} else if(List2Size >= List1Size)
		{
			while (tmp2 != NULL)
			{
				while (tmp1 != NULL)
				{
					//printf("tmp1 %i tmp2 %i\n",tmp1->val,tmp2->val);
					if (tmp2->val == tmp1->val)
					{
						push(head3, tmp2->val);
					}

					tmp1 = tmp1->next;
				}
				tmp1 = *head1;
				tmp2 = tmp2->next;
			}
		}
	}

	*head3 = removeDuplicates(*head3);
}
