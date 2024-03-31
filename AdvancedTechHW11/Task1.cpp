# include <iostream>
# include <vector>
# include "lib.h"
# include <map>


using namespace std;


class Talent {

public:

	virtual void doSmth() = 0;
};

class Flyable: virtual public Talent {

public:

	void doSmth() override {
	
		cout << "I believe i can fly! I believe i can touch the sky!" << endl;
	}
};

class Dancable : virtual public Talent {

public:

	void doSmth() override {

		// do smth;

		cout << "Baby, dance with me. Come one and dance with me!" << endl;
	}
};

class Singable : virtual public Talent {

public:

	void doSmth() override {

		// do smth;

		cout << "Billie Jean is not my lover. She's just a girl who claims that i am the one..." << endl;
	}
};

class Drinkable : virtual public Talent {

public:

	// LeviGin special request (HTTP)...

	void doSmth() override {

		// do smth;

		cout << "I am sexy and i know it!" << endl;
	}

};

map<string, Talent*> talentsInters = {
		{"flyable", new Flyable()},
		{"dancable", new Dancable()},
		{"singable", new Singable()},
		{"drinkable", new Drinkable()}
};

class Dog {

private:

	string name;

	vector<string> talents;

public:

	Dog() : name("Unknown") {

	}

	Dog(string name) {
	
		this->name = name;
	}

	~Dog() {
	
		cout << "All the dogs get to the heaven..." << endl;
	}

	void addTalent(string talent) {
	
		if (talentsInters.contains(talent)) {
		
			if (find(talents.begin(), talents.end(), talent) == talents.end()) talents.push_back(talent);
		
		}
		else cout << "There is no such a talent in the pool!" << endl;	
	}

	void showTalents() {

		cout << "Dog \"" << name << "\" has following talents: " << endl;

		for (auto talent : talents) cout << talent << endl;	
	}

	void useTalent(string talent) {
	
		if (talentsInters.contains(talent)) {

			if (find(talents.begin(), talents.end(), talent) == talents.end()) cout << "The dog has not thins talent..." << endl;
			else talentsInters[talent]->doSmth();

		}
		else cout << "There is no such a talent in the pool!" << endl;
	}
};

void task1() {

	Dog* pesya = new Dog();

	pesya->addTalent("flyable");
	pesya->addTalent("dancable");
	pesya->addTalent("singable");
	pesya->useTalent("flyable");
	pesya->showTalents();
}
