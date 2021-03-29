//
// Created by Samuel Bennion on 3/24/21.
//

#ifndef CS_236_LAB3_INTERPRETER_H
#define CS_236_LAB3_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
private:
    DatalogProgram dlProgram;
    Database db;
    vector<Tuple> tuples;
    vector<Relation> relations;
    //vector
    void createRelations(vector<Predicate*> schemes){
    for(Predicate* s : schemes){
        relations.push_back(Relation(s->getName(), s->getParametersAsString()));
        //std::cout << s-> getParametersAsString();
    }
    }
    void createTuples(vector<Predicate*> facts) {
        for (Predicate *f : facts) {
            //tuples.push_back(new Tuple(dlProgram.getSchemes().getName()));
            tuples.push_back(Tuple(f->getName(), f->getParametersAsString()));
        }
        int i;
        for (Tuple t : tuples) {
            i = 0;
            while ((t.getRelationName() != relations[i].getName()) || i == relations.size()) {
                i++;
            }
            if (t.getRelationName() == relations[i].getName()) {
                t.setRelationName(relations[i].getName());
                relations[i].addTuple(t);
            }
        }
    }
    Relation matchRelationFromQuery(Predicate* query){
        int i = 0;
        while((query->getName() != relations[i].getName()) || i == relations.size()){
            i++;
        }
        if(query->getName() == relations[i].getName()){
            return relations[i];
        }
//        else{
//            return Relation();
//        }
    }
public:
    Interpreter(DatalogProgram dlProgram){
        //dlProgram = _dlProgram;
        createRelations(dlProgram.getSchemes());
        createTuples(dlProgram.getFacts());
        for(Relation r : relations) {
            db.addRelation(r.getName(), r);
            //cout << r.toString() << endl;
        }
        evalQueries(dlProgram.getQueries());
    }
    void evalQueries(vector<Predicate *> queries){
        for(Predicate* q : queries){
           Relation matchingRelation = matchRelationFromQuery(q);
           for(unsigned int i = 0; i < q->getParameters().size(); i++){

           }
        }
    }
};


#endif //CS_236_LAB3_INTERPRETER_H
