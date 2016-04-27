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
		printList();
		addItem();
		setPriority();
		printNext();
		pop();
		push();
		enque();
		findItem();
		clear();
		help();
	protected:
	private:
	std::string que[100];
};

#endif
