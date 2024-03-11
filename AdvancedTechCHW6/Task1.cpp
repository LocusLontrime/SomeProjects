#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lib.h"
#include <map>


// using namespace std;


struct Task {

	std::string taskName;
	int beginTime;
	int endTime;

	Task(): beginTime(0), endTime(0) {}
};

enum Case {
	begin,
	end,
	status,
	exit_
};


void task1() {

	Task currTask;

	std::vector<Task> status = {};

	time_t k = time(nullptr);

	std::cout << "k: " << k << std::endl;

	bool flag = true;

	while (flag)
	{

		std::cout << "Please, enter a command ('begin', 'end', 'status', 'exit')" << std::endl;

		std::map<std::string, Case> commands = {
			{"begin", Case::begin}, 
			{"end", Case::end}, 
			{"status", Case::status},
			{"exit", Case::exit_}
		};

		std::string s;

		std::cin >> s;

		if (!commands.contains(s)) continue;
		
		switch (commands[s])
		{
			case Case::begin:

				if (currTask.beginTime) {

					currTask.endTime = time(nullptr);
				
					status.push_back(currTask);

					currTask.beginTime = 0;
				}

				std::cout << "Please, enter task name: " << std::endl;

				std::cin >> currTask.taskName;

				currTask.beginTime = time(nullptr);

				break;

			case Case::end:

				if (currTask.beginTime) {

					currTask.endTime = time(nullptr);

					status.push_back(currTask);

					currTask.beginTime = 0;
				}

				break;

			case Case::status:

				std::cout << "List of tasks done: " << std::endl;

				for (int i = 0 ; i < status.size(); i++)
				{
					Task task_ = status[i];
					std::cout << i + 1 << ". " << task_.taskName << " -> time elapsed: " << (task_.endTime - task_.beginTime) << " seconds" << std::endl;
				}

				if (currTask.beginTime) std::cout << "Current task: " << currTask.taskName << std::endl;

				break;

			case Case::exit_:
				std::cout << "" << std::endl;
				flag = false;
				break;
		}
	}
}



