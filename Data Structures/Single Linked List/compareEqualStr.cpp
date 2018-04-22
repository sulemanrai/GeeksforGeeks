#include<stdio.h>
#include<stdlib.h>
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
};
struct Node* newNode(char c)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->c = c;
    temp->next = NULL;
    return temp;
};
int compare(struct Node *list1, struct Node *list2);
// Driver program
int main()
{
    int t,n;

    scanf("%d",&t);

    char x;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%c",&x);

        struct Node *list1 = newNode(x);
        struct Node *temp=list1;
        int i;
        for(i=0; i<n-1; i++)
        {
            scanf(" %c",&x);
            temp->next = newNode(x);
            temp=temp->next;
        }
        int m;
        scanf("%d",&m);
        scanf("%c",&x);
        struct Node *list2 = newNode(x);
        temp=list2;
        for(i=0; i<m-1; i++)
        {
            scanf(" %c",&x);
            temp->next = newNode(x);
            temp=temp->next;
        }
        printf("%d", compare(list1, list2));
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// Compare two strings represented as linked lists


int compareEqualStr(struct Node *list1, struct Node *list2)
{
	struct Node * tmp1 = list1;
	struct Node * tmp2 = list2;
	int isSame;

	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp1 == NULL)
			break;

		if (tmp2 == NULL)
			break;

		if(tmp1->c == tmp2->c)
		{
			isSame = 0;
		} else if (tmp2->c < tmp1->c)
		{
			isSame = 1;
			break;
		} else if(tmp1->c < tmp2->c)
		{
			isSame = -1;
			break;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	return isSame;
}

int size(struct Node *head)
{
	int count = 0;

	if (head == NULL)
		return count;

	return 1 + size(head->next);
}
void append(struct Node** head_ref, char new_data)
{
	//cout << "0" << endl;
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->c = new_data;


	struct Node* tail = *head_ref;


	if (*head_ref == NULL)
	{
		//cout << "1" << endl;
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

int compare(struct Node *list1,struct Node *list2)
{
	int isSame;
	if (size(list1) == size(list2)) {
		isSame =  compareEqualStr(list1, list2);
	} else if(size(list1) < size(list2))
	{
		int diff = size(list2) - size(list1);
		int count = 0;
		while(count != diff)
		{
			append(&list1, '\0');
			count++;
		}
		isSame = compareEqualStr(list1, list2);
	} else if(size(list2) < size(list1))
	{
		int diff = size(list1) - size(list2);
		int count = 0;
		while (count != diff)
		{
			append(&list2, '\0');
			count++;
		}
		isSame = compareEqualStr(list1, list2);
	}
	return isSame;
}
