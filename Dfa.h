/**
 * @file Dfa.h
 * @version 1.0
 * @date 18/11/2021
 * @author Dane Arbelo Hernández
 * @title Clase de DFA
 * @brief Clase que almacena los elementos del DFA y reconoce o no cadenas
 */
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 7 CyA - DFA
// Autor: Danel Arbelo Hernández
// Correo: alu0101117621@ull.es
// Fecha: 18/11/2021
// Archivo Dfa.h: contine la declaración de la clase Dfa que utiliza la s clases Alfabeto, Estados y Funcion de Transicion
// para declarar un DFA y ver si las cadenas que se le pasan al método identificar cadenas pertenecen a ese DFA.
#pragma once
#include <iostream>
#include <set>
#include <string>
#include "Alfabeto.h"
#include "Estados.h"
#include "FuncionTransicion.h"

using namespace std;

/**
 * @brief Clase para crear un DFA
 */
class Dfa {
private:
  Alfabeto alfabeto_; // Objeto que almacena el alfabeto
  Estados estados_;  //Objeto que almacena los estados, el estado inicial y los estados finales
  FuncionTransicion funcion_transicion_;  //Objeto que guarda las transiciones
public:

  /**
   * @brief Constructor por defecto de Dfa
   */
  Dfa();

  /**
   * @brief Destructor de Dfa
   */
  ~Dfa();

  /**
   * @brief insertar_alfabeto Inserta una cadena en el alfabeto
   * @param cadena cadena a insertar
   */
  void insertar_alfabeto(string& cadena);

  /**
   * @brief insertar_estados Inserta un estado
   * @param cadena estado a insertar
   */
  void insertar_estados(string& cadena);

   /**
   * @brief insertar_estado_inicial Inicializa el estado inicial
   * @param cadena estado a inicializar
   */
  void insertar_estado_inicial(string& cadena);

  /**
   * @brief insertar_estsdos_finales Inserta un estado final
   * @param cadena estado a insertar
   */
  void insertar_estsdos_finales(string& cadena);

  /**
   * @brief insertar_transiciones Inserta una transicion
   * @param cadena transicion a insertar
   */
  void insertar_transiciones(string& cadena);

  /**
   * @brief identificar_cadena Comprueba una cadena si es aceptada devuelve un 1 si no un 0
   * @param cadena cadena a comprobar
   * @return double si la cadena pertenece al lenguaje es 1 si no 0
   */
  bool identificar_cadena(string& cadena);

  /**
   * @brief prueba Imprime los elementos del DFA
   */
  void prueba();
};