
#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
class Queue
{
public:
	Node *head, *tail;
	int cnt = 0;

	Queue()
	{
		head = NULL;
		tail = NULL;
	}
	void enqueue(int element)
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
	void dequeue()
	{
		cnt--;
		Node *tmp = head, *last;
		last = head;
		head = head->next;
		delete last;
	}
	void print()
	{
		Node *tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << " <-";
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
	Queue a;
	a.enqueue(3);
	a.enqueue(4);
	a.enqueue(5);
	a.enqueue(6);
	a.dequeue();
	a.dequeue();
	a.print();
	return 0;
}