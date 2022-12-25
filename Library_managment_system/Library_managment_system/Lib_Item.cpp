#include "Lib_Item.h"


void Lib_Item::setTitle(const std::string& input)
{
	title = input;
}

void Lib_Item::setInternalID(const int& input)
{
	internalID = input;
}

void Lib_Item::setReserved(const bool& input)
{
	reserved = input;
	//reservedTILL = DATE_TIME::GetCurrentDay() + 7; //seven days reservation
}

void Lib_Item::setChecked(const bool& input)
{
	checkedOUT = input;
	//returnDATE = DATE_TIME::GetCurrentDay() + 30; //30 days till you have to return the book
}

std::string Lib_Item::getTitle() const
{
	return title;
}

int Lib_Item::getInternalID() const
{
	return internalID;
}

bool Lib_Item::getReserved() const
{
	return reserved;
}

bool Lib_Item::getChecked() const
{
	return checkedOUT;
}

std::string Lib_Item::getReturnDate() const
{
	return returnDATE;
}

std::string Lib_Item::getReservedTILL() const
{
	return reservedTILL;
}
