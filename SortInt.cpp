/*****************************************************************************
Z: 15156390 
Professor: Bullard, James 
Author:  Thew, Ryan
Description:  Print and sort array
******************************************************************************/


#include <iostream>
#include <fstream>
#include <vector>
#include "SortInt.h"
#include <stack>
using namespace std;



/***************************************************************************
Initialize constructor
****************************************************************************/
STACK::STACK()
{
//	cout << "------------------- constructor evoked ---------------------\n";
	capacity = 30;
	top = -1;
	array_ = new int [capacity];	//allocate array

//LOAD STACK
	int i;
	ifstream in;
	in.open("mycounts.txt");
//	//cout << "Insert has been invoked\n\n";
	while (!in.eof())
	{
		in >> i;
		Push(i);
	}
	in.close();
	cout << "Number of samples loaded: " << count;
	cout << endl;
////END OF LOAD LIST
	//sortA(Stack);
	//calStats();
}

/***************************************************************************
Initialize deconstructor
****************************************************************************/
STACK::~STACK()
{
	delete[] array_;
}

/***************************************************************************
Initialize print
****************************************************************************/
void STACK::print()
{
	cout << "STACK: " << endl;
	for (int i = top; i >=0; i--)
	{
		cout << array_[i] << "   ";
	}
	cout << endl;
}


//void STACK::insert(int key)
//{
//	//  cout << "Insert has been invoked\n";
//	if (!Is_Full())
//	{
//		Stack[count] = key;
//		count++;
//	}
//}

/***************************************************************************
Initialize sort
****************************************************************************/
void STACK::sortA()//int *array)
{
	cout << "------------------ sort function evoked --------------------\n";
	int tmp;
	for (int i = 0; i < capacity; i++)
	{
		for (int j = 0; j < capacity; j++)
		{
			if (array_[i] > array_[j])
			{
				tmp = array_[i];     //address of *ai given to tmp
				array_[i] = array_[j];	   //address of *ai given to *aj
				array_[j] = tmp;	   //address of tmp given to *aj
			}
		}
	}
}

void STACK::calStats()
{
// MEAN
	average();
//Q2 (MEDIAN)
	quartile(2);
//STD
	stdev();
// MAD
}

double STACK::quartile(int selection) 
{
	sortA();
	double Q1, Q2, Q3;
	if (count % 2 == 0) //EVEN COUNT
	{
		Q2 = (array_[count / 2 - 1] + array_[(count / 2)]) / 2;
		Q1 = (array_[0] / 2 + Q2 / 2);
		Q3 = (array_[count - 1] / 2 + Q2 / 2);
	}
	else //ODD COUNT
	{
		Q2 = array_[count / 2];
		Q1 = array_[count / 4];
		Q3 = array_[3 * count / 4];
	}
	if (selection == 1)
		return Q1;
	else if (selection == 2)
		return Q2;
	else if (selection == 3)
		return Q3;
	else
	{
		cerr << "quartile not selected";
		return -1;
	}

}

void STACK::getStats()
{
//	//PRINT STATS
	cout << "\n\t\t\t" << "------- STATS -------" << endl;
	cout << "\t\t\t|" << " n = " << top+1 << endl;
	cout << "\t\t\t|" << " Sum = " << accumulate() << endl;
	cout << "\t\t\t|" << " Mean = " << average() << endl;
	cout << "\t\t\t|" << " Q1 = " << quartile(1) << endl;
	cout << "\t\t\t|" << " Q2 = " << quartile(2) << endl;
	cout << "\t\t\t|" << " Q3 = " << quartile(3) << endl;
	cout << "\t\t\t|" << " Std = " << stdev() << endl;
	cout << "\t\t\t|" << " Var = " << stdev() * stdev() << endl;
//	cout << "\t\t\t|" << " MAD = " << MAD << endl;
	cout << "\t\t\t" << "---------------------" << endl;
	cout << endl;
}


float STACK::accumulate()
{
	float sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += array_[i];
	}//Next i
	return sum;
}

double STACK::average() 
{
	double result;
	result = accumulate() / count;  //average
	return result;
}

double STACK::stdev()
{
	double result;
	float tmp, sumX2 = 0;
	for (int i = 0; i < count;i++)
	{
		tmp = array_[i] * array_[i];
		sumX2 = sumX2 + tmp;
	}
	result = sqrt((sumX2/count) - pow(average(),2.0));
	return result;
}

//void STACK::med_abs_diff()
//{
//	int *ARRM;
//	ARRM = new int[MaxCapacity];
//
//	for (int i = 0; i < MaxCapacity;i++)
//	{
//		ARRM[i] = abs(Stack[i] - Q2);
//	}
//
//	sortA(ARRM);
//	if (count % 2 == 0) //EVEN COUNT
//	{
//		MAD = (ARRM[count / 2 - 1] + ARRM[(count / 2)]) / 2;
//
//	}
//	else //ODD COUNT
//	{
//		MAD = ARRM[count / 2];
//	}
//}

void STACK::Push(int Element)
{
	if (!IsFull()) 
	{ 
		array_[++top] = Element;
		count++;
	};
}

int STACK::Pop()
{
	if (!Empty()) 
	{ 
		count--;
		return(array_[top--]); 
	}
}

int STACK::GetTop()
{
	if (!Empty()) 
	{ 
		return(array_[top]);
	}
}

int STACK::IsFull()
{
	if (top == (capacity - 1)) 
	{
		return 1;
	} 
	else 
	{ 
		return 0; 
	} 
}