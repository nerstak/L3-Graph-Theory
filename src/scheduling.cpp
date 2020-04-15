#include "Graph.h"

string Graph::computeEarliest() {
    string outStr, route;
    int curr;

    //We calculate and display this on order from lowest rank to highest
    for (const vector<int> &rank: _rank) {
        for (int state:rank) {
            _earliestCalendar[state] = minmaxLink(state, EARLIEST);

            outStr += "\nState: " + to_string(state) + "\n";
            outStr += _earliestCalendar[state].toString(EARLIEST);
            outStr += taskDuration(state);
        }
    }

    //Earliest duration is the time it takes to reach the exit vertice (there is only one exit)
    curr = _exitVertices[0];
    outStr += "\n\nEarliest Duration is " + to_string(_earliestCalendar[curr].getTime()) + ", going through:\n ";

    //The route taken for this earliest duration is seen by going back through the calendar from the exit vertice
    do {
        route = ">" + to_string(curr) + route;
        curr = _earliestCalendar[curr].getLinkState();
    } while (curr != -1);

    return outStr + route;
}

string Graph::computeLatest() {
    string outStr;
    int curr, state;

    //We calculate this in order from highest rank to lowest, (but still display it from lowest to highest(?))
    for (auto rank = _rank.rbegin(); rank < _rank.rend(); ++rank) {
        for (auto state = (*rank).rbegin(); state < (*rank).rend(); ++state) {
            _latestCalendar[*state] = minmaxLink(*state, LATEST);
            outStr = taskDuration(*state) + outStr;
            outStr = _latestCalendar[*state].toString(LATEST) + outStr;
            outStr = "\nState: " + to_string(*state) + "\n" + outStr;
        }
    }

    outStr = "\n" + outStr;


    //TODO check if its normal that latest route is same as earliest route
    //The route taken for this earliest duration is seen by going through the calendar from the single entrance vertice
    //The total duration is the same and the latest time route (critical path) is displayed to check its the same
    curr = _entryVertices[0];
    outStr += "\n\nThe Latest Time route is:\n ";

    do {
        outStr += ">" + to_string(curr);
        curr = _latestCalendar[curr].getLinkState();
    } while (curr != -1);

    return outStr;
}

Schedule Graph::minmaxLink(int state, int timeType) {
    int linkTime, pathWeight, startTime;
    vector<int> links;
    Calendar calendarType;

    //Earliest calendar starts with a time of 0 at the entry vertice and gets the time from predecessors
    if (timeType == EARLIEST) {
        links = getPredecessors(state);
        calendarType = _earliestCalendar;
        startTime = 0;
    }
        //Latest calendar starts with the Earliest duration at the exit vertice and gets the time from successors
    else {
        links = getSuccessors(state);
        calendarType = _latestCalendar;
        startTime = _earliestCalendar[_exitVertices[0]].getTime();
    }

    //default value if at start/end of schedule
    Schedule newLink = Schedule(-1, startTime);
    if (!links.empty()) {
        for (int linkState: links) {

            //Earliest calendar adds time from predecessor, Latest substracts considers time to successor
            if (timeType == EARLIEST) {
                pathWeight = _matrix[linkState][state].getWeight();
            } else {
                pathWeight = -_matrix[state][linkState].getWeight();
            }

            linkTime = calendarType[linkState].getTime() + pathWeight;

            if (newLink.getLinkState() == -1) {
                //set start value fot comparaison
                newLink.setLink(linkState, linkTime);
            } else {
                //update min/max value
                //This finds max predecessor if we're doing earliest time and min successor if we're doing latest time
                if ((linkTime * timeType) > (newLink.getTime() * timeType)) {
                    newLink.setLink(linkState, linkTime);
                }
            }
        }
    }

    return newLink;
}


string Graph::taskDuration(int state) {
    string outStr = "   Task duration: ";
    vector<int> successors = getSuccessors(state);

    // Displays just "-" if it is a final state
    if (successors.empty()) {
        outStr += "-";
    } else {
        // The time duration should be the same for all successors
        outStr += to_string(_matrix[state][successors[0]].getWeight());
    }

    return outStr + "\n";
}

string Graph::margins() {
    string outStr = "\n";
    for (const vector<int> &rank: _rank) {
        for (int state:rank) {
            outStr += "\nState: " + to_string(state) + "\n  ";
            outStr += "Margin:  " + to_string(_latestCalendar[state].getTime()) +
                      " - " + to_string(_earliestCalendar[state].getTime()) + " = " +
                      to_string(_latestCalendar[state].getTime() - _earliestCalendar[state].getTime());
        }
    }
    return outStr;
}