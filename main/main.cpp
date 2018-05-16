//Name        : AsynTasks.cpp
//Author      : Jules
//Version     : 1.0
//Description : main.cpp file for an example command line that uses an asynchronous task library

#include <iostream>
#include <vector>
#include <sstream>

#include "task.h"

int main(){

std::vector<Task*> vTasks;

	while(true){
		std::vector<std::string> tokens;
		std::string line;
		std::cout << "Enter an instruction: ";
		std::getline (std::cin,line);
		std::istringstream ss(line);
		std::string buffer;
		while (ss >> buffer){
			tokens.push_back(buffer);
		}


}

}

