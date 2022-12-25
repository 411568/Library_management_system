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
