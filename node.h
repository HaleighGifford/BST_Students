//*****************************************************************************************************
//
//		File:			    node.h
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
//						 3.	  studentList.cpp
//						 4.	  studentFile.txt
//		
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;

	union
	{
		Node<TYPE> * next;
		Node<TYPE> * left;
	};
	
	union
	{
		Node<TYPE> * prev;
		Node<TYPE> * right;
	};

	Node();
	Node(const TYPE & d, Node<TYPE> * n = nullptr, Node<TYPE> * p = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> ::Node(const TYPE & d, Node<TYPE> * n, Node<TYPE> * p)
{
	data = d;
	next = n;
	prev = p;
}

//****************************************************************************************************

#endif
