//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_PREDICATE_H
#define CS_236_LAB2_PREDICATE_H

#include <vector>
#include "Parameter.h"
class Predicate {
private:
    std::string name;
    vector<Parameter*> parameters{};
public:
    Predicate(string name){
        this->name = name;
    }
    void addParameter(Parameter* param){
        parameters.push_back(param);
    }
    string toString();
};


#endif //CS_236_LAB2_PREDICATE_H
