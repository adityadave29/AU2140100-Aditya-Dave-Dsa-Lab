#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
	int data;
	int priority;
	Node *next;
};
class pQueque
{
public:
	Node *head, *tail;
	pQueque()
	{
		head = NULL;
		tail = NULL;
	}
	void enqueue(int element, int priority)
	{
		Node *newNode = new Node();
		newNode->data = element;
		newNode->priority = priority;
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
		Node *tmp = head, *prev = NULL, *min, *min_pr;
		int min1 = head->priority;
		while (tmp != NULL)
		{
			if (tmp->priority < min1)
			{
				min1 = tmp->priority;
				min = tmp;
				min_pr = prev;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		if (head->priority == min1)
		{
			head = head->next;
			return;
		}
		min_pr->next = min->next;
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
};

int main()
{
	pQueque a;
	a.enqueue(4, 3);
	a.enqueue(6, 3);
	a.enqueue(7, 2);
	a.enqueue(8, 5);
	a.enqueue(41, 9);
	a.enqueue(66, 2);
	a.print();
	cout << endl
		 << endl;
	a.dequeue();
	a.dequeue();
	a.print();
	return 0;
}