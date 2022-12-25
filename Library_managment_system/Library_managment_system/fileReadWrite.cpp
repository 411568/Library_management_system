#include "fileReadWrite.h"

void fileReadWrite::readUserDatabase(std::vector<Student>& students)
{
	std::fstream file("LibraryUserDatabase.txt");
	Student tempUser;
	
	for( std::string inputLine; std::getline(file, inputLine); )
	{
		std::vector<std::string> v;
		std::string delimiter_char = ";";
		size_t pos = 0;
		while ((pos = inputLine.find(delimiter_char)) != std::string::npos)
		{
			v.push_back(inputLine.substr(0, pos));
			inputLine.erase(0, pos + delimiter_char.length());
		}

		tempUser.setName(v[0]);
		tempUser.setSurname(v[1]);
		tempUser.setAge(std::stoi(v[2]));
		tempUser.setUniID(v[3]);

		students.push_back(tempUser);
	}
}


void fileReadWrite::readBookDatabase(std::vector<Book>& books)
{
	std::fstream file("LibraryItemDatabase.txt");
	Book tempBook;
	
	for(std::string inputLine; std::getline(file, inputLine); )
	{
		std::vector<std::string> v;
		std::string delimiter_char = ";";
		size_t pos = 0;
		while ((pos = inputLine.find(delimiter_char)) != std::string::npos)
		{
			v.push_back(inputLine.substr(0, pos));
			inputLine.erase(0, pos + delimiter_char.length());
		}

		tempBook.setTitle(v[0]);
		tempBook.setInternalID(std::stoi(v[1]));
		if (v[2] == "1")
		{
			tempBook.setReserved(true);
		}
		else
		{
			tempBook.setReserved(false);
		}
		if (v[3] == "1")
		{
			tempBook.setChecked(true);
		}
		else
		{
			tempBook.setChecked(false);
		}
		tempBook.setReturnDate(v[4]);
		tempBook.setReservedDate(v[5]);
		tempBook.setISBN(v[6]);
		tempBook.setPageCount(std::stoi(v[7]));

		books.push_back(tempBook);
	}
}
