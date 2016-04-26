/**
 * @author Andrew Casner https://github.com/Andrew-Casner
 * @version 1.0
 * Final assginment driver
 */

#include "todo.cpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	bool quit = false;
	//Main code loop
		std::string input;
		//run startup 
		std::cout << "Loading your TODO List..." << std::endl;
		Todo list = Todo();
		//accept input
		while(!quit){
			std::cout << "~>:";
			std::cin >> input;
			std::cin.ignore();	//Get rid of extra newline left in stream after cin
			if(input == "help") {	//choose what to do
				std::cout << "help here" << std::endl;
				std::cout << "list commands here" << std::endl;
			}
			else{
				std::cout << "Command not found" << std::endl;
				std::cout << "Type 'help' for help on commands" << std::endl;
			}
		}
	return 0;
}

