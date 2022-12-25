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

	Library lib = Library::GetInstance();
	
	//add all the users from the database file to the library class
	std::vector<std::shared_ptr<User>> users;
	readUserDatabase(users); //this gives vector out of range error
	for (auto user : users)
	{
		lib.addUser(user);
	}

	std::string input;
	bool valid_input = false;

	//list of all studentIDs
	std::vector<std::string> studentIDs;
	for (auto student : users)
	{
		auto temp = std::static_pointer_cast<Student>(student);
		//studentIDs.push_back(temp->getUniID());
	}

	do
	{
		system("cls");
		std::cout << "Enter your university ID: " << std::endl;
		std::cin >> input;
		if (/*exists such a student*/1)
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
