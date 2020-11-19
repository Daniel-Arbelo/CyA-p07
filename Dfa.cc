// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo Dfa.cc: contiene la definición de los métodos de la clase Dfa.
#include "Dfa.h"

Dfa::Dfa() {

}

Dfa::~Dfa() {

}

// Inserta la cadena en el alfabeto
void Dfa::insertar_alfabeto(string& cadena) {
  alfabeto_.insertar(cadena);
}

// Inserta un estado
void Dfa::insertar_estados(string& cadena) {
  estados_.insertar(cadena);
}

// Inicializa el estado inicial
void Dfa::insertar_estado_inicial(string& cadena) {
  estados_.set_estado_inicial(cadena);
}

// Inserta los estados iniciales
void Dfa::insertar_estsdos_finales(string& cadena) {
  estados_.insertar_estado_aceptacion(cadena);
}

// Inserta las transiciones en la funcion de transicion
void Dfa::insertar_transiciones(string& cadena) {
  funcion_transicion_.insertar(cadena);
}

// Retorna un 1 si la cadena pasada es aceptada, si no devuelve un 0
bool Dfa::identificar_cadena(string& cadena) {
  string estado_actual = estados_.get_estado_inicial();
  string simbolo;
  //for(string::iterator it = cadena.begin(); it != cadena.end(); it++) {

  for(string::iterator it = cadena.begin(); it != cadena.end(); it++) {
    simbolo.push_back(*it);
    estado_actual = funcion_transicion_.get_next(estado_actual, simbolo);
    simbolo.erase();
  }
  if(estados_.es_estado_aceptacion(estado_actual))
    return 1;
  else
  {
    return 0;
  }
  
}

// Imprime los elementos del DFA
void Dfa::prueba() {
  alfabeto_.imprimir();
  cout << endl;
  estados_.Imprimir();
  cout << endl;
  funcion_transicion_.Imprimir();
}
