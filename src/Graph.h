#ifndef GRAPH_THEORY_GRAPH_H
#define GRAPH_THEORY_GRAPH_H

#include <string>
#include <vector>
#include "MatrixValue.h"

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

    /**
     * Read graph from file
     * @param stream File stream (read)
     * @param nameFile Name of the file
     * @return Validity of creation of graph
     */
    bool readGraphFromFile(ifstream &stream, const string &nameFile);

    /**
     * Initialise the matrix
     */
    void initMatrix();

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


};


#endif //GRAPH_THEORY_GRAPH_H
