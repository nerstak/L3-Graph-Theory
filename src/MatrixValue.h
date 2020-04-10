#ifndef GRAPH_THEORY_MATRIXVALUE_H
#define GRAPH_THEORY_MATRIXVALUE_H

class MatrixValue {
private:
    bool _adjacency;
    int _weight;

public:
    /**
     * Constructor
     * @param adjacency Value of the cell in the adjacency matrix
     * @param weight Value of the cell corresponding to the weight
     */
    MatrixValue(bool adjacency, int weight);

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

    /**
     * Set value of weight AND set adjacency to 1
     * @param weight Value of weight
     */
    void setWeight(int weight);

    /**
     * Set value of adjacency AND set weight to 0 if adjacency is false
     * @param adjacency Value of adjacency
     */
    void setAdjacency(bool adjacency);
};


#endif //GRAPH_THEORY_MATRIXVALUE_H
