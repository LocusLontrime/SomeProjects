// Partitions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exercise 3.9

#include <iostream>
#include <cmath>

using namespace std; // 3.6 36 98 989

int partitionsCount(int guests, int seats)  // supposed that guests q is bigger than seats q
{
    int partitions = 1;
    for (; seats > 0;)
    {
        partitions *= guests - --seats;
    }
    return partitions;
}

int main()
{
    // std::cout << "Hello World!\n";
    int guests, seats;
    cout << "Please, enter the amounts of guests and seats:" << endl;
    cin >> guests >> seats;
    cout << "The partitions quantity: " << partitionsCount(guests, seats) << endl;
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
