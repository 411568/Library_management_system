#include "User_Interface.h"

void User_Interface::start()
{
	//work in progress

	std::string input;
	bool valid_input = false;

	//welcome menu
	do
	{
		system("cls");
		std::cout << "1 - Student\n2 - Admin" << std::endl;
		std::cin >> input;
		if (input == "1")
		{
			StudentMenu();
			valid_input = true;
		}
		else if (input == "2")
		{
			//not implemented yet
			//AdminMenu();
			valid_input = true;
		}
		else
		{
			std::cout << "\nWrong input! Press any key to continue...";
			std::cin.get();
		}
	} while (valid_input == false);
}


void User_Interface::StudentMenu()
{
	//work in progress

	system("cls");
	std::cout << "ASDASD";
}
