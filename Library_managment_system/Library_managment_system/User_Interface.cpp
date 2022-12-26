#include "User_Interface.h"

void User_Interface::start()
{
	//work in progress

	Library& lib = Library::GetInstance();
	lib.readUserFile();
	lib.readBookFile();

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
	std::string ID;

	//library instance
	Library& lib = Library::GetInstance();

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
			ID = input;
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
			StudentBookReturn(ID);
			valid_input = true;
		}
		else if (input == "2")
		{
			StudentBookCheck(ID);
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


void User_Interface::StudentBookCheck(std::string studentID)
{
	//vector of books in the library
	std::vector<Book> books;

	Library& lib = Library::GetInstance();
	books = lib.getItems();

	
	std::string input;
	bool valid_input = false;
	std::string bookID;
	do
	{
		std::vector<int> bookIDs;

		system("cls");
		std::cout << "Which book would you like to check out?" << std::endl;
		std::cout << "Please enter the ID for the entry you're interested in." << std::endl << std::endl;

		//show all the entries
		for (auto book : books)
		{
			if (book.getChecked() == false)
			{
				std::cout << book.getInternalID() << " " << book.getTitle() << " ISBN: ";
				std::cout << book.getISBN() << " Page Count: " << book.getPageCount();
				std::cout << std::endl;

				bookIDs.push_back(book.getInternalID());
			}
		}

		std::cin >> input;

		//check if the book exists
		try
		{
			if (std::count(bookIDs.begin(), bookIDs.end(), std::stoi(input)))
			{
				bookID = input;
				valid_input = true;
			}
			else
			{
				std::cout << "Invalid entry, please try again.";
				std::cin.get();
				std::cin.get();
			}
		}
		catch (...)
		{
			std::cout << "Invalid entry, please try again.";
			std::cin.get();
			std::cin.get();
		}
	} while (valid_input == false);


	//check out the book
	lib.checkOutBook(studentID, std::stoi(bookID));
	

	system("cls");
	std::cout << "The book has been checked out. Thank you." << std::endl;
	std::cin.get();
	std::cin.get();

	start();
}


void User_Interface::StudentBookReturn(std::string studentID)
{
	//vector of books checked out by the student
	std::vector<Book> books;

	Library& lib = Library::GetInstance();
	std::vector<Student> students;
	students = lib.getUsers();

	int i = 0;
	for (; i < students.size(); i++)
	{
		if (students[i].getUniID() == studentID)
		{
			break;
		}
	}

	//get all the books
	books = students[i].getCheckedOutItems();
	

	std::string input;
	bool valid_input = false;
	std::string bookID;

	if (books.empty() == false)
	{
		do
		{
			std::vector<int> bookIDs;

			system("cls");
			std::cout << "Which book would you like to return?" << std::endl;
			std::cout << "Please enter the book ID." << std::endl << std::endl;

			//show all the entries that the user has checked out
			for (auto book : books)
			{
				std::cout << book.getInternalID() << " " << book.getTitle() << " ISBN: ";
				std::cout << book.getISBN() << " Page Count: " << book.getPageCount();
				std::cout << std::endl;

				bookIDs.push_back(book.getInternalID());
			}

			std::cin >> input;

			//check if the book exists
			try
			{
				if (std::count(bookIDs.begin(), bookIDs.end(), std::stoi(input)))
				{
					bookID = input;
					valid_input = true;
				}
				else
				{
					std::cout << "Invalid entry, please try again.";
					std::cin.get();
					std::cin.get();
				}
			}
			catch (...)
			{
				std::cout << "Invalid entry, please try again.";
				std::cin.get();
				std::cin.get();
			}
		} while (valid_input == false);


		//return the book
		int payment = lib.returnBook(studentID, std::stoi(bookID));


		system("cls");
		std::cout << "The book has been returned. Thank you." << std::endl;
		if (payment > 0)
		{
			std::cout << "You have to pay: " << payment * 10 << "zl, as it was overdue." << std::endl;
		}
		std::cin.get();
		std::cin.get();
	}
	else // if there is nothing to return 
	{
		system("cls");
		std::cout << "Nothing to return..." << std::endl;
		std::cin.get();
		std::cin.get();
	}
	start();
}
