#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>


class Vernam {
  public:
    Vernam(std::string mensaje, std::string clave);
    Vernam(std::string clave);

    void cifrar(std::string mensaje);
    void descifrar(std::string cifrado);

    std::string get_mensaje_cifrado();
    std::string get_mensaje_descifrado();
  private:
    std::string mensaje_;
    std::string clave_;
    std::string mensaje_cifrado_binario_;
    std::string mensaje_cifrado_;
    std::string mensaje_descifrado_binario_;
    std::string mensaje_descifrado_;
    std::vector<std::string> binario;
    
    void convertir_binario(std::string mensaje);
    std::string convertir_binario_string(std::string mensaje);
    void destroy();
};