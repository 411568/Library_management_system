/*
	This is the console user interface for the library managment system
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
	User_Interface() = default;
	User_Interface(const User_Interface&) = delete;
	User_Interface& operator=(const User_Interface&) = delete;
	User_Interface(User_Interface&&) = delete;
	User_Interface& operator=(User_Interface&&) = delete;

	//submenus
	void StudentMenu();

	void StudentBookCheck(std::string studentID);

	void StudentBookReturn(std::string studentID);


public:
	//start the main interface
	void start();
};

