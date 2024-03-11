#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lib.h"
#include <map>
#include <algorithm>


 using namespace std;


 struct Birthday {

	 string name;
 
	 int year;

	 int month;

	 int day;
 
 };


 // comparator:
 bool cmp(Birthday& b1, Birthday& b2) {

	 if (b1.month < b2.month) return true;

	 if (b1.month > b2.month) return false;

	 return b1.day < b2.day;
 }


 void task2(){

	 string s;

	 Birthday b;

	 vector<Birthday> dates;
	 vector<Birthday> todayBirthdays;

	 struct tm newtime;
	 time_t now = time(0);
	 localtime_s(&newtime, &now);

	 int month = newtime.tm_mon + 1;
	 int day = newtime.tm_mday;

	 cout << "month: " << month << " day: " << day << endl;

 
	 while(1) {

		 cout << "Please, enter birthday info separated by space or 'end' to finish the program: " << endl;

		 cin >> b.name;

		 if (b.name == "end") break;

		 cin >> b.year >> b.month >> b.day; 

		 if (b.month > month || (b.month == month && b.day > day))
		 {
			 dates.push_back(b);
		 }
		 else if (b.month == month && b.day == day) {
			 todayBirthdays.push_back(b);
		 } 
	 }

	 // algo:
	 // today birthdays:
	 cout << "Todays birthdays: " << endl;
	 for (auto tb : todayBirthdays) {
		 cout << tb.name << " " << tb.year << " " << tb.month << " " << tb.day;
	 }

	 // nearest new birthday (from tomorrow...):
	 

	 if (!dates.empty()) {

		 sort(dates.begin(), dates.end(), cmp);

		 Birthday nearest = dates[0];
		 cout << "The nearest birthday: " << endl;
		 cout << nearest.name << " " << nearest.year << " " << nearest.month << " " << nearest.day;

	 }
	 else cout << "No nearest birthday found..." << endl; 
 }

