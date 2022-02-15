#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

class Vernam {
  public:
    Vernam(std::string clave_) : clave(clave_){};

    void cifrar(std::string entrada_);
    void descifrar(std::string cifrado_);

    std::string get_mensaje_cifrado();
    std::string get_mensaje_descifrado();

    void print_descifrado();
    void print_cifrado();

private:
    std::string entrada;
    std::string clave;
    std::string mensaje_cifrado_binario;
    std::string mensaje_cifrado;
    std::string mensaje_descifrado_binario;
    std::string mensaje_descifrado;
    std::vector<std::string> binario;

    void borrar();
    void convertir_binario(std::string entrada_);
    std::string convertir_binario_string(std::string mensaje_binario);
};