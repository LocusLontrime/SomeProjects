#include <iostream>
#include "lib.h"
#include <string>
#include <vector>
#include <map>
#include <random>


using namespace std;


struct Subscriber {

	string phoneNumber;

	string name;

};


class Phone {

	private:

		vector<Subscriber> phoneBook;

		map<string, Subscriber> phoneBookMap;

	public:

		void add() {
		
			cout << "Please enter subscriber's name and phone number, separated by space: " << endl;

			Subscriber subscriber;

			cin >> subscriber.name >> subscriber.phoneNumber;

			phoneBook.push_back(subscriber);

			phoneBookMap[subscriber.name] = subscriber;

			cout << "Subscriber has been added..." << endl;
		}

		void call() {

			char ch;
		
			cout << "You wanna enter phone number or name? (p/n)" << endl;

			cin >> ch;

			string s;

			switch (ch) {
			
				case 'p':

					cout << "Please, enter phone number: " << endl;

					cin >> s;

					cout << "Calling " << s << "..." << endl;

					break;

				case 'n':
					
					cout << "Please, enter name: " << endl;

					cin >> s;

					cout << "Calling " << phoneBookMap[s].phoneNumber << "..." << endl;

					break;

				default:

					cout << "Please, enter 'p' for phone and 'n' for name" << endl;

					break;	
			}
		}

		void sms() {
		
			char ch;

			cout << "You wanna enter phone number or name? (p/n)" << endl;

			cin >> ch;

			string s;
			string smsText;

			switch (ch) {

			case 'p':

				cout << "Please, enter phone number: " << endl;

				cin >> s;

				cout << "Please, enter sms text" << endl;

				cout << "Sending " << "'" << smsText << "' on number " << s << "..." << endl;

				break;

			case 'n':

				cout << "Please, enter name: " << endl;

				cin >> s;

				cout << "Sending " << "'" << smsText << "' on number " 
					<< phoneBookMap[s].phoneNumber << "..." << endl;

				break;

			default:

				cout << "Please, enter 'p' for phone and 'n' for name" << endl;

				break;
			}	
		}

		void exit() {

			cout << "" << endl;

		}

};

