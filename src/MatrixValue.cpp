#include "MatrixValue.h"

MatrixValue::MatrixValue(int adjacency, int weight) {
    if(adjacency != 0 && adjacency != 1 && adjacency != -1) {
        throw "Incorrect value of adjacency";
    } else {
        _adjacency = adjacency;
        _weight = weight;
    }
}

MatrixValue::MatrixValue(const MatrixValue &mv) {
    _adjacency = mv._adjacency;
    _weight = mv._weight;
}

int MatrixValue::getAdjacency() {
    return _adjacency;
}

int MatrixValue::getWeight() {
    return _weight;
}