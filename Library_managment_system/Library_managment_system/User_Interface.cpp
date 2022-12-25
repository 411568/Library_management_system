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
			std::cin.get();
		}
	} while (valid_input == false);
}


void User_Interface::StudentMenu()
{
	//work in progress
	std::string input;
	bool valid_input = false;

	//library instance
	Library& lib = Library::GetInstance();
	lib.readUserFile();

	//get all the student IDs
	std::vector<std::string> uIDs;
	for (auto student : lib.getUsers())
	{
		uIDs.push_back(student.getUniID());
	}

	do
	{
		system("cls");
		std::cout << "Enter your university ID: " << std::endl;
		std::cin >> input;

		//check if the student ID exists
		if(std::count(uIDs.begin(), uIDs.end(), input))
		{
			valid_input = true;
		}
		else
		{
			std::cout << "Wrong ID! Please enter the correct ID or contact the library administrator." << std::endl;
			std::cin.get();
			std::cin.get();
		}
	} while (valid_input == false);


	valid_input = false;
	do
	{
		system("cls");
		std::cout << "1 - Return a book\n2 - Check out a book\n3 - Reserve a book" << std::endl;
		std::cin >> input;
		if (input == "1")
		{
			//bookReturn();
			valid_input = true;
		}
		else if (input == "2")
		{
			//bookCheckOut();
			valid_input = true;
		}
		else if (input == "3")
		{
			//bookReserve();
			valid_input = true;
		}
		else
		{
			std::cout << "\nWrong input! Press any key to continue...";
			std::cin.get();
			std::cin.get();
		}
	} while (valid_input == false);
}
