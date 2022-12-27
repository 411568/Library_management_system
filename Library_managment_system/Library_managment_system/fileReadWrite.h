#pragma once
#include <vector>
#include <map>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include "User.h"
#include "Student.h"
#include "Library.h"


class fileReadWrite
{
public:
	//reads the user database and writes it to a vector 
	static void readUserDatabase(std::vector<Student>& students);

	//reads the book database and writes it to a vector 
	static void readBookDatabase(std::vector<Book>& books);

	//saves the user database
	static void saveUserDatabase(const std::vector<Student>& students);

	//saves the book database 
	static void saveItemDatabase(const std::vector<Book>& books);
};
