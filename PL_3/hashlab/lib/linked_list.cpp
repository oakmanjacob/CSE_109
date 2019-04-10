#include <cstdlib>
#include "linked_list.h"

/**
 * Constructor for Node
 */
Node::Node(int data)
{
	this->data = data;
	next = NULL;
}

/**
 * Destructor for Node
 * also deletes any nodes connected
 */
Node::~Node()
{
	if (next != NULL)
	{
		delete next;
	}
}

/**
 * Constructor for LinkedList
 */
LinkedList::LinkedList()
{
	length = 0;
	head = NULL;
	tail = NULL;
}

/**
 * Destructor for LinkedList
 * Deletes the head which should also delete all subsequent nodes
 */
LinkedList::~LinkedList()
{
	if (head != NULL)
	{
		delete head;
	}
}

/**
 * Returns the number of nodes in the linked list
 */
int LinkedList::len()
{
	return length;
}

/**
 * Insert a node at the start of the list
 */
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

/**
 * Insert a node at the end of the list
 */
bool LinkedList::insert_tail(int data)
{
	if (head == NULL)
	{
		head = new Node(data);
		tail = head;
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

/**
 * Insert a node at the given index
 */
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

/**
 * Remove the head node, making the second node the head
 */
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

/**
 * Remove the last node ofthe linked list
 */
bool LinkedList::remove_tail()
{
	return remove_at_index(length - 1);
}

/**
 * Remove the node atthe given index
 */
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

/**
 * Returns the index of the node that first contains the given data.
 * Returns -1 if the node is not found in the linked list.
 */
int LinkedList::find(int data)
{
	Node *curNode = head;
	int i = 0;
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