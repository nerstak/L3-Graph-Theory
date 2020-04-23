#include "Int1-9_Schedule.h"

Schedule::Schedule(int linkState, int time) {
    _linkState = linkState;
    _time = time;
}

int Schedule::getTime() {
    return _time;
}

int Schedule::getLinkState() {
    return _linkState;
}

void Schedule::setLink(int linkState, int time) {
    _linkState = linkState;
    _time = time;
}

string Schedule::toString(int timeType) {
    string outStr, linkType, link = "None";

    outStr += "   Time: " + to_string(_time) + "\n";

    if (_linkState != -1) {
        link = to_string(_linkState);
    }

    if (timeType == EARLIEST) {
        linkType = "Predecessor";
    } else {
        linkType = "Successor";
    }

    outStr += "   " + linkType + ": " + link + "\n";

    return outStr;
}
