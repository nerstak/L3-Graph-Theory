#ifndef GRAPH_THEORY_SCHEDULE_H
#define GRAPH_THEORY_SCHEDULE_H

#include <vector>
#include <iostream>

#define EARLIEST 1
#define LATEST -1

using namespace std;


class Schedule {
private:
    int _linkState;
    int _time;

public:

    Schedule(int linkState, int time);

    int getTime();

    int getLinkState();

    string toString(int timeType);

    void setLink(int linkState, int time);


};

typedef vector<Schedule> Calendar;


#endif //GRAPH_THEORY_SCHEDULE_H
