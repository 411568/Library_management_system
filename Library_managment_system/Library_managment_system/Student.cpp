#include "Student.h"

void Student::setUniID(const std::string& input)
{
	uniID = input;
}

void Student::setAge(const int& input)
{
	age = input;
}

void Student::addBook(const Book& input)
{
	checkedOutItems.push_back(input);
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

void Student::removeBook(const int& bID)
{
	for (int i = 0; i < checkedOutItems.size(); i++)
	{
		if (checkedOutItems[i].getInternalID() == bID)
		{
			//delete that book from the vector
			checkedOutItems.erase(checkedOutItems.begin() + i);
		}
	}
}
