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
	int IsFull();
	int GetTop();
	int Pop();
	void Push(int Element);
	int Empty() { if (top == -1) { return -1; } else { return 0; } };
	int CurrSize() { return(top + 1); };


	void print();	//print array
	//void insert(int key);  //insert into array
	void sortA();	//sort array in ascending order
	void getStats();  //print stats
	void calStats();

	//// stat functions
	float accumulate();
	double quartile(int selection);
	double average();
	double stdev();
	//void med_abs_diff();*/

private:
	int *array_;
	int capacity;
	int top, count;
};


#endif