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

	//setters
	void addItem(Book input);
	void addUser(Student input);

	//getters
	std::vector<Book> getItems();
	std::vector<Student> getUsers();
};
