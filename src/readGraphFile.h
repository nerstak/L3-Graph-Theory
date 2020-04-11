#ifndef GRAPH_THEORY_READGRAPHFILE_H
#define GRAPH_THEORY_READGRAPHFILE_H

#include "Graph.h"
#include "logs.h"

/**
 * Read an unique number on a line
 * @param stream File stream (read)
 * @return Number read on the line
 */
static int readUniqueNumber(ifstream &stream);

/**
 * Read lines of transition
 * @param stream File stream (read)
 * @param matrix Matrix of graph to fill
 * @param nbVertices Supposed number of vertices
 * @param nbEdges Supposed number of edges
 * @return True if values given and the ones read corresponds
 */
static bool
readLines(ifstream &stream, string const &nameFile, vector<vector<MatrixValue>> &matrix, int nbVertices, int nbEdges);

/**
 * Extract value from a line of transition
 * @param transitionString Line of transition
 * @param vertexFrom Initial vertex
 * @param vertexTo Final vertex
 * @param weight Weight of the transition
 */
static void separateTransition(string &transitionString, int &vertexFrom, int &vertexTo, int &weight);

/**
 * Read digit and preset for another read
 * @param it Iterator of string to be read
 * @return Value of digit
 */
static int readDigit(string::iterator &it);

/**
 * Check if value is in vector
 * @param l List
 * @param elt Element to verify
 * @return Boolean of presence
 */
static bool isInVector(vector<int> &l, int elt);

/**
 * Display number of vertices and edges in log
 * @param nameFile Name of the log file
 * @param nbVertices Number of vertices
 * @param nbEdges Number of edges
 */
static void displayNumbers(const string &nameFile, int nbVertices, int nbEdges);

#endif //GRAPH_THEORY_READGRAPHFILE_H
