#pragma once
#include <vector>
#include <map>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include "User.h"
#include "Student.h"

//reads the user database and writes it to a vector 
void readUserDatabase(std::vector<std::shared_ptr<User>>& users);
