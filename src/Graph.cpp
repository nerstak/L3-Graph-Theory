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
