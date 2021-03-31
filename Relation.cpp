//
// Created by Samuel Bennion on 2/24/21.
//

#include "Relation.h"

Relation Relation::select(int index, std::string value2) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;
    for(Tuple t : tuples){
        if(t.getValues()[index] == value2){
            r.addTuple(t);
        }
    }
    return r;
}

Relation Relation::select(int index1, int index2) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;
    for(Tuple t : tuples){
        if(t.getValues()[index1] == t.getValues()[index2]){
            r.addTuple(t);
        }
    }
    return r;
}

Relation Relation::project(std::vector<int> indices) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;

    Tuple retTuple;
    for(Tuple t : tuples){
        for(unsigned int i = 0; i < indices.size(); i++){
            retTuple.addValue(t.getValues().at(indices.at(i)));
        }
    }
    if(retTuple.getValues().size() > 0){
        r.addTuple(retTuple);
    }
    return r;
}

Relation Relation::rename(std::vector<std::string> ids) {
    Relation r;
    r.name = name;
    r.tuples = tuples;
    if(ids.size() > 0){
        r.headers = ids;
    }
    return r;
}

Relation::Relation() {
    NULL;
}

int Relation::numOfTuples(std::vector<std::string> vars){
    int howMany = 0;
    for(Tuple t : tuples){
        std::stringstream ss;
        for (unsigned int j = 0; j < t.getValues().size(); j++) {
            howMany++;
        }
    }
    if (howMany != 0){
        return (howMany / vars.size());
    }
    else return 1;
}