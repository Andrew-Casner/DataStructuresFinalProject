#include "todo.h"

using namespace std;

Todo::Todo(){
	//create todo list
	//print list
	printList();
}

Todo::~Todo(){
	
}

void Todo::printList(){
	//print list
	if(que[0] != ""){
		for(int i = 0; i < 100; i++){
			if(que[i] != ""){
				cout << i << ": " << que[i] << endl;
			}
		}
	}
	else{
		cout << "Your List is empty" << endl;
	}
}
void Todo::addItem(string item){
	temp = item;
}

void Todo::setPriority(string priority){
	if(priority == "y"){
		push();
	}
	else{
		enque();
	}
}

void Todo::printNext(){
	
}

void Todo::pop(){
	
}

void Todo::push(){
	
}

void Todo::enque(){
	
}

void Todo::findItem(){
	
}

void Todo::clear(){
	
}

void Todo::help(){
	
}
