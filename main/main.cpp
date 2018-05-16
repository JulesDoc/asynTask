//Name        : AsynTasks.cpp
//Author      : Jules
//Version     : 1.0
//Description : main.cpp file for an example command line that uses an asynchronous task library

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "task.h"
#include "taskrandom.h"
#include "tasksleep.h"
#include "taskloop.h"

//Prototype declaration
void showHelp();
bool isInteger(const std::string & s);

int main(int argc, char* argv[]) {

	if (argc == 2 && std::string(argv[1]) == "--help"){
		showHelp();
		return EXIT_SUCCESS;
	}

        std::once_flag flag1;
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

		if (tokens.size() > 0){//To avoid empty instruction

			//Starting Task of different types.
			//If the user do not specify type, Task Loop by default is created.
			//Another choice could be create a base task without type specification
			//as parameter and run a dummy method. The code is ready for that purpose.

			if (tokens[0]=="start"){
				if (tokens.size() == 1) {
					try{
						vTasks.push_back(new TaskLoop());
					}catch(std::exception& e){
						std::cout << "Standard exception: " << e.what() << '\n';
					}
				}
				else if (tokens[1].empty() || tokens[1]=="loop"){
					try{
						vTasks.push_back(new TaskLoop());
					}catch(std::exception& e){
						std::cout << "Standard exception: " << e.what() << '\n';
					}
				}
				else if (tokens[1]=="random"){
					try{
						vTasks.push_back(new TaskRandom());
					}catch(std::exception& e){
						std::cout << "Standard exception: " << e.what() << '\n';
					}
				}
				else if (tokens[1]=="sleep"){
					try{
						vTasks.push_back(new TaskSleep());
					}catch(std::exception& e){
						std::cout << "Standard exception: " << e.what() << '\n';
					}
				}
				else std::cout << "Wrong type specification, quit and see --help" << '\n';
			}
			//Resuming tasks
			else if (!vTasks.empty() && tokens[0]=="resume" && tokens.size() == 2 && isInteger(tokens[1])){
				uint i = std::stoi(tokens[1]);
				if (i >= 0 && i < vTasks.size()) vTasks[i]->resume();
				else std::cout << "Task with ID " << i << " can't be resumed -- see status" << '\n';
			}

			//Pausing tasks
			else if (!vTasks.empty() && tokens[0]=="pause" && tokens.size() == 2 && isInteger(tokens[1])){
				uint i = std::stoi(tokens[1]);
				if (i >= 0 && i < vTasks.size()) vTasks[i]->pause();
				else std::cout << "Task with ID " << i << " can't be paused -- see status" << '\n';
			}

			//Stopping tasks
			else if (!vTasks.empty() && tokens[0]=="stop" && tokens.size() == 2 && isInteger(tokens[1])){
				uint i = std::stoi(tokens[1]);
				if (i >= 0 && i < vTasks.size()) vTasks[i]->stop();
				else std::cout << "Task with ID " << i << " can't be stopped -- see status" << '\n';
			}
			//Global Status
			else if (tokens[0]=="status" && tokens.size()==1){
				if(vTasks.empty()) std::cout << "No Tasks created" << '\n';
				else for (auto t : vTasks) t->showStatus();
			}
			//Individual status
			else if (tokens[0]=="status" && tokens.size()==2 && isInteger(tokens[1]) && !vTasks.empty()){
				uint i = std::stoi(tokens[1]);
				if(i >= 0 && i < vTasks.size()) vTasks[i]->showStatus();
				else std::cout << "That task does not exist" << '\n';
			}
			//Quit
			else if (tokens[0]=="quit") break;

			//Bad formed instruction
			else std::cout << "Wrong instruction, please try again or ask for status" << '\n';

		}//Looping if enter without instruction

	}
	try{
		for (auto& t : vTasks){
	 		delete t;
			std::call_once(flag1, [](){ std::cout << "Cleaning!\n"; });
		}
	}catch(std::exception& e){
		std::cout << "Standard exception: " << e.what() << '\n';
	}
	std::cout << "GoodBye!!" << '\n'; 
	return EXIT_SUCCESS;
}

//This function is used to accept only a positive integer number after a specific instruction
inline bool isInteger(const std::string & s)//Taken from stackoverflow.com/questions/2844817
{
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

	char * p ;
	strtol(s.c_str(), &p, 10) ;

	return (*p == 0) ;
}
void showHelp(){

	std::string getcontent;
	std::ifstream openfile ("../../help.txt");
	if(openfile.is_open())
	{
		while(!openfile.eof())
		{
			getline(openfile, getcontent);
			std::cout << getcontent << '\n';
		}
	}

}
