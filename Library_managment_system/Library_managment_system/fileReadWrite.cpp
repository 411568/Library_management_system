#include "fileReadWrite.h"

void fileReadWrite::readUserDatabase(std::vector<Student>& students)
{
	std::fstream file("LibraryUserDatabase.txt");
	
	for( std::string inputLine; std::getline(file, inputLine); )
	{
		Student tempUser;
		std::vector<std::string> v;
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

		v.erase(v.begin(), v.begin() + 4);

		if (v.empty() == false)
		{
			//if there is more elements then look for checked out and reserved books
			std::vector<std::string> checked;
			std::vector<std::string> reserved;

			//checked out books first
			for (auto elem : v)
			{
				if (elem != "_")
				{
					checked.push_back(elem);
				}
				else
				{
					break;
				}
			}

			v.erase(v.begin(), std::find(v.begin(), v.end(), "_")+1);

			//then the reserved books
			for (auto elem : v)
			{
				if (elem != "_")
				{
					reserved.push_back(elem);
				}
				else
				{
					break;
				}
			}


			auto lib = Library::GetInstance();
			std::vector<Book> books = lib.getItems();

			//add books to the user
			for(auto elem : checked)
			{
				for (auto book : books)
				{
					if (elem == std::to_string(book.getInternalID()))
					{
						tempUser.addBook(book);
					}
				}
			}

			for(auto elem : reserved)
			{
				for (auto book : books)
				{
					if (elem == std::to_string(book.getInternalID()))
					{
						tempUser.addReserve(book);
					}
				}
			}
		}

		students.push_back(tempUser);
	}
}

void fileReadWrite::readBookDatabase(std::vector<Book>& books)
{
	std::fstream file("LibraryItemDatabase.txt");
	
	for(std::string inputLine; std::getline(file, inputLine); )
	{
		Book tempBook;
		std::vector<std::string> v;
		std::string delimiter_char = ";";
		size_t pos = 0;
		while ((pos = inputLine.find(delimiter_char)) != std::string::npos)
		{
			v.push_back(inputLine.substr(0, pos));
			inputLine.erase(0, pos + delimiter_char.length());
		}

		tempBook.setTitle(v[0]);
		tempBook.setInternalID(std::stoi(v[1]));
		if (v[2] == "1")
		{
			tempBook.setReserved(true);
		}
		else
		{
			tempBook.setReserved(false);
		}
		if (v[3] == "1")
		{
			tempBook.setChecked(true);
		}
		else
		{
			tempBook.setChecked(false);
		}
		tempBook.setReturnDate(v[4]);
		tempBook.setReservedDate(v[5]);
		tempBook.setISBN(v[6]);
		tempBook.setPageCount(std::stoi(v[7]));

		books.push_back(tempBook);
	}
}

void fileReadWrite::saveUserDatabase(const std::vector<Student>& students)
{

}

void fileReadWrite::saveItemDatabase(const std::vector<Book>& books)
{

}
