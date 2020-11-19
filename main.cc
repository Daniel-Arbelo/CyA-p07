// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo main.cc: Programa que se encarga de crear un DFA, pasado en un fichero de texto, y comprobar las si las
// cadenas que contiene el segundo fichero pertenecen a ese lenguaje, metiendolas en el último fichero con un si o un 
// no si pertenecen o no.

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "FuncionTransicion.h"
#include "Dfa.h"

using namespace std;


static void ensenar_uso(string nombre) {  
  cerr <<  "Modo de empleo: " << nombre << " input.dfa input.txt output.txt" << endl <<
           "Pruebe " << nombre << " --help para mas información" << endl <<
           "  -En el fichero input.dfa debe aparecer la especificación del DFA" << endl <<
           "  -En el primer fichero txt pasado debe aparecer una cadena por línea del DFA ateriro" << endl <<
           "  -El último fichero contendrá tras la ejecución del programa las mismas cadenas" << endl <<
           "   del fichero de entrada seguidas de un texto --Si /No indicativo de la aceptación" << endl << 
           "   (o no) de la cadena en cuestion."<< endl;
}

bool es_comentario(string& linea) {
  bool resultado = 0;
  if(linea[0] == '/' && linea[1] == '/')
    resultado = 1;
  return resultado;
}

int main(int argc, char* argv[]) {
  if(argc == 1) {
    cout << "Modo de empleo: " << argv[0] << " input.dfa input.txt output.txt" << endl <<
            "Pruebe " << argv[0] << " --help para mas información" << endl;
    return 1;
  }
  // Enseñar ayuda
  string arg = argv[1];  
  if((arg == "-h") || (arg == "--help")) {
    ensenar_uso(argv[0]);
    return 0;
  }
  // Si no tiene el numero adecuado de argumentos, se termina el programa con un mensaje
  if(argc != 4) {  
    cout << "Modo de empleo: " << argv[0] << " input.dfa input.txt output.txt" << endl <<
            "Pruebe " << argv[0] << " --help para mas información" << endl;
    return 1;
  } 
  Dfa automata;
  string linea;
  int numero_lineas;
  // Abrimos el fichero de entrada del DFA
  ifstream fichero_entrada_dfa(argv[1]);
  // Inicializamos el alfabeto
  getline(fichero_entrada_dfa, linea);
  while(es_comentario(linea)) {
    getline(fichero_entrada_dfa, linea);
  }
  numero_lineas = stoi(linea);
  for(int i = 0; i < numero_lineas; ++i) {
    getline(fichero_entrada_dfa, linea);
    automata.insertar_alfabeto(linea);
  }
  // Inicializamos los estados
  getline(fichero_entrada_dfa, linea);
  numero_lineas = stoi(linea);
  for(int i = 0; i < numero_lineas; ++i) {
    getline(fichero_entrada_dfa, linea);
    automata.insertar_estados(linea);
  }
  // Inicializamos el estado inicial
  getline(fichero_entrada_dfa, linea);
  automata.insertar_estado_inicial(linea);
  // Inicializamos los estados de aceptacion
  getline(fichero_entrada_dfa, linea);
  numero_lineas = stoi(linea);
  for(int i = 0; i < numero_lineas; ++i) {
    getline(fichero_entrada_dfa, linea);
    automata.insertar_estsdos_finales(linea);
  }
  // Trancisiones
  getline(fichero_entrada_dfa, linea);
  numero_lineas = stoi(linea);
  for(int i = 0; i < numero_lineas; ++i) {
    getline(fichero_entrada_dfa, linea);
    automata.insertar_transiciones(linea);
  }
  fichero_entrada_dfa.close();
  // Leer fichero que contiene las cadenas y meterlas en el fichero de salida
  // Abrimos el ficero de entrada
  ifstream fichero_entrada_cadenas(argv[2]);
  ofstream fichero_salida(argv[3]);
  // Recorremos el fichero viendo si se aceptan las cadenas y metiendolas en el fichero de salida
  while(!fichero_entrada_cadenas.eof()) {
        getline(fichero_entrada_cadenas, linea);
        if(automata.identificar_cadena(linea) == 1)
          fichero_salida << linea << " --Sí" << endl;
        else
        {
          fichero_salida << linea << " --No" << endl;
        }
        
  }
  fichero_entrada_cadenas.close();
  fichero_salida.close();
}
