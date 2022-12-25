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
		while (sstr.good())
		{
			std::string substr;
			std::getline(sstr, substr, ';');
			v.push_back(substr);
		}

		tempUser.setName(v[0]);
		tempUser.setSurname(v[1]);
		tempUser.setAge(std::stoi(v[2]));
		tempUser.setUniID(v[3]);
		
		sharedUser = std::make_shared<User>(tempUser);
		users.push_back(sharedUser);
	}
}
