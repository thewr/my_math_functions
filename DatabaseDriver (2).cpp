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


#include "Sort.h"
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
		if (ss >> m0 >> dummy >> d0 >> dummy >> y0)
		{
			if ((m0 != 0) && (m0 <= 12) && (y0 >= 1900) && (d0 != 0) && (d0 <= 31))
			{
				break;
			}
		}
		//else
		//{
			cout << "ERROR!! Please re-enter date" << endl;
			cout << "Enter date of birth: ";
		//}
	}
	return s;
}



class Menu
{
public: 
	void display_main();
	void display_edit();
	void display_print();
	//void display_print_player_history();
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


void Menu::display_main()
{
	system("CLS");
	cout  << "------------------------------ EHM DATABASE ----------------------------------- " << endl;
	cout << "Main Menu" << endl;
	cout << "1 - add" << endl;
	cout << "2 - print" << endl;
	cout << "3 - edit" << endl;
	cout << "4 - load" << endl;
	cout << "5 - save" << endl;
	cout << "6 - calculate" << endl;
	cout << "7 - exit" << endl;
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

void Menu::display_edit()
{
	system("CLS");
	cout << TABS << "------ EDIT ----- " << endl;
	cout << TABS << " 1) Role" << endl;
	cout << TABS << " 2) Date of Birth" << endl;
	cout << TABS << " 3) Attributes" << endl;
	cout << TABS << " 4) Return" << endl;
	cout << TABS << "----------------- " << endl;
	cout << "Enter choice: ";
}

void Menu::display_print()
{
	system("CLS");
	cout << TABS << "----- PRINT ----- " << endl;
	cout << TABS << " 1) All" << endl;
	cout << TABS << " 2) Filter" << endl;
	cout << TABS << " 3) Stats" << endl;
	cout << TABS << " 4) Return" << endl;
	cout << TABS << "----------------- " << endl;
	cout << "Enter choice: ";
}


typedef vector <double> record_t;
typedef vector <record_t> data_t;

int main()
{
	/**
	   allocate variables
	*/
	string first_name, last_name, role, role_0, role_1, dob, line, date = "12/5/2048";
	char selection;//, dummy;
	int A[27], AGE = 0, in, j = 0, k = 0, M = 3, count;
	int new_min = -1;
	int new_max = 1;
	//float Q1, Q2, Q3;
	////  forjacobi
	double z_ov;
	double Sin2, Cos2, Cos_, Sin_, Tan2, Cot2, tmp, d_j, d_k;
	double den = 0.0, num = 0.0;
	long double min[2] = { 0.0, 0.0 };
	double max[2] = { 0.0, 0.0 };
	double sumsqr, prev_sumsqr = 0.0, sum = 0.0;
	const double eps = 1E-16;
	////


	vector<double> freq;
	freq.resize(5, 0.0);

	string file = "stats_data.txt";
	fstream out;
	/**
	   define objects
	*/
	Stack<int> int_stk;
	Stack<double> dbl_stk;
	Iterator pos;
	Node* ptr;
	Math m;
	Menu menu;
	List L;
	Attribute theAttribute;
	/**
	   read data from file "record_data.txt"
	   and insert into list.
	*/
	L.load_list("record_data.txt");
	int N = static_cast<int>(L.pop_count() - 1);

	data_t arrayA, arrayA_T, arrayA_COV, evec, rec_dist,rec_fvecs, clusters, weights;
	arrayA.resize(N, record_t(3, 0));
	arrayA_T.resize(3, record_t(N, 0));
	arrayA_COV.resize(3, record_t(3, 0));
	evec.resize(3, record_t(2, 0));
	rec_fvecs.resize(N, record_t(M, 0.0));
	rec_dist.resize(N, record_t(5, 0.0));
	clusters.resize(5, record_t(2, 0.0));
	weights.resize(N, record_t(5, 0.0)); //w[i][j]


	record_t eval(M);
	

	vector<int> grades(N);
	int grade;

	/**
		print load stats
	*/
	cout << "Avg: " << L.pop_avg() << endl;
	cout << "Std: " << L.pop_stdev() << endl;
	cout << "Date: " << date << endl;
	menu.pause();

	do {
		/**
		   menu display and input prompt
		*/
		menu.display_main();
		menu.get_input();
		switch (menu.choice()) {
			/*************************************** ADD PLAYEER  ******************************************************/
		case 1:
			menu.display_main();
			/* get player information (Name/Role) */
			cout << "First: ";
			getline(cin, first_name);
			cout << "Last: ";
			getline(cin, last_name);
			/* error check to see if name is not already in list */
			ptr = L.search_list(first_name, last_name);
			if (ptr)
			{
				cout << endl << "Player already in database!!" << endl;
				menu.pause();
				break;
			}
			/* get position and calculate age */
			cout << "Role: ";
			getline(cin, role);
			cout << "Enter date of birth: ";
			dob = get_dob();

			/* print stats */
			menu.display_main();
			cout << "First: " << first_name << endl;
			cout << "Last: " << last_name << endl;
			cout << "Role: " << role << endl;
			cout << "Age: " << get_age(dob, date) << endl;

			/**
			   get player attributes
			*/
			for (int i = 0; i < 27; i++)
			{
				theAttribute = Attribute(i);
				cout << getAttribute(theAttribute) << ": ";
				while (getline(cin, line))
				{
					stringstream ss(line);
					if (ss >> in)
					{
						if ((in > 0) && (in <= 20))
						{//sucuess
							break;
						}
					}
					/**
					   re-enter input if error
					*/
					cout << "ERROR!\n";
					menu.pause();
					menu.display_main();
					cout << "First: " << first_name << endl;
					cout << "Last: " << last_name << endl;
					cout << "Role: " << role << endl;
					cout << "Age: " << get_age(dob, date) << endl;
					theAttribute = Attribute(i);
					cout << getAttribute(theAttribute) << ": ";
				}
				A[i] = in;
				menu.display_main();
				cout << "First: " << first_name << endl;
				cout << "Last: " << last_name << endl;
				cout << "Role: " << role << endl;
				cout << "Age: " << get_age(dob, date) << endl;
			}
			/**
			   insert player into database
			*/
			L.push_back(first_name, last_name, role, dob, A);
			cout << endl;
			cout << last_name << ", " << first_name << " added to database." << endl << endl;
			menu.pause();
			break;
		case 2:
			/**
			   print players
			*/
			do
			{
				menu.display_print();
				cin >> selection;
				switch (selection) {
				case '1':
					for (pos = L.begin(); !pos.equals(L.end()); pos.next())
					{
						cout << "NAME: " << pos.get().last << ", " << pos.get().first;
						cout << "; AGE: " << get_age(pos.get().dob, date);
						cout << "; ROLE: " << pos.get().role << endl;

						for (int i = 0; i < 27; i++)
						{
							//if ((i == 9) || (i == 18))
							//	cout << endl;

							//cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << pos.get().A[i];
							in = pos.get().A[i];
							//arrayA[pos.get().tag][i] = pos.get().A[i];

							if ((i != FAC) && (i != AGG))
								int_stk.push(in);

						}

						cout << endl;
						cout << "Q = " << "{" << int_stk.quartile(1) << ", " << int_stk.quartile(2) << ", " << int_stk.quartile(3) << "}; ";
						cout << "AVG: " << int_stk.average();
						cout << "; SD: " << setprecision(2);
						cout << setw(2) << setfill('0') << int_stk.stdev();
						z_ov = (int_stk.average() - L.pop_avg()) / L.pop_stdev();
						cout << "; Z = " << z_ov;

						while (!int_stk.empty())
							int_stk.pop();


						if (z_ov >= 0.65)
						{
							grade = 'A';
							++freq[4];
						}
						else if ((z_ov >= 0.20) && (z_ov < 0.65))
						{
							grade = 'B';
							++freq[3];
						}
						else if ((z_ov >= -0.20) && (z_ov < +0.20))
						{
							grade = 'C';
							++freq[2];
						}
						else if ((z_ov >= -0.55) && (z_ov < -0.20))
						{
							grade = 'D';
							++freq[1];
						}
						else
						{
							grade = 'F';
							++freq[0];
						}

						cout << "; GRD: " << grade << endl;
						grades[pos.get().tag] = grade;
						cout << endl;

					}
					cout << endl << "-----------------------------------------------------------------------" << endl;

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
				case '2':
					break;
				case  '3':
					/*				cout << "Enter role: ";
									cin >> role;*/
					cout << "Enter GRADE: ";
					cin >> grade;
					cout << grade;
					cout << endl;

					cout << "       AVG     STD     1S" << endl;

		
					for (int row = 0; row < 27; row++)
					{
						pos = L.begin();
						j = 0;
						while (!pos.equals(L.end()))
						{
						
							while (getAttribute(Attribute(j)) != getAttributeFLTR(row))
							{
								j++;
							}

							if (pos.get().grade == grade) //*/(get_age(pos.get().dob, date) <= AGE)/*((pos.get().role == role) &&*/
							{
								int_stk.push(pos.get().A[j]);
							}
							pos.next();
						}



						cout << getAttribute(Attribute(j)) << " ";
						cout << setw(8) << setprecision(3);
						cout << int_stk.average() << setw(8);
						cout << int_stk.stdev() << "   " << setw(4);
						cout << setprecision(2) << ceil((int_stk.average() - 0.50*int_stk.stdev())) << endl;
						int_stk.pop_all();  //next row
					}
		
					
					cout << "n = " << j/27;
					cout << endl;
					menu.pause();
					break;
				case '4':
					break;
				default:
					cout << "Error!" << endl;
				}
			} while (selection != '4');
			break;
		case 3:
			/**
				search database record_data.txt
			*/
			cout << "Enter name of player to search for:" << endl;
			cout << "First: ";
			getline(cin, first_name);
			cout << "Last: ";
			getline(cin, last_name);
			ptr = L.search_list(first_name, last_name);

			if (ptr)
			{
				cout << endl << "Player found!!" << endl << endl;
				cout << "Name: " << ptr->data.last << ", " << ptr->data.first << endl;
				cout << "Role: " << ptr->data.role << endl;
				cout << "Age: " << get_age(ptr->data.dob, date) << endl << endl;

				cout << "Edit Player? (y/n): ";
				cin >> line;
				cin.ignore();
				if ((line == "y") || (line == "yes"))
				{
					do
					{
						menu.display_edit();
						cin >> selection;
						cin.ignore();
						cout << endl;
						switch (selection)
						{
						case '1':
							cout << "Role: ";
							cin >> role;
							cout << "Done" << endl;
							ptr->data.role = role;
							menu.pause();
							break;
						case '2':
							cout << "Enter date of birth: ";
							dob = get_dob();
							ptr->data.dob = dob;
							cout << "Done" << endl;
							menu.pause();
							break;
						case '3':

							for (int i = 0; i < 27; i++)
							{
								cout << getAttribute(Attribute(i)) << ": " << setw(3) << left << ptr->data.A[i];
								cout << endl;

								cout << "Edit? ";
								cin >> line;

								if (line == "y")
								{
									cout << getAttribute(Attribute(i)) << ": ";
									while (cin >> in)
									{
										stringstream ss(in);
										if (in <= 20)
											break;
										else
											cout << "Error!" << endl;
										cout << getAttribute(Attribute(i)) << ": ";
									}
									ptr->data.A[i] = in;
								}
								menu.display_edit();
							}
							menu.pause();
							break;
						case '4':
							cout << "returning to main menu ..." << endl;
							break;
						default:
							cout << "Error!" << endl;
						}
					} while (selection != '4');
				}
			}
			else
				cout << endl << "Player NOT found!!" << endl;
			menu.pause();
			break;

		case 4:
			/**
				load database from record_data.txt
			*/
			L.load_list("record_data.txt");
			menu.pause();
			break;
		case 5:
			/**
				save database to record_data.txt
			*/
			L.save_list("record_data.txt");
			menu.pause();
			break;
		case 6:
			/**
				get feature values for clustering
			*/

			for (pos = L.begin(); !pos.equals(L.end()); pos.next())
			{
				for (int i = 0; i < 27; i++)
					if ((i != FAC) || (i != AGG))
						int_stk.push(pos.get().A[i]);			



				for (int j = 0; j < 3; j++)
				{
					arrayA[pos.get().tag][j] = int_stk.quartile(j + 1);
					//cout << arrayA[pos.get().tag][j] << " ";
				}
				//cout << endl;
				int_stk.pop_all();
				
			}

			/**
				 find transpose of data_matrix
			*/




			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					arrayA_T[j][i] = arrayA[i][j];
				}
			}


			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					arrayA_COV[j][i] = 0.0;
					for (int k = 0; k < N; k++)
					{
						arrayA_COV[j][i] += arrayA_T[j][k] * arrayA[k][i] / (N - 1);
					}
				}
			}

