/*****************************************************************************
Z: 15156390
Professor: Bullard, James
Author:  Thew, Ryan
Description:  Print and sort array
******************************************************************************/


#include <iostream>
#include <vector>
#include "SortInt.h"
using namespace std;

int main()
{
	STACK s;
	//s.print();
	s.sortA();
	s.print();
//	cout << "\t Top Element of Stack = " << s.GetTop() << endl;
//	cout << "\t After pop = " << s.Pop() << endl;
//	cout << "\t Top Element of Stack = " << s.GetTop() << endl;
	//s.print();
	s.calStats();
	s.getStats();


	s.print();
	s.calStats();
	s.getStats();

	
	system("pause");
	return 0;
}