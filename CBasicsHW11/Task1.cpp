#include <iostream>
#include <map>
#include <string>
#include "lib.h"


using namespace std;


string alphabetEng = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

map<char, int> alphabet;


string caesarEncode(string text, int shift) {
	int len = alphabetEng.length();
	string newText = "";

	for (size_t i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i])) {
		
			char upperCh = toupper(text[i]);
			char newCh = alphabetEng[(len + alphabet[upperCh] + shift) % len];

			if (islower(text[i])) newCh = tolower(newCh);

			newText += newCh;
		}
		else newText += text[i];
	}

	return newText;
}

string caesarDecode(string text, int shift) { return caesarEncode(text, -shift); }


void task1() {

	int length = size(alphabetEng);
	cout << "Length: " << length << endl;

	// convenient dict building:
	for (size_t i = 0; i < length; i++)
	{
		alphabet[alphabetEng[i]] = i;
	}

	// printing the map built:
	cout << "Alphabet: " << endl;
	for (auto pair : alphabet) {
	
		cout << pair.first << ": " << pair.second << endl;

	}

	// Caezar cipher:
	int shift = 15;
	string textToBeEncoded = "Sic parvis magna";
	string textEncoded = caesarEncode(textToBeEncoded, shift);

	cout << "Text: " << textToBeEncoded << endl;
	cout << "Text encoded: " << textEncoded << endl;
	cout << "Decoded Encoded Text (check): " << caesarDecode(textEncoded, shift) << endl;
}





