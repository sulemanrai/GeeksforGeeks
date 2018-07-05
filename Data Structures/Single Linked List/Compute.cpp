#include<stdio.h>
#include<stdlib.h>
#include "iostream"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
struct Node
{
	string data;
	Node* next;
};
Node *newNode(string str)
{
	Node *new_node = new Node;
	new_node->data = str;
	new_node->next = NULL;
	return new_node;
}
bool Compute(struct Node* root);
void print(Node *root)
{
	Node *temp = root;
	while (temp != NULL)
	{
		cout << (temp->data) << endl;
		temp = temp->next;
	}
}
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
			string str = "";
			cin >> str;
			if (head == NULL)
				head = temp = newNode(str);
			else
			{
				temp->next = newNode(str);
				temp = temp->next;
			}
		}
		if (Compute(head))
			cout << "True" << endl;
		else
			cout << "False" << endl;
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
String data;
Node* next;
};
*/
/* Function to reverse the linked list */
// Function to reverse string and return reverse string pointer of that
char* ReverseConstString(char const* str)
{
	int start, end, len;
	char temp, *ptr = NULL;

	// find length of string
	len = strlen(str);

	// create dynamic pointer char array
	ptr = (char*)malloc(sizeof(char)*(len + 1));

	// copy of string to ptr array
	ptr = strcpy(ptr, str);

	// swapping of the characters
	for (start = 0, end = len - 1; start <= end; start++, end--)
	{
		temp = ptr[start];
		ptr[start] = ptr[end];
		ptr[end] = temp;
	}

	// return pointer of reversed string
	return ptr;
}

bool Compute(Node* root)
{
	//print(root);
	Node * tmp = root;

	//Node * tmp2 = reversedRoot;
	string str = "";
	string reversedstr = "";
		while(tmp != NULL)
		{
		   // const char * c = tmp->data.c_str();
			char *cstr = new char[tmp->data.length() + 1];
			strcpy(cstr, tmp->data.c_str());
			int i = 0;
			while(i < tmp->data.length())
			{
				str.push_back(cstr[i]);
				//cout << cstr[i] << endl;
				i++;
			}
			tmp = tmp->next;
			delete[] cstr;
		}

		const char * p = ReverseConstString(str.c_str());

		if (str == p)
			return true;

	return false;
}
