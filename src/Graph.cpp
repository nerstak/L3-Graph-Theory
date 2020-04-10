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

Graph::~Graph() {
}

void Graph::findEntryAndEnding() {
    for(int from = 0; from < _numberVertices; from++) {
        // By default, a node is an exit and an entry point
        bool entry{1}, exit{1};
        _entryVertices.push_back(from);
        _exitVertices.push_back(from);
        int to = 0;
        while(to < _numberVertices && (entry || exit)) {
            // Checking ingoing edges
            if (_matrix[to][from].getAdjacency() == true && entry) {
                // We remove it from entry points
                _entryVertices.pop_back();
                entry = false;
            }

            // Checking outgoing edges
            if (_matrix[from][to].getAdjacency() == true && exit) {
                // We remove it from ending points
                _exitVertices.pop_back();
                exit = false;
            }

            to++;
        }
    }
}
