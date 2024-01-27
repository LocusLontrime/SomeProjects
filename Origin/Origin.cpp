// Origin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <conio.h>
#include <stdio.h>

using namespace std;  // not good decision for a huge projects with many namespaces used...

int main()
{
    // important method...
    string name1, name2;
    cout << "What is your name?\n";
    cin >> name1 >> name2;
    cout << "Hello World! Hello, " << name1 + " " + name2 << "\n";
    unsigned long long number;
    number = pow(2, 64) - 1;  // 1198976856446;
    cout << "number: " << number << "\n";
    cout << "short num: " << unsigned short(number) << "\n";
    cout << "int num: " << unsigned int(number) << "\n";
    cout << "something: " << long long(98) << "\n";
    char enter = '\n';
    char tab = '\t';
    cout << tab << "hi!" << tab << "man!" << enter;
    cout << "FAFA LALA!!!\n"; 
    cout << "enter num, tab num: " << int(enter) << " and " << int(tab) << enter;
    int k = 2;
    k = k << 9;
    cout << "k: " << k << enter
    << "Babich said: \"When i used to be a child...\"\n"
    << "Strange sequence: \\...\\\n";
    cout << setw(11) << "LOCATION" << setw(12) << "POPULATION\n"
        << setw(11) << "Omsk" << setw(12) << "1110836\n"
        << setw(11) << "Moscow" << setw(12) << "12636312\n"
        << setw(11) << "Tomsk" << setw(12) << "574000\n"
        << setw(11) << "Novosibirsk" << setw(12) << "1567000\n";
    int variable = 98;
    double var = static_cast<double>(variable);
    cout << "variable: " << variable << enter;
    cout << "var: " << var << endl;

    // 1.cycles and 2.branching:
    bool answer;
    answer = 98 < 989;
    cout << "answer: " << answer << endl;
    bool res = true;
    cout << "res: " << res << endl;
    // cubeList:
    cout << "Cubes: " << endl;
    for (int numb = 1; numb <= 10; numb++)
    {
        cout << setw(4) << numb;
        int cube = numb * numb * numb;
        cout << setw(6) << cube << endl;
    }
    // debugging... ok
    // diff shapes of for...
    unsigned int num;
    unsigned long long factorial = 1;
    cout << "Please, enter the number for factorial eveluating:" << endl;
    cin >> num;
    for (int i = num; i > 0; i--)
    {
        factorial *= i;
    }
    cout << "factorial: " << factorial << endl;
    // for (;;) -> dangerous, like while True: in Python...
    // while
    int key = 1; 
    int opsQ;
    // 3x + 1 problem:
    while (key != 0) 
    {
        opsQ = 0;
        cout << "Please, enter key:" << endl;
        cin >> key;
        while (key > 0 && key != 1) 
        {
            opsQ++;
            cout << "key: " << key << endl;
            if (key % 2 == 1) 
            {
                key = 3 * key + 1;
            }
            else 
            {
                key /= 2;
            }
        }
        cout << "ops q: " << opsQ << endl;
    }
    // branching:
    // let us count words and symbols quantities:
    int charCounter = 0, wordCounter = 0;
    char ch;
    cout << "let us count words and symbols quantities:" << endl;
    while ((ch = _getche()) != '\r')
    {
        if (ch == ' ')
        {
            wordCounter++;
        }
        else
        {
            charCounter++;
        }
    }
    cout << "words, symbols: " << wordCounter << ", " << charCounter << endl;
    // else if...
    int a = 3, b = 5, c = 5;
    if (a == b)
        if (b == c)
            cout << "a, b, c are the same!" << endl;
        else
            cout << "b, c are not the same!" << endl;
    // bad, let us correct this:
    if (a == b == c)
        cout << "a, b, c are the same!" << endl;
    else
        cout << "a, b, c are not the same!" << endl;
    // else if ex:
    int g = 91;
    if (g < 0)
        cout << "g is less than zero" << endl;
    else if (g == 0)
        cout << "g is equal to zero" << endl;
    else
        cout << "g is bigger than zero" << endl;
    // switch:
    int n;
    cout << "Please, enter n: " << endl;
    switch (n)
    {
        // any logic:
        case 0:
            cout << "" << endl;
            break;
        case 1:
            cout << "" << endl;
            break;
        case 98:
            cout << "" << endl;
            break;
        default:
            cout << "" << endl;
            break;
    }
    // conditional op:
    int min;
    if (a < b)
        min = a;
    else
        min = b;
    // can be transformed into this:
    min = (a < b) ? a : b;
    // getch() - delay...
    // enum:
    enum type {Good, Bad, Strange, Perfect, Ideal};
    
    type k = Good;
    type l = Perfect;

    return 0;

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
