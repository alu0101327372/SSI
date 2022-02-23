// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Sistemas de Seguiridad Informática // Curso: 3º
// Práctica 2: Cifrado RC4
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.edu.es
#ifndef RC4_H_
#define RC4_H_

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#include <time.h>

class RC4 {
  public:
    RC4(std::vector<int> clave);
    ~RC4(void);

    void cifrar(std::string msg);
    void descifrar(std::string msg);

    void print_descifrado();
    void print_cifrado();
  private:
    int i_;
    int j_; 
    std::vector<int> S_;
    std::vector<int> K_;
    std::vector<int> valor_;
    std::vector<std::bitset<8>> mensaje_cifrado_;

    void ksa(void);
    int prga(void);
    void destroy(void);
};

#endif // RC4_H_