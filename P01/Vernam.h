// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Sistemas de Seguiridad Informática // Curso: 3º
// Práctica 1: Cifrado de Vernam
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.es
#ifndef VERNAM_H_
#define VERNAM_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

class Vernam {
  public:
    Vernam(std::string clave);
    ~Vernam(void);

    void cifrar(std::string msg);
    void descifrar(std::string msg);

    void print_descifrado(void);
    void print_cifrado(void);
  private:
    std::string mensaje_;
    std::string mensaje_binario_;
    std::string clave_;
    std::string mensaje_cifrado_binario_;
    std::string mensaje_cifrado_;
    std::string mensaje_descifrado_binario_;
    std::string mensaje_descifrado_;
    std::vector<std::string> binario;

    void destroy(void);
    void convertir_binario(std::string mensaje);
    std::string convertir_binario_string(std::string mensaje_binario);
};

#endif // VERNAM_H_