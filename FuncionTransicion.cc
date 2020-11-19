// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo FuncioTransicion.cc: contiene la definición de los métodos de la clase FuncionTransicion.
#include "FuncionTransicion.h"

FuncionTransicion::FuncionTransicion() {

}

FuncionTransicion::~FuncionTransicion() {

}

// Inserta una transicion
void FuncionTransicion::insertar(string& cadena) {
  funcion_.insert(cadena);
}

// Imptime las transiciones
void FuncionTransicion::Imprimir() {
  cout << "Trancisiones:" << endl;
  for(set<string>::iterator it = funcion_.begin(); it != funcion_.end(); it++)
  {
    cout << " " << *it << ",";
  }
  cout << endl;
}

// Dado un estado y un simbolo devuelve el estado al que se transita
string FuncionTransicion::get_next(string& estado_actual, string& simbolo) {
  string aux, aux2, aux3, aux4, resultado;
  int contador = 0;
  for(set<string>::iterator it = funcion_.begin(); it != funcion_.end(); it++)
  {
    aux = *it;
    for(string::iterator it2 = aux.begin(); it2 != aux.end(); it2++)
    {
        if(*it2 != ' ' && contador == 0) {
          aux2.push_back(*it2);
          
        }
        else if(contador == 1 && *it2 != ' ') {
          aux3.push_back(*it2);
        }
        else if(contador == 2 && *it2 != ' ') {
          aux4.push_back(*it2);
        }
        else if(*it2 == ' ') {
          contador ++;
        }
    }
    if((aux2.compare(estado_actual) == 0) && (aux3.compare(simbolo) == 0))
      resultado = aux4;
    aux2.erase();
    aux3.erase();
    aux4.erase();
    contador = 0;
  }
  return resultado;
}