#ifndef RULE_H 
#define RULE_H

#include <iostream>
using namespace std; 

struct Rule{
    char state;
    string content; 
    int count; 
    Rule(){}; 
    Rule(string rule, int select){
      if(select == 1){
        this->state = rule[0];
        string _content;
        for(int i = 2; i < rule.size(); i++){
          if(int(rule[i]) + 32 <= 122){
            this->count += 1;
            _content += rule[i];
          }
        }
        this->content = _content;
      } else {
        this->state = rule[0];
        string _content;
        for(int i = 2; i < rule.size(); i++){
          _content += rule[i];
        }
        this->content = _content;
      }
    }
    char get_state_count(){
      if(count == 0) return state; 
      return '1';
    }
    void restar_count(char key){
      if(this->count != 0){
        for(int i = 0; i < this->content.size(); i++){
          if(key == this->content[i]){
            count -= 1; 
          }
        }
      }
    }
    ~Rule(){}
};
#endif
