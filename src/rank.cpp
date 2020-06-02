#include "Graph.h"
#include "logs.h"

using namespace std;

void Graph::findRank() {
    _rank.clear();

    Graph newGraph(*this);

    newGraph.popRank();

    _rank=newGraph.getRank();

    int size = _rank.size();

    writeLogFile(_name,"\n\n~~Rank Calculation~~\n");

    for (int i = 0; i < size; i++) {
        string display;
        display =  "\n Rank " + to_string(i) + ":\n";
        display += "    " + verticesToString(_rank[i]);
        writeLogFile(_name, display);
    }
}


void Graph::popRank() {
    //If there are vertices at this rank
    if (!_entryVertices.empty()) {
        //Basically same process as checking for cycles but way simplified now that we know there are none
        _rank.push_back(_entryVertices);
        disconnectEntries();
        popRank();
    }
}