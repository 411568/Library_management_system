#include "DateParser.h"
#pragma warning(suppress : 4996)

std::string DateParser::getCurrentDate()
{
	std::string temp;
	time_t now = time(0);

	tm* ltm = localtime(&now);

	temp += std::to_string(1900+ltm->tm_year);
	temp += "_";
	
	temp += std::to_string(1+ltm->tm_mon);
	temp += "_";

	temp += std::to_string(ltm->tm_mday);

	return temp;
}

std::string DateParser::toDate(std::string year, std::string month, std::string day)
{
	std::string temp;

	temp += year;
	temp += "_";
	
	temp += month;
	temp += "_";

	temp += day;

	return temp;
}

std::string DateParser::getReturnDate()
{
	std::string tDate = getCurrentDate();

	std::string year = tDate.substr(0, 4);
	std::string month = tDate.substr(5, 2);
	std::string day = tDate.substr(8, 2);

	//one month till return
	if (std::stoi(month) > 11)
	{
		month = "00";
		year = std::stoi(year) + 1;
	}
	else
	{
		month = std::stoi(month) + 1;
	}

	return toDate(year, month, day);
}
