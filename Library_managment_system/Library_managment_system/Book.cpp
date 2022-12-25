#include "Book.h"

void Book::setISBN(const std::string& input)
{
	ISBN = input;
}

void Book::setPageCount(const int& input)
{
	pageCount = input;
}

std::string Book::getISBN() const
{
	return ISBN;
}

int Book::getPageCount() const
{
	return pageCount;
}

void Book::getInfo(std::map<std::string, std::string>& infoMap)
{
	infoMap["ISBN"] = ISBN;
	infoMap["pageCount"] = pageCount;
	infoMap["title"] = this->getTitle();
	infoMap["internalID"] = this->getInternalID();
	infoMap["reserved"] = this->getReserved();
	infoMap["checkedOUT"] = this->getChecked();
	infoMap["reservedTILL"] = this->getReservedTILL();
	infoMap["returnDATE"] = this->getReturnDate();
}
