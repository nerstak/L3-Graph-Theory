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
    string outStr, route ;
    int curr;

    for(const vector<int> &rank: _rank)
    {
        for(int state:rank)
        {
            _earliestCalendar[state]= minmaxLink(state, EARLIEST);
            outStr+= "\nState: " + to_string(state) + "\n";
            outStr+= _earliestCalendar[state].toString(EARLIEST);
        }
    }

    curr=_exitVertices[0];
    outStr+= "\n\nEarliest Time is " + to_string(_earliestCalendar[curr].getTime()) + ", going through:\n ";

    do{
        route= ">" + to_string(curr) + route;
        curr= _earliestCalendar[curr].getLinkState();
    } while (curr!=-1);

    return outStr + route;
}

string Graph::computeLatest() {
    string outStr;
    int curr, state;

    for (int i = _rank.size() - 1; i >= 0 ; i--) {
        for (int j = _rank[i].size() - 1 ; j >= 0 ; j--) {
            state= _rank[i][j];

            _latestCalendar[state]= minmaxLink(state, LATEST);
            outStr= _latestCalendar[state].toString(LATEST) + outStr;
            outStr= "\nState: " + to_string(state) + "\n" + outStr;
        }
    }

    outStr= "\n" + outStr;

    //TODO check if its normal that latest route is same as earliest route
    curr=_entryVertices[0];
    outStr+= "\n\nThe Latest Time route is:\n ";

    do{
        outStr+= ">" + to_string(curr);
        curr=_latestCalendar[curr].getLinkState();
    } while(curr!=-1);

    return outStr;
}

Schedule Graph::minmaxLink(int state, int timeType){
    int linkTime, pathWeight, startTime;
    vector<int> links;
    Calendar calendarType;

    if( timeType == EARLIEST )
    {
        links=getPredecessors(state);
        calendarType = _earliestCalendar;
        startTime=0;
    } else {
        links=getSuccessors(state);
        calendarType = _latestCalendar;
        startTime=_earliestCalendar[_exitVertices[0]].getTime();
    }

    Schedule newLink= Schedule(-1,startTime);

    if(!links.empty())
    {
        for(int linkState: links)
        {
            if(timeType==EARLIEST)
            {
                pathWeight= _matrix[linkState][state].getWeight();
            } else {
                pathWeight= -_matrix[state][linkState].getWeight();
            }

            linkTime= calendarType[linkState].getTime() + pathWeight;

            if(newLink.getLinkState()==-1)
            {
                //set default value
                newLink.setLink(linkState, linkTime);
            } else {
                //update minimum value
                if((linkTime* timeType) > (newLink.getTime() * timeType))
                {
                    newLink.setLink(linkState, linkTime);
                }
            }
        }
    }

    return newLink;
}

string Graph::margins() {
    string outStr="\n";
    for(const vector<int> &rank: _rank)
    {
        for(int state:rank)
        {
            outStr+= "\nState: " + to_string(state) + "\n  ";
            outStr+= "Margin:  " + to_string(_latestCalendar[state].getTime()) +
                    " - " + to_string(_earliestCalendar[state].getTime()) + " = " +
                    to_string(_latestCalendar[state].getTime() - _earliestCalendar[state].getTime() );
        }
    }
    return outStr;
}
