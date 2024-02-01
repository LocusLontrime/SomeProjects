#include <iostream>
#include "lib.h"
#include <string>


using namespace std;

void task1() {

	string text, word;

	cout << "Please, enter the text: " << endl;
	getline(std::cin, text);
	cout << "Please, enter the word: " << endl;
	cin >> word;

	int counter = 0;
	for (size_t j = 0; j < text.size() - word.size() + 1; j++)
	{
		bool flag = true;
		for (size_t i = j; i - j < word.size(); i++)
		{
			cout << "text[" << i << "], word[" << i - j << "]: " << text[i] << ", " << word[i - j] << endl;
			if (text[i] != word[i - j]) {
			
				flag = false;
				break;
			}
		}

		if (flag) {
		
			counter++;
			cout << "counter: " << counter << endl;
		}
	}

	cout << "There are " << counter << " occurrences of the word \"" << word 
		<< "\" in the text: \"" << text << "\"" << endl;
}
