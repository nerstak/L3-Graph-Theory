#ifndef GRAPH_THEORY_GRAPH_H
#define GRAPH_THEORY_GRAPH_H

#include <string>
#include <vector>
#include "MatrixValue.h"
#include "Schedule.h"

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

    void initCalendar(Calendar calendar);

    /**
     * Find entry & ending points
     */
    void findEntryAndEnding();

public:
    explicit Graph(const string &path, const string &nameFile);

    ~Graph();

    const vector<int> &getEntryVertices() const;

    const vector<int> &getExitVertices() const;

    const vector<vector<MatrixValue>> &getMatrix() const;

    const bool &getCycle() const;

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
     * Runs loop detection and changes the cycle value of graph
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

    void computeEarliest();

    Schedule earliestPredecessor(int state);

};


#endif //GRAPH_THEORY_GRAPH_H
