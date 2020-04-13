#ifndef GRAPH_THEORY_SCHEDULE_H
#define GRAPH_THEORY_SCHEDULE_H

#include <vector>
#include <iostream>

using namespace std;


class Schedule {
private:
    int _prevState;
    int _time;

public:

    Schedule(int prevstate, int time);

    int getTime();

    int getPrevState();

    string toString();

    void setPrev(int prevState, int time);


};

typedef vector<Schedule> Calendar;


#endif //GRAPH_THEORY_SCHEDULE_H
