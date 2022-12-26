/*
    Author: Krzysztof Sikora
    Project name: Library Managment System
*/

#include "User_Interface.h"
#include <iostream>

int main()
{
    std::cout << "Welcome to the Library Managment System\n press any key to start the program..."
              << std::endl;

    std::cin.get();

    std::unique_ptr<User_Interface> userInteface;

        //using this now because I want to see all the errors
		Library& lib = Library::GetInstance();
		lib.readBookFile();
		lib.readUserFile();

        userInteface->start();

        return 0;

    /*
    try
    {
		Library& lib = Library::GetInstance();
		lib.readBookFile();
		lib.readUserFile();

        userInteface->start();

        //save all the changes to database
        //lib.saveDataToFiles();
    }
    catch (...)
    {
        std::cout << "Error occurred. Exiting..." << std::endl;
        return 0;
    }*/
}
