#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include "SortInt.h"
#include "Attributes.h"

using namespace std;

#ifndef List_h
#define List_h

class STACK;
class List;
class Iterator;

struct Categories
{
	string first, last, role, dob;
	int A[27];
};

class Node
{
public:
	/*
	    Constructs a node with a given value.
		@param s the data to store in this node
	*/
	Node(string first_, string last_, string role_, string dob_, int* A_);
	Categories data; 
private:
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
	void push_back(string first_, string last_, string role_, string dob_, int* A_);
	/**
	   Insert an element into the list.
	   @param iter the position to remove
	   @return an iterator pointing to the element after the
	   erased element
	*/
	void insert(Iterator iter, string first_, string last_, string role_, string dob_, int* A_);
	/**
	   Removes an element from the list.
	   @param i the position to remove
	   @return an iterator pointing to the element after the 
	   erased element
	*/
	double pop_avg() { return list_avg; }
	double pop_stdev() { return list_stdev; }
	double pop_count() { return list_count; }
	void load_list(string file);
	void save_list(string file);

	Node* search_list(Node*, string first_, string last_);
	Node* search_list(string first_,string last_);
	

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
	double list_avg;
	double list_stdev;
	unsigned long list_count;
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

Node::Node(string first_, string last_, string role_, string dob_, int* A_)
{	
	data.first = first_;
	data.last = last_;
	data.role = role_;
	data.dob = dob_;
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

void List::push_back(string first_, string last_, string role_, string dob_, int *A_)
{
	Node* new_node = new Node(first_, last_, role_,dob_,A_);

	if (back == NULL) /* list is empty */
	{
		front = new_node;
		back = new_node;
		//new_node->data.tag = 0;
	}
	else
	{
		new_node->prev = back;
		back->next = new_node;
		back = new_node;
		//new_node->data.tag= new_node->prev->data.tag + 1;
	}
}

void List::insert(Iterator iter, string first_, string last_, string role_, string dob_,int* A_)
{
	if (iter.position == NULL)
	{
		push_back(first_, last_, role_, dob_, A_);
		return;
	}
	Node* after = iter.position;
	Node* before = after->prev;
	Node* new_node = new Node(first_, last_, role_, dob_, A_);
	new_node->prev = before;
	new_node->next = after;
	after->prev = new_node;
	if (before == NULL) /* insert at beginning */
		front = new_node;
	else
		before->next = new_node;
}

void List::load_list(string file)
{
	ifstream infile;
	Categories r;
	Stack s; 
	infile.open(file);
	int record_count = 0;
	cout << "...loading tree from file...\n";
	if (infile.is_open()) {
		while (infile >> r.first)//!infile.eof())
		{
			//getline(infile, line);
			if (!r.first.empty())  //ignore blanks
			{
				infile >> r.last >> r.role >> r.dob;

				for (unsigned int i = 0; i < 27; i++)
				{
					infile >> r.A[i];
					if((i != FAC)&&(i != AGG))
						s.push(r.A[i]);
				}
				record_count++;
				push_back(r.first, r.last, r.role, r.dob, r.A);
			}
		}
	}
	else
		cout << "Error opening " << file << endl;

	cout << "Records loaded: " << record_count++ << endl;
	list_avg = s.average();
	list_stdev = s.stdev();
	list_count = s.size();
	infile.close();
}

void List::save_list(string file)
{
	ofstream outold;
	fstream outnew;
	outnew.open(file);
	Categories r;
	cout << "...writing tree element to file...\n";

	//clear original content
	outold.open(file, ofstream::out | ofstream::trunc);
	outold.close();

	//write content
	Iterator iter;
	if (outnew.is_open())
	{
		iter = begin();
		while (!iter.equals(end()))
		{
			outnew << iter.get().first << " " << iter.get().last << " " << iter.get().role << " " << iter.get().dob << " ";
			for (int i = 0; i < 27; i++) {
				outnew << iter.get().A[i] << " ";
			}
			outnew << endl;
			iter.next();
		}
		outnew.close();
	}

}

Node* List::search_list(string first_, string last_)
{
	return search_list(front, first_, last_);
}

Node* List::search_list(Node* loc_ptr, string first_, string last_)
{
	if (loc_ptr != 0)
	{
		if (((loc_ptr->data.first == first_)) && ((loc_ptr->data.last == last_)))
			return loc_ptr;
		else
			return search_list(loc_ptr->next, first_, last_);
	}
	else
		return loc_ptr;
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
