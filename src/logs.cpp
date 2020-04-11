#include "logs.h"
#include <fstream>
#include <iostream>

using namespace std;

void createLogFile(string nameFile) {
    ofstream myFile("logs/" + nameFile, ios::trunc);
    if(myFile.is_open()) {
        myFile.close();
    }
}

void writeLogFile(string nameFile, const string &value) {
    // Display on screen
    cout << value;

    // Write on log
    ofstream myFile("logs/" + nameFile, ios::app);
    if(myFile.is_open()) {
        myFile << value;
    }
}