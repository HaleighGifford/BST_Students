//*****************************************************************************************************
//
//		File:			    studentList.cpp
//		
//		Student:			Haleigh Cates
//
//		Assignment:	 	    Program  #11
//
//		Course Name:		Data Structures II  
//
//		Course Number:		COSC 3100 - 01
//
//		Due:			    April 3, 2019 
//
//
//		This program uses a Binary Search Tree to keep the academic records
//		for each student in a college.
//
//		Other files required:
//                       1.   BST.h
//						 2.	  student.h
//						 3.	  node.h
//						 4.	  studentFile.txt
//		
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
#include "student.h"
#include "BST.h"

//****************************************************************************************************

void process(BST<Student> &);
char getChoice();
void buildList(BST<Student> &);
void addStudent(BST<Student> &);
void findStudent(BST<Student> &);
void updateStudent(BST<Student> &);
void removeStudent(BST<Student> &);
void printList(BST<Student> &);
void display1student(Student stu);
void listInfo(BST<Student> &);

//****************************************************************************************************

int main()
{
	BST<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//****************************************************************************************************

void process(BST<Student> & studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
			case 'A':	addStudent(studentList);
						break;
			case 'S':	findStudent(studentList);
						break;
			case 'U':	updateStudent(studentList);
						break;
			case 'D':	removeStudent(studentList);
						break;
			case 'P':	printList(studentList);
						break;
			case 'X':	listInfo(studentList);
						break;
			case 'Q':	break;
		}
	} 
	while (choice != 'Q');
}

//****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << endl << "========MENU=======\n"
		 << " A:   Add a new Student \n"
		 << " S:   Search for a Student \n"
		 << " U:   Update a Student \n"
		 << " D:   Delete a Student \n"
		 << " P:   Print Student List \n"
		 << " X:   List Information \n"
		 << " Q:   Quit     \n\n"
		 << "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice); 

		switch (choice)
		{
			case 'A':
			case 'S':
			case 'U':
			case 'D':
			case 'P':
			case 'X':
			case 'Q':	valid = true;
						break;
			default:	valid = false;
						cout << "\aInvalid choice\n" << "Please try again:";
						break;
		}
	} 
	while (!valid);

	return choice;
}

//****************************************************************************************************

void buildList(BST<Student> & studentList)
{
	Student student;
	ifstream studentData;
	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//****************************************************************************************************

void addStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the student information\n" << right << setw(15) << "id: ";
	cin >> student.id;

	cin.ignore();

	cout << right << setw(15) << "name: ";
	cin.getline(student.name, 50);

	cout << right << setw(15) << "city, state: ";
	cin.getline(student.citystate, 50);

	cout << right << setw(15) << "phone #: ";
	cin >> student.phone;

	cout << right << setw(15) << "gender: ";
	cin >> student.gender;

	cout << right << setw(15) << "year: ";
	cin >> student.year;

	cout << right << setw(15) << "credits: ";
	cin >> student.credits;

	cout << right << setw(15) << "gpa: ";
	cin >> student.gpa;

	cout << right << setw(15) << "major: ";
	cin >> student.major;

	cout << endl;

	if (studentList.insert(student))
	{
		if (studentList.retrieve(student))
		{
			cout << "Student successfully inserted." << endl;
			cout << student << endl;
		}
		else
		{
			cout << "Unable to find student." << endl;
		}
	}
	else
	{
		cout << "Unable to insert student." << endl;
	}
}

//****************************************************************************************************

void findStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the student id: ";
	cin >> student.id;

	if (studentList.retrieve(student))
	{
		cout << student << endl;
	}
	else
	{
		cout << endl << "Unable to find student." << endl;
	}
}

//****************************************************************************************************

