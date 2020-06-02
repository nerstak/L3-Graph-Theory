#include "Graph.h"
#include "logs.h"

using namespace std;

void Graph::checkLoop() {
    //make a copy so it doesnt remove actual states
    Graph newGraph(*this);

    writeLogFile(_name,"\n~~ Cycle Detection by removing states ~~\n");

    //Calls recursive function
    _cycle = newGraph.popCycle();

    if (_cycle) {
        writeLogFile(_name,"\nThe graph contains a cycle.");
    } else {
        writeLogFile(_name,"\nThe graph does not contains a cycle.");
    }
}

bool Graph::popCycle(int step) {
    vector<int> remaining;
    string display;

    //remaining vertices are those that are not entries (including disconnected ones)
    for (int i = 0; i < _numberVertices; i++) {
        if (!getPredecessors(i).empty()) {
            remaining.push_back(i);
        }
    }

    display = "\nStep " + to_string(step) + ":\n";

    display += "  Elimination of entry points: ";
    display += verticesToString(_entryVertices) + "\n";

    display += "  Remaining Vertices: ";
    display += verticesToString(remaining)+ "\n";

    //Disconnect our entries and find new entries
    disconnectEntries();

    display += "  New entry points: ";
    display += verticesToString(_entryVertices) + "\n";

    writeLogFile(_name,display);

    //If there are new entries we need another step to disconnect them
    if (!_entryVertices.empty()) {
        return popCycle(++step);
    } else {
        //If there are no remaining vertices, there is no cycle
        return !remaining.empty();
    }
}