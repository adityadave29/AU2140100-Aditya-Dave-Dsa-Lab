#include <iostream>
using namespace std;
class Node
{
public:
	float data;
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
	void push(float element)
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
	float pop()
	{
		cnt--;
		Node *tmp = head, *prv, *last;
		float lastdata;
		if (head->next == NULL)
		{
			lastdata = head->data;
			head = NULL;
			return lastdata;
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
			return lastdata;
		}
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
	cout << "Enter valid postfix expression with space (e to end) : " << endl;
	while (y != "e")
	{
		cin >> y;
		if (y != "e")
		{
			if (y != "+" && y != "-" && y != "*" && y != "/")
			{
				a.push(stof(y));
			}
			else
			{
				if (a.cnt > 1)
				{
					float x1 = a.pop();
					float x2 = a.pop();
					if (y == "+")
					{
						a.push(x1 + x2);
					}
					else if (y == "-")
					{
						a.push(x2 - x1);
					}
					else if (y == "*")
					{
						a.push(x1 * x2);
					}
					else if (y == "/")
					{
						a.push(x2 / x1);
					}
				}
			}
		}
	}
	a.print();
	return 0;
}