#ifndef TABLAGEN_H 
#define TABLAGEN_H

#include <iostream> 
#include "variable.h"

using namespace std; 

class TablaGen{
  private: 
    Variable **variables = nullptr; 
    bool cumple = false; 
    int cant_variables = 0; 
  public: 
    TablaGen(){}; 
    TablaGen(string _variables){
      int size_v = _variables.size(); 
      Variable **new_variables = new Variable*[size_v-1]; 
      for (int i = 0; i < size_v; i++){
        Variable *var = new Variable(_variables[i]); 
        new_variables[i] = var; 
      }
      this->variables = new_variables; 
      this->cant_variables = size_v; 
    }; 
    void update_var(char key); 
    Variable *get_var(char key); 
    ~TablaGen(){};
}; 

void TablaGen::update_var(char key){
  for(int i = 0; i < this->cant_variables; i++){
    if(key == this->variables[i]->data){
      this->variables[i]->state = true; 
      break; 
    }
  }
}

Variable* TablaGen::get_var(char key){
  for(int i = 0; i < this->cant_variables; i++){
    if(key == this->variables[i]->data){
      return this->variables[i];
      break; 
    }
  }
  return nullptr; 
}

#endif
