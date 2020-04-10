#include "MatrixValue.h"

MatrixValue::MatrixValue(bool adjacency, int weight) {
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

void MatrixValue::setWeight(int weight) {
    _weight = weight;
    _adjacency = 1;
}

void MatrixValue::setAdjacency(bool adjacency) {
    _adjacency = adjacency;
    if(_adjacency == 0) {
        _weight = 0;
    }
}

