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

class RC4 {
  public:
    RC4(std::vector<int> clave);
    ~RC4(void);

    std::vector<int> get_secuencia();

    std::vector<int> cifrar(std::vector<int> mensaje);
    std::vector<int> descifrar(std::vector<int> mensaje);

    std::vector<std::bitset<8>> convertir_binario(std::vector<int> mensaje);

    std::ostream& print(std::ostream &os, std::vector<int> v);
    std::ostream& print(std::ostream &os, std::vector<std::bitset<8>> v);
  private:
    // Índices
    int i_; int j_; 
    // Vector de estado
    std::vector<int> S_;
    // Vector de clave
    std::vector<int> K_;
    // Clave cifrada
    std::vector<int> cifrado_;
    // Mensaje binario
    std::vector<std::bitset<8>> binario_;

    void clean(void);

    void KSA(std::vector<int>& clave);
    int PRGA(void);
};

#endif // RC4_H_