/*
	This class represents a single student - it is a child class of "user"
	Additional properties include:
		- uniID - university ID
		- age
		- checkedOutItems - a vector containing all the items student has checkedOut
		- reservedItems - items reserved by the student
*/

#pragma once
#include "User.h"
#include <vector>
#include <memory>
#include "Lib_Item.h"
#include "Book.h"

class Student : public User
{
private:
	std::string uniID;
	int age{};

	std::vector<Book> checkedOutItems;
	std::vector<Book> reservedItems;

public:
	//returns all of the informations about a user (except for the list of checked out items)
	virtual void getInfo(std::map<std::string, std::string>& infoMap);

	//setters
	void setUniID(const std::string& input);
	void setAge(const int& input);
	void addBook(const Book& input);
	void removeBook(const int& bID);
	void addReserve(const Book& input);

	//getters 
	std::string getUniID() const;
	int getAge() const;
	std::vector<Book> getCheckedOutItems() const;
	std::vector<Book> getReservedItems() const;
};

