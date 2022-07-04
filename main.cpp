#include <iostream> 
#include "testvacioon.h"
#include "slowtest.h"
#include "cvector.h"
#include <ctime>
using namespace std; 

int main(){
  string terminales; 
  string variables; 
  int cant_reglas; 
  unsigned t0, t1, t2, t3;
  double time;
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

  cout << endl << "Cantidad de variables: " << variables.size(); 
  cout << endl << "Cantidad de terminales: " << terminales.size(); 
  cout << endl << "Cantidad de reglas: " << cant_reglas << endl; 
  Slow_test *slow = new Slow_test(variables, terminales, cant_reglas, reglas); 
  t0=clock();
  bool rpta1 = slow->es_vacio(); 
  t1=clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);  
  cout << "Tiempo de ejecucion del algoritmo O(n^2): " << time << endl;
  if(rpta1 == true){
    cout << "YES" << endl; 
  } else {
    cout << "NO" << endl;
  }
  TestVacioOn *fast = new TestVacioOn(variables, cant_reglas, reglas);
  t2=clock();
  bool rpta2 = fast->es_vacio(); 
  t3=clock();
  time = (double(t3-t2)/CLOCKS_PER_SEC);  
  cout << "Tiempo de ejecucion del algoritmo O(n): " << time << endl;
  if(rpta2 == true){
    cout << "YES" << endl; 
  } else {
    cout << "NO" << endl;
  }
  return 0; 
}
