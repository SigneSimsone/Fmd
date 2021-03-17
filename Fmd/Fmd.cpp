/*******************************************
Signe Simsone, ss20120
Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā.
Dati no faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.

F15. Dots teksta fails, kurā atrodas sintaktiski pareizs C++ programmas teksts.
Uzrakstīt programmu, kura saskaita, cik dažādu bibliotēku (#include) iekļauts dotajā programmā.
Drīkst uzskatīt, ka programmas tekstā nav komentāru un ka attiecīgie simboli neparādīsies teksta literāļos.
Programma izveidota: 2021/03/##
*******************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string word = "#include";
	string line;
	int countwords = 0;
	ifstream file("program.txt");

	if (file.is_open()) {
		cout << "File '" << "program.txt" << "' opened." << endl;

		while (!file.eof()) {
			getline(file, line); //reads every line in the file
			int found = line.find(word); //searches the string that contains the line for the word "#include"
			if (found != string::npos) //checks if the word has been found
				countwords++;
		}
		cout << "This file " << "contains " << countwords << " libraries (" << word << ")." << endl;
		file.close();
	}
	else {
		cout << "Error! File not found!" << endl;
		return 1;
	}
}