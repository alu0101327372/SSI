#pragma once
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

    void print_descifrado();
    void print_cifrado();
  private:
    std::string mensaje_;
    std::string mensaje_binario_;
    std::string clave_;
    std::string mensaje_cifrado_binario_;
    std::string mensaje_cifrado_;
    std::string mensaje_descifrado_binario_;
    std::string mensaje_descifrado_;
    std::vector<std::string> binario;

    void destroy();
    void convertir_binario(std::string mensaje);
    std::string convertir_binario_string(std::string mensaje_binario);
};