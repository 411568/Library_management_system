/*
	This class works with the date, which in this program is held as a string formatted as follows: yyyy_mm_dd
	The following static methods are implemented:
		- getCurrentDate() - returns todays date as a string
		- getReturnDate() - returns the date one month from noe
		- toDate() - parses the input parameters (year, month, day) to the string format
		- dateDiff() - returns the difference (in number of days) between two dates
*/

#pragma once
//ctime error (outdated functions)
#pragma warning(suppress : 4996)
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

class DateParser
{
public:
	static std::string getCurrentDate();

	static std::string getReturnDate();

	static std::string toDate(std::string year, std::string month, std::string day);

	static int dateDiff(std::string date1, std::string date2);
};

