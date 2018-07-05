#include<stdio.h>
#include<stdlib.h>
/* Link list Node */
struct Node
{
	int data;
	struct Node* next;
};
struct Node *start = NULL;
void sortList(struct Node *head);
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
	while (Node != NULL)
	{
		printf("%d ", Node->data);
		Node = Node->next;
	}
	printf("\n");
}
/* Drier program to test above function*/
void insert(int n1)
{
	int n, value, i;
	//scanf_s("%d",&n);
	n = n1;
	struct Node *temp = NULL;
	for (i = 0; i<n; i++)
	{
		scanf("%d", &value);

		if (i == 0)
		{
			start = (struct Node *) malloc(sizeof(struct Node));
			start->data = value;
			start->next = NULL;
			temp = start;
			continue;
		}
		else
		{
			temp->next = (struct Node *) malloc(sizeof(struct Node));
			temp = temp->next;
			temp->data = value;
			temp->next = NULL;
		}
	}
}
int main()
{

	int n;

	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		insert(n);
		sortList(start);
		printList(start);
	}

	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Sort the list of 0's,1's and 2's
The input list will have at least one element
Node is defined as
struct Node
{
int data;
Node *next;
}
*/
void sortList(Node *head)
{
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	//Add code here
	struct Node * tmp = head;

	while(tmp != NULL)
	{
		if(tmp->data == 0)
		{
			count0++;
		} else if(tmp->data == 1)
		{
			count1++;
		} else if(tmp->data == 2)
		{
			count2++;
		}
		tmp = tmp->next;
	}

	//printf("count0 %i count1 %i count2 %i", count0, count1, count2);
	tmp = head;
	int count = 0;

	while(tmp != NULL)
	{
		while(count != count0)
		{
			tmp->data = 0;
			tmp = tmp->next;
			count++;
		}
		count = 0;
		while (count != count1)
		{
			tmp->data = 1;
			tmp = tmp->next;
			count++;
		}
		count = 0;
		while (count != count2)
		{
			tmp->data = 2;
			tmp = tmp->next;
			count++;
		}
	}


}
