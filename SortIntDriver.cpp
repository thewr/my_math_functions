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
#include <stdlib.h>
#include <iomanip>



#include "SortInt.h"
#include "List.h"
#include "Attributes.h"
#include "Math.h"

using namespace std;

const string TABS = "\t\t\t\t";

//template<typename T>
class Keyboard
{
public:
	int getInput() const;
	bool valid(int input);
private:
	bool complete = false;

};

int Menu_Choice(int c)
{
	return c;
}


void Display_Menu()
{
	system("CLS");
	cout << TABS << "------ MENU ----- " << endl;
	cout << TABS << " 1: Add" << endl;
	cout << TABS << " 2: Print" << endl;
	cout << TABS << " 3: Exit" << endl;
	cout << TABS << "----------------- " << endl;
	cout << endl;

	//while (cin.fail())  //force input to be only numeric
	//{
	//	cout << "Invalid Entery" << endl;
	//	cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//	cout << "\nEnter your choice: ";
	//	cin >> ch;
	//}
	//cin.ignore();  //ignore enter before getline
	//cout << endl << endl;
}



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

	int A[27];// = { 4,2,7,9,5 };
	Math math;
	
	//cout << TABS << "N = " << m1.length(A) << endl;
	//cout << TABS << "Sum = " << m1.accumulate(A) << endl;
	//cout << TABS << "Avg = " << m1.average(A) << endl;
	//cout << TABS << "Std = " << m1.stdev(A) << endl;
	//cout << TABS << "Q1 = " << m1.quartile(A, 1) << endl;
	//cout << TABS << "Q2 = " << m1.quartile(A, 2) << endl;
	//cout << TABS << "Q3 = " << m1.quartile(A, 3) << endl;
	//cout << endl;


	int ch;
	string name,role;
	Iterator pos;

	int in;
	string line;

	do {
		Display_Menu();

		cout << "Enter your choice: ";
		cin >> ch;

		while (cin.fail())  //force input to be only numeric
		{
			cout << "Invalid Entery" << endl;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nEnter your choice: ";
			cin >> ch;
		}
		cin.ignore();  //ignore enter before getline
		cout << endl << endl;

		switch (ch) {
		case 1:
			Display_Menu();
			cout << "--- Add Player ---" << endl << endl;
			/**
			   Get player information (Name/Role)
			*/
			cout << "Name: ";
			getline(cin, name);
			cout << "Role: ";
			getline(cin, role);
			/**
			   Get player attributes
			*/


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
						cout << "ERROR!! INVALID INPUT!!" << endl;
						system("pause");
						//reenter input
						Display_Menu();
						cout << "--- Add Player ---" << endl << endl;
						cout << "Name: " << name << endl;
						cout << "Role: " << role << endl;
						theAttribute = Attribute(i);
						cout << getAttribute(theAttribute) << ": ";
					}
					A[i] = in;
					Display_Menu();
					cout << "--- Add Player ---" << endl << endl;
					cout << "Name: " << name << endl;
					cout << "Role: " << role << endl;


			}

			player.push_back(name, role, A);
			cout << endl;
			cout << name << " added to database." << endl << endl;
			system("pause");
			break;
		case 2:
			cout << "---------------------------------------" << endl;
			for (pos = player.begin(); !pos.equals(player.end()); pos.next())
			{
				cout << "Name: " << pos.get().name << endl;
				cout << "Role: " << pos.get().role << endl;
				//cout << "Tag = " << pos.get().tag << endl;
				cout << "        " << endl;
				for (int i = 0; i < 27; i++)
				{
					if ((i==9)||(i==18))
						cout << endl;				
					
					cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << pos.get().A[i];// << " ";
				}
				cout << endl;
				cout << "Q1: " << math.quartile(pos.get().A, 1) << endl;
				cout << "---------------------------------------" << endl;
			}
			cout << endl;
			system("pause");
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