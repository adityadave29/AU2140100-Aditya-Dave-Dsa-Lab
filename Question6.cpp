#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node(int data)
   {
      this->data = data;
      this->next = NULL;
   }
};

void insertAt(Node *&head, int data)
{
   Node *n = new Node(data);
   n->next = head;
   head = n;
}
int i = 0;
void searchRecursive(Node *head, int key)
{
   i++;
   if (head == NULL)
   {
      cout << "Not Found" << endl;
   }
   if (head->data == key)
   {
      cout << i << endl;
   }
   else
   {
      return searchRecursive(head->next, key);
   }
   
}
void printNode(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}

int main()
{
   Node *head = NULL;
   insertAt(head, 5);
   insertAt(head, 4);
   insertAt(head, 3);
   insertAt(head, 2);
   insertAt(head, 1);
   printNode(head);
   searchRecursive(head, 5);
}
