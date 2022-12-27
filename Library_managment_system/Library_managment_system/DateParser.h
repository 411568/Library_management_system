#pragma once
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

