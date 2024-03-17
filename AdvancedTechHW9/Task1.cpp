#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <ctime>


using namespace std;


class Branch {

	private:

		Branch* parent;

		vector<Branch*> children;

		bool occupied;

		string name;

	public:

		Branch() : parent(nullptr), occupied(false) {
	
			
	
		}

		void addBranch() {
		
			Branch *child = new Branch();

			child->parent = this;
		
			children.push_back(child);
		}

		Branch* getBaseBranch() {
		
			// we are now at the root position:
			if (parent == nullptr) {
			
				return nullptr;

			} 

			// we are at the base branch now:
			if (parent->parent == nullptr) {
			
				return this;

			}

			// we are ath the middle branch now:
			return this->getBaseBranch();
		
		}

		int countElves() {

			int sum = (occupied) ? 1 : 0;

			for (auto child : children) {

				sum += child->countElves();

			}
		
			return sum;
		}

		int countNeighs() {
		
			return this->getBaseBranch()->countElves();
		
		}

		vector<Branch*> getChildren() {
		
			return this->children;
		
		}

		void setName(string name) {
		
			this->name = name;
		
		}

		void occupy() {
		
			this->occupied = true;

		}

};

string getElfName(map<string, Branch*> elves) {

	string s;

	cin >> s;

	while (elves.contains(s)) {
	
		cout << "Repeated name, please choose another one: " << endl;

		cin >> s;
	
	}

	return s;

}


void task1() {

	srand(time(NULL));
	vector<Branch*> trees;

	map<string, Branch*> elves;

	for (size_t treeq = 0; treeq < 5; treeq++)
	{
		Branch *tree = new Branch();
		trees.push_back(tree);

		int baseBranchesCount = rand() % 3 + 3;

		cout << "Occupying tree №" << treeq + 1 << "..." << endl;

		for (size_t j = 0; j < baseBranchesCount; j++)
		{
			tree->addBranch();

			cout << "...Please place an Elf on base branch №" << j + 1 << ": " << endl;

			string name = getElfName(elves);

			if (name != "None") {

				tree->getChildren()[j]->occupy();

				tree->getChildren()[j]->setName(name);

				elves[name] = tree->getChildren()[j];

			}

			int middleBranchesCount = rand() % 2 + 2;

			for (size_t i = 0; i < middleBranchesCount; i++)
			{
				tree->getChildren()[j]->addBranch();

				cout << "......Please place an Elf on middle branch №" << i + 1 << ": " << endl;

				string name = getElfName(elves);

				if (name != "None") {

					tree->getChildren()[j]->getChildren()[i]->occupy();

					tree->getChildren()[j]->getChildren()[i]->setName(name);

					elves[name] = tree->getChildren()[j]->getChildren()[i];
				}
			}
		}

		cout << "Elves q on tree №" << treeq + 1 << ": " << tree->countElves() << endl;
	}

	cout << "Please, enter the name of an Elf: " << endl;

	string s;

	cin >> s;

	if (elves.contains(s)) {
	
		cout << "Neighs number: " << elves[s]->countNeighs() << endl;
	
	}
	else {
	
		cout << "There is no elf with the name: " << s << endl;
	
	}
}
