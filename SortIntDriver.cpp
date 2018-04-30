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
#include <conio.h>
#include <fstream>
#include <stdio.h>



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

struct Record // A struct is a data structure, it contains various pieces of data
{
	string first, last, role;
	int age;
	int atrbs[27];
	//Record(string first_, string last_, string role_) :first(first_), last(last_), role(role_) { for (int i = 0; i < 27; i++) atrbs[i] = 0; };//, int atrbs_[]) :first(first_), last(last_), role(role_) {};
};


//std::istream& operator>>(std::istream& is, Record& r) // This function is used so we can std::ifstream >> Record
//{
//	is >> r.first >> r.last >> r.role;
//	for (unsigned int i = 0; i < 27; i++)
//		is >> r.atrbs[i];
//	return is;
//}
//
//std::ostream& operator<<(std::ostream& os, Record& r) // This function is used so we can std::cout << Record
//{
//	os << r.first << " " << r.last << " " << r.role << " ";
//	for (unsigned int i = 0; i < 27;i++)
//		os << r.atrbs[i] << " ";
//	return os;
//}

//
//bool ReadFile(Record r, const char* filename) // Read sz amount of records into r
//{
//	ifstream file;		// We open the file as normal;
//	file.open("record_data.txt");
//
//	if (file)				// Check if the file was opened
//	{
//		file >> r;
//		return 1;	// File read
//	}
//	else
//	{
//		return 0; 	// File could not be opened
//	}
//}


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
		cout << "Invalid Entery" << endl;
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
	cout << TABS << " 3. Load" << endl;
	cout << TABS << " 4. Save" << endl;
	cout << TABS << " 5: Exit" << endl;
	cout << TABS << "----------------- " << endl;
	cout << endl;

	if (choice() == 1)
	{
		cout << "Enter your choice: " << choice() << endl << endl;
		cout << "----------- Add L -----------" << endl;
	}
	else if (choice() == 2)
	{
		cout << "Enter your choice: " << choice() << endl << endl;
		cout << TABS << "DATABASE" << endl << endl;
	}	
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
	Stack s;
	Menu menu;
	List L;
	L.load_list("record_data.txt");
	cout << "Avg: " << L.get_list_avg() << endl;
	cout << "Std: " << L.get_list_stdev() << endl;

	menu.pause();
	Attribute theAttribute;

	unsigned years;

	//gamedate
	unsigned y1 = 2049;
	unsigned m1 = 01;
	unsigned d1 = 02;

	unsigned y0 = 0001;
	unsigned m0 = 01;
	unsigned d0 = 00;

	int A[27]; 	

	string first_name, last_name,role;
	Iterator pos;

	int in;
	string line;

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
			cout << "Role: ";
			getline(cin, role);
			cout << "DOB (month.day.year):" << endl;
			cout << "  month: "; cin >> m0;
			cout << "  day: "; cin >> d0;
			cout << "  year: "; cin >> y0;
			cin.ignore();

			if (m1 > m0)
				years = (y1 - y0);
			else
				years = (y1 - y0) - 1;

			menu.display();
			cout << "First: " << first_name << endl;
			cout << "Last: " << last_name << endl;
			cout << "Role: " << role << endl;
			cout << "Age: " << years << endl;
			

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
						cout << "Age: " << years << endl;
						theAttribute = Attribute(i);
						cout << getAttribute(theAttribute) << ": ";
					}
					A[i] = in;
					menu.display();
					cout << "First: " << first_name << endl;
					cout << "Last: " << last_name << endl;
					cout << "Role: " << role << endl;
					cout << "Age: " << years << endl;
			}
			/**
			   Insert player into database
			*/
			L.push_back(first_name, last_name, role, years, A);
			cout << endl;
			cout << last_name << ", " << first_name << " added to database." << endl << endl;
			menu.pause();
			break;
		case 2:
			menu.display();
			for (pos = L.begin(); !pos.equals(L.end()); pos.next())
			{
				

				cout << "Name: " << pos.get().last << ", " << pos.get().first << endl;
				cout << "Age: " << pos.get().age << endl;
				cout << "Role: " << pos.get().role << endl;

				for (int i = 0; i < 27; i++)
				{
					if ((i==9)||(i==18))
						cout << endl;				
					
					cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << pos.get().A[i];// << " ";
					in = pos.get().A[i];
					s.push(in);
				}
				cout << endl << endl;
				cout << "< " << s.quartile(1) << " - " << s.quartile(2) <<  " - " << s.quartile(3) << " > ";
				cout << "                         ";
				cout << "< Q1 - Q2 - Q3 > " << endl;
				cout << "Avg: " << s.average() << "; Std: " << s.stdev() << endl;
				if (s.average() >= (L.get_list_avg() + 1.5*L.get_list_stdev()/sqrt(27)))
					cout << "Grade: A" << endl;
				else if (s.average() >= (L.get_list_avg() + 0.75*L.get_list_stdev()/sqrt(27)) && (s.average() < (L.get_list_avg() + 1.5*L.get_list_stdev()/sqrt(27))))
					cout << "Grade: B" << endl;
				else if (s.average() >= (L.get_list_avg()) && (s.average() < (L.get_list_avg() + 0.75*L.get_list_stdev()/sqrt(27))))
					cout << "Grade: C" << endl;
				else if (s.average() >= (L.get_list_avg() - 0.75*L.get_list_stdev()/sqrt(27)) && (s.average() < (L.get_list_avg())))
					cout << "Grade: D" << endl;
				else
					cout << "Grade: F" << endl;

				while (!s.empty())
					s.pop();
				cout << "-----------------------------------------------------------------------" << endl;
			}
			cout << endl;
			menu.pause();
			break;
		case 3:
			/**
			Load database county_data.txt
			*/
			L.load_list("record_data.txt");
			menu.pause();
			break;
		case 4:
			/**
			Save sorted county data
			*/
			L.save_list("record_data.txt");
			menu.pause();
			break;
		case 5:
			cout << "Exiting program ... " << endl;
			exit(1);
		default:
			cout << "Not a valid choice!" << endl;
		} 
	} while (menu.choice() != 5);

	
	return 0;
}