#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <string>



using namespace std;


enum TaskType {

	A,
	B,
	C,
	ZERO

};


class Employee {

protected: 
	string name;

public:

	Employee(string name) {
	
		this->name = name;
	
	}

	string getName() {
	
		return name;
	
	}

};


class Worker: public Employee {

private:
	TaskType currTask;

public:
	
	Worker(string name) : Employee(name), currTask(ZERO) {
	
		
	
	}

	void setTask(TaskType task) {
	
		currTask = task;
	
	}

	TaskType getCurrTask() {
	
		return currTask;

	}

};


class Manager : public Employee {

private:
	int id;
	vector<Worker> team;
	int busyWorkersQ;

	TaskType* types = new TaskType[]{A, B, C};

public:

	Manager(int id, string name): Employee(name), busyWorkersQ(0) {

		this->id = id;

	}

	void addWorker(Worker worker) {
	
		team.push_back(worker);

		// cout << "new team size: " << team.size() << endl;

	}

	int splitHardTask(int seed) {

		cout << name << " got Hard Task from TopManager..." << endl;
	
		srand(seed + id);

		int tasksCount = rand() % (team.size() - busyWorkersQ + 1);	

		cout << "team.size() - busyWorkersQ + 1: " << team.size() - busyWorkersQ + 1 << endl;
		cout << "tasksCount: " << tasksCount << endl;

		// A, B, C task splitting:
		int aq = rand() % (tasksCount + 1);

		int bq = rand() % (tasksCount - aq + 1);

		int cq = tasksCount - aq - bq;

		for (size_t i = 0; i < tasksCount; i++)
		{

			team[busyWorkersQ + i].setTask(types[i < aq ? 0 : (i >= aq && i < aq + bq ? 1 : 2)]);

			cout << team[busyWorkersQ + i].getName() << " got task " << team[busyWorkersQ + i].getCurrTask() << endl;

		}

		this->busyWorkersQ += tasksCount;

		cout << "busyWorkersQ: " << busyWorkersQ << endl;

		return team.size() - busyWorkersQ;
	
	}

};


class TopManager : public Employee {

private:
	int id;
	vector<Manager> managers;

public:

	TopManager(int id, string name) : Employee(name) {

		this->id = id;

	}

	void addManager(Manager manager) {

		managers.push_back(manager);

	}

	void createStaff(int managersQ, int teamSize) {
	
		for (int j = 1; j <= managersQ; j++)
		{

			Manager* manager = new Manager(id + j, "Manager" + to_string(id + j));

			for (size_t i = 1; i <= teamSize; i++)
			{

				// cout << "j, i: " << j << " " << i << endl;

				Worker* worker = new Worker("Worker" + to_string(id + managersQ + (j - 1) * teamSize + i));

				// cout << "worker name: " << worker->getName() << endl;

				manager->addWorker(*worker);

			}

			this->addManager(*manager);

		}
	
	}

	int delegateTask(int seedId) {

		int sum = 0;
	
		for (auto &manager : managers) {
		
			sum += manager.splitHardTask(seedId);
		
		}

		cout << "sum: " << sum << endl;

		return sum;
	
	}

	int getId() {
	
		return id;

	}

};


void task3() {

	TopManager *topm = new TopManager(1, "Oleg");

	cout << "TopManager " << "(id: " << topm->getId() << ") " << topm->getName() << " sterted working..." << endl;

	topm->createStaff(3, 5);

	int x;

	do {
	
		cout << "Please, enter seedId for topManager task: ";
		cin >> x;		
	
	} while (topm->delegateTask(x));

}
