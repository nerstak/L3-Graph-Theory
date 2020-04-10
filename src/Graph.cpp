#include "Graph.h"

const vector<int> &Graph::getEntryVertices() const {
    return entryVertices;
}

const vector<int> &Graph::getExitVertices() const {
    return exitVertices;
}

const vector<vector<MatrixValue>> &Graph::getMatrix() const {
    return _matrix;
}

void Graph::initMatrix(int &size) {
    for(int i = 0; i < size; i++) {
        vector<MatrixValue> tmp;
        for(int j = 0; j < size; j++) {
            tmp.push_back(MatrixValue(0,0));
        }

        _matrix.push_back(tmp);
    }
}

Graph::~Graph() {
}
