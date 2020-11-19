// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo Estados.cc: contiene la definición de los métodos de la clase Estados.
#include "Estados.h"

Estados::Estados() {

}

Estados::~Estados() {

}

// Inserta un nuevo estado
void Estados::insertar(string& cadena) {
  estados_.insert(cadena);
}

// Inserta los estados de aceptacion
void Estados::insertar_estado_aceptacion(string& cadena) {
  estados_aceptacion_.insert(cadena);
}

// Inicializa el estado inicial
void Estados::set_estado_inicial(string& cadena) {
  estado_inicial_ = cadena;
}

// Retorna el estado inicial
string& Estados::get_estado_inicial() {
  return estado_inicial_;
}

// Retorna un uno si se encuentra en el conjunto de estados de aceptacion
bool Estados::es_estado_aceptacion(string& cadena) {
  bool resultado = 0;
  for(set<string>::iterator it = estados_aceptacion_.begin(); it != estados_aceptacion_.end(); it++) {
    if(it->compare(cadena) == 0)
      resultado = 1;
  }
  return resultado;
}

// Imprime los estados
void Estados::Imprimir() {
  cout << "Q = {";
  for(set<string>::iterator it = estados_.begin(); it != estados_.end(); it++)
  {
    cout << " " << *it << ",";
  }
  cout << "}" << endl;
}

// Imprime los estados de aceptacion
void Estados::ImprimirEstadoAceptacion() {
  cout << "F = {";
  for(set<string>::iterator it = estados_aceptacion_.begin(); it != estados_aceptacion_.end(); it++)
  {
    cout << " " << *it << ",";
  }
  cout << "}" << endl;
}