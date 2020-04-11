#include <algorithm>
#include <iostream>
#include "loop.h"

using namespace std;

void Graph::checkLoop(){
    Graph newGraph(*this);

    _cycle= newGraph.popCycle();

    if(_cycle)
    {
        cout << "yo there is a cycle" ;
    }
    else
    {
        cout << "yo there is no cycle" ;
    }
}

void Graph::disconnectEntries(){

    for(int i : _entryVertices){
        //if it is not both an entrance and exit (aka already no successors)
        if( find(_exitVertices.begin(),_exitVertices.end(),i) == _exitVertices.end()){
            for(int j=0; j<_numberVertices ; j++)
            {
                _matrix[i][j].setAdjacency(false);
            }
        }
    }
}

bool Graph::popCycle()
{
    int prevEntries=_entryVertices.size();
    disconnectEntries();

    _entryVertices.clear();
    _exitVertices.clear();
    findEntryAndEnding();

    if(prevEntries != _entryVertices.size())
    {
        return popCycle();
    }

    //If all vertices are entries, there is no cycle
    return prevEntries!=_numberVertices;
}