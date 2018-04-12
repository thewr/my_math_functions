#ifndef SortInt_h
#define SortInt_h
//#include <iostream>

using namespace std;
/***************************************************************************
Class Array (constructor, deconstructor, print and sort)
****************************************************************************/



class STACK
{
public:
	STACK();	//constructor
	~STACK();		//destructor
	int full();
	int top();
	int pop();
	void push(int Element);
	int empty() { if (s_top == -1) { return -1; } else { return 0; } };
	int size() { return(s_top + 1); };


	void print();	//print array
	//void insert(int key);  //insert into array
	void sortA();	//sort array in ascending order
	void printStats();  //print stats

	bool isWhole(const double & val);

	//// stat functions
	float accumulate();
	double quartile(int selection);
	double average();
	double stdev();
	double mad();

private:
	int *array_;
	int capacity;
	int s_top;
};


#endif