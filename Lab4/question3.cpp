#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
};
class Stacks
{
public:
    Node *head, *tail;
    int cnt = 0;

    Stacks()
    {
        head = NULL;
        tail = NULL;
    }
    void push(char element)
    {
        cnt++;
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
    void pop()
    {
        cnt--;
        Node *tmp = head, *prv, *last;
        char lastdata;
        if (head->next == NULL)
        {
            lastdata = head->data;
            head = NULL;
        }
        else
        {
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
        }
    }
    bool check(char x)
    {
        if (tail->data == x)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data;
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
    string y;
    char x = '(';
    char x1 = ')';
    char z = '[';
    char z1 = ']';
    char t = '{', t1 = '}';
    char c = '/';
    cout << "Enter : " << endl;
    getline(cin, y);
    for (int i = 0; i < y.length(); i++)
    {
        if (y[i] == x || y[i] == z || y[i] == t)
        {
            a.push(y[i]);
        }
        else if (y[i] == x1)
        {
            if (a.check(x))
            {
                a.pop();
            }
        }
        else if (y[i] == z1)
        {
            if (a.check(z))
            {
                a.pop();
            }
        }
        else if (y[i] == t1)
        {
            if (a.check(t))
            {
                a.pop();
            }
        }
        else if (y[i] == c)
        {
            if (y[i + 1] == c)
            {
                break;
            }
        }
    }
    if (a.cnt == 0)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
    return 0;
}