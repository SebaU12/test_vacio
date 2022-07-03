#ifndef SLOW_TEST_H 
#define SLOW_TEST_H

#include <iostream>
#include "tablagen.h"
#include "cvector.h"
#include "rule.h"

using namespace std; 

class Slow_test{
  private: 
    List<Rule *> *rules= new CVector<Rule *>();
    List<char> *generadores = new CVector<char>();
    int cant_rules; 
    char Sstate; 
  public: 
    Slow_test(){};
    Slow_test(string variables, string terminales, int cant_reglas, List<string> *reglas){
      //Generar la lista generadora 
      this->set_generador(terminales); 
      this->cant_rules = cant_reglas; 
      //Generar las reglas 
      this->set_rules(variables.size(), variables, reglas); 
    };
    ~Slow_test(){};
    void set_rules(int cant_variables, string variables, List<string> *reglas);
    void set_generador(string terminales); 
    bool es_vacio();
}; 

void Slow_test::set_generador(string terminales){
  int cant = terminales.size(); 
  for (int i = 0; i < cant; i++){
    this->generadores->push_back(terminales[i]); 
  }
}

void Slow_test::set_rules(int cant_variables, string variables, List<string> *reglas){
  int start = 0; 
  for (auto rul = reglas->begin(); rul != nullptr ; rul = reglas->aumentar(rul)) {
    if(start == 0){
      this->Sstate = rul->data[0]; 
      start = 1; 
    }
    Rule *newRule = new Rule(rul->data,  0); 
    rules->push_back(newRule);
  }    
}

bool Slow_test::es_vacio(){
  bool flag = false; 
  bool flag2 = false; 
  bool flag3 = false; 
  int size_gen_b = 0; 
  while (true){
    size_gen_b = this->generadores->size(); 
    for (auto rul = this->rules->begin(); rul != nullptr ; rul = this->rules->aumentar(rul)) {
      for(int j = 0; j < rul->data->content.size(); j++){
        flag = false; 
        for (auto gen = this->generadores->begin(); gen != nullptr ; gen = this->generadores->aumentar(gen)) {
          if(gen->data == rul->data->content[j]){
            flag = true; 
            break; 
          }
        }   
        if(flag == false) break; 
      }
      if(flag == true){
        flag2 = false; 
        for (auto gen = this->generadores->begin(); gen != nullptr ; gen = this->generadores->aumentar(gen)) {
          if(rul->data->state == gen->data) flag2 = true; 
        }
        if(flag2 == false){
          this->generadores->push_back(rul->data->state);
          if(rul->data->state == this->Sstate) return false; 
          break;
        }
      }
    }
    if(size_gen_b == this->generadores->size()) break; 
  }
  for (auto gen = this->generadores->begin(); gen != nullptr ; gen = this->generadores->aumentar(gen)) {
    if (gen->data == this->Sstate) return false; 
  }
  return true; 
}

#endif
