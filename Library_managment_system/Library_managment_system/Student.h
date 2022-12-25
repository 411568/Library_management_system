/*
	This class represents a single student - which is a child class of "user"
	Additional properties include:
		- uniID - university ID
		- age
		- checkedOutItems - a vector containing all the items student has checkedOut
*/

#pragma once
#include "User.h"
#include <vector>
#include <memory>
#include "Lib_Item.h"

class Student : public User
{
private:
	std::string uniID;
	int age;

	std::vector<std::shared_ptr<Lib_Item>> checkedOutItems;

public:
	//returns all of the informations about a user (except for the list of checked out items)
	virtual void getInfo(std::map<std::string, std::string>& infoMap);

	//setters
	void setUniID(const std::string& input);
	void setAge(const int& input);

	//getters 
	std::string getUniID() const;
	int getAge() const;
	std::vector<std::shared_ptr<Lib_Item>> getCheckedOutItems() const;
};

