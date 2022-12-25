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
}

void Lib_Item::setChecked(const bool& input)
{
	checkedOUT = input;
}

void Lib_Item::setReservedDate(const std::string& input)
{
	reservedTILL = input;
}

void Lib_Item::setReturnDate(const std::string& input)
{
	returnDATE = input;
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
