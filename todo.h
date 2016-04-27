/**
 * @author Andrew Casner https://github.com/Andrew-Casner
 * @version 1.0
 * Todo class file header
 */
 
#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

class Todo{
	public:
		Todo();
		~Todo();
		void printList();
		void addItem(std::string item);
		void setPriority(std::string priority);
		void printNext();
		void pop();
		void push();
		void enque();
		void findItem();
		void clear();
		void help();
	protected:
	private:
		std::string que[100];
		std::string temp;
};

#endif
