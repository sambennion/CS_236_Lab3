#include <__bit_reference>
//
// Created by Samuel Bennion on 2/24/21.
//

#ifndef CS_236_LAB3_RELATION_H
#define CS_236_LAB3_RELATION_H
#include "Tuple.h"
//#include "Interpreter.h"
#include <set>
#include <utility>
class Relation {
private:
    std::string name;
    std::vector<std::string> headers;
    std::set<Tuple> tuples = {}; // needs to be a set

public:
    Relation();
    Relation(std::string _name, std::vector<std::string> _headers){
        name = std::move(_name);
        headers = std::move(_headers);
    }
    void addTuple(const Tuple& tuple){
        tuples.insert(tuple);
    }
    std::string toString(){
        //toString();
        //std::stringstream ss;
        std::string s;
        //ss << name << "\n";
        s += name + "( ";
        //std::cout << s << "\n";
        for(const std::string& h : headers){
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
    std::set<Tuple> getTuples(){
        return tuples;
    }
    Relation select(int index, std::string value2);
    Relation select(int index1, int index2);
    Relation project(std::vector<int> indices);
    Relation rename(std::vector<std::string> ids);

    int numOfTuples(std::vector<std::string> vars);
    std::string tuplesResults(const std::vector<int>& indices, std::vector<std::string> vars, int num){
        std::stringstream ss;
        for(Tuple t : tuples){

            int outputtedNum = 0;
            for(unsigned int i = 0; i < t.getValues().size(); i++){
                if(vars[i%indices.size()] == t.getValues()[i]){
//                    NULL;

                }
                else if( (i == t.getValues().size() - 1) || i == vars.size() - 1){
                    ss << vars[i%indices.size()] << "=" << t.getValues()[i] << "\n";
                }
                else {
                    int newNumber = (t.getValues().size() / num);
                    if ( outputtedNum == (newNumber - 1)){
                        ss << vars[i % indices.size()] << "=" << t.getValues()[i] << "\n";
                        outputtedNum = 0;

                    }
                    else {
                        ss << "  " << vars[i % indices.size()] << "=" << t.getValues()[i] << ", ";
                        outputtedNum++;

                    }
                }

            }
        }
        return ss.str();
    };
};


#endif //CS_236_LAB3_RELATION_H
