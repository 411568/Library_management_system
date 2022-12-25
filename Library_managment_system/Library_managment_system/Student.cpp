#include "Student.h"

void Student::setUniID(const std::string& input)
{
	uniID = input;
}

void Student::setAge(const int& input)
{
	age = input;
}

std::string Student::getUniID() const
{
	return uniID;
}

int Student::getAge() const
{
	return age;
}
	
std::vector<Book> Student::getCheckedOutItems() const
{
	return checkedOutItems;
}

void Student::getInfo(std::map<std::string, std::string>& infoMap)
{
	infoMap["uniID"] = uniID;
	infoMap["age"] = age;
	infoMap["name"] = this->getName();
	infoMap["surname"] = this->getSurname();
}

