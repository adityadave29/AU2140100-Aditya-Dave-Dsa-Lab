
#include<bits/stdc++.h>
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

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

void Replaceelement(Node* &head,int position,int element){
    Node* temp = head;
    int i=0;
    while(i!=position-1){
        temp = temp->next;
        i++;
    }
    temp->data = element;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    InsertAtHead(head,11);
    InsertAtHead(head,12);
    InsertAtHead(head,13);
    InsertAtHead(head,14);
    print(head);
    Replaceelement(head,3,22);
    print(head);
}