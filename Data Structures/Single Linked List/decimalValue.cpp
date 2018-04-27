// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;
/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
};
long long unsigned int decimalValue(struct Node *head);
void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isEmpty(struct Node *head);
/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        cout << decimalValue(head) << endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */
/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
}; */
// Should return decimal equivalent modulo 1000000007 of binary linked list
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

long long power(int a, int n)
{
	if (n == 0) {
		return 1LL;
	}
	else if (n % 2 == 0) {
		long long p = power(a, n >> 1);
		return ((p % MOD) * (p % MOD)) % MOD;
	}
	else {
		long long p = power(a, (n - 1) >> 1);
		return ((p * p) % MOD * (a % MOD));
	}
}

long long unsigned int decimalValue(Node *head)
{
   // Your Code Here
   	reverselist(head);

	struct Node * temp = head;
	long long unsigned sum = 0;
	int index = 0;

	while(temp != NULL)
	{
		if (temp->data == 1)
		{
			sum += temp->data * power(2, index);
		}
		index++;
		temp = temp->next;
	}

	return (sum % MOD);
}
