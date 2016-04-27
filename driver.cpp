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
			else if(input == "add"){
				std::string item;
				std::string answer;
				std::cout << "~>What do you have to do?: ";
				std::cin >> item;
				std::cin.ignore();
				list.addItem(item);
				std::cout << "~>Is this important? (y/n): ";
				std::cin >> answer;
				std::cin.ignore();
				list.setPriority(answer);
			}
			else{
				std::cout << "Command not found" << std::endl;
				std::cout << "Type 'help' for help on commands" << std::endl;
			}
		}
	return 0;
}

