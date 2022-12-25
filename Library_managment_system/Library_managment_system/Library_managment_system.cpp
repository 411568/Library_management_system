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

    try
    {
        userInteface->start();
    }
    catch (...)
    {
        std::cout << "Error occurred. Exiting..." << std::endl;
        return 0;
    }
}
