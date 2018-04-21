#include "iostream"
// C++ program to rearrange a linked list in-place
using namespace std;

// Linked list node
struct Node
{
	int data;
	struct Node *next;
};

Node *mergelist(Node *head1, Node *head2);
Node* pop_front(Node **head);
void splitList(Node *head, Node **Ahead, Node **Dhead);
void reverselist(Node *&head);
void push_back(Node** head);
void append(struct Node** head_ref, int new_data);
void printlist(Node *head);
void sort(Node **head);

// C++ program to sort a linked list that is alternatively
// sorted in increasing and decreasing order



Node* pop_front(Node **head)
{
	struct Node * tmp = *head;
	(*head) = (*head)->next;
	return tmp;
}

// A utility function to create a new node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void append(struct Node** head_ref, int new_data)
{
	cout << "0" << endl;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = new_data;


	struct Node* tail = *head_ref;


	if (*head_ref == NULL)
	{
		cout << "1" << endl;
		//cout << "inside" << endl;
		*head_ref = newNode;
		newNode->next = NULL;
		return;
	}



	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	tail->next = newNode;
	newNode->next = NULL;
}

void push_back(Node **head,Node* temp)
{
	struct Node * tail = *head;
	//cout << temp->data << endl;
	//cout << "inside" << endl;
	if (*head == NULL)
	{
		*head = temp;
		(*head)->next = NULL;
		return;
	}
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = temp;
	temp->next = NULL;
}

// A utility function to reverse a linked list
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

// A utility function to print a linked list
void printlist(Node *head)
{
	struct Node * tmp = head;

	while (tmp != NULL)
	{
		cout << " "<< tmp->data;
		if (tmp->next != NULL)
			cout << " ->";
		tmp = tmp->next;
	}
	cout << endl;
}

// A utility function to merge two sorted linked lists
Node *mergelist(Node *head1, Node *head2)
{
	//printlist(head1);
	//printlist(head2);

	if (head1 == NULL && head2 == NULL)
		return NULL;

	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	Node * tmp1 = head1;
	Node * tmp2 = head2;

	Node* head = NULL;

	if(tmp1->data < tmp2->data)
	{
		head = head1;
		tmp1 = tmp1->next;
	} else if (tmp2->data < tmp1->data)
	{
		head = head2;
		tmp2 = tmp2->next;
	}

	Node * current = head;
	Node * newHead = NULL;
	//cout << "current " << current->data << endl;

	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1->data < tmp2->data)
		{
			current->next = tmp1;
			current = tmp1;
			tmp1 = current->next;
			//tmp1 = tmp1->next;
			//current = current->next;
		} else
		{
			current->next = tmp2;
			current = tmp2;
			tmp2 = current->next;
			//tmp2 = tmp2->next;
			//current = current->next;
		}
	}
	if (tmp1 == NULL)
	{
		current->next = tmp2;
		return head;
	}
	else if (tmp2 == NULL)
	{
		current->next = tmp1;
	//	printlist(head);
		return head;
	}
	//current->next = NULL;

	//printlist(tmp2);
	//printlist(head);
	//return head;
}

// This function alternatively splits a linked list with head
// as head into two:
// For example, 10->20->30->15->40->7 is splitted into 10->30->40
// and 20->15->7
// "Ahead" is reference to head of ascending linked list
// "Dhead" is reference to head of descending linked list
void splitList(Node *head, Node **Ahead, Node **Dhead)
{
	struct Node *AList = *Ahead;
	struct Node *DList = *Dhead;
	struct Node * prev = NULL;
	struct Node * current = head;

	while(current != NULL)
	{
		prev = current;
		current = prev->next;
		if (prev != NULL) {
			Node * tmp = pop_front(&head);
			push_back(&AList, tmp);
		}
		if(current != NULL)
		{
			Node * tmp = pop_front(&head);
			prev = current;
			current = current->next;
			push_back(&DList, tmp);
		}
	}
	(*Ahead) = (*Ahead)->next;
	(*Dhead) = (*Dhead)->next;

	//printlist(AList);
	//printlist(DList);

}

// Linked list node
// This is the main function that sorts the
// linked list
void sort(Node **head)
{
	struct Node *AList = newNode(0);
	struct Node *DList = newNode(0);

	splitList(*head, &AList, &DList);
	reverselist(DList);
	*head = mergelist(AList, DList);
}
// Driver program to test above function
int main()
{
	Node *head = newNode(991);
	head->next = newNode(20);
	head->next->next = newNode(1000);
	head->next->next->next = newNode(19);
	head->next->next->next->next = newNode(1001);
	head->next->next->next->next->next = newNode(1);
	//head->next->next->next->next->next->next = newNode(89);

	cout << "Given Linked List is " << endl;
	printlist(head);

	sort(&head);

	printlist(head);



	return 0;
}
