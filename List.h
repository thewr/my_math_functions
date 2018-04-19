#include <string>
#include <cassert>
#include <iostream>

using namespace std;

#ifndef List_h
#define List_h

class List;
class Iterator;

struct Categories
{
	string name;
	string role;
	int tag;
	int A[27];
};

//typedef struct categories Categories;
//
//void passByReference(Categories *c) 
//{
//	string s1, s2;
//	c->name = s1;
//	c->role = s2;
//	
//}

//struct categories player;

class Node
{
public:
	/*
	    Constructs a node with a given value.
		@param s the data to store in this node
	*/
	Node(string s1, string s2, int* A_);
private:
	Categories data; 
	Node* prev;
	Node* next;
	Node* down;
	friend class List;
	friend class Iterator;
};

class List
{
public:
	/**
	   Constructs an empty list.
	*/
	List();
	/** 
	   Appends an element to the list.
	   @param s the value to append
	*/
	void push_back(string s1, string s2, int* A_);
	/**
	   Insert an element into the list.
	   @param iter the position to remove
	   @return an iterator pointing to the element after the
	   erased element
	*/
	void insert(Iterator iter, string s1, string s2, int* A_);
	/**
	   Removes an element from the list.
	   @param i the position to remove
	   @return an iterator pointing to the element after the 
	   erased element
	*/
	Iterator erase(Iterator i);
	/**
	   Gets the beginning of the list.
	   @return an iterator poinint go the beginning of the list
	*/
	Iterator begin();
	/** 
	   Gets the past-the-end position of the list.
	   @return an iterator poinint past the end of the list
	*/
	Iterator end();
private:
	/**
	   Node pointers for player entry
	*/
	Node* front;
	Node* back;
	int tag;
	/** 
	   Node points for record entry
	*/
	Node* top;
	Node* bottom;
};

class Iterator
{
public:
	/**
	   Constructs an iterator that does not point into any list.
	*/
	Iterator();
	/**
	   Looks up the value at a position.
	   @return the value of the node to which the iterator points to
	*/
	Categories get() const;
	/** 
	   Advances the iterator to the next node.
	*/
	void next();
	/** 
	   Moves the iterator to the previous node.
	*/
	void prev();
	/**
	   Compares two iterators.
	   @param b the iterator to compare with this iterator
	   @return true if this iterator and b are equal
	*/
	bool equals(Iterator b) const;
private:
	Node* position;
	Node* back;
	friend class List;
};

Node::Node(string s1, string s2, int* A_)
{
	
	data.name = s1;
	data.role = s2;
	for (int i = 0; i < 27; i++)
		data.A[i] = A_[i];
	//tag = 0;
	prev = NULL;
	next = NULL;
}

List::List()
{
	front = NULL;
	back = NULL;
}

void List::push_back(string s1, string s2, int *A_)
{
	Node* new_node = new Node(s1, s2, A_);
	new_node->data.tag = 0;
	if (back == NULL) /* list is empty */
	{
		front = new_node;
		back = new_node;
	}
	else
	{
		new_node->prev = back;
		back->next = new_node;
		back = new_node;
		new_node->data.tag= new_node->prev->data.tag + 1;
	}
}

void List::insert(Iterator iter, string s1, string s2, int* A_)
{
	if (iter.position == NULL)
	{
		push_back(s1, s2, A_);
		return;
	}
	Node* after = iter.position;
	Node* before = after->prev;
	Node* new_node = new Node(s1, s2, A_);
	new_node->prev = before;
	new_node->next = after;
	after->prev = new_node;
	if (before == NULL) /* insert at beginning */
		front = new_node;
	else
		before->next = new_node;
}

Iterator List::erase(Iterator i)
{
	Iterator iter = i;
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->prev;
	Node* after = remove->next;
	if (remove == front)
		front = after;
	else
		before->next = after;
	if (remove == back)
		back = before;
	else
		after->prev = before;
	iter.position = after;
	delete remove;
	return iter;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = front;
	iter.back = back;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.back = back;
	return iter;
}

Iterator::Iterator()
{
	position = NULL;
	back = NULL;
}

Categories Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::prev()
{
	if (position == NULL)
		position = back;
	else
		position = position->prev;
	assert(position != NULL);
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}


#endif
