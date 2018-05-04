/*****************************************************************************
Author:  Thew, Ryan
Description:  Database
******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <stdio.h>


#include "SortInt.h"
#include "List.h"
#include "Attributes.h"
#include "Math.h"

using namespace std;

const string TABS = "\t\t\t\t";

unsigned get_age(const string dob /*dob*/, string & cur /*cur*/)
{
	unsigned m1, d1, y1;
	unsigned m0, d0, y0;
	char dummy;

	stringstream ss1(cur);
	ss1 >> m1 >> dummy >> d1 >> dummy >> y1;
	stringstream ss0(dob);
	ss0 >> m0 >> dummy >> d0 >> dummy >> y0;

	if (m1 > m0)
		return (y1 - y0);
	else
		return (y1 - y0) - 1;
}

string get_dob()
{
	string s;
	char dummy;
	unsigned m0, d0, y0;
	//"Enter date of birth: ";
	while (getline(cin, s))
	{
		stringstream ss(s);
		ss >> m0 >> dummy >> d0 >> dummy >> y0;
		if ((m0 != 0) && (m0 <= 12) && (y0 >= 1900) && (d0 != 0) && (d0 <= 31))
		{
			cout << s << endl;
			return s;
			break;
		}
		else
		{
			cout << "ERROR!! Please re-enter date" << endl;
			cout << "Enter date of birth: ";
		}
	}

	//cout << s;
}

class Menu
{
public: 
	void display();
	void get_input();
	unsigned choice();
	void pause();
private:
	unsigned ch = 0;
};

void Menu::pause()
{
	cout << "Press any key to continue...";
	while (!_kbhit())
	{
		//do nothing until key is pressed...
	}
}

void Menu::get_input()
{
	cout << "Enter your choice: ";
	cin >> ch;

	while (cin.fail())  //force input to be only numeric
	{
		cout << "Invalid Entry" << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nEnter your choice: ";
		cin >> ch;
	}
	cin.ignore();  //ignore enter before getline
	cout << endl << endl;
}

unsigned Menu::choice()
{
	return ch;
}


void Menu::display()
{
	system("CLS");
	cout << TABS << "------ MENU ----- " << endl;
	cout << TABS << " 1: Add" << endl;
	cout << TABS << " 2: Print" << endl;
	cout << TABS << " 3. Search" << endl;
	cout << TABS << " 4. Load" << endl;
	cout << TABS << " 5. Save" << endl;
	cout << TABS << " 6: Exit" << endl;
	cout << TABS << "----------------- " << endl;
	cout << endl;

	if (choice() == 1)
	{
		cout << "Enter your choice: " << choice() << endl << endl;
		cout << TABS << "ADD PLAYER" << endl;
	}
	else if (choice() == 2)
	{
		cout << "Enter your choice: " << choice() << endl << endl;
		cout << TABS << "DATABASE" << endl;
	}	
}


typedef vector <double> record_t;
typedef vector <record_t> data_t;


