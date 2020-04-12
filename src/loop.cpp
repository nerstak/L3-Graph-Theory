#include <iostream>
#include "loop.h"

using namespace std;

void Graph::checkLoop() {
    //make a copy so it doesnt remove actual states
    Graph newGraph(*this);

    cout << "~~ Cycle Detection by removing states ~~" << endl;

    //Calls recursive function
    _cycle = newGraph.popCycle();

    cout << endl;
    if (_cycle) {
        cout << "The graph contains a cycle.";
    } else {
        cout << "The graph does not contains a cycle.";
    }
}

bool Graph::popCycle(int step) {
    vector<int> remaining;

    //remaining vertices are those that are not entries (including disconnected ones)
    for (int i = 0; i < _numberVertices; i++) {
        if (!getPredecessors(i).empty()) {
            remaining.push_back(i);
        }
    }

    cout << endl << "Step " << step << ": " << endl;

    cout << "  Elimination of entry points: ";
    cout << verticesToString(_entryVertices);
    cout << endl;

    cout << "  Remaining Vertices: ";
    cout << verticesToString(remaining);
    cout << endl;

    //Disconnect our entries and find new entries
    disconnectEntries();

    cout << "  New entry points: ";
    cout << verticesToString(_entryVertices);
    cout << endl;

    //If there are new entries we need another step to disconnect them
    if (!_entryVertices.empty()) {
        return popCycle(++step);
    } else {
        //If there are no remaining vertices, there is no cycle
        return !remaining.empty();
    }
}