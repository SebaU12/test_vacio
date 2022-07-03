#ifndef TESTVACIOON_H 
#define TESTVACIOON_H

#include <iostream>
#include "tablagen.h"
#include "rule.h"
#include "cvector.h"

using namespace std; 

class TestVacioOn{
  private: 
    TablaGen *tabla_generadora; 
    List<Rule *> *rules= new CVector<Rule *>();
    int cant_rules; 
    Variable* Sstate; 
  public: 
    TestVacioOn(){}
    TestVacioOn(string variables, int cant_reglas, List<string> *reglas){
      //Formar tablaGeneradora
      TablaGen *tabla_gen = new TablaGen(variables); 
      this->tabla_generadora = tabla_gen;
      this->cant_rules = cant_reglas; 
      //Generar las reglas 
      this->set_rules(reglas); 
    };
    ~TestVacioOn(){};
    void set_rules(List<string> *reglas);
    bool es_vacio();
}; 

void TestVacioOn::set_rules(List<string> *reglas){
  int start = 0; 
  for (auto rul = reglas->begin(); rul != nullptr ; rul = reglas->aumentar(rul)) {
    if(start == 0){
      this->Sstate = this->tabla_generadora->get_var(rul->data[0]); 
      start = 1; 
    }
    Rule *newRule = new Rule(rul->data,  1); 
    rules->push_back(newRule);
  }    
}

bool TestVacioOn::es_vacio(){
  char data; 
  int start = 0; 
  char popped; 
  List<char> *keys= new CVector<char>();
  while (true){
    for (auto rul = this->rules->begin(); rul != nullptr ; rul = this->rules->aumentar(rul)) {
      if(start == 1){
        rul->data->restar_count(popped); 
      }
      data = rul->data->get_state_count(); 
      if(data == rul->data->state){
        if(this->tabla_generadora->get_var(data)->state == false){
          keys->push_back(data);
          break; 
        }
      }
    }
    start = 1; 
    if(keys->size() > 0){
      popped = keys->pop_back(); 
    } else {
      if(this->Sstate->state == true) return false; 
      else return true; 
    }
    if(this->Sstate->state == true) return false; 
    this->tabla_generadora->update_var(popped);
  }
  return false;
}

#endif
