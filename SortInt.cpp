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
	capacity = 30;
	s_top = -1;
	array_ = new int [capacity];	//allocate array

//LOAD STACK
	//int i;
	//ifstream in;
	//in.open("mycounts.txt");
	////cout << "Insert has been invoked\n\n";
	//while (!in.eof())
	//{
	//	in >> i;
	//	push(i);
	//}


	//in.close();
	//cout << "Number of samples loaded: " << count;
	//cout << endl;
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
	for (int i = s_top; i >=0; i--)
		cout << array_[i] << " ";

	cout << endl;
}

/***************************************************************************
Initialize sort
****************************************************************************/
void STACK::sortA()
{
	//cout << "------------------ sort function evoked --------------------\n";
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

double STACK::quartile(int selection) 
{
	sortA();

	double k = (-0.25*selection + 1)*size();
	if (selection == 1)
	{
		double Q1;
		if (isWhole(k))
			Q1 = (array_[static_cast<int>(ceil(k))] + array_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q1 = array_[static_cast<int>(k)];

		return Q1;
	}
	else if (selection == 2)
	{
		double Q2;
		if (isWhole(k))
			Q2 = (array_[static_cast<int>(ceil(k))] + array_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q2 = array_[static_cast<int>(k)];

		return Q2;
	}
	else if (selection == 3)
	{
		double Q3;
		if (isWhole(k))
			Q3 = (array_[static_cast<int>(ceil(k))] + array_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q3 = array_[static_cast<int>(k)];

		return Q3;
	}
	
	else
	{
		cerr << "quartile not selected";
		return -1;
	}

}

bool STACK::isWhole(const double & val)
{
	if (floor(val) == val)
		return true;
	else
		return false;
}

void STACK::printStats()
{
	cout << "\n\t\t\t" << "------- STATS -------" << endl;
	cout << "\t\t\t|" << " n = " << s_top+1 << endl;
	cout << "\t\t\t|" << " Sum = " << accumulate() << endl;
	cout << "\t\t\t|" << " Mean = " << average() << endl;
	cout << "\t\t\t|" << " Q1 = " << quartile(1) << endl;
	cout << "\t\t\t|" << " Median = " << quartile(2) << endl;
	cout << "\t\t\t|" << " Q3 = " << quartile(3) << endl;
	cout << "\t\t\t|" << " Std = " << stdev() << endl;
	cout << "\t\t\t|" << " Var = " << stdev() * stdev() << endl;
	cout << "\t\t\t|" << " MAD = " << mad() << endl;
	cout << "\t\t\t" << "---------------------" << endl;
	cout << endl;
}


float STACK::accumulate()
{
	float sum = 0;
	for (int i = 0; i < size(); i++)
		sum += array_[i];

	return sum;
}

float STACK::average() 
{
	return accumulate() / (float)size();
}

double STACK::stdev()
{
	float x_d, x_var_sum = 0;
	float x_bar = average();
	for (int i = 0; i < size();i++)
	{
		x_d = array_[i] - x_bar;
		x_var_sum = x_var_sum + pow(x_d,2.0);
	}
	return sqrt(x_var_sum/(float)(size()-1));
}

float STACK::mad()
{
	float *T;
	T = new float[capacity];

	double median = quartile(2);

	for (int i = 0; i < size();i++)
	{
		T[i] = abs(array_[i] - median);
	}

	//cout << "------------------ sort function evoked --------------------\n";
	float tmp;
	for (int i = 0; i < size(); i++)
	{
		for (int j = 0; j < size(); j++)
		{
			if (T[i] > T[j])
			{
				tmp = T[i];     //address of *ai given to tmp
				T[i] = T[j];	   //address of *ai given to *aj
				T[j] = tmp;	   //address of tmp given to *aj
			}
		}
	}

	float k = 0.5*size();
	if (isWhole(k))
	{
		return (T[static_cast<int>(ceil(k))] + T[static_cast<int>(ceil(k)) - 1]) / 2.0;
	}
	else
	{
		return T[static_cast<int>(k)];
	}
}

void STACK::push(int Element)
{
	if (!full()) 
		array_[++s_top] = Element;
}

int STACK::pop()
{
	if (!empty()) 
		return(array_[s_top--]); 
}

int STACK::top()
{
	if (!empty()) 
		return(array_[s_top]);
}

int STACK::full()
{
	if (s_top == (capacity - 1)) 
		return 1;
	else 
		return 0; 

}