#include <iostream>
#include <fstream>
#include <Windows.h>
#include "lib.h"
#include <vector>
#include <array>


using namespace std;

template<std::size_t S>
long long solve(std::array<int, S> input);


void task5() {

	// long long k{ 0 };


	// cout << "k: " << k << endl;

    // array<int, 10> arr = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    // cout << "Res: " << solve(arr) << endl;

    int q = 0;

    cout << "start..." << endl;

    for (int i = 0; i < 1000000000; i++) q += 1;
   
    cout << "done!" << endl;
}



template<std::size_t S>
long long solve(std::array<int, S> input) {

    int counter = 0;

    constexpr int maxControl{ 10 };

    long long result{ S }, evens{ 0 };
    cout << "S: " << S << endl;
    int num[100001];
    std::fill(num, num + 100001, 0);

    auto add = [&](int j, int l, int r) {
        auto& arg = num[input[j]];
        counter++;

        cout << "adding(" << l << "|" << r << ")...input[j], arg: " << input[j] << " " << arg << endl;

        arg++;
        if (arg > 1) evens += (arg % 2) ? -1 : 1;
        return evens ? 0 : 1;
    };

    auto minus = [&](int j, int l, int r) {
        auto& arg = num[input[j]];
        counter++;

        cout << "subtracting(" << l << "|" << r << ")...input[j], arg: " << input[j] << " " << arg << endl;

        arg--;
        if (arg > 0) evens += (arg % 2) ? -1 : 1;
        return evens ? 0 : 1;
    };


    int right{ 0 }, left{ 0 };
    for (int iControl = 0; iControl < maxControl; ) {
        long long old = result;

        cout << "left, right: " << left << " | " << right << endl;

        if (right < S) add(right++, left, right);
        if (right < S) result += add(right++, left, right);

        while (right < S) result += add(right++, left, right) + minus(left++, left, right);

        if (left > 0) add(--left, left, right);
        if (left > 0) result += add(--left, left, right);

        while (left > 0) result += add(--left, left, right) + minus(--right, left, right);

        if (old == result) iControl++;
        else iControl = 0;
    }

    cout << "Counter: " << counter << endl;

    return result;

}


