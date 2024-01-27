// Pounds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exercise 2.10

#include <iostream>

using namespace std;

int main()
{
    // std::cout << "Hello World!\n";
    const int shillingWeight = 12;
    const int poundWeight = 20 * shillingWeight;
    int pounds, shillings, pennies;
    cout << "Please, enter amounts of pounds, shillings, pennies\n";
    cin >> pounds >> shillings >> pennies;
    int currWeight = shillings * shillingWeight + pennies;
    float percentage = 1.0 * currWeight / poundWeight;
    int newPennies = round(100 * percentage);
    cout << "percentage: " << percentage << "\n";
    cout << "newPennies: " << newPennies << "\n";
    cout << "decimal Pounds: " << 'J' << pounds << "." << newPennies << "\n";
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
