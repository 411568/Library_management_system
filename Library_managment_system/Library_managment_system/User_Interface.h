/*
	This is the console user interface for the library managment system
	The main menu is shown by the "start()" method, which in turn uses all the other private methods to show 
	additional submenus for the student/admin.
	isNumber() method checks whether an input string is a number - it is used in some input checks
*/

#pragma once
#include "User.h"
#include "Student.h"
#include "Book.h"
#include "Lib_Item.h"
#include "Library.h"
#include "fileReadWrite.h"
#include <stdlib.h>
#include <iostream>
#include <string>

class User_Interface
{
private:
	//submenus
	void StudentMenu();

	void StudentBookCheck(std::string studentID);

	void StudentBookReturn(std::string studentID);

	void StudentBookReserve(std::string studentID);

	void AdminLogin();

	void AdminMenu();

	void ShowAllUsers();

	void ShowSingleUser(std::string studentID);

	void ShowAllBooks();

	void ShowSingleBook(int bID);

	void AdminAddUser();

	void AdminAddBook();

	void AdminOverdueReport();

	bool isNumber(const std::string& s);

public:
	//start the main interface
	void start();

	static User_Interface& GetInstance();
};

