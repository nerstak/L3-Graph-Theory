#include <fstream>
#include <algorithm>
#include <iostream>
#include "readGraphFile.h"
#include "Graph.h"


using namespace std;

Graph::Graph(const string &nameFile) {
    ifstream inputStream("graphs/" + nameFile + ".txt");

    if(inputStream) {
        createLogFile(nameFile);
        _name = nameFile;
        readGraphFromFile(inputStream);

        findEntryAndEnding();

        inputStream.close();
    }
}

bool Graph::readGraphFromFile(ifstream &stream) {
    string line;

    _numberVertices = readUniqueNumber(stream);
    _numberEdges = readUniqueNumber(stream);

    displayNumbers(_name, _numberVertices, _numberEdges);

    initMatrix();

    initCalendars();

    if(!readLines(stream, _name, _matrix, _numberVertices, _numberEdges)) {
        // TODO: Free elements
    }
}

static int readUniqueNumber(ifstream &stream) {
    string line;
    getline(stream, line);
    return stoi(line);
}

static bool
readLines(ifstream &stream, string const &nameFile, vector<vector<MatrixValue>> &matrix, int nbVertices, int nbEdges) {
    string line;
    vector<int> listVertices;
    int nbRealEdges{0};

    // Reading each remaining line
    while (getline(stream, line)) {
        nbRealEdges++;
        int vertexFrom, vertexTo, weight;
        separateTransition(line, vertexFrom, vertexTo, weight);

        matrix[vertexFrom][vertexTo] = MatrixValue(true,weight);

        // Verify if node is recorded
        if (!isInVector(listVertices, vertexFrom)) {
            listVertices.push_back(vertexFrom);
        }
        if (!isInVector(listVertices, vertexTo)) {
            listVertices.push_back(vertexTo);
        }

        // Log
        string display = to_string(vertexFrom) + " -> " + to_string(vertexTo) + " = " + to_string(weight) + "\n";
        writeLogFile(nameFile, display);
    }


    return nbRealEdges == nbEdges && nbVertices == listVertices.size();
}

static void separateTransition(string &transitionString, int &vertexFrom, int &vertexTo, int &weight) {
    string::iterator it = transitionString.begin();

    // Initial vertex
    vertexFrom = readDigit(it);

    // Final vertex
    vertexTo = readDigit(it);

    // Weight
    weight = readDigit(it);
}

static int readDigit(string::iterator &it) {
    string tmp;
    // Reading digit
    while (isdigit(*it) or *it == '-') {
        tmp += *it;
        it++;
    }

    // Moving to the next digit
    while(!isdigit(*it) && *it != '-') {
        it++;
    }

    return stoi(tmp);
}

static bool isInVector(vector<int> &l, int elt) {
    return find(l.begin(), l.end(), elt) != l.end();
}

static void displayNumbers(const string &nameFile, int nbVertices, int nbEdges) {
    string display = "* Reading graph from file " + nameFile + "\n";

    display += to_string(nbVertices) + " vertices\n" + to_string(nbEdges) + " edges\n";

    writeLogFile(nameFile,display);
}