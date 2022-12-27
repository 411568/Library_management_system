/*
    Author: Krzysztof Sikora
    Project name: Library Managment System
    Date: 27.12.2022
*/

#include "User_Interface.h"
#include <iostream>

int main()
{
    std::cout << "Welcome to the Library Managment System\n press any key to start the program..."
              << std::endl;

    std::cin.get();

    try
    {
		auto lib = Library::GetInstance();
		lib.readBookFile();
		lib.readUserFile();

        auto interface = User_Interface::GetInstance();
        interface.start();

        //save all data before exiting
        lib.saveToFiles();

        return 0;
    }
    catch (...)
    {
        std::cout << "Error occurred. Exiting..." << std::endl;
        return 0;
    }
}
