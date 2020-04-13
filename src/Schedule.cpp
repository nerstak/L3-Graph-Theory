#include "Schedule.h"

Schedule::Schedule(int prevstate, int time) {
    _prevState=prevstate;
    _time=time;
}

int Schedule::getTime() {
    return _time;
}

int Schedule::getPrevState() {
    return _prevState;
}

void Schedule::setPrev(int prevState, int time) {
    _prevState = prevState;
    _time=time;
}

string Schedule::toString() {
    string outStr, prev="None";

    outStr += "   Time: " + to_string(_time) + "\n";

    if(_prevState!=-1)
    {
        prev=to_string(_prevState);
    }
    outStr += "   Previous: " + prev + "\n";

    return outStr;
}
