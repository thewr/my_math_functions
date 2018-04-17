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
#include "Math.h"

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

typedef vector <double> record_t;
typedef vector <record_t> data_t;


int main()
{
	STACK s;
	List player;
	Attribute theAttribute;

	data_t db_;
	db_.resize(5, record_t(3, 0.0));

	int A[10] = { 1,2,3,4,5,6,7,8};
	Math m(A);
	cout << "Sum = " << m.accumulate(A) << endl;
	cout << "Avg = " << m.average(A) << endl;
	cout << "Std = " << m.stdev(A) << endl;
	cout << "Q1 = " << m.quartile(A, 1) << endl;
	cout << "Q2 = " << m.quartile(A, 2) << endl;
	cout << "Q3 = " << m.quartile(A, 3) << endl;
	cout << endl;


	int ch;
	string name;
	Iterator pos;

	do {
		cout << "---- MENU ----- " << endl;
		cout << "1: Add Player" << endl;
		cout << "2: Print" << endl;
		cout << "3: Exit" << endl;


		cout << endl << "Enter your choice:";
		cin >> ch;

		while (cin.fail())  //force input to be only numeric
		{
			cout << "Invalid Entery" << endl;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nEnter your choice:";
			cin >> ch;
		}
		cin.ignore();  //ignore enter before getline
		cout << endl << endl;

		switch (ch) {
		case 1:
			cout << "Name: ";
			getline(cin, name);
			player.push_back(name);
			break;
		case 2:

			for (pos = player.begin(); !pos.equals(player.end()); pos.next())
				cout << pos.getString() << "; tag = " << pos.getInt() << endl;
			cout << endl;
			break;
		case 3:
			cout << "Exiting program ... " << endl;
			exit(1);
		default:
			cout << "Not a valid choice!" << endl;
		} 
	} while (ch != 3);


	//player.push_back("Godbout, Felix");
	//player.push_back("Donovan, Ray");
	//player.push_back("Ray, Eddie");




	//int in;
	//string line;
	//for (int i = 0; i < 27; i++)
	//{
	//		theAttribute = Attribute(i);
	//		cout << getAttribute(theAttribute) << ": ";
	//		while(getline(cin,line))
	//		{
	//			stringstream ss(line);
	//			if (ss >> in)
	//			{
	//				if ((in > 0)&&(in <= 20))//((ss.eof()))
	//				{//sucuess
	//					break;
	//				}
	//			}
	//			cout << "   ERROR: not a valid input!" << endl;
	//			//reenter input
	//			theAttribute = Attribute(i);
	//			cout << getAttribute(theAttribute) << ": ";
	//		}
	//		s.push(in);
	//}

	//system("pause");

	//pos = player.begin();
	//for(int i = 1; i<=3;i++)
	//	db_[pos.getInt()][i-1] = s.quartile(i);


	//cout << pos.getString() << endl;
	//cout << "NAME: " << pos.getString() << "; STATS: "  << db_[0][0] << " " << db_[0][1] << " " << db_[0][2] << endl;

	////s.print();
	//s.printStats();

	

	system("pause");
	return 0;
}