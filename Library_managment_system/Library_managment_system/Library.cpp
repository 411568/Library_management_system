#include "Library.h"


Library& Library::GetInstance()
{
	static Library* singleton = new Library();
	return *singleton;
}

void Library::addItem(std::shared_ptr<Lib_Item> input)
{
	libraryItems.push_back(input);
}

void Library::addUser(std::shared_ptr<User> input)
{
	libraryUsers.push_back(input);
}

std::vector<std::shared_ptr<Lib_Item>> Library::getItems() 
{
	return libraryItems;
}

std::vector<std::shared_ptr<User>> Library::getUsers() 
{
	return libraryUsers;
}
