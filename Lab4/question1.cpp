#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stacks
{
    Node *head, *tail;

public:
    Stacks()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int element)
    {
        Node *newNode = new Node();
        newNode->data = element;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pop()
    {
        Node *tmp = head, *prv, *last;
        int lastdata;
        while (tmp->next != NULL)
        {
            prv = tmp;
            tmp = tmp->next;
        }
        tail = prv;
        last = tail->next;
        lastdata = last->data;
        delete last;
        tail->next = NULL;
        return lastdata;
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << "->";
            tmp = tmp->next;
        }
    }

    Node *gethead()
    {
        return head;
    }

    Node *gettail()
    {
        return tail;
    }
};
int main()
{
    Stacks a;
    a.push(5);
    a.push(8);
    a.push(9);
    cout << a.pop() << endl;
    a.print();
    return 0;
}