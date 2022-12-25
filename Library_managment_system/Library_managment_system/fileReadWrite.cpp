#include "fileReadWrite.h"
void readUserDatabase(std::vector<Student>& students)
{
	std::fstream file("LibraryUserDatabase.txt");
	std::vector<std::string> v;
	Student tempUser;
	
	for( std::string inputLine; std::getline(file, inputLine); )
	{
		std::string delimiter_char = ";";
		size_t pos = 0;
		while ((pos = inputLine.find(delimiter_char)) != std::string::npos)
		{
			v.push_back(inputLine.substr(0, pos));
			inputLine.erase(0, pos + delimiter_char.length());
		}

		tempUser.setName(v[0]);
		tempUser.setSurname(v[1]);
		tempUser.setAge(std::stoi(v[2]));
		tempUser.setUniID(v[3]);

		students.push_back(tempUser);
	}
}
