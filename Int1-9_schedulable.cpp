#include "Int1-9_Graph.h"

bool Graph::getVerticeWeight() {
    bool schedulableWeight = true; // by default the verification to the weights for the graph to be schedulable is true
    int BaseWeight;
    vector<int> successorsOfVertex;

    for (int i = 0; i < _numberVertices; i++) { // check for all vertex
        successorsOfVertex = getSuccessors(i); // we want to know all the successors of a vertex

        if(i == 4) {
            int lol =4;
        }

        if (!successorsOfVertex.empty()) {
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
    vector<int> entrySuccessor = getSuccessors(_entryVertices[0]);

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
