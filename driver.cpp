/**
 * @author Andrew Casner https://github.com/Andrew-Casner
 * @version 1.0
 * Final assginment driver
 */

#include "todo.cpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
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
				list.help();
			}
			else if(input == "add"){
				std::string item;
				std::string answer;
				std::string date;
				std::cout << "~>:What do you have to do?: ";
				std::getline(std::cin, item);
				std::cout << "~>:When is this due? (dd/mm/yyyy format or n if no due date): ";
				std::getline(std::cin, date);
				list.addItem(item, date);
				std::cout << "~>:Is this important? (y/n): ";
				std::cin >> answer;
				std::cin.ignore();
				list.setPriority(answer);
			}
			else if(input == "todo"){
				list.printList();
			}
			else if(input == "next"){
				list.printNext();
			}
			else if(input == "done"){
				list.pop();
			}
			else if(input == "find"){
				std::string item;
				std::cout << "~>:Find: ";
				std::cin >> item;
				std::cin.ignore();
				list.findItem(item);
			} else if (input == "sort") {
				list.sortByDate();
			} else if (input == "quit") {
				quit = true;
				std::cout << "Goodbye!" << std::endl;
			}
			else{
				std::cout << "Command not found" << std::endl;
				std::cout << "Type 'help' for help on commands" << std::endl;
			}
		}
	return 0;
}

