#include "iostream"
#include <unordered_set>

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
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;
		struct Node *head = NULL;
		struct Node *temp = head;

		for (int i = 0; i<K; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = newNode(data);
			else
			{
				temp->next = newNode(data);
				temp = temp->next;
			}
		}


		Node *result = removeDuplicates(head);
		print(result);
		cout << endl;

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
Node *removeDuplicates(Node *root)
{
	// your code goes here
	unordered_set<int> set;
	struct Node * previous = NULL;
	struct Node * current = root;
	struct Node * tmp = NULL;
	bool isDuplicate = false;

	while(current != NULL)
	{
		if(isDuplicate == false)
		{
			previous = current;
			current = previous->next;
			set.insert(previous->data);
			isDuplicate = true;
		} else if (isDuplicate == true)
		{
			auto search = set.find(current->data);
			if (search != set.end()) {
				//std::cout << "Found " << (*search) << '\n';
				previous->next = current->next;
				tmp = current;
				//previous = current->next;
				//current = previous->next;
				current = current->next;
				isDuplicate = true;
			} else
			{
				isDuplicate = false;
			}
		}
	}
	return root;
}
