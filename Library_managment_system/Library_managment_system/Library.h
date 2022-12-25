/*
	This class represents the library. It contains a list of all the items in the library and it's users.
*/

#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Lib_Item.h"
#include "User.h"
#include "Student.h"
#include "Book.h"

class Library
{
private:
	//list of all the items in the library
	std::vector<std::shared_ptr<Lib_Item>> libraryItems;

	//list of all the users
	std::vector<std::shared_ptr<User>> libraryUsers;

public:
	static Library& GetInstance();

	//setters
	void addItem(std::shared_ptr<Lib_Item> input);
	void addUser(std::shared_ptr<User> input);

	//getters
	std::vector<std::shared_ptr<Lib_Item>> getItems();
	std::vector<std::shared_ptr<User>> getUsers();
};

