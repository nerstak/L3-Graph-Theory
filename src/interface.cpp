#include <iostream>
#include "interface.h"

using namespace std;

void menu() {
    bool loop = true;
    int choice{0};
    while (loop) {
        choice = interaction();

        if (choice != 2) {
            processFile();
        } else {
            loop = false;
        }
    }
}

static int interaction() {
    separation();
    cout << "~~Hello user~~" << endl;
    cout << "Make a choice : " << endl;
    cout << "[1] Load graph from file" << endl;
    cout << "[2] Exit" << endl;

    int i = 0;
    cin >> i;
    while (i < 1 || i > 5) {
        cout << "Wrong value. Please make a choice between 1 and 2." << endl;
        cin >> i;
    }

    return i;
}

static void processFile() {
    separation();
    string myFileName;
    myFileName = "Int1-9-graph" + to_string(askNumberFile()) + ".txt";
    Graph myGraph = Graph("graphs/", myFileName);

    myGraph.checkLoop();

    if (!myGraph.getCycle()) {
        myGraph.findRank();

        if (schedulable() == true){
            writeLogFile(myFileName,"\n\n ~~Earliest Time~~ " + myGraph.computeEarliest());
            writeLogFile(myFileName, "\n\n ~~Latest Time~~ " + myGraph.computeLatest());
            writeLogFile(myFileName,"\n\n ~~Margins~~ " + myGraph.margins());
        }
    }

}

void separation() {
    cout << endl << "\n*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;
}

static int askNumberFile() {
    int choice = -1;
    while (choice < 0 || choice > 13) {
        cout << "Enter the graph you want to load :" << endl;
        cin >> choice;
        if (choice >= 0 && choice <= 13)
            return choice;
        cout << "Choice not available";
    }
}

void displayAdjacencyMatrix() {
    cout <<"\t ";
    for (int k = 0; k < _numberVertices; k++){
            cout << k;
    }
    cout <<"\n";
    for (int i = 0; i < _numberVertices; i++) {
                  cout << i << " : "<<;
                  for (int j = 0; j < _numberVertices; j++){
                        cout << _matrix[i][j].getAdjacency();
                  }
                   cout <<"\n"<<;
    }
}

void displayWeightMatrix() {
    cout <<"\t ";
    for (int k = 0; k < _numberVertices; k++){
            cout << k;
    }
    cout <<"\n";
    for (int i = 0; i < _numberVertices; i++) {
                  cout << i << " : "<<;
                  for (int j = 0; j < _numberVertices; j++){
                        cout << _matrix[i][j].getWeight();
                  }
                   cout <<"\n"<<;
    }
}
