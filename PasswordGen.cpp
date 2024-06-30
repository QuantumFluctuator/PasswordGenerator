#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

static bool imported(false);

static vector<string> wordList;

//DEBUG FUNCTIONS
void debugPrintWords();

//FUNCTIONS
void setRandSeed();
void importWords(const char* x="list.txt");
string generatePword();
void outputPword(string pwrd);

int main()
{
    string password;
    setRandSeed();
    importWords();
    //debugPrintWords();
    password = generatePword();
    outputPword(password);
}

void setRandSeed() { srand((unsigned)time(0)); }

void importWords(const char* x) {
    ifstream in(x);
    string str;

    while (getline(in, str)) {
        wordList.push_back(str);
    }
}

void debugPrintWords() {
    for (int i(0); i < wordList.size(); i++) {
        cout << wordList[i] << endl;
    }
}

string generatePword() {
    if (!imported) { importWords(); }

    string pwrd("");
    
    pwrd += wordList[rand() % wordList.size()];
    pwrd += ".";
    pwrd += wordList[rand() % wordList.size()];
    pwrd += ".";
    pwrd += wordList[rand() % wordList.size()];

    return pwrd;
}

void outputPword(string pwrd) { cout << pwrd; }