#ifndef GRAPH_THEORY_SCHEDULE_H
#define GRAPH_THEORY_SCHEDULE_H

#include <vector>

using namespace std;


class Schedule {
private:
    int _prevState;
    int _time;

public:

    Schedule(int prevstate, int time);

    int getTime();

    int getPrevState();

    void setPrevState(int prevState);

    void setTime(int time);

};

typedef vector<Schedule> Calendar;


#endif //GRAPH_THEORY_SCHEDULE_H
