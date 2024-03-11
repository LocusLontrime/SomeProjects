#include <iostream>
#include <fstream>
#include <Windows.h>
#include "lib.h"
#include <vector>
#include <array>


using namespace std;


long long solve(int* input, int size);


void testF() {

    int* arr = new int[4] {2, 2, 2, 3};

    int* arrx = new int[15] { 2, 5, 2, 3, 6, 7, 8, 23, 23, 13, 65, 31, 3, 4, 3 };

    int* arry = new int[27]  { 6, 1, 7, 4, 6, 7, 1, 4, 7, 1, 4, 6, 6, 7, 4, 1, 6, 4, 7, 1, 4, 5, 3, 2, 1, 6, 9 };

    int* arrk = new int[11] { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 };

    // int* arrl = new int[1000]; // ans: 122470

    //ifstream f;
    //string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\LittleNums.txt";
    //f.open(path);

    //int i = 0;
    //while (!f.eof()) {
    //    f >> arrl[i++];
    //    // cout << i << " | " << arrz[i++] << endl;
    //}

    // std::cout << "calculating... | i = " << i << endl;

    //int* arrm = new int[19999]; // ans: 7874661

    //ifstream f;
    //string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\MiddleNums.txt";
    //f.open(path);
    //
    //int i = 0;
    //while (!f.eof()) {
    //    f >> arrm[i++];
    //    // cout << i << " | " << arrz[i++] << endl;
    //}

    //std::cout << "calculating... | i = " << i << endl;
    
    int* arrz = new int[100000];  // ans: 8258251
    
    ifstream f;
    string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\BigNums.txt";
    f.open(path);

    int i = 0;
    while (!f.eof()) {
        f >> arrz[i++];
        // cout << i << " | " << arrz[i++] << endl;
    }
        
     std::cout << "calculating... | i = " << i << endl;

    int t1 = clock();
    
    std::cout << "res: " << solve(arrz, 100000) << endl;

    int t2 = clock();
    std::cout << "Time elapsed: " << (t2 - t1) << " ms" << "\n" << endl;

}


long long solve(int* input, int size) {
    const int maxSteps = 10; 
    const int maxSize = 100001;

    long long res = size, evens = 0;

    int frequencies[maxSize];
    std::fill(frequencies, frequencies + maxSize, 0);

    auto add = [&](int j) {
        auto& val = frequencies[input[j]];
        return (evens += ++val > 1 ? ((val % 2) ? -1 : 1) : 0) ? 0 : 1;
    };

    auto subtract = [&](int j) {
        auto& val = frequencies[input[j]];
        return (evens += --val > 0 ? ((val % 2) ? -1 : 1) : 0) ? 0 : 1;
    };

    std::cout << "now in cycle..." << endl;                                                                


    int lb = 0, rb = 0;
    int i = 0;
    while (i < maxSteps) {  // after maxSteps without any new naives -> break...
        long long prevRes = res;

        std::cout << "lb, rb: " << lb << ", " << rb << endl;

        if (rb < size) add(rb++);
        if (rb < size) res += add(rb++);

        // std::cout << "...interim1 lb, rb: " << lb << ", " << rb << endl;

        while (rb < size) {
            int add_ = add(rb);
            rb++;
            int minus_ = subtract(lb);
            lb++;
            res += add_ + minus_;
        }

        // std::cout << "...interim2 lb, rb: " << lb << ", " << rb << endl;

        if (lb > 0) add(--lb);
        if (lb > 0) res += add(--lb);

        // std::cout << "...interim3 lb, rb: " << lb << ", " << rb << endl;

        while (lb > 0) {
            lb--;
            int add_ = add(lb);
            rb--;
            int minus_ = subtract(rb);
            res += add_ + minus_;
        } 

        // cout << "...interim4 lb, rb: " << lb << ", " << rb << endl;

        // checks for "no new naive subarrays" case:
        if (prevRes == res) {
            i++; 
            // std::cout << "......................................................................................" << endl;
        }
        else i = 0;
    }

    /*for (size_t i = 0; i < size; i++)
    {
        std::cout << num[i] << " ";
    }*/

    std::cout << endl;

    return res;

}
