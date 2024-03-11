#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct statement {
    string name;
    string firstname;
    string date;
    double money;
};

void writeToFile(ofstream& file, statement& data) {

    file << data.name << " " << data.firstname << " " << data.date << " " << data.money << "\n";

}


void readToFile(ifstream& file, statement& data) {

    file >> data.name >> data.firstname >> data.date >> data.money;

}

void task1() {

    statement data;
    string options;
    cout << "Enter 'list' or 'add': ";
    cin >> options;

    if (options == "add") {
        ofstream file("statement.txt", ios_base::app);
        cout << "Enter the data separated by a space (name, firstname, date(DD.MM.YYYY), money): " << endl;
        cin >> data.name >> data.firstname >> data.date >> data.money;
        writeToFile(file, data);
        file.close();
    }
    else if (options == "list") {
        ifstream file("statement.txt");
        while (!file.eof()) {
            readToFile(file, data);
            cout << data.name << " " << data.firstname << " " << data.date << "  " << data.money << endl;
        }
        file.close();
    }
    else
    {
        cout << "Incorrect input!";
    }
}