void updateStudent(BST<Student> & studentList)
{
	Student student;

	cout << "Enter the id of the student you want to update: ";
	cin >> student.id;

	if (studentList.retrieve(student))
	{
		cout << student;

		cin.ignore();

		cout << right << setw(15) << "update name: ";
		cin.getline(student.name, 50);

		cout << right << setw(15) << "update city, state: ";
		cin.getline(student.citystate, 50);

		cout << right << setw(15) << "update phone #: ";
		cin >> student.phone;

		cout << right << setw(15) << "update gender: ";
		cin >> student.gender;

		cout << right << setw(15) << "update year: ";
		cin >> student.year;

		cout << right << setw(15) << "update credits: ";
		cin >> student.credits;

		cout << right << setw(15) << "update gpa: ";
		cin >> student.gpa;

		cout << right << setw(15) << "update major: ";
		cin >> student.major;

		cout << endl;
	}
	else
	{
		cout << "Unable to find student." << endl;
	}

	if (studentList.update(student))
	{
		if (studentList.retrieve(student))
		{
			cout << "Student successfully inserted." << endl;
			cout << student;
		}
		else
		{
			cout << "Unable to find student." << endl;
		}
	}
	else
	{
		cout << "Unable to update student." << endl;
	}
}

//****************************************************************************************************

void removeStudent(BST<Student> & studentList)
{
	Student student;
	char answer;

	cout << "Enter the student id: ";
	cin >> student.id;

	if (studentList.retrieve(student))
	{
		cout << "\nIs this the student you want to remove?\n"
			 << student << "Y or N: ";
		cin >> answer;
	}
	else
	{
		cout << "Unable to find student." << endl;
	}

	if (toupper(answer) == 'Y')
	{
		if (studentList.remove(student))
			cout << "Student removed." << endl << endl;
		else
			cout << "Student NOT removed." << endl << endl;
	}
	else if (toupper(answer) == 'N')
		cout << "Student NOT removed." << endl << endl;
}

//****************************************************************************************************

void printList(BST<Student> & studentList)
{
	cout << "\nStudent List" << endl;
	cout << left << setw(10) << "ID"
		 << left << setw(26) << "NAME"
		 << left << setw(10) << "MAJOR"
		 << left << setw(15) << "GPA" << endl;

	studentList.inorderTraverse(display1student);
}

//****************************************************************************************************

void display1student(Student stu)
{
	cout << left << setw(10) << stu.id
		 << left << setw(26) << stu.name
		 << left << setw(10) << stu.major
		 << left << setw(15) << stu.gpa << endl;
}

//****************************************************************************************************

void listInfo(BST<Student> & studentList)
{
	cout << right << setw(19) << "Num of Students: " << studentList.getCount() << endl
		 << right << setw(19) << "Height of Tree: " << studentList.getHt() << endl;

	if (studentList.isEmpty())
		cout << right << setw(21) << "isEmpty: Yes" << endl;
	else
		cout << right << setw(21) << "isEmpty: No" << endl;

	if (studentList.isFull())
		cout << right << setw(21) << "isFull: Yes" << endl;
	else
		cout << right << setw(21) << "isFull: No" << endl;

	if (studentList.isComplete())
		cout << right << setw(21) << "isComplete: Yes" << endl;
	else
		cout << right << setw(21) << "isComplete: No" << endl;

	if (studentList.isBalanced())
		cout << right << setw(21) << "isBalanced: Yes" << endl;
	else
		cout << right << setw(21) << "isBalanced: No" << endl;
}

//****************************************************************************************************

/*

========MENU=======
 A:   Add a new Student
 S:   Search for a Student
 U:   Update a Student
 D:   Delete a Student
 P:   Print Student List
 X:   List Information
 Q:   Quit

Enter your choice: x
  Num of Students: 61
   Height of Tree: 12
          isEmpty: No
           isFull: No
       isComplete: No
       isBalanced: No

========MENU=======
 A:   Add a new Student
 S:   Search for a Student
 U:   Update a Student
 D:   Delete a Student
 P:   Print Student List
 X:   List Information
 Q:   Quit

Enter your choice:
*/