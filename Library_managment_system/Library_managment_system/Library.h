/*
	This class represents the library. It contains a list of all the items in the library and it's users.
*/

#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Book.h"
#include "User.h"
#include "Student.h"
#include "Book.h"
#include "fileReadWrite.h"
#include "DateParser.h"

class Library
{
private:
	//list of all the items in the library
	static std::vector<Book> libraryItems;

	//list of all the students
	static std::vector<Student> libraryUsers;

public:
	static Library& GetInstance();
	
	//get the list of users from file
	void readUserFile();

	//get the list of books from file
	void readBookFile();


	//checkOUT a book
	void checkOutBook(const std::string& studID, const int& bID);

	//return a book (returns the amount of money you have to pay if overdue)
	int returnBook(const std::string& studID, const int& bID);

	//setters
	void addItem(Book input);
	void addUser(Student input);

	//getters
	std::vector<Book> getItems();
	std::vector<Student> getUsers();
};
