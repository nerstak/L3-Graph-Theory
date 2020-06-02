#ifndef GRAPH_THEORY_SCHEDULE_H
#define GRAPH_THEORY_SCHEDULE_H

#include <vector>
#include <iostream>

#define EARLIEST 1
#define LATEST (-1)

using namespace std;


class Schedule {
private:
    int _linkState; //This is the predecessor for earliest time and successor for latest time
    int _time;

public:
    Schedule(int linkState, int time);

    int getTime();

    int getLinkState();

    void setLink(int linkState, int time);

    /**
     * Creates string of time and successor/predecessor information for a given state
     * @param timeType if EARLIEST, linkstate is described as predecessor, otherwise it is described as predecessor
     * @return string of info
     */
    string toString(int timeType);
};

//A calendar is a list of schedule info for each state
//Each state's info lies at the corresponding index in the calendar
typedef vector<Schedule> Calendar;


#endif //GRAPH_THEORY_SCHEDULE_H
