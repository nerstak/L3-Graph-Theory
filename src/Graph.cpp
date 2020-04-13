#include "Graph.h"
#include <algorithm>

const vector<int> &Graph::getEntryVertices() const {
    return _entryVertices;
}

const vector<int> &Graph::getExitVertices() const {
    return _exitVertices;
}

const vector<vector<MatrixValue>> &Graph::getMatrix() const {
    return _matrix;
}

const bool &Graph::getCycle() const {
    return _cycle;
}

const vector<vector<int>> &Graph::getRank() const {
    return _rank;
}

void Graph::initMatrix() {
    for (int i = 0; i < _numberVertices; i++) {
        vector<MatrixValue> tmp;
        for (int j = 0; j < _numberVertices; j++) {
            tmp.push_back(MatrixValue(false, 0));
        }

        _matrix.push_back(tmp);
    }
}

void Graph::initCalendars() {
    for(int i = 0; i < _numberVertices; i++) {
        _earliestCalendar.push_back(Schedule(-1,0));
        _latestCalendar.push_back(Schedule(-1,0));
    }
}


Graph::~Graph() = default;

void Graph::findEntryAndEnding() {
    _entryVertices.clear();
    _exitVertices.clear();
    for (int state = 0; state < _numberVertices; state++) {
        // By default, a node is an exit and an entry point
        _entryVertices.push_back(state);
        _exitVertices.push_back(state);

        // Cannot be entry if there is predecessor
        if (!getPredecessors(state).empty()) {
            _entryVertices.pop_back();
        }

        // Cannot be exit if there is successor
        if (!getSuccessors(state).empty()) {
            _exitVertices.pop_back();
        }
    }
}

vector<int> Graph::getPredecessors(int state) {
    vector<int> predecessors;
    for (int s = 0; s < _numberVertices; s++) {
        if (_matrix[s][state].getAdjacency()) {
            predecessors.push_back(s);
        }
    }

    return predecessors;
}

vector<int> Graph::getSuccessors(int state) {
    vector<int> successors;
    for (int s = 0; s < _numberVertices; s++) {
        if (_matrix[state][s].getAdjacency()) {
            successors.push_back(s);
        }
    }

    return successors;
}

void Graph::disconnectEntries() {
    vector<int> successors, singleSuccessors;

    //Get every successor to our entries
    for (int i : _entryVertices) {
        //successors of current entry
        singleSuccessors = getSuccessors(i);
        for (int j: singleSuccessors) {
            //if not already added to successors (union of all successors and curr Entry successors)
            if (find(successors.begin(), successors.end(), j) == successors.end()) {
                successors.push_back(j);
            }
        }
    }

    //"Disconnect" all entries by removing their successors.
    for (int i: _entryVertices) {
        for (int j = 0; j < _numberVertices; j++) {
            _matrix[i][j].setAdjacency(false);
        }
    }

    //Add new entries
    _entryVertices.clear();
    for (int i: successors) {
        //It is only an entry if it does not have a predecessor
        if (getPredecessors(i).empty()) {
            _entryVertices.push_back(i);
        }
    }
}

string Graph::verticesToString(vector<int> states) {
    string entries;
    if (states.empty()) {
        entries = "None";
    } else {
        for (int i:states) {
            entries += to_string(i) + " ";
        }
    }
    return entries;
}

string Graph::computeEarliest() {
    string outStr= "\n",route ;
    int curr;

    for(vector<int> rank: _rank)
    {
        for(int state:rank)
        {
            _earliestCalendar[state]= earliestPredecessor(state);
            outStr+= "\nState: " + to_string(state) + "\n";
            outStr+= _earliestCalendar[state].toString();
        }
    }

    curr=_exitVertices[0];
    outStr+= "\n\nEarliest Time is " + to_string(_earliestCalendar[curr].getTime()) + ", going through:\n ";

    do{
        route= ">" + to_string(curr) + route;
        curr= _earliestCalendar[curr].getPrevState();
    } while (curr!=-1);

    return outStr + route;
}

Schedule Graph::earliestPredecessor(int state){
    int predTime;
    vector<int> predecessors = getPredecessors(state);
    Schedule minPredecessor= Schedule(-1,0);

    if(!predecessors.empty())
    {
        for(int pred: predecessors)
        {
            predTime= _earliestCalendar[pred].getTime()+ _matrix[pred][state].getWeight();

            if(minPredecessor.getPrevState()!=-1)
            {
                if(predTime < minPredecessor.getTime())
                {
                    minPredecessor.setPrev(pred,predTime);
                }
            } else {
                minPredecessor.setPrev(pred,predTime);
            }
        }
    }

    return minPredecessor;
}

