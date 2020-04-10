#include "Graph.h"

const vector<int> &Graph::getEntryVertices() const {
    return _entryVertices;
}

const vector<int> &Graph::getExitVertices() const {
    return _exitVertices;
}

const vector<vector<MatrixValue>> &Graph::getMatrix() const {
    return _matrix;
}

void Graph::initMatrix() {
    for(int i = 0; i < _numberVertices; i++) {
        vector<MatrixValue> tmp;
        for(int j = 0; j < _numberVertices; j++) {
            tmp.push_back(MatrixValue(false,0));
        }

        _matrix.push_back(tmp);
    }
}

Graph::~Graph() = default;

void Graph::findEntryAndEnding() {
    for(int state = 0; state < _numberVertices; state++) {
        // By default, a node is an exit and an entry point
        _entryVertices.push_back(state);
        _exitVertices.push_back(state);

        // Cannot be entry if there is predecessor
        if(!getPredecessors(state).empty()) {
            _entryVertices.pop_back();
        }

        // Cannot be exit if there is successor
        if(!getSuccessors(state).empty()) {
            _exitVertices.pop_back();
        }
    }
}

vector<int> Graph::getPredecessors(int state) {
    vector<int> predecessors;
    for(int s = 0; s < _numberVertices; s++) {
        if(_matrix[s][state].getAdjacency()) {
            predecessors.push_back(s);
        }
    }

    return predecessors;
}

vector<int> Graph::getSuccessors(int state) {
    vector<int> successors;
    for(int s = 0; s < _numberVertices; s++) {
        if(_matrix[state][s].getAdjacency()) {
            successors.push_back(s);
        }
    }

    return successors;
}
