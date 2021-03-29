//
// Created by Samuel Bennion on 3/18/21.
//

#ifndef CS_236_LAB3_TUPLE_H
#define CS_236_LAB3_TUPLE_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
//#include "Relation.h"
class Tuple {
private:
    std::vector<std::string> values;
    std::string relationName;
public:
//    Tuple(std::vector<std::string> _values){
//        values = _values;
//    }
//    void addValue(std::string value){
//        values.push_back(value);
//    }
    //Tuple();
    Tuple(std::string _name, std::vector<std::string> _values){
        relationName = _name;
        values = _values;
    }
    void setRelationName(std::string name){
        relationName = name;
    }
    void setTupleValues(std::vector<std::string> tuples){
        values = tuples;
    }
    std::string getRelationName(){
        return relationName;
    }
    void printTuples();
    std::string toString(){
        std::string s;
        s += "( ";
        for(std::string v : values){
            s += v + ", ";
        }
        s += " )";
        return s;
    }
    bool operator< (const Tuple t) const {
        return values < t.values;
    }
};


#endif //CS_236_LAB3_TUPLE_H
