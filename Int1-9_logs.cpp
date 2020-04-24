#include "Int1-9_logs.h"
#include <fstream>
#include <iostream>

using namespace std;

void createLogFile(const string& nameFile) {
    ofstream myFile("Int1-9-trace" + nameFile + ".txt", ios::trunc);
    if(myFile.is_open()) {
        myFile.close();
    }
}

void writeLogFile(const string& nameFile, const string &value) {
    // Display on screen
    cout << value;

    // Write on log
    ofstream myFile("Int1-9-trace" + nameFile + ".txt", ios::app);
    if(myFile.is_open()) {
        myFile << value;
    }
}