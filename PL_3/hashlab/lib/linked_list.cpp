#include <cstdlib>
#include "linked_list.h"

Node::Node(int data)
{
	this->data = data;
	next = NULL;
}

Node::~Node()
{
	if (next != NULL)
	{
		delete next;
	}
}

LinkedList::LinkedList()
{
	length = 0;
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList()
{
	if (head != NULL)
	{
		delete head;
	}
}

int LinkedList::len()
{
	return length;
}

bool LinkedList::insert_head(int data)
{
	if (head == NULL)
	{
		head = new Node(data);
		tail = head;
		length++;
	}
	else
	{
		Node *node = new Node(data);
		node->next = head;
		head = node;
		length++;
	}
	return true;
}

bool LinkedList::insert_tail(int data)
{
	if (head == NULL)
	{
		head = new Node(data);
		length++;
	}
	else
	{
		tail->next = new Node(data);
		tail = tail->next;
		length++;
	}
	return true;
}

bool LinkedList::insert_at_index(int index, int data)
{
	if (index >= length)
	{
		return false;
	}
	else
	{
		Node *curNode = head;
		for (int i = 0; i < index; i++)
		{
			curNode = curNode->next;
		}

		Node *newNode = new Node(data);
		newNode->next = curNode->next;
		curNode->next = newNode;
		if (newNode->next == NULL)
		{
			tail = newNode;
		}

		length++;
	}
	
	return true;
}

bool LinkedList::remove_head()
{
	if (head == NULL)
	{
		return false;
	}

	Node* oldHead = head;
	head = oldHead->next;
	oldHead->next = NULL;
	delete oldHead;
	length--;

	if (length == 0)
	{
		tail = NULL;
	}
	return true;
}

bool LinkedList::remove_tail()
{
	return remove_at_index(length - 1);
}

bool LinkedList::remove_at_index(int index)
{
	if (index >= length)
	{
		return false;
	}
	else
	{
		Node *curNode = head;
		for (int i = 0; i < index  - 1; i++)
		{
			curNode = curNode->next;
		}

		Node *removed = curNode->next;
		curNode->next = removed->next;
		removed->next = NULL;
		delete removed;
		length--;

		if (curNode->next == NULL)
		{
			tail = curNode;
		}
	}
	
	return true;
}

int LinkedList::find(int data)
{
	Node *curNode = head;
	unsigned int i = 0;
	while (curNode != NULL)
	{
		if (curNode->data == data)
		{
			return i;
		}
		curNode = curNode->next;
		i++;
	}
	return -1;
}