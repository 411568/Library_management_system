#include "Library.h"

std::vector<Book> Library::libraryItems;
std::vector<Student> Library::libraryUsers;

Library& Library::GetInstance()
{
	static Library* singleton = new Library();
	return *singleton;
}

void Library::readUserFile()
{
	fileReadWrite::readUserDatabase(libraryUsers);
}

void Library::readBookFile()
{
	fileReadWrite::readBookDatabase(libraryItems);
}

void Library::addItem(Book input)
{
	libraryItems.push_back(input);
}

void Library::addUser(Student input)
{
	libraryUsers.push_back(input);
}

std::vector<Book> Library::getItems() 
{
	return libraryItems;
}

std::vector<Student> Library::getUsers() 
{
	return libraryUsers;
}


void Library::checkOutBook(const std::string& studID, const int& bID)
{
	int j = 0;
	for (; j < libraryItems.size(); j++)
	{
		if (libraryItems[j].getInternalID() == bID)
		{
			libraryItems[j].setChecked(true);
			libraryItems[j].setReturnDate(DateParser::getReturnDate());
			break;
		}
	}

	for (int i = 0; i < libraryUsers.size(); i++)
	{
		if (libraryUsers[i].getUniID() == studID)
		{
			libraryUsers[i].addBook(libraryItems[j]);
			break;
		}
	}
}


int Library::returnBook(const std::string& studID, const int& bID)
{
	std::string returnDate;
	std::string todaysDate = DateParser::getCurrentDate();
	for (int i = 0; i < libraryItems.size(); i++)
	{
		if (libraryItems[i].getInternalID() == bID)
		{
			returnDate = libraryItems[i].getReturnDate();

			libraryItems[i].setChecked(false);
			libraryItems[i].setReturnDate("0000_00_00");
			break;
		}
	}

	int j = 0;
	for (; j < libraryUsers.size(); j++)
	{
		if (libraryUsers[j].getUniID() == studID)
		{
			//delete that book from the checked out ones
			libraryUsers[j].removeBook(bID);
			break;
		}
	}
	return 0;
	
	std::string yRet = returnDate.substr(0, 4);
	std::string mRet = returnDate.substr(5, 2); 

	std::string yNow = todaysDate.substr(0, 4);
	std::string mNow = todaysDate.substr(5, 2);

	if (std::stoi(yRet) == std::stoi(yNow))
	{
		if (std::stoi(mRet) >= std::stoi(mNow))
		{
			//nothing to pay
			return 0;
		}
		else
		{
			//x months overdue - x money to pay
			return std::stoi(mNow) - std::stoi(mRet);
		}
	}
	else
	{
		//x months overdue - x money to pay
		return (std::stoi(mNow) + (12 - std::stoi(mRet)));
	}
}
