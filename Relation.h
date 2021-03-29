//
// Created by Samuel Bennion on 2/24/21.
//

#ifndef CS_236_LAB3_RELATION_H
#define CS_236_LAB3_RELATION_H
#include "Tuple.h"
//#include "Interpreter.h"
#include <set>
class Relation {
private:
    std::string name;
    std::vector<std::string> headers;
    std::set<Tuple> tuples = {}; // needs to be a set

public:
    Relation();
    Relation(std::string _name, std::vector<std::string> _headers){
        name = _name;
        headers = _headers;
    }
    void addTuple(Tuple tuple){
        tuples.insert(tuple);
    }
    std::string toString(){
        //toString();
        //std::stringstream ss;
        std::string s =  "";
        //ss << name << "\n";
        s += name + "( ";
        //std::cout << s << std::endl;
        for(std::string h : headers){
            s += h + ", ";
        }
        s += ")\n";
        for(Tuple t : tuples){
            s += t.toString() + "\n";
        }
        return s;
    }
    std::string getName(){
        return name;
    }
    void select(int index, std::string value2);
    void select(int index1, int index2);
    void project(std::vector<int> indices);
};


#endif //CS_236_LAB3_RELATION_H
