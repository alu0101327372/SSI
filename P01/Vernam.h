#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

class Vernam
{
private:
    std::string entrada;
    std::string clave;
    std::string mensaje_cifrado_binario;
    std::string mensaje_cifrado;
    std::string mensaje_descifrado_binario;
    std::string mensaje_descifrado;

    std::vector<std::string> binario;

public:
    Vernam(std::string entrada_, std::string clave_) : entrada(entrada_), clave(clave_){};
    Vernam(std::string clave_) : clave(clave_){};

    ~Vernam(){};

    void cifrar(std::string entrada_);
    void descifrar(std::string cifrado_);
    void write();

    std::string get_mensaje_cifrado();
    std::string get_mensaje_descifrado();

    void print_descifrado();
    void print_cifrado();

private:
    void borrar();
    void convertir_binario(std::string entrada_);
    std::string convertir_binario_string(std::string mensaje_binario);
};