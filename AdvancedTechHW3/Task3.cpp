#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct vec {
    double x;
    double y;
};

vec add(vec v1, vec v2);
vec substract(vec v1, vec v2);
double scale(vec v1, vec v2);
double length(vec v);
double normalize(vec v);

int main() {

    vec v1, v2;
    cout << "Enter the coord vector1 [x, y]: ";
    cin >> v1.x >> v1.y;

    cout << "Enter the coord vector1 [x, y]: ";
    cin >> v2.x >> v2.y;

    cout << "Add: " << add(v1, v2).x << " " << add(v1, v2).y << endl;
    cout << "Substract: " << substract(v1, v2).x << " " << substract(v1, v2).y
        << endl;
    cout << "Scale: " << scale(v1, v2) << endl;
    cout << "Length: " << length(v1) << endl;
    cout << "Normalize: " << normalize(v1) << endl;
    return 0;
}

vec add(vec v1, vec v2) {

    vec res;
    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    return res;
}

vec substract(vec v1, vec v2) {
    vec res;
    res.x = v1.x - v2.x;
    res.y = v1.y - v2.y;
    return res;
}

double scale(vec v1, vec v2) {

    return v1.x * v2.x + v1.y * v2.y;

}

double length(vec v) { return sqrt(v.x * v.x + v.y * v.y); }

double normalize(vec v) {

    return pow(v.x / length(v), 2) + pow(v.y / length(v), 2);
}