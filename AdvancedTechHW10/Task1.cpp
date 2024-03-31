# include <iostream>
# include <thread>
# include <string>
# include <numeric>

using namespace std;

string* names = new string[6];
int* velocities = new int[6];
int* distances = new int[6] {0, 0, 0, 0, 0, 0};

int counter = 0;


void func(int i) {

	if (distances[i] + velocities[i] < 100) distances[i] += velocities[i];
	else distances[i] = 100;
	
	cout << i << "th swimmer \"" << names[i] << "\": " << distances[i] << "/100" << endl;
}


void task1() {

	for (size_t i = 0; i < 6; i++)
	{
		cout << "Please, enter the name and velocity of the " << i << "th swimmer: " << endl;
		cin >> names[i] >> velocities[i];
	}

	thread* swimmers = new thread[6]; 

	int sum = 0;

	for (size_t i = 0; i < 6; i++)
	{
		swimmers[i] = thread(func, i);
	}

	while (accumulate(distances, distances + 6, sum) != 600) {
		sum = 0;

		for (size_t i = 0; i < 6; i++)
		{
			cout << swimmers[i].get_id() << endl;
			swimmers[i].join();		
		}
	
		this_thread::sleep_for(chrono::seconds(1));
	}
}
