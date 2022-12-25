/*
	This class representsa  single book. It is a child class for the Lib_Item
	Additional properties include:
		- ISBN - the international book number
		- pagaCount - number of pages
*/

#pragma once
#include "Lib_Item.h"
class Book : public Lib_Item
{
private:
	std::string ISBN;
	int pageCount;

public:
	//get all the info about a book
	virtual void getInfo(std::map<std::string, std::string>& infoMap);
	
	//setters
	void setISBN(const std::string& input);
	void setPageCount(const int& input);

	//getters
	std::string getISBN() const;
	int getPageCount() const;
};

