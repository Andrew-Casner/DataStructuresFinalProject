#include "todo.h"

using namespace std;

Todo::Todo(){
	//create todo list
	//print list
	printList();
	Date currentDate;
	cout << "Today is " << currentDate.printDate() << endl;
	Date tempDate;
}

Todo::~Todo(){
	
}

void Todo::printList(){
	//print list
	if(que[0] != ""){
		for(int i = 0; i < LIST_SIZE; i++){
			if(que[i] != ""){
				cout << i+1 << ": " << que[i];
				if (queDate[i].display && queDate[i].daysLeft(currentDate) >= 0) //Has due date and not overdue
					cout << " is due on " << queDate[i].printDate() << ", which is in " << queDate[i].daysLeft(currentDate) << " days." << endl;
				else if (queDate[i].display) //Has due date and overdue
					cout << " was due on " << queDate[i].printDate() << ", and is overdue by " << -1 * queDate[i].daysLeft(currentDate) << " days." << endl;
				else
					cout << endl;
			}
		}
	}
	else{
		cout << "Your List is empty" << endl;
	}
}

void Todo::addItem(string item, string date){
	temp = item;
	tempDate.setDate(date);
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
	cout << "~>:Next Item TODO: " << que[0];
	if (queDate[0].display && queDate[0].daysLeft(currentDate) >= 0)	//Has due date and not overdue
		cout << " is due on " << queDate[0].printDate() << ", which is in " << queDate[0].daysLeft(currentDate) << " days." << endl;
	else if (queDate[0].display) //Has due date and overdue
		cout << " was due on " << queDate[0].printDate() << ", and is overdue by " << -1 * queDate[0].daysLeft(currentDate) << " days." << endl;
	else
		cout << endl;
}

void Todo::pop(){
	cout << "->:Compleated " << que[0] << endl;
	for(int i = 1; i < LIST_SIZE; i++){
		que[i-1] = que[i];
		queDate[i-1] = queDate[i];
	}
}

void Todo::push(){
	string holder = que[0];
	string holder2;
	que[0] = temp;
	temp = "";
	Date dHolder = queDate[0];
	Date dHolder2;
	queDate[0] = tempDate;
	tempDate.setDate("n");
	
	for(int i = 1; i < LIST_SIZE; i++){
		holder2 = que[i];
		que[i] = holder;
		holder = holder2;
		dHolder2 = queDate[i];
		queDate[i] = dHolder;
		dHolder = dHolder2;
	}
}

void Todo::enque(){
	for(int i = 0; i < LIST_SIZE; i++){
		if(que[i]==""){
			que[i] = temp;
			temp = "";
			queDate[i] = tempDate;
			tempDate.setDate("n");
		}
	}
}

void Todo::findItem(string item){
	bool found = false;
	int index;
	for(int i = 0; i < LIST_SIZE; i++){
		if(que[i] == item){
			found = true;
			index = i+1;
		}
	}
	if(found){
		cout <<  "~>:Found!" << endl;
		cout << index << ": " << item;
		if (queDate[index-1].display && queDate[index-1].daysLeft(currentDate) >= 0)	//Has due date and not overdue
			cout << " is due on " << queDate[index-1].printDate() << ", which is in " << queDate[index-1].daysLeft(currentDate) << " days." << endl;
		else if (queDate[index-1].display) //Has due date and overdue
			cout << " was due on " << queDate[index-1].printDate() << ", and is overdue by " << -1 * queDate[index-1].daysLeft(currentDate) << " days." << endl;
		else
			cout << endl;
	}
	else{
		cout << "~>:Could not find " << item << endl;
	}
}

void Todo::clear(){
	for(int i = 0; i < LIST_SIZE; i++){
		que[i] = "";
		queDate[i].display = false;
	}
}

void Todo::sortByDate() {
	std:string task[LIST_SIZE];
	Date dueDate[LIST_SIZE];
	int daysL[LIST_SIZE];
	for (int i = 0; i < LIST_SIZE; i++) {	//Set all vals in temp arrays
		if (queDate[i].display)
			daysL[i] = queDate[i].daysLeft(currentDate);
		else if (que[i] != "")
			daysL[i] = 10000;	//Big number for stuff with no due date
		else
			daysL[i] = 50000;	//Bigger number for empty spots
		task[i] = que[i];
		dueDate[i] = queDate[i];
	}
	for (int i = 0; i < LIST_SIZE; i++) {	//Bubble sort
		for (int j = 0; j < LSIT_SIZE - 1; j++) {
			if (daysL[j] > daysL[j + 1])	{
				int tempDL = daysL[j + 1];
				daysL[j + 1] = daysL[j];
				daysL[j] = tempDL;
				Date tempDate = dueDate[j + 1];
				dueDate[j + 1] = dueDate[j];
				dueDate[j] = tempDate;
				string tempS = task[j + 1];
				task[j + 1] = task[j];
				task[j] = tempS;
			}
		}
	}
	for (int i = 0; i < LIST_SIZE; i++) {	//Display results
		if (task[i] != "") {
			cout << i+1 << ": " << task[i];
			if (dueDate[i].display && dueDate[i].daysLeft(currentDate) >= 0)	//Has due date and not overdue
				cout << " is due on " << dueDate[i].printDate() << ", which is in " << dueDate[i].daysLeft(currentDate) << " days." << endl;
			else if (dueDate[i].display) //Has due date and overdue
				cout << " was due on " << dueDate[i].printDate() << ", and is overdue by " << -1 * dueDate[i].daysLeft(currentDate) << " days." << endl;
			else
				cout << endl;
		}
	}
	return;
}

void Todo::help(){
	cout << "=====================Commands=====================" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "add		-Adds a new todo item" << endl;
	cout << "todo		-Shows all items in the todo list" << endl;
	cout << "next		-Shows the next item needed todo" << endl;
	cout << "done		-You have compleated the next item" << endl;
	cout << "find		-Finds if you have that item in your todo list" << endl;
	cout << "sort		-Sorts your todo list by due date and prints" << endl;
	cout << "quit		-Quit this program" << endl;
	cout << "" << endl;
	cout << "" << endl;

}

	
	
