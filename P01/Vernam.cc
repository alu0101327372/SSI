#include "Vernam.h"

Vernam::Vernam(std::string mensaje, std::string clave) : mensaje_(mensaje), clave_(clave) {}



Vernam::Vernam(std::string clave) : clave_(clave) {}



void Vernam::cifrar(std::string mensaje) {
  destroy();
  convertir_binario(mensaje_);
  // Pasar el mensaje en binario a string
  std::string mensaje_output;
  for (int i = 0; i < binario.size(); i++) {
    mensaje_output += binario[i];
  }

  // Leer el mensaje cada 8 bits
  std::bitset<8> clave_output;
  std::vector<std::bitset<8>> mensaje_entero;
  std::istringstream msg(mensaje_output);
  for (int i = 0; i < mensaje_output.size() / 8; i++) {
    msg >> clave_output;
    mensaje_entero.push_back(clave_output);
  }

  // Leer la clave cada 8 bits
  std::bitset<8> clave;
  std::vector<std::bitset<8>> clave_entera;
  std::istringstream clv(clave_);
  for (int i = 0; i < clave_.size() / 8; i++) {
    clv >> clave;
    clave_entera.push_back(clave);
  }

  // Suma XOR entre los 8 bits del mensaje y de la clave
  for (int i = 0; i < mensaje_entero.size(); i++) {
    mensaje_entero[i] ^= clave_entera[i];
  }

  // Convertir la clave y el mensaje a string
  for (int i = 0; i < mensaje_entero.size(); i++) {
    mensaje_cifrado_binario_ += mensaje_entero[i].to_string();
  }

  mensaje_cifrado_ = convertir_binario_string(mensaje_cifrado_binario_);
}



void descifrar(std::string cifrado) {
  mensaje_cifrado_ = cifrado;
  destroy();
  convertir_binario(mensaje_cifrado_);
  // Pasar el mensaje en binario a string
  std::string mensaje_output;
  for (int i = 0; i < binario.size(); i++) {
    mensaje_output += binario[i];
  }

  // Leer el mensaje cada 8 bits
  std::bitset<8> clave_output;
  std::vector<std::bitset<8>> mensaje_entero;
  std::istringstream msg(mensaje_output);
  for (int i = 0; i < mensaje_output.size() / 8; i++) {
    msg >> clave_output;
    mensaje_entero.push_back(clave_output);
  }

  // Leer la clave cada 8 bits
  std::bitset<8> clave;
  std::vector<std::bitset<8>> clave_entera;
  std::istringstream clv(clave_);
  for (int i = 0; i < clave_.size() / 8; i++) {
    clv >> clave;
    clave_entera.push_back(clave);
  }

  // Suma XOR entre los 8 bits del mensaje y de la clave
  for (int i = 0; i < mensaje_entero.size(); i++) {
    mensaje_entero[i] ^= clave_entera[i];
  }

  // Convertir la clave y el mensaje a string
  for (int i = 0; i < mensaje_entero.size(); i++) {
    mensaje_descifrado_binario_ += mensaje_entero[i].to_string();
  }

  mensaje_descifrado_ = convertir_binario_string(mensaje_descifrado_binario_);
}



void Vernam::convertir_binario(std::string mensaje) {
  std::vector<int> numero;
  binario.clear();
  // Obtengo el caracter en decimal y lo convierto a binario.
  for (int i = 0; i < mensaje.size(); i++) {
    numero.push_back(int(mensaje[i]));
    binario.push_back(std::bitset<8>(numero[i]).to_string());
  }
}



std::string Vernam::convertir_binario_string(std::string mensaje_binario) {
  int tamaño = mensaje_binario.size() / entrada.size();
  std::vector<std::string> mensaje;

  std::string caracter;
  for (int i = 0; i < mensaje_binario.size() / tamaño; i++) {
    for (int j = i * tamaño; j < (i + 1) * tamaño; j++) {
      caracter += mensaje_binario[j];
    }
    mensaje.push_back(caracter);
    caracter.clear();
  }

  std::string mensaje_string;
  for (int i = 0; i < mensaje.size(); i++) {
    unsigned long decimal = std::bitset<8>(mensaje[i]).to_ulong();
    if (decimal > 125) {
        decimal = decimal % 125;
    }
    if (decimal < 32) {
        decimal += decimal % 32;
    }
    mensaje_string.push_back(char(decimal));
  }

  return mensaje_string;
}



std::string Vernam::get_mensaje_cifrado() {
  return mensaje_cifrado_;
}



std::string Vernam::get_mensaje_descifrado() {
  return mensaje_descifrado_;
}



void Vernam::destroy() {
  mensaje_.clear();
  mensaje_cifrado_binario_.clear();
  mensaje_cifrado_.clear();
  mensaje_descifrado_.clear();
  mensaje_descifrado_binario_.clear();
}