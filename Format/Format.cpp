// Format.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exercise 2.11

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // std::cout << "Hello World!\n";
    cout << setiosflags(ios::left) << setw(10) << "SurName"
        << setiosflags(ios::left) << setw(10) << "Name"
        << setiosflags(ios::left) << setw(16) << "Address"
        << setiosflags(ios::left) << setw(12) << "City" << endl
        << "----------------------------------------------------" << endl
        << setiosflags(ios::left) << setw(10) << "Petrov"
        << setiosflags(ios::left) << setw(10) << "Vasiliy"
        << setiosflags(ios::left) << setw(16) << "Klenovaya 16"
        << setiosflags(ios::left) << setw(12) << "St. Petersburg" << endl
        << setiosflags(ios::left) << setw(10) << "Ivanov"
        << setiosflags(ios::left) << setw(10) << "Sergey"
        << setiosflags(ios::left) << setw(16) << "Osinovaya 3"
        << setiosflags(ios::left) << setw(12) << "Nahodka" << endl
        << setiosflags(ios::left) << setw(10) << "Sidorov"
        << setiosflags(ios::left) << setw(10) << "Ivan"
        << setiosflags(ios::left) << setw(16) << "Berezovaya 21"
        << setiosflags(ios::left) << setw(12) << "Kaliningrad" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
