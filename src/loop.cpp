#include <algorithm>
#include <iostream>
#include "loop.h"

using namespace std;

void Graph::checkLoop() {
    Graph newGraph(*this);

    _cycle = newGraph.popCycle();

    if (_cycle) {
        cout << "The graph contains a cycle.";
    } else {
        cout << "The graph does not contains a cycle.";
    }
}

void Graph::disconnectEntries() {
    vector<int> successors, newEntries, singleSuccessors;

    for (int i : _entryVertices) {
        singleSuccessors = getSuccessors(i);
        for (int j: singleSuccessors) {
            //if not already added to successors (union of all successors and currVertex successors)
            if (find(singleSuccessors.begin(), singleSuccessors.end(), i) == singleSuccessors.end()) {
                successors.push_back(j);
            }
        }
    }

    for (int i: _entryVertices) {
        for (int j = 0; j < _numberVertices; j++) {
            _matrix[i][j].setAdjacency(false);
        }
    }

    _entryVertices.clear();

    for (int i: successors) {
        if (getPredecessors(i).empty()) {
            _entryVertices.push_back(i);
        }
    }
}


bool Graph::popCycle(int step) {
    cout << "Step " << step << ": ";
    for (int i:_entryVertices) {
        cout << to_string(i) + " ";
    }
    cout << endl;

    if (!_entryVertices.empty()) {
        disconnectEntries();
        return popCycle(++step);
    } else {
        findEntryAndEnding();
        return _entryVertices.size() != _numberVertices;
    }
}