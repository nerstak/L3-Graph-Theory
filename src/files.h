#ifndef GRAPH_THEORY_FILES_H
#define GRAPH_THEORY_FILES_H

#include "Graph.h"

/**
 * Read an unique number on a line
 * @param stream File stream (read)
 * @return Number read on the line
 */
static int readUniqueNumber(ifstream &stream);

/**
 * Read lines of transition
 * @param stream File stream (read)
 * @return
 */
static int readLines(ifstream &stream, vector<vector<MatrixValue>> &matrix, int nbVertices, int nbEdges);

/**
 * Extract value from a line of transition
 * @param transitionString Line of transition
 * @param vertexFrom Initial vertex
 * @param vertexTo Final vertex
 * @param weight Weight of the transition
 */
static void separateTransition(string &transitionString, int &vertexFrom, int &vertexTo, int &weight);

static int readDigit(string::iterator &it);

static bool isInVector(vector<int> &l, int elt);

#endif //GRAPH_THEORY_FILES_H
