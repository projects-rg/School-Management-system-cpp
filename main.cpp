#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<cstring>


using namespace std;

void addStudent();
void StudentLogin();
void StaffLogin();
void Exit();

int main() {

	system("cls"); //clear screen
	int choice;
	
	//prints choices to user
	cout << "***** School Management System *****\n";
	cout << "1.Add Student\n";
	cout << "2.Student Login\n";
	cout << "3.Staff Login\n";
	cout << "4.Exit\n";
	cout << "\nPLEASE ENTER A NUMBER BELOW: \n";

	//gets user input
	cin >> choice;
	switch (choice) {
	case 1:
		addStudent();
		break;
	case 2:
		StudentLogin();
		break;
	case 3:
		StaffLogin();
		break;
	case 4:
		Exit();
		break;
	default:
		cout << "Sorry, Wrong choice Selected... Please try again\n";
		main();
	}

	
}


void addStudent() {
	char id[30];
	char name[30];
	string staffID = "";
	string s;
	string line;
	int n = 0;
	int len = 0;
	int length = 0;
	int count = 0;
	string inital = "00";


	ifstream filename("data.txt");
	for (int i = 0; getline(filename, line); ++i) {
		count++;
	}

	cout << "Enter the number of students you would like to enter: ";
	cin >> n;

	count = count + n;

	for (int i = 0;i < n;i++) {
		ofstream outfile;
		outfile.open("data.txt", ios::app);

		cout << "Enter Student ID: ";
		cin >> s;
		

		while (s.size() < 9) {
			s.append(9 - s.length(), ' ');
		}

		strcpy(id, s.c_str());
		
		outfile << id << "\t";

		cout << "Enter the Students Full name: ";
		cin >> s;;
		while (s.size() < 15) {
			s.append(15 - s.length(), ' ');
		}

		strcpy(name, s.c_str());

		outfile << name << "\t";

		outfile << inital << "\t";
		outfile << inital << "\t";

		cout << "Enter your Staff ID: ";
		cin >> staffID;

		outfile << staffID << endl;

	}
	

}

void StudentLogin() {
	system("cls");
	char info[30];
	char studentId[8];
	cout << "Please Enter your Student Number: ";
	cin >> studentId;
	ifstream file;
	int checkFile = 0;
	file.open("data.txt", ios::in);

	while (file >> info) {
		if (strcmp(info, studentId) == 0) {
			cout<< "\nStudent ID: " << info<< endl;
			file >> info;
			cout << "Full Name: " << info << endl;

			file >> info;
			cout << "Class CSE1001 mark: " << info<< endl;

			file >> info;
			cout << "Class CSE1002 mark: " << info<< endl;
			
			file >> info;
			cout << "Staff ID: " << info << endl;
			
			file.close();
			checkFile = 1;
		}
	}
	if (checkFile == 0) {
		cout << "Sorry, That Student ID doesn't Exist.."<< endl;
		cin.get();
		main();
	}

}

void StaffLogin() {
	int choice;
	string line;
	char info[30];
	int count = 0;
	char subcode[15];
	ifstream infile;
	int check = 0;
	string search, readout, score;

	ifstream filename("data.txt");
	for (int i = 0; getline(filename, line); ++i) {
		count++;
	}

	cout << "Enter your subject code: ";
	cin >> subcode;
	string code1 = "CSE1001", code2 = "CSE1002",
		mark = "";

	cout << "\nAvailable operations: \n1. Add data "
		"about marks\n"
		<< "2. View data\nEnter option: ";
	cin >> choice;

	if (choice == 1) {
		cout
			<< "Warning! You would need to add mark"
			<< "details for all the students!"
			<< endl;
		for (int i = 0; i < count; i++) {
			fstream file("data.txt");

			// The seek in file has been done
			// according to the length
			// of the data being inserted. It needs
			// to adjusted accordingly for different
			// lengths of data.

			if (strcmp(subcode, code1.c_str())
				== 0) {
				file.seekp(26 + 41 * i,
					std::ios_base::beg);
				cout << "Enter the mark of student#"
					<< (i + 1) << " : ";
				cin >> mark;
				file.write(mark.c_str(), 2);
			}

			if (strcmp(subcode, code2.c_str())
				== 0) {
				file.seekp(29 + 41 * i,
					std::ios_base::beg);
				cout << "Enter the mark of student#"
					<< (i + 1) << " : ";
				cin >> mark;
				file.write(mark.c_str(), 2);
			}
		}
	}

	// This loop is used to view marks of a student.
	// The extra infile commands have been used to
	// get a specific mark only since the data has
	// been separated by a tabspace.

	else if (choice == 2) {
		infile.open("data.txt", ios::in);
		if (strcmp(subcode, code1.c_str()) == 0) {
			cout << "Registration number - Marks\n"
				<< endl;
			while (infile >> info) {
				cout << info;
				infile >> info;
				infile >> info;
				cout << " - " << info << endl;
				infile >> info;
				infile >> info;
				check = 1;
			}
		}

		infile.close();
		infile.open("data.txt", ios::in);

		if (strcmp(subcode, code2.c_str()) == 0) {
			cout << "Registration number - Marks\n"
				<< endl;
			while (infile >> info) {
				cout << info;
				infile >> info;
				infile >> info;
				infile >> info;
				cout << " - " << info << endl;
				infile >> info;
				check = 1;
			}
		}
	}

	infile.close();
}



void Exit() {
	cout << "Thank you for using the School Managament System!";
}