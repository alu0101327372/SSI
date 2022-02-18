#include "Vernam.h"

Vernam::Vernam(std::string clave) : clave_(clave) {}



Vernam::~Vernam(void) {
  destroy();
}



void Vernam::destroy() {
  mensaje_.clear();
  mensaje_binario_.clear();
  mensaje_cifrado_binario_.clear();
  mensaje_cifrado_.clear();
  mensaje_descifrado_.clear();
  mensaje_descifrado_binario_.clear();
}



void Vernam::convertir_binario(std::string mensaje) {
  std::vector<int> numero;
  binario.clear();
  // Obtener el caracter en decimal y convertir a binario.
  for (int i = 0; i < mensaje.size(); i++) {
    numero.push_back(int(mensaje[i]));
    binario.push_back(std::bitset<8>(numero[i]).to_string());
    mensaje_binario_ += binario[i];
  }
}



std::string Vernam::convertir_binario_string(std::string mensaje_binario) {
  std::vector<std::string> mensaje;
  int tamaño = mensaje_binario.size() / mensaje_.size();

  std::string caracter = "";
  for (int i = 0; i < mensaje_binario.size() / tamaño; i++) {
    for (int j = i * tamaño; j < (i + 1) * tamaño; j++) {
      caracter += mensaje_binario[j];
    }
    mensaje.push_back(caracter);
    caracter.clear();
  }

  std::string mensaje_string = "";
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



void Vernam::cifrar(std::string msg) {
  destroy();
  mensaje_ = msg;
  convertir_binario(mensaje_);

  std::string mensaje_str  = "";
  for (int i = 0; i < binario.size(); i++) {
    mensaje_str += binario[i];
  }
  // Leer el mensaje cada conjunto de 8 bits
  std::bitset<8> mensaje;
  std::istringstream flujo_mensaje(mensaje_str);
  std::vector<std::bitset<8>> mensaje_bits;

  for (int i = 0; i < mensaje_str.size() / 8; i++) {
    flujo_mensaje >> mensaje;
    mensaje_bits.push_back(mensaje);
  }
  // Leer la clave cada conjunto de 8 bits
  std::bitset<8> clave;
  std::vector<std::bitset<8>> clave_bits;
  std::istringstream flujo_clave(clave_);
  for (int i = 0; i < clave_.size() / 8; i++) {
    flujo_clave >> clave;
    clave_bits.push_back(clave);
  }
  // Suma XOR entre los 8 bits del mensaje y de la clave.
  for (int i = 0; i < mensaje_bits.size(); i++) {
    mensaje_bits[i] ^= clave_bits[i];
  }
  // Pasar la suma a string
  for (int i = 0; i < mensaje_bits.size(); i++) {
    mensaje_cifrado_binario_ += mensaje_bits[i].to_string();
  }
  mensaje_cifrado_ = convertir_binario_string(mensaje_cifrado_binario_);
}



void Vernam::descifrar(std::string msg) {
  destroy();
  mensaje_ = msg;
  mensaje_cifrado_ = msg;
  convertir_binario(mensaje_cifrado_);

  std::string mensaje_str  = "";
  for (int i = 0; i < binario.size(); i++) {
    mensaje_str += binario[i];
  }
  // Leer el mensaje cada conjunto de 8 bits
  std::bitset<8> mensaje;
  std::istringstream flujo_mensaje(mensaje_str);
  std::vector<std::bitset<8>> mensaje_bits;

  for (int i = 0; i < mensaje_str.size() / 8; i++) {
    flujo_mensaje >> mensaje;
    mensaje_bits.push_back(mensaje);
  }
  // Leer la clave cada conjunto de 8 bits
  std::bitset<8> clave;
  std::vector<std::bitset<8>> clave_bits;
  std::istringstream flujo_clave(clave_);
  for (int i = 0; i < clave_.size() / 8; i++) {
    flujo_clave >> clave;
    clave_bits.push_back(clave);
  }
  // Suma XOR entre los 8 bits del mensaje y de la clave.
  for (int i = 0; i < mensaje_bits.size(); i++) {
    mensaje_bits[i] ^= clave_bits[i];
  }
  // Pasar la suma a string
  for (int i = 0; i < mensaje_bits.size(); i++) {
    mensaje_descifrado_binario_ += mensaje_bits[i].to_string();
  }
  mensaje_descifrado_ = convertir_binario_string(mensaje_descifrado_binario_);
}



void Vernam::print_cifrado() {
  std::cout << "Entrada\n";
  std::cout << "\tMensaje Original: " << mensaje_ << "\n";
  std::cout << "Salida\n";
  std::cout << "\tMensaje original en binario: " << mensaje_binario_ << "\n";
  std::cout << "\tLongitud del mensaje en binario: " << mensaje_binario_.length() << "\n";
  std::cout << "Entrada\n";
  std::cout << "\tClave Aleatoria: " << clave_ << "\n";
  std::cout << "\tMensaje cifrado en binario: " << mensaje_cifrado_binario_ << "\n";
  std::cout << "\tMensaje cifrado: " << mensaje_cifrado_ << "\n";
}



void Vernam::print_descifrado() {
  std::cout << "Entrada\n";
  std::cout << "\tMensaje Cifrado: " << mensaje_cifrado_ << "\n";
  std::cout << "Salida\n";
  std::cout << "\tMensaje cifrado en binario: " << mensaje_binario_ << "\n";
  std::cout << "\tLongitud del mensaje en binario: " << mensaje_binario_.length() << "\n";
  std::cout << "Entrada\n";
  std::cout << "\tClave Aleatoria: " << clave_ << "\n";
  std::cout << "\tMensaje descifrado en binario: " << mensaje_descifrado_binario_ << "\n";
  std::cout << "\tMensaje descifrado: " << mensaje_descifrado_ << "\n";
}