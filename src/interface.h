#ifndef GRAPH_THEORY_INTERFACE_H
#define GRAPH_THEORY_INTERFACE_H

#include "Graph.h"
#include "logs.h"

/**
 * Function handling menu
 */
void menu();

/**
 * Interaction with user
 * @return
 */
static int interaction();

/**
 * Open a graph from file and operate tasks
 */
static void processFile();

/**
 * Separation function (graphically)
 */
static void separation();

/**
 * Ask for number of the graph to the user
 * @return Number of the graph asked
 */
static int askNumberFile();

#endif //GRAPH_THEORY_INTERFACE_H
