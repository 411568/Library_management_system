/*
	This class is used by the Library object to read and write its data from/to files.
	It contains:
		- readUser/BookDatabase() - those methods take the vector from the library object and add objects to it based on the file content
		- saveUser/ItemDaatabase() - those two save the library object content to files
*/

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
