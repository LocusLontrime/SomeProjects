// MoneyAmount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exercise 3.67

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // std::cout << "Hello World!\n";
    int initialAmount, depositTerm;
    float rate;
    cout << "Please, enter the initial amount of money, deposit term and rate:" << endl;
    cin >> initialAmount >> depositTerm >> rate;
    float finalAmount = initialAmount;
    for (;depositTerm > 0; depositTerm--) 
    {
        finalAmount *= 1 + rate / 100.0;
    }
    cout << "The final amount is: " << finalAmount << endl;
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
