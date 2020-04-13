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

void Schedule::setPrevState(int prevState) {
    Schedule::_prevState = prevState;
}

void Schedule::setTime(int time) {
    Schedule::_time = time;
}
