#include "DateParser.h"
#pragma warning(suppress : 4996)

std::string DateParser::getCurrentDate()
{
	std::string temp;
	time_t now = time(0);

	tm* ltm = localtime(&now);

	temp += std::to_string(1900+ltm->tm_year);
	temp += "_";
	
	//if the month or day is less than 10 then add 0 before it to keep the same format
	if (1 + ltm->tm_mon < 10)
		temp += "0";
	temp += std::to_string(1+ltm->tm_mon);
	temp += "_";

	if (1 + ltm->tm_mday < 10)
		temp += "0";
	temp += std::to_string(ltm->tm_mday);

	return temp;
}

std::string DateParser::toDate(std::string year, std::string month, std::string day)
{
	std::string temp;

	temp += year;
	temp += "_";
	
	if (1 + std::stoi(month) < 10)
		temp += "0";
	temp += month;
	temp += "_";

	if (1 + std::stoi(day) < 10)
		temp += "0";
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

int DateParser::dateDiff(std::string date1, std::string date2)
{
	int y1 = std::stoi(date1.substr(0, 4));
	int m1 = std::stoi(date1.substr(5, 2));
	int d1 = std::stoi(date1.substr(8, 2));

	int y2 = std::stoi(date2.substr(0, 4));
	int m2 = std::stoi(date2.substr(5, 2));
	int d2 = std::stoi(date2.substr(8, 2));

	//Rata Die
	if (m1 < 3)
	{
		y1--;
		m1 += 12;
	}
	int rdn1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (153 * m1 - 457) / 5 + d1 - 306;

	if (m2 < 3)
	{
		y2--;
		m2 += 12;
	}
	int rdn2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (153 * m2 - 457) / 5 + d2 - 306;

	return (rdn1 - rdn2);
}
