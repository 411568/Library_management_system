/*
	This class represents the library. It contains a list of all the items in the library and it's users.
	Properties:
		- libraryItems - vector of all the books in the library
		- libraryUsers - vector of all the students

	Methods:
		- readUser/BookFile() - read data from files
		- saveToFiles() - saves data to file (uses the fileReadWrite)
		- checkOutBook() - takes a student ID and book ID and checks out a book
		- returnBook() - returns a book to the library and returns the amount of days it's been overdue
		- reserveBook() - reserves a single book for a student
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

	//deleting the constructors because it's a singleton
	Library() {};

	Library(Library const& copy);
	Library& operator=(Library const&) = delete;
	Library& operator=(Library const&&) = delete;
	Library(Library const&& copy) = delete;

public:
	static Library& GetInstance();
	
	//get the list of users from file
	void readUserFile();

	//get the list of books from file
	void readBookFile();

	//save all the data back to files
	void saveToFiles();


	//checkOUT a book
	void checkOutBook(const std::string& studID, const int& bID);

	//return a book (returns the amount of money you have to pay if overdue)
	int returnBook(const std::string& studID, const int& bID);

	//reserve book
	void reserveBook(const std::string& studID, const int& bID);


	//setters
	void addItem(Book input);
	void addUser(Student input);

	//getters
	std::vector<Book> getItems();
	std::vector<Student> getUsers();
};
