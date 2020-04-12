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
    if (!_entryVertices.empty()) {
        _rank.push_back(_entryVertices);
        disconnectEntries();
        popRank();
    }
}