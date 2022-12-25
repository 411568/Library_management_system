/*
	This class represents a single item in the library. 
	Every one of those has the following properties:
		- title
		- internalID - ID used within this library only
		// - alleyID - name of the alley where one can find the book
		// - shelfNUM - shelf number
		- reserved - whever is has been reserved or not
		- checkeckedOUT - whever is has been checked out
		- returnDATE - the date when one should return the item if it's been checked out
		- reseverdTILL - end of the reservatio date

	Method getInfo() returns all the information about the item on which it has been called.
*/

#pragma once
#include <string>
#include <ctime>
#include <map>

class Lib_Item
{
private:
	std::string title;
	int internalID;

	//char alleyID;
	//int shelfNUM;

	bool reserved;
	bool checkedOUT;

	std::string returnDATE;
	std::string reservedTILL;

public:
	//get all the info about an item
	virtual void getInfo(std::map<std::string, std::string>& infoMap) = 0;

	//setters
	void setTitle(const std::string& input);
	void setInternalID(const int& input);
	void setReserved(const bool& input);
	void setChecked(const bool& input);
	void setReturnDate(const std::string& input);
	void setReservedDate(const std::string& input);

	
	//getters
	std::string getTitle() const;
	int getInternalID() const;
	bool getReserved() const;
	bool getChecked() const;
	std::string getReturnDate() const;
	std::string getReservedTILL() const;
};

