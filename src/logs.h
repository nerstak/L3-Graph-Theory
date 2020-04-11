#ifndef GRAPH_THEORY_LOGS_H
#define GRAPH_THEORY_LOGS_H

#include <string>

/**
 * Create or reset log file
 * @param nameFile Name of the file
 */
void createLogFile(std::string nameFile);

/**
 * Write logs (both on screen and file)
 * @param nameFile Name of the file
 * @param value String to record
 */
void writeLogFile(std::string nameFile, const std::string &value);

#endif //GRAPH_THEORY_LOGS_H
