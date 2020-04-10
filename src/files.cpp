#include <fstream>
#include <algorithm>
#include "files.h"

using namespace std;

Graph::Graph(const string &nameFile) {
    ifstream inputStream(nameFile);

    if(inputStream) {
        readGraphFromFile(inputStream,nameFile);
        _name = nameFile;

        // TODO: Perform tests

        inputStream.close();
    }
}

bool Graph::readGraphFromFile(ifstream &stream, const string &nameFile) {
    string line;;

    _numberVertices = readUniqueNumber(stream);
    _numberEdges = readUniqueNumber(stream);

    initMatrix();

    if(!readLines(stream, _matrix,_numberVertices,_numberEdges)) {
        // TODO: Free elements
    }

    findEntryAndEnding();


}



static int readUniqueNumber(ifstream &stream) {
    string line;
    getline(stream, line);
    return stoi(line);
}

static bool readLines(ifstream &stream, vector<vector<MatrixValue>> &matrix, int nbVertices, int nbEdges) {
    string line;
    vector<int> listVertices;
    int nbRealEdges{0};

    while (getline(stream, line)) {
        nbRealEdges++;
        int vertexFrom, vertexTo, weight;
        separateTransition(line, vertexFrom, vertexTo, weight);

        matrix[vertexFrom][vertexTo] = MatrixValue(1,weight);


        if (!isInVector(listVertices, vertexFrom)) {
            listVertices.push_back(vertexFrom);
        }

        if (!isInVector(listVertices, vertexTo)) {
            listVertices.push_back(vertexTo);
        }
    }


    if(nbRealEdges == nbEdges && nbVertices == listVertices.size()) {
        return true;
    }
    return false;
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
    while (isdigit(*it)) {
        tmp += *it;
        it++;
    }

    // Moving to the next digit
    while(!isdigit(*it)) {
        it++;
    }

    return stoi(tmp);
}

static bool isInVector(vector<int> &l, int elt) {
    if(find(l.begin(),l.end(),elt) != l.end()) {
        return true;
    }
    return false;
}