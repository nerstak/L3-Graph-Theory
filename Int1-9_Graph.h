#ifndef GRAPH_THEORY_INT1_9_GRAPH_H
#define GRAPH_THEORY_INT1_9_GRAPH_H

#include <string>
#include <vector>
#include "Int1-9_MatrixValue.h"
#include "Int1-9_Schedule.h"

using namespace std;

class Graph {
private:
    string _name = "Graph";
    vector<int> _entryVertices; // List of all entry points
    vector<int> _exitVertices; // List of all exit points
    vector<vector<MatrixValue>> _matrix; // Adjacency & Weight Matrices
    int _numberVertices;
    int _numberEdges;

    bool _cycle;
    bool _schedulable;

    vector<vector<int>> _rank; // Vertices at each rank

    Calendar _earliestCalendar;
    Calendar _latestCalendar;

    /**
     * Read graph from file
     * @param stream File stream (read)
     * @param nameFile Name of the file
     * @return Validity of creation of graph
     */
    bool readGraphFromFile(ifstream &stream);

    /**
     * Initialise the matrix
     */
    void initMatrix();

    /**
     * Initialises the calendar
     */
    void initCalendars();

    /**
     * Find entry & ending points
     */
    void findEntryAndEnding();

public:
    explicit Graph(const string &nameFile);

    ~Graph();

    const vector<int> &getEntryVertices() const;

    const vector<int> &getExitVertices() const;

    const vector<vector<MatrixValue>> &getMatrix() const;

    const bool &getCycle() const;

    const bool &getSchedulable() const;

    const vector<vector<int>> &getRank() const;

    std::string toString();

    /**
     * Get list of predecessors for given state
     * @param state to analyse
     * @return List of predecessors
     */
    vector<int> getPredecessors(int state);

    /**
     * Get list of successors for given state
     * @param state to analyse
     * @return List of successors
     */
    vector<int> getSuccessors(int state);

    /**
     * Turns a list of states (ints) into a simple string
     * @param states to turn into string
     * @return list separated by spaces
     */
    string verticesToString(vector<int> states);

    /**
     * Runs loop detection and chastatic nges the cycle value of graph
     */
    void checkLoop();

    /**
     * Disconnects all entry states and sets their successors as entries
     */
    void disconnectEntries();

    /**
     * Recursive function that keeps removing steps to see if the graph is a cycle
     * @param step Current step of recursion
     * @return True if loop (all states disconnected), False otherwise
     */
    bool popCycle(int step = 0);

    /**
     * Finds and prints the rank of each Vertex
     */
    void findRank();

    /**
     * Recursive function to create the Rank table
     */
    void popRank();

    /**
     * Creates the earliest times calendar
     * @return string describing latest time and predecessor of each state as well as critical path
     */
    string computeEarliest();

    /**
     * Creates the latest times calendar
     * @return string describing latest time and successor of each state as well as critical path
     */
    string computeLatest();

    /**
     * Finds the time and predecessor/successor of a state in a calendar
     * @param state State to find scheduling info on
     * @param timeType EARLIEST will calculate earliest time, LATEST will calculate latest time
     * @return scheduling info for state
     */
    Schedule minmaxLink(int state, int timeType);

    /**
     * Creates a string with the time margin at each state
     * @return latest time - earliest time for each state
     */
    string margins();

    /**
     * Displays duration of task or "-" if it is a exit state
     * @return String with info
     */
    string taskDuration(int state);

    bool getVerticeWeight();

    bool getWeightEntryVertex();

    /**
     * Verify if a graph is schedulable (with outputs)
     * @return Boolean
     */
    string schedulable();

    bool verifyNegativeWeights();
};


#endif //GRAPH_THEORY_INT1_9_GRAPH_H
