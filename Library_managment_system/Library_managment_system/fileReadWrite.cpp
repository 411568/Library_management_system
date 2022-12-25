#include "fileReadWrite.h"
void readUserDatabase(std::vector<std::shared_ptr<User>>& users)
{
	std::fstream file("LibraryUserDatabase.txt");
	std::stringstream sstr("123");
	std::vector<std::string> v;
	Student tempUser;
	std::shared_ptr<User> sharedUser;
	
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

		sharedUser = std::make_shared<User>(tempUser);
		users.push_back(sharedUser);
	}
}
