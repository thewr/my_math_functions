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
	int val, max = 5;
	for (int i = 0; i < max; i++)
	{
		cout << "data#" << i+1 <<": ";
		cin >> val;
		s.push(val);
	}

	s.print();
	s.printStats();

	system("pause");
	return 0;
}