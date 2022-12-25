#include "User.h"

void User::setName(const std::string& input)
{
	name = input;
}

void User::setSurname(const std::string& input)
{
	surname = input;
}

std::string User::getName() const
{
	return name;
}

std::string User::getSurname() const
{
	return surname;
}
