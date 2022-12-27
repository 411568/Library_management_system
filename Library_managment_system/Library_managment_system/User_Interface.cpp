#include "User_Interface.h"

User_Interface& User_Interface::GetInstance()
{
	static User_Interface* singleton = new User_Interface();
	return *singleton;
}

void User_Interface::start()
{
	std::string input;
	bool valid_input = false;

	//welcome menu
	do
	{
		system("cls");
		std::cout << "1 - Student\n2 - Admin\n3 - Exit program" << std::endl;
		std::cin >> input;
		if (input == "1")
		{
			StudentMenu();
			valid_input = true;
		}
		else if (input == "2")
		{
			AdminLogin();
			valid_input = true;
		}
		else if (input == "3")
		{
			auto lib = Library::GetInstance();
			lib.saveToFiles();
			exit(0);
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
	auto lib = Library::GetInstance();
	auto students = lib.getUsers();

	//get all the student IDs
	std::vector<std::string> uIDs;
	for (auto student : students)
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
		else if (input == "-1")
		{
			start();
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
		if (input == "1") //return book
		{
			StudentBookReturn(ID);
			valid_input = true;
		}
		else if (input == "2") //check out book
		{
			StudentBookCheck(ID);
			valid_input = true;
		}
		else if (input == "3") //reserve book
		{
			StudentBookReserve(ID);
			valid_input = true;
		}
		else if (input == "-1")
		{
			start();
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

	auto lib = Library::GetInstance();
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
			else if (input == "-1")
			{
				start();
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

	auto lib = Library::GetInstance();
	std::vector<Student> students = lib.getUsers();

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
				else if (input == "-1")
				{
					start();
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
			std::cout << "You have to pay: " << payment << "zl, as it was overdue." << std::endl;
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


void User_Interface::StudentBookReserve(std::string studentID)
{
	//vector of books in the library
	std::vector<Book> books;

	auto lib = Library::GetInstance();
	books = lib.getItems();

	
	std::string input;
	bool valid_input = false;
	std::string bookID;
	do
	{
		std::vector<int> bookIDs;

		system("cls");
		std::cout << "Which book would you like to reserve?" << std::endl;
		std::cout << "Please enter the ID for the entry you're interested in." << std::endl << std::endl;

		//show all the entries
		for (auto book : books)
		{
			if (book.getReserved() == false) //you can reserve books that are currently checked out as well
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
			else if (input == "-1")
			{
				start();
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


	//reserve that book
	lib.reserveBook(studentID, std::stoi(bookID));
	

	system("cls");
	std::cout << "The book has been reserved for you." << std::endl;
	std::cin.get();
	std::cin.get();

	start();
}


void User_Interface::AdminLogin()
{
	bool valid_input = false;
	std::string input;

	do
	{
		system("cls");
		std::cout << "Please enter the password: ";

		std::cin >> input;
		if (input == "1234") //password for admin
		{
			valid_input = true;
		}
		else if (input == "-1")
		{
			start();
			valid_input = true;
		}
		else
		{
			std::cout << "Wrong password! Plase try again." << std::endl;
			std::cin.get();
			std::cin.get();
		}
	} while (valid_input == false);

	system("cls");
	AdminMenu();
}

void User_Interface::AdminMenu()
{
	bool valid_input = false;
	std::string input;

	do
	{
		system("cls");
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - View all users\n2 - View all books\n3 - Add user\n4 - Add book\n5 - Show overdue books" << std::endl;

		std::cin >> input;
		if (input == "1")
		{
			ShowAllUsers();
			valid_input = true;
		}
		else if (input == "2")
		{
			ShowAllBooks();
			valid_input = true;
		}
		else if (input == "3")
		{
			AdminAddUser();
			valid_input = true;
		}
		else if (input == "4")
		{
			AdminAddBook();
			valid_input = true;
		}
		else if (input == "5")
		{
			AdminOverdueReport();
			valid_input = true;
		}
		else if (input == "-1")
		{
			start();
			valid_input = true;
		}
		else
		{
			std::cout << "Wrong input! Please try again." << std::endl;
			std::cin.get();
			std::cin.get();
		}
	} while (valid_input == false);
}

void User_Interface::ShowAllUsers()
{
	std::string input;
	bool valid_input = false;

	//get all the library users
	auto lib = Library::GetInstance();
	std::vector<Student> students = lib.getUsers();
	std::vector<std::string> IDs;

	do
	{
		system("cls");
		std::cout << "To see the user details please enter his uniID: " << std::endl;
		for (auto student : students)
		{
			std::cout << student.getUniID() << " " << student.getName() << " " << student.getSurname() << std::endl;
			IDs.push_back(student.getUniID());
		}
		
		std::cin >> input;

		if (std::count(IDs.begin(), IDs.end(), input))
		{
			//goto single user view
			ShowSingleUser(input);
			valid_input = true;
		}
		else if (input == "-1")
		{
			start();
			valid_input = true;
		}
		else
		{
			std::cout << "No such user exists." << std::endl;
			std::cin.get();
			std::cin.get();
		}
	
	} while (valid_input == false);

	AdminMenu();
}

void User_Interface::ShowSingleUser(std::string studentID)
{
	system("cls");

	auto lib = Library::GetInstance();
	std::vector<Student> students = lib.getUsers();

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getUniID() == studentID)
		{
			std::cout << "Student ID: " << students[i].getUniID() << std::endl;
			std::cout << "Name: " << students[i].getName() << std::endl;
			std::cout << "Surname: " << students[i].getSurname() << std::endl;
			std::cout << "Age: " << students[i].getAge() << std::endl;
			
			std::vector<Book> checked = students[i].getCheckedOutItems();
			std::vector<Book> reserved = students[i].getReservedItems();
	
			std::cout << "Checked out books: " << std::endl;
			for (auto elem : checked)
			{
				std::cout << elem.getInternalID() << " " << elem.getTitle() << std::endl;
			}

			std::cout << "Reserved books: " << std::endl;
			for (auto elem : reserved)
			{
				std::cout << elem.getInternalID() << " " << elem.getTitle() << std::endl;
			}

			break;
		}
	}

	std::cin.get();
	std::cin.get();
}

void User_Interface::ShowAllBooks()
{
	std::string input;
	bool valid_input = false;

	//get all the library users
	auto lib = Library::GetInstance();
	std::vector<Book> books = lib.getItems();
	std::vector<int> IDs;

	do
	{
		system("cls");
		std::cout << "To see the user details please enter his uniID: " << std::endl;
		for (auto book : books)
		{
			std::cout << book.getInternalID() << " " << book.getTitle() << std::endl;
			IDs.push_back(book.getInternalID());
		}
		
		std::cin >> input;

		try
		{
			if (std::count(IDs.begin(), IDs.end(), std::stoi(input)))
			{
				//goto single book view
				ShowSingleBook(std::stoi(input));
				valid_input = true;
			}
			else if (input == "-1")
			{
				start();
				valid_input = true;
			}
			else
			{
				std::cout << "No such book exists." << std::endl;
				std::cin.get();
				std::cin.get();
			}
		}
		catch (...)
		{
				std::cout << "Wrong input!" << std::endl;
				std::cin.get();
				std::cin.get();
		}

	
	} while (valid_input == false);
	AdminMenu();
}

void User_Interface::ShowSingleBook(int bID)
{
	system("cls");

	auto lib = Library::GetInstance();
	std::vector<Book> books = lib.getItems();

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getInternalID() == bID)
		{
			std::cout << "Internal ID: " << books[i].getInternalID() << std::endl;
			std::cout << "Title: " << books[i].getTitle() << std::endl;
			std::cout << "ISBN: " << books[i].getISBN() << std::endl;
			std::cout << "Page Count: " << books[i].getPageCount() << std::endl;
	
			std::cout << "Checked out: ";
			if (books[i].getChecked() == true)
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}
			
			std::cout << "Reserved: ";
			if (books[i].getReserved() == true)
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}

			break;
		}
	}

	std::cin.get();
	std::cin.get();
}


void User_Interface::AdminAddUser()
{
	system("cls");
	
	Library& lib = Library::GetInstance();

	std::string name;
	std::cout << "Please enter the name: ";
	std::cin >> name;
	system("cls");
	
	std::string surname;
	std::cout << "Please enter the surname: ";
	std::cin >> surname;
	system("cls");

	//age requires checking if it's an integer
	bool valid_input = true;
	std::string age;
	do
	{
		system("cls");
		std::cout << "Please enter age: ";
		std::cin >> age;
		try
		{
			int ageInt = std::stoi(age);
		}
		catch(...)
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.get();
			std::cin.get();
			valid_input = false;
		}
	} while (valid_input == false);


	system("cls");
	std::string ID;
	std::cout << "Please enter university ID: ";
	std::cin >> ID;
	system("cls");

	Student temp;
	temp.setName(name);
	temp.setSurname(surname);
	temp.setAge(std::stoi(age));
	temp.setUniID(ID);

	lib.addUser(temp);

	AdminMenu();
}


void User_Interface::AdminAddBook()
{
	system("cls");
	
	Library& lib = Library::GetInstance();

	std::string title;
	std::cout << "Please enter the title: ";
	std::cin >> title;
	system("cls");
	
	//internal ID requires checking if it's an integer
	std::string inID;
	bool valid_input = true;
	do
	{
		system("cls");
		std::cout << "Please enter the internal book ID: ";
		std::cin >> inID;

		if (isNumber(inID))
		{
			valid_input = true;
		}
		else
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.get();
			std::cin.get();
			valid_input = false;
		}
	} while (valid_input == false);

	system("cls");
	std::string ISBN;
	std::cout << "Please enter the ISBN: ";
	std::cin >> ISBN;
	system("cls");

	//page count requires checking if it's an integer
	std::string pages;
	valid_input = true;
	do
	{
		system("cls");
		std::cout << "Please enter the page count: ";
		std::cin >> pages;

		if (isNumber(pages))
		{
			valid_input = true;
		}
		else
		{
			std::cout << "Invalid input!" << std::endl;
			std::cin.get();
			std::cin.get();
			valid_input = false;
		}
	} while (valid_input == false);

	Book temp;
	temp.setTitle(title);
	temp.setInternalID(std::stoi(inID));
	temp.setChecked(false);
	temp.setReserved(false);
	temp.setReservedDate("0000_00_00");
	temp.setReturnDate("0000_00_00");
	temp.setISBN(ISBN);
	temp.setPageCount(std::stoi(pages));

	lib.addItem(temp);

	AdminMenu();
}

void User_Interface::AdminOverdueReport()
{
	system("cls");

	Library& lib = Library::GetInstance();
	auto users = lib.getUsers();
	auto books = lib.getItems();

	for (auto user : users)
	{
		std::cout << user.getName() << " " << user.getSurname() << std::endl;

		int payment = 0;
		auto userBooks = user.getCheckedOutItems();
		std::vector<int> bookIDs;
		for (auto userItem : userBooks)
		{
			bookIDs.push_back(userItem.getInternalID());
		}

		for (auto book : books)
		{
			if (std::count(bookIDs.begin(), bookIDs.end(), book.getInternalID()))
			{
				int daysChecked = DateParser::dateDiff(DateParser::getCurrentDate(), book.getReturnDate());
				if (daysChecked > 15)
				{
					std::cout << book.getTitle() << " overdue " << daysChecked - 15 << " days." << std::endl;
					payment += daysChecked - 15;
				}
			}
		}

		std::cout << payment << "zl to pay" << std::endl << std::endl;
	}

	std::cin.get();
	std::cin.get();

	AdminMenu();
}

bool User_Interface::isNumber(const std::string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}
