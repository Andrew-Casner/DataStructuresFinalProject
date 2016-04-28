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
#include <ctime>

const int LIST_SIZE = 100;

std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
short int mLengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

struct Date {
	short int day;
	short int month;
	int year;
	bool display;
	
	Date() {
		time_t rawTime;
		struct tm * timeInfo;
		time(&rawTime);
		timeInfo = localtime(&rawTime);
		std::string stringTime = asctime(timeInfo);	//Get asci string with time
		std::string temp = stringTime.substr(4, 3);	//Get 3 char month string
		for (short int i = 0; i < 12; i++) {	//Compare to get int value for month
			if (temp == months[i]) {
				month = i;
				break;
			}
		}
		temp = stringTime.substr(8, 2);	//Get 2 char date string
		day = stoi(temp, nullptr);	//Convert to int
		temp = stringTime.substr(20, 4);	//Get 4 char year string
		year = stoi(temp, nullptr);	//Convert to int
		display = true;
	}
		
	Date(short int d, short int m, int y, bool disp = false) {
		day = d;
		month = m;
		year = y;
		display = disp;
	}
	
	void setDate(std::string inDate) {	//inDate is in 'dd/mm/yyyy' format
		if (inDate == "n" || inDate == "N") {	//N for no due date, set to default
			day = 1;
			month = 0;
			year = 1970;
			display = false;
		} else {
			std::string temp;
			temp = inDate.substr(0, 2);
			day = stoi(temp, nullptr);
			temp = inDate.substr(3, 2);
			month = stoi(temp, nullptr) - 1;
			temp = inDate.substr(6, 4);
			year = stoi(temp, nullptr);
			display = true;
		}
		return;
	}		
	
	int daysLeft(Date currentDate) {
		int dLeft = 0, yLeft = 0, mLeft = 0;
		yLeft = (year - currentDate.year) * 365.242199;
		for (int i = currentDate.month; i < month; i++) {
			mLeft += mLengths[i];
		}
		dLeft = day - currentDate.day;
		return (dLeft + mLeft + yLeft);
	}
	
	std::string printDate() {
		std::stringstream ss;
		if (display) {
			ss << months[month] << " " << day << ", " << year;
			return ss.str();
		}
		return "\0";
	}
};

class Todo{
	public:
		Todo();
		~Todo();
		void printList();
		void addItem(std::string item, std::string date);
		void setPriority(std::string priority);
		void printNext();
		void pop();
		void push();
		void enque();
		void findItem(std::string item);
		void clear();
		void help();
		void sortByDate();	//Sort list by due date
	protected:
	private:
		std::string que[LIST_SIZE];	//Changed so that just change const at top of file to alter max size
		Date queDate[LIST_SIZE];	//Due date for each task
		Date currentDate;
		Date tempDate;
		std::string temp;
};

#endif
