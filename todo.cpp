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
				cout << i+1 << ": " << que[i] << endl;
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
	cout << "~> Next Item TODO: " << que[0] << endl;
}

void Todo::pop(){
	
}

void Todo::push(){
	string holder = que[0];
	string holder2;
	que[0] = temp;
	temp = "";
	for(int i = 1; i < 100; i++){
		holder2 = que[i];
		que[i] = holder;
		holder = holder2;
	}
}

void Todo::enque(){
	for(int i = 0; i < 100; i++){
		if(que[i]==""){
			que[i] = temp;
			temp = "";
		}
	}
}

void Todo::findItem(){
	
}

void Todo::clear(){
	
}

void Todo::help(){
	
}
