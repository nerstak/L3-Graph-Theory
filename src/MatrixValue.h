#ifndef GRAPH_THEORY_MATRIXVALUE_H
#define GRAPH_THEORY_MATRIXVALUE_H

class MatrixValue {
private:
    int _adjacency;
    int _weight;

public:
    /**
     * Constructor
     * @param adjacency Value of the cell in the adjacency matrix
     * @param weight Value of the cell corresponding to the weight
     */
    MatrixValue(int adjacency, int weight);

    /**
     * Copy Constructor
     * @param mv MatrixValue to copy
     */
    MatrixValue(const MatrixValue &mv);

    /**
     * Get value of adjacency cell
     * @return Value of adjacency cell
     */
    int getAdjacency();

    /**
     * Get value of weight
     * @return Value of weight
     */
    int getWeight();
};


#endif //GRAPH_THEORY_MATRIXVALUE_H
