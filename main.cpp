#include <iostream>
#include "src/Graph.h"

int main() {
    Graph g = Graph("graphs/0.txt");
    auto x = g.getMatrix();
    return 0;
}