			cout << "Covariance Matrix" << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << arrayA_COV[j][i] << " ";
				}
				cout << endl;
			}



			/* solve eignen values using jacobi matrix */
			for (int count = 1; count <= 15; count++) {
				for (int j = 0; j < M - 1; j++) {
					for (int k = j + 1; k < M; k++) {
						num = 0.0;
						den = 0.0;
						for (int i = 0; i < M; i++) {
							num += 2 * arrayA_COV[i][j] * arrayA_COV[i][k];
							den += (arrayA_COV[i][j] + arrayA_COV[i][k]) * (arrayA_COV[i][j] - arrayA_COV[i][k]);
						}
						if (abs(num) < eps && den >= 0) {
							break; //exit for loop
						}
						// find sin(2*theta) and cos(2*theta)
						if (abs(num) <= abs(den)) {    // 2*sigma(xy) <= |sqrt(x2-y2)|
							Tan2 = abs(num) / abs(den);
							Cos2 = 1 / sqrt(1 + Tan2 * Tan2);
							Sin2 = Tan2 * Cos2;
						}
						else {
							Cot2 = abs(den) / abs(num);
							Sin2 = 1 / sqrt(1 + Cot2 * Cot2);
							Cos2 = Cot2 * Sin2;
						}
						// condition +/- for cos(theta) and sin(theta)
						Cos_ = sqrt((1 + Cos2) / 2);
						Sin_ = Sin2 / (2 * Cos_);
						if (den < 0) {
							tmp = Cos_;
							Cos_ = Sin_;
							Sin_ = tmp;
						}
						Sin_ = m.sgn(num) * Sin_;
						//	 perform rotation on matrix
						for (int i = 0; i < M; i++) {
							tmp = arrayA_COV[i][j];
							arrayA_COV[i][j] = tmp * Cos_ + arrayA_COV[i][k] * Sin_;
							arrayA_COV[i][k] = -tmp * Sin_ + arrayA_COV[i][k] * Cos_;
						}
					}// NEXT k
				}// NEXT j

				sumsqr = 0;
				for (int c = 0; c < M; c++) {
					sumsqr += arrayA_COV[0][c] * arrayA_COV[c][0];
				}
				// display some results from the iteration.
			/*	if (count > 5) {
					cout << "\t\t" << "---------------- " << "count:" << count << " ---------------" << endl;
					cout << "\t\t" << "prev_sumsqr = " << prev_sumsqr << ";\n\t\t" << "sumsqr = " << sumsqr << ";\n";
					cout << "\t\t" << "Error:" << abs(sumsqr - prev_sumsqr) << endl;
				}*/
				// if error is small break loop else continue
				if (abs(sumsqr - prev_sumsqr) < eps) {
					break;
				}
				else { prev_sumsqr = sumsqr; }
			}// NEXT count

			for (int j = 0; j < M; j++)
			{
				for (int k = 0; k < M; k++)
				{
					eval[j] += (arrayA_COV[k][j])*(arrayA_COV[k][j]);

				}
				eval[j] = sqrt(eval[j]);
			}
			// find eigen vector
			for (int i = 0; i < 2; i++) //column
			{
				for (j = 0; j < M; j++) //row
				{
					evec[j][i] = arrayA_COV[j][i] / eval[i];
				}
			}

			cout << endl;
			for (int i = 0; i < M;i++) {
				cout << "evec" << i << ": ";
				for (j = 0; j < 2; j++)
				{
					cout << setprecision(3) << left << evec[i][j] << "  ";
				}
				cout << endl;
			}

			///////////////////////////void EIG::Set_Clusters(int val)
		//	// apply feature vectors to get components for players
			pos = L.begin();
			for (int rows = 0; rows < N; rows++) {
				cout << "Name = " << pos.get().last << " loaded." << endl;
				cout << "Pt: ";
				for (int k = 0; k < 2; k++) {
					sum = 0.0;
					for (int i = 0; i < M; i++)
					{
						sum += arrayA[rows][i] * evec[i][k];
					}
					rec_fvecs[rows][k] = sum;
					//cout << sum << " ";

					//			//			//	find min & max of feature components of data_matrix
					if (rows == 0)
					{
						min[k] = rec_fvecs[rows][k];//	int min = a; 
						max[k] = rec_fvecs[rows][k];
					}

			

					else if (rec_fvecs[rows][k] < min[k]) //minimum
					{
						min[k] = rec_fvecs[rows][k];
					}
					else if (rec_fvecs[rows][k] > max[k])
					{
						max[k] = rec_fvecs[rows][k];
					}
					
					cout << rec_fvecs[rows][k] << " ";
				}// Next k
				cout << endl;
				pos.next();
			}// Next rows

			//	 //-------------------------------------------------------
			////	 // NORMALIZE VECTORS
				//double v_new, v;
				//for (int i = 0; i < N; i++)
				//{
				//	for (int k = 0; k < 2; k++)
				//	{
				//	v = rec_fvecs[i][k];
				//		v_new = ((v - min[k]) / (max[k] - min[k])) * (new_max - new_min) + new_min;
				//		rec_fvecs[i][k] = v_new;

				//		if (k == 1)
				//		{
				//			v = rec_fvecs[i][k];
				//			v_new = ((v - min[k]) / (max[k] - min[k])) * (1.0) - 0.5;
				//			rec_fvecs[i][k] = v_new;
				//		}
				//	}
				//}

				//--------------------------------------------------------
			//	// INTIALIZE CLUSTERS
				//int count = 0;
				//// generate initial clusters
			clusters[0][0] = min[0]; clusters[0][1] = min[1];
			for (int i = 1; i < 5;i++)
			{
				count = 0;
				while (count < 2){
					if (count == 0)
					{
						clusters[i][count] = clusters[i - 1][count] + (2.0) / (5 - 1);
					}
					else
					{
						clusters[i][count] = clusters[i - 1][count] + (1.0) / (5 - 1);
												 //if ((abs(clusters[i][count])) < 1E-6)
												 //{
												 //	clusters[i][count] = 0.0;
												 //}
					}
					count++;
				}
			}

			cout << endl << "Initial Clusters: " << endl;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << clusters[i][j] << " ";
				}
				cout << endl;
			}

			for (unsigned int iter = 0; iter < 50; iter++)
			{

				//// get weights for data
				den = 0.0;
				num = 0.0;
				sum = 0.0;

				for (int i = 0; i < N; i++) {
					//cout << rec_fvecs[i][0] << " " << rec_fvecs[i][1] << endl;
					for (int j = 0; j < 5;j++)
					{
						d_j = m.distance(rec_fvecs[i][0], rec_fvecs[i][1], clusters[j][0], clusters[j][1]);
						num = pow(d_j, 2.0 / (3.0 - 1));

						sum = 0.0;
						k = 0;
						while (k < 5)
						{

							d_k = m.distance(rec_fvecs[i][0], rec_fvecs[i][1], clusters[k][0], clusters[k][1]);
							den = pow(d_k, 2.0 / (3.0 - 1)); //* f_clust_Dist[i][k]; //m = 2;
							sum += num / den;
							k++;
						}
						weights[i][j] = 1 / sum;
						//	cout << weights[i][j] << " ";
					}
					//	cout << endl;
				}

				////--------------------------------------------------
				//  update centroids
				k = 0;
				j = 0;

				den = 0.0;
				num = 0.0;
				//cout << endl << "CLUSTERS @ ITERATION# " << iter << endl;
				while (k < 5)
				{
					j = 0;
					while (j < 2)
					{
						num = 0.0;
						den = 0.0;
						for (int i = 0; i < N; i++)
						{
							num += pow(weights[i][k], 3.0) * (rec_fvecs[i][j]);
							den += pow(weights[i][k], 3.0);
						}
						sum = num / den;
						clusters[k][j] = sum;
						//cout << clusters[k][j] << " ";
						j++;
					}
					//cout << endl;
					k++;
				}
				////============== END OF ITERATION ===========
				//cout << "END OF ITERATION# " << iter << endl;
			}



			////============== get ranks
			//empty stack
			dbl_stk.pop_all();

			//pos = 0;
			pos = L.begin();
			for (int rows = 0; rows < N; rows++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (k == 0)
						tmp = weights[rows][k];

					dbl_stk.push(weights[rows][k]);
				}

				while (!dbl_stk.empty())
				{
					//cout << tmp << " < " << dbl_stk.top() << " ? ";
					if (tmp < dbl_stk.top())
					{
						tmp = dbl_stk.top();
					}
					dbl_stk.pop();
				}

				count = 1;
				while (count <= 5)
				{
					if (tmp == weights[rows][count-1])
					{
						break;
					}
					count++;
				}

				cout << "Weights: " << pos.get().last << endl;
				for (int k = 0; k < 5; k++)
				{
					cout << weights[rows][k] << " ";
				}
				cout << endl;
				grades[rows] = count;
				pos.set(grades[rows]);
				cout << tmp << " " << pos.get().grade << endl;

				pos.next();
			}

			
			menu.pause();
			break;
		case 7:
			cout << "Exiting program ... " << endl;
			exit(1);
		default:
			cout << "Not a valid choice!" << endl;
		} 
		} while (menu.choice() != 7);

	
	return 0;
}