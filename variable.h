#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
using namespace std; 
struct Variable {
    char data;
    bool state = false; 
    Variable(){}; 
    Variable(char value){
        this->data = value;
    }
    ~Variable(){};
};
#endif
