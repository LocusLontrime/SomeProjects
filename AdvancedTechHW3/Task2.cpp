#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum roomType {
    living,
    children,
    kitchen,
    bathroom
};

struct room {

    double square;
    roomType rType;
};


struct floorHome {

    double height;
    int qRoom;
    vector<room> r;

};


struct home {

    int qFloor;
    bool oven;
    double square;
    vector<floorHome> storey;

};

struct garage {

    double square;

};

struct bathhouse {

    double square;
    bool oven;

};

struct storage {
    double square;
};



struct area {

    int number;
    double square;
    home house;
    garage garage_;
    bathhouse bathhouse_;
    storage storage_;
};

struct region {

    string name;
    vector<area> area_;

};


int main() {

    region reg;
    int count;
    string name;
    cout << "Enter the name your regin: ";
    cin >> name;
    reg.name = name;
    cout << "Enter quantity area in your region: ";
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        area area_;
        int number;
        double sq;
        cout << "Enter the number area and square: ";
        cin >> number >> sq;
        area_.number = number;
        area_.square = sq;

        home home_;
        cout << "Enter the home square: ";
        cin >> home_.square;

        cout << "Is there a stove in the house (0/1): ";
        cin >> home_.oven;

        cout << "How many floors are there in the house: ";
        cin >> home_.qFloor;

        for (size_t i = 0; i < home_.qFloor; i++)
        {
            floorHome floorHome_;
            cout << "What is the ceiling height on the floor: ";
            cin >> floorHome_.qRoom;
            cout << "How many rooms per floor: ";
            cin >> floorHome_.qRoom;
            for (size_t i = 0; i < floorHome_.qRoom; i++)
            {
                room r_;
                char rmType;
                cout << "What is the area in the room: ";
                cin >> r_.square;
                cout << "Which rooms are on the floor (l: living, c: children, k: kitchen, b: bathroom): ";
                cin >> rmType;
                switch (rmType)
                {
                case 'l':
                    r_.rType = roomType::living;
                    break;
                case 'c':
                    r_.rType = roomType::children;
                    break;
                case 'k':
                    r_.rType = roomType::kitchen;
                    break;
                case 'b':
                    r_.rType = roomType::bathroom;
                    break;
                }

                floorHome_.r.push_back(r_);
            }

            home_.storey.push_back(floorHome_);
        }
        area_.house = home_;

        bool flag;
        cout << "Do you have a sauna on the site (0/1)";
        cin >> flag;
        if (flag) {
            bathhouse bh;
            cout << "Is there a stove in the house (0/1): ";
            cin >> bh.oven;
            cout << "Enter the home square: ";
            cin >> bh.square;
            area_.bathhouse_ = bh;
        }
        cout << "Do you have a garage on the site (0/1): ";
        cin >> flag;
        if (flag) {
            garage g;
            cout << "Enter the home square: ";
            cin >> g.square;
            area_.garage_ = g;
        }
    }
    return 0;
}