int main()
{
	/**
	   allocate variables
	*/
	string first_name, last_name,role, dob, line, date = "12/5/2048";
	int A[27], in; 	
	double z_ov, sp;
	Iterator pos;
	Node* ptr;

	vector<unsigned> freq;
	freq.resize(5, 0.0);
	/** 
	   define objects 
	*/
	Stack s;
	Menu menu;
	List L;
	Attribute theAttribute;
	/**
	   load up list print shit
	*/
	L.load_list("record_data.txt");
	cout << "Avg: " << L.pop_avg() << endl;
	cout << "Std: " << L.pop_stdev() << endl;
	cout << "Date: " << date << endl;
	menu.pause();
	


	do {
		/**
		   Menu display and input prompt
		*/
		menu.display();
		menu.get_input();
		switch (menu.choice()) {

		case 1:
			/**
			   Get player information (Name/Role)
			*/
			menu.display();

			cout << "First: ";
			getline(cin, first_name);

			cout << "Last: ";
			getline(cin, last_name);
			/**
			   Check to see if in Name is in database 
			*/
			ptr = L.search_list(first_name, last_name);
			if (ptr)
			{
				cout << "Player already in database!!" << endl;
				menu.pause();
				break;
			}

			cout << "Role: ";
			getline(cin, role);
			cout << "Enter date of birth: ";
			date = get_dob();

			menu.display();
			cout << "First: " << first_name << endl;
			cout << "Last: " << last_name << endl;
			cout << "Role: " << role << endl;
			cout << "Age: " << get_age(dob, date) << endl;
			
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
							if ((in > 0)&&(in <= 20))
							{//sucuess
								break;
							}
						}
						/**
						   Reenter input if error
						*/
						cout << "ERROR!\n";
						menu.pause();
						menu.display();
						cout << "First: " << first_name << endl;
						cout << "Last: " << last_name << endl;
						cout << "Role: " << role << endl;
						cout << "Age: " << get_age(dob,date) << endl;
						theAttribute = Attribute(i);
						cout << getAttribute(theAttribute) << ": ";
					}
					A[i] = in;
					menu.display();
					cout << "First: " << first_name << endl;
					cout << "Last: " << last_name << endl;
					cout << "Role: " << role << endl;
					cout << "Age: " << get_age(dob,date) << endl;
			}
			/**
			   Insert player into database
			*/
			L.push_back(first_name, last_name, role, dob, A);
			cout << endl;
			cout << last_name << ", " << first_name << " added to database." << endl << endl;
			menu.pause();
			break;
		case 2:
			menu.display();
			for (pos = L.begin(); !pos.equals(L.end()); pos.next())
			{
				

				cout << "Name: " << pos.get().last << ", " << pos.get().first << endl;
				cout << "Age: " << get_age(pos.get().dob,date) << endl;
				cout << "Role: " << pos.get().role << endl;

				for (int i = 0; i < 27; i++)
				{
					if ((i==9)||(i==18))
						cout << endl;				
					
					cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << pos.get().A[i];// << " ";
					in = pos.get().A[i];
					if( (i != FAC)&&(i != AGG))
						s.push(in);
				}
				cout << endl << endl;
				cout << "< " << s.quartile(1) << " - " << s.quartile(2) <<  " - " << s.quartile(3) << " > ";
				cout << "                         ";
				cout << "< Q1 - Q2 - Q3 > " << endl;
				cout << "Avg: " << s.average() << "; Std: " << s.stdev() << endl;

				sp = sqrt(((s.size() - 1.0)*pow(s.stdev(),2.0) + (L.pop_count() - 1.0)*pow(L.pop_stdev(), 2.0))/(s.size()+L.pop_count()-2.0));

				z_ov = (s.average() - L.pop_avg()) / L.pop_stdev();
				cout << "Observed Value = " << z_ov << endl;


				if (z_ov >= 0.68)
				{
					cout << "Grade: A" << endl;
					++freq[4];				
				}
				else if ((z_ov >= 0.33) && (z_ov < 0.68))
				{
					cout << "Grade: B" << endl;
					++freq[3];
				}
				else if ((z_ov >= -0.18) && (z_ov < + 0.18))
				{
					cout << "Grade: C" << endl;
					++freq[2];
				}
				else if ((z_ov >= - 0.68) && (z_ov < -0.18))
				{
					cout << "Grade: D" << endl;
					++freq[1];				
				}
				else
				{
					cout << "Grade: F" << endl;
					++freq[0];
				}


				while (!s.empty())
					s.pop();

				cout << "-----------------------------------------------------------------------" << endl;
			}
			cout << endl;

			cout << "F.D.C.B.A " << "     ";

			for (int i = 0; i < 5; i++)
			{
				if (i == 4)
					cout << freq[i];
				else
					cout << freq[i] << ".";
			}
			cout << endl;


			menu.pause();
			break;
		case 3:
			/**
			Search database record_data.txt
			*/
			cout << "Enter name of player to search for:" << endl;
			cout << "First: ";
			getline(cin, first_name);
			cout << "Last: ";
			getline(cin, last_name);
			ptr = L.search_list(first_name, last_name);

			if (ptr)
			{
				cout << "Player found!!" << endl;
				cout << "Name: " << ptr->data.last << ", " << ptr->data.first << endl << endl;
			
				cout << "Edit Player? (y/n): ";
				getline(cin, line);
				if ((line == "y")||(line == "yes"))
				{
					cout << "Role: " << ptr->data.role << endl;
					cout << "Age: " << get_age(ptr->data.dob,date) << endl << endl;
					for (int i = 0; i < 27; i++)
					{
						if ((i == 9) || (i == 18))
							cout << endl;

						cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << ptr->data.A[i];
						cout << endl;
					}
				}
			}
			else
				cout << "Player NOT found!!" << endl;
			menu.pause();
			break;

		case 4:
			/**
			Load database from record_data.txt
			*/
			L.load_list("record_data.txt");
			menu.pause();
			break;
		case 5:
			/**
			Save database to record_data.txt
			*/
			L.save_list("record_data.txt");
			menu.pause();
			break;
		case 6:
			cout << "Exiting program ... " << endl;
			exit(1);
		default:
			cout << "Not a valid choice!" << endl;
		} 
	} while (menu.choice() != 6);

	
	return 0;
}