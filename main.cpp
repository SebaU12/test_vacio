#include <iostream> 
#include "testvacioon.h"
#include "slowtest.h"
#include "cvector.h"
using namespace std; 

int main(){
  string terminales; 
  string variables; 
  int cant_reglas; 
  cin >> terminales; 
  cin >> variables; 
  cin >> cant_reglas; 
  List<string> *reglas= new CVector<string>();
  for(int i = 0; i < cant_reglas + 1; i++){
    string regla; 
    getline(cin, regla);
    if(i != 0){
      reglas->push_back(regla);
    }
  }

  Slow_test *slow = new Slow_test(variables, terminales, cant_reglas, reglas); 
  if(slow->es_vacio() == true){
    cout << "YES" << endl; 
  } else {
    cout << "NO" << endl;
  }
  TestVacioOn *fast = new TestVacioOn(variables, cant_reglas, reglas);
  if(fast->es_vacio() == true){
    cout << "YES" << endl; 
  } else {
    cout << "NO" << endl;
  }
  return 0; 
}
