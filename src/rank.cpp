#include <iostream>
#include "rank.h"

using namespace std;

void Graph::findRank() {
    _rank.clear();

    popRank();

    int size = _rank.size();

    cout << endl << " ~~Rank Calculation~~" << endl;

    for (int i = 0; i < size; i++) {
        cout << endl << " Rank " << i << ":" << endl;
        cout << "    " << verticesToString(_rank[i]);
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