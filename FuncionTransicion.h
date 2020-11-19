/**
 * @file FuncionTransicion.h
 * @version 1.0
 * @date 18/11/2021
 * @author Dane Arbelo Hernández
 * @title Clase de FuncionTransicion
 * @brief Clase que almacena las funciones de transicion y tiene una funcion para estas transiciones
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
// Archivo FuncioTransicion.h: contiene la difinición de la clase que almacena la funcion de transicion, y 
// gracias al metodo get_next dado un estado y un simbolo se devuelve el estado siguiente.
#pragma once
#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * @brief Clase  que almacena las transiciones
 */
class FuncionTransicion {
private:
    set<string> funcion_;  // Almacena las cadenas con las trancisiones
public:

  /**
   * @brief Constructor por defecto de FuncionTransicion
   */
  FuncionTransicion();

  /**
   * @brief Destructor por defecto de FuncionTransicion
   */
  ~FuncionTransicion();

  /**
   * @brief insertar Inserta una transicion en la funcion de transiciones
   * @param cadena transicion a insertar
   */
  void insertar(string& cadena);

  /**
   * @brief Imptimir Imprime las transiciones
   */
  void Imprimir();

  /**
   * @brief get_next Dado un estado y un simbolo devuelve el estado al que se transita
   * @param  estado_actual estado en el que se encuentra
   * @param simbolo simbolo con el que se transita
   * @return string cadena que contien el estado al que se transita
   */
  string get_next(string& estado_actual, string& simbolo);
};