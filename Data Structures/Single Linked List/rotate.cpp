#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
void insert()
{
	int n, i, value;
	struct node *temp = NULL;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &value);
		if (i == 0)
		{
			head = (struct node *) malloc(sizeof(struct node));
			head->data = value;
			head->next = NULL;
			temp = head;
			continue;
		}
		else
		{
			temp->next = (struct node *) malloc(sizeof(struct node));
			temp = temp->next;
			temp->data = value;
			temp->next = NULL;
		}
	}
}
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	int t, k, n, value;
	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	scanf("%d", &t);
	while (t--)
	{
		insert();
		scanf("%d", &k);
		rotate(&head, k);
		printList(head);
	}
	return(0);
}
int size(struct node *head)
{
	int i = 0;
	struct node * tmp = head;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}
void rotate(struct node **head_ref, int k)
{
	if (k == 0 || k >= size(*head_ref))
		return;
	struct node *tmp = *head_ref;
	struct node *originalhead = *head_ref;
	int i = 1;

	while(i != k)
	{
		tmp = tmp->next;
		i++;
	}

	*head_ref = tmp->next;
	tmp->next = NULL;
	//printf("original head %i\n", originalhead->data);

	struct node* newhead = *head_ref;
	//printf("newhead %i\n", newhead->data);

	while(newhead->next != NULL)
	{
		newhead = newhead->next;
	}
	//printf("newhead %i\n", newhead->data);
	newhead->next = originalhead;
}
