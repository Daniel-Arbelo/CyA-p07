// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo Alfabeto.cc: contiene la definición de los métodos de la clase Alfabeto.

#include "Alfabeto.h"

Alfabeto::Alfabeto() {

}

Alfabeto::~Alfabeto() {

}

// Inserta una cadena del alfabeto en el conjunto
void Alfabeto::insertar(string& cadena) {
  Alfabeto_.insert(cadena);
}

// Imprimer el alfabeto
void Alfabeto::imprimir() {
  cout << "Σ = {";
  for(set<string>::iterator it = Alfabeto_.begin(); it != Alfabeto_.end(); it++)
  {
    cout << " " << *it << ",";
  }
  cout << "}" << endl;
}