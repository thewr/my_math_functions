/*****************************************************************************
Z: 15156390
Professor: Bullard, James
Author:  Thew, Ryan
Description:  Print and sort array
******************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>


#include "SortInt.h"
#include "List.h"
#include "Attributes.h"


using namespace std;

//template<typename T>
class Keyboard
{
public:
	int getInput() const;
	bool valid(int input);
private:
	bool complete = false;

};

//template<typename T>
int Keyboard::getInput() const
{
	//bool complete = false;
	string line;
	int x = 0;

	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please input proper number between 1-20" << endl;
	}
	return x;

}

bool Keyboard::valid(int input)
{
	if (cin.fail())
	{
		return false;
	}
	else
		return true;
}




int main()
{
	STACK s;
	Keyboard k;
	List player;
	Attribute theAttribute;

	player.push_back("Godbout, Felix");
	player.push_back("Donovan, Ray");
	player.push_back("Ray, Eddie");

	Iterator pos;
	for(pos = player.begin(); !pos.equals(player.end()); pos.next())
		cout << pos.get() << endl;

/*
	int in;
	string line;
	for (int i = 0; i < 27; i++)
	{
			theAttribute = Attribute(i);
			cout << getAttribute(theAttribute) << ": ";
			while(getline(cin,line))
			{
				stringstream ss(line);
				if (ss >> in)
				{
					if ((in > 0)&&(in <= 20))//((ss.eof()))
					{//sucuess
						break;
					}
				}
				cout << "   ERROR: not a valid input!" << endl;
				//reenter input
				theAttribute = Attribute(i);
				cout << getAttribute(theAttribute) << ": ";
			}

			s.push(in);
	}

	s.print();
	s.printStats();

	*/

	system("pause");
	return 0;
}