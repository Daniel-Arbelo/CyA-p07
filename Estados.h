/**
 * @file Estados.h
 * @version 1.0
 * @date 18/11/2021
 * @author Dane Arbelo Hernández
 * @title Clase de Estados
 * @brief Clase que almacena los estados del DFA
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
// Archivo Estados.h: contiene la difinición de la clase que almacena los estados, el estado inicial, todos los estados,
// y los estados de aceptación.
#pragma once
#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * @brief Clase  que almacena los estado, el estado de inicio y los de aceptacion
 */
class Estados {
private:
  set<string> estados_;  // Almacena todos los estados
  string estado_inicial_;  // Almacena el estado inicial
  set<string> estados_aceptacion_;  // Almacena los estados de aceptacion
public:

  /**
   * @brief Constructor por defecto de Estados
   */
  Estados();

  /**
   * @brief Destructor de Estados
   */
  ~Estados();

  /**
   * @brief insertar Inserta un estado
   * @param cadena estado a insertar
   */
  void insertar(string& cadena);

  /**
   * @brief insertar_estado_aceptacion Inserta un estado final
   * @param cadena estado a insertar
   */
  void insertar_estado_aceptacion(string& cadena);

  /**
   * @brief set_estado_inicial Inicializa el estado inicial
   * @param cadena estado a inicializar
   */
  void set_estado_inicial(string& cadena);

  /**
   * @brief get_estado_inicial retorna el estado inicial
   * @return string retorna el estado inicial
   */
  string& get_estado_inicial();

  /**
   * @brief es_estado_aceptacion devuelve un 1 si el estado pasado es de aceptacion y un 0 si no
   * @param cadena estado a comprobar
   * @return bool si la cadena pertenece a los estados de aceptacion es 1 si no 0
   */
  bool es_estado_aceptacion(string& cadena);

  /**
   * @brief Imprimir Imprime los estados
   */
  void Imprimir();

  /**
   * @brief ImprimirEstadoAceptacion Imprime los estados de aceptacion
   */
  void ImprimirEstadoAceptacion();
};