#include <iostream>
#include <vector>
#include <algorithm>
#include "lib.h"


using namespace std;


void task5()
{
    int a1, b1, c1;
    int a2, b2, c2;

    cout << "Please, enter the sizes of the first box separated by spaces: " << endl;
    cin >> a1 >> b1 >> c1;
    cout << "Please, enter the sizes of the second box separated by spaces: " << endl;
    cin >> a2 >> b2 >> c2;

    vector<int> s1, s2;

    s1.push_back(a1);
    s1.push_back(b1);
    s1.push_back(c1);

    s2.push_back(a2);
    s2.push_back(b2);
    s2.push_back(c2);

    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));

    if (s1[0] < s2[0] && s1[1] < s2[1] && s1[2] < s2[2])
        cout << "The first box can be placed in the second one!" << endl;
    else
        cout << "The fi" << endl;
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
