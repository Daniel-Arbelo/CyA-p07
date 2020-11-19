/**
 * @file Alfabeto.h
 * @version 1.0
 * @date 18/11/2021
 * @author Dane Arbelo Hernández
 * @title Clase Alfabeto de DFA
 * @brief Clase que almacena un alfabeto
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
// Archivo Alfabeto.h: contiene la declaración de la clase que almacena el alfabeto en un set de strings.

#pragma once
#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * @brief Clase para almacenar alfabetos
 */
class Alfabeto {
private:
  set<string> Alfabeto_;  //Almacena el alfabeto
public:
  /**
   * @brief Constructor por defecto de Alfabeto
   */
  Alfabeto();

  /**
   * @brief Destructor de la clase Alfabeto
   */
  ~Alfabeto();
  
  /**
   * @brief insertar Inserta una cadena en el alfabeto
   * @param cadena cadena a insertar
   */
  void insertar(string& cadena);

  /**
   * @brief imprimir imprimer el contenido del alfabeto
   */
  void imprimir();
};