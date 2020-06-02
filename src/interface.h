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
 * @return user choice
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

/**
 * Used in tables to add a space if the number is 1 digit so it lines up
 * @param i number to consider
 * @return space or not
 */
static string addSpace(int i);

#endif //GRAPH_THEORY_INTERFACE_H
