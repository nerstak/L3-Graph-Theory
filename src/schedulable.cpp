#include "Graph.h"
#include "MatrixValue.cpp"

bool Graph::getVerticeWeight(){
    bool schedulableWeight = true; // by default the verification to the weights for the graph to be schedulable is true
    for (int i = 0; i < _numberVertices-1; i++) { // check for all vertex
        vector<int> successorsOfVertex = _matrix[i].getsuccessors(); // we want to know all the successors of a vertex
        if (!successorsOfVertex.empty()){
            int BaseWeight = successorsOfVertex[0].getWeight;
        if (BaseWeight >= 0){
            for(int j = 1; j< successorsOfVertex.size(); j++){
                if (successorsOfVertex[j].getWeight!= BaseWeight){
                    schedulableWeight = false;
                }
            }
        }
        else{
            schedulableWeight = false;
        }
     }
    return schedulableWeight;
    }
}

bool Graph::getWeightEntryVertex(){
    bool entryWeight = false;
           if(_entryVertices[0]== 0){
                entryWeight = true;
            }
    return entryWeight;
}

bool Graph::schedulable(){
    _schedulable = true;
    if (_entryVertices.size()!=1 && _exitVertices.size()!=1){
        _schedulable = false;
    }

    else if (getCycle()!=false){
         _schedulable = false;
    }

    else if (getVerticeWeight()!= true){
        _schedulable = false;
    }

    else if (getWeightEntryVertex()!= true){
        _schedulable = false;
    } )

    return _schedulable;
}
