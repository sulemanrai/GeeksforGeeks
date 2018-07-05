{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 struct Node* addTwoLists (struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {
        temp=Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
//if(res)
//freeList(res);
   }
   return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void push_back(struct Node** head_ref, int new_data)
{
	struct Node* new_Node = newNode(new_data);
	struct Node * tail = *head_ref;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new_Node;
	new_Node->next = NULL;
}

void reverseUtil(Node *curr, Node *prev, Node **head)
{
	if (*head == NULL)
	{
		return;
	}

	if (curr->next == NULL)
	{
		*head = curr;
		return;
	}


	reverseUtil(curr->next, prev, head);
	prev = curr;
	curr = curr->next;
	curr->next = prev;
	prev->next = NULL;
}

void reverse(Node **head)
{
	if (*head == NULL)
		return;
	reverseUtil(*head, NULL, head);
}

int Size(Node * head)
{
	int size = 0;
	while(head != NULL)
	{
		size++;
		head = head->next;
	}
	return size;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
int data;
Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* first, Node* second) {
	// Code here
	struct Node * ptr1 = first;
	struct Node * ptr2 = second;
	struct Node * sumList = NULL;

	//int addition;

	int remainder =0;
	int carry = 0;


	if(Size(first) > Size(second))
	{
		int diff = 0;
		diff = Size(first) - Size(second);
		//cout << "diff first " << diff << endl;
		int i = 0;

		while (i != diff)
		{
			push_back(&second, 0);
			i++;
		}
	} else if(Size(second) > Size(first))
	{
		int diff = 0;
		diff = Size(second) - Size(first);
		//cout << "diff second " << diff << endl;
		int i = 0;

		while(i != diff)
		{
			push_back(&first, 0);
			i++;
		}
	}
	ptr1 = first;
	ptr2 = second;

	while(ptr1 != NULL && ptr2 != NULL)
	{

		//cout <<"ptr1  "  << ptr1->data << endl;
		//cout <<"ptr2  " << ptr2->data << endl;
		int addition = ptr1->data + ptr2->data + carry;
		//cout << "addition " << addition << endl;
		if(addition % 10 != 0)
		{

			carry = addition / 10;
			remainder = addition % 10;
			push(&sumList, remainder);
			//cout << "carry " << carry << endl;
			//cout << "remainder " << remainder << endl;
		} else if (addition % 10 == 0)
		{
			carry = addition / 10;
			remainder = addition % 10;
			push(&sumList, remainder);
		}

		//cout << " ptr1 " << ptr1->data << " ptr2 " << ptr2->data << " addition " << addition << " remainder " << remainder << " carry " << carry << endl;

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

	}
		if(carry != 0)
	{
		push(&sumList, carry);
	}
	reverse(&sumList);
	return sumList;
}
