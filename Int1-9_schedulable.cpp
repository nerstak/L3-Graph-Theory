#include "Int1-9_Graph.h"

bool Graph::getVerticeWeight() {
    bool schedulableWeight = true;
    int BaseWeight;
    vector<int> successorsOfVertex;

    // Check for all vertex
    for (int i = 0; i < _numberVertices; i++) {
        successorsOfVertex = getSuccessors(i);
        //if it is not an end state
        if (!successorsOfVertex.empty()) {
            // Check that all edges to successors have the same weight
            BaseWeight = _matrix[i][successorsOfVertex[0]].getWeight();

            for (int j = 1; j < successorsOfVertex.size(); j++) {
                if (_matrix[i][successorsOfVertex[j]].getWeight() != BaseWeight) {
                    schedulableWeight = false;
                }
            }
        }
    }
    return schedulableWeight;
}

bool Graph::getWeightEntryVertex() {
    bool entryWeight = true;
    //We have previously checked that there is only one entry so _entryVertices[0] is the only entry to check for
    vector<int> entrySuccessor = getSuccessors(_entryVertices[0]);

    // We have previously checked all outgoing vertices are the same, so the value of 1 will be the value of all of them
    if (!entrySuccessor.empty()) {
        entryWeight = _matrix[_entryVertices[0]][entrySuccessor[0]].getWeight() == 0;
    }
    return entryWeight;
}

string Graph::schedulable() {
    _schedulable = false;
    string status;

    status = " Checking for single entry: ";

    if (_entryVertices.size() == 1) {
        status += "TRUE\n Checking for single exit: ";
        if (_exitVertices.size() == 1) {
            status += "TRUE\n Checking for lack of Cycle: ";
            if (!getCycle()) {
                status += "TRUE\n Checking for same outgoing weights: ";
                if (getVerticeWeight()) {
                    status += "TRUE\n Checking for negative weights: ";
                    if(verifyNegativeWeights()) {
                        status += "TRUE\n Checking for weight of 0 on entry vertices: ";
                        if (getWeightEntryVertex()) {
                            status += "TRUE\n     GRAPH IS SCHEDULABLE";
                            _schedulable=true;
                        }
                    }
                }
            }
        }
    }

    if(!_schedulable){
        status += "FALSE\n     GRAPH IS NOT SCHEDULABLE";
    }

    return status;
}

bool Graph::verifyNegativeWeights() {
    for(const auto& list: _matrix) {
        for(auto state: list) {
            if(state.getWeight() < 0) {
                return false;
            }
        }
    }
    return true;
}
