/*
	This class represents a single library user
	Main properties are:
		- name
		- surname

	Functionality:
		- getInfo() - returns all the informations about a single user
*/

#pragma once
#include <string>
#include <map>

class User
{
private:
	std::string name;
	std::string surname;

public:
	//returns all of the informations about a user

	//doesn't work for some reason XD
//	virtual void getInfo(std::map<std::string, std::string>& infoMap) = 0;

	//setters
	void setName(const std::string& input);
	void setSurname(const std::string& input);

	//getters
	std::string getName() const;
	std::string getSurname() const;
};

