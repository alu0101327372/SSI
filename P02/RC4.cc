// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Sistemas de Seguiridad Informática // Curso: 3º
// Práctica 2: Cifrado RC4
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.edu.es
#include "RC4.h"

RC4::RC4(std::vector<int> clave) : K_(256), S_(256), i_(0), j_(0) {
  KSA(clave);
}



RC4::~RC4(void) {
  clean();
}



void RC4::clean(void) {
  i_ = 0; j_ = 0;
  S_.clear();
  K_.clear();
}



// Algoritmo de Programación de Clave
void RC4::KSA(std::vector<int>& clave) {
  //Iterar sobre el rango [0, 256]
  for (int i = 0; i < S_.size(); i++) {
    S_[i] = i;
    K_[i] = clave[i % clave.size()];
  }
  int j = 0;
  for (int i = 0; i < S_.size(); i++) {
    // Encontrar la clave
    j = (j + S_[i] + K_[i]) % 256;
    // Actualizar S_[i] y S_[j]
    std::swap(S_[i], S_[j]);
  }
}



// Generación de Secuencia Cifrante
int RC4::PRGA(void) {
  // Generación de cada byte de secuencia
  i_ = (i_ + 1) % 256;
  j_ = (j_ + S_[i_]) % 256;
  // Actualizar S_[i] y S_[j]
  std::swap(S_[i_], S_[j_]);
  // Secuencia cifrante
  int t = (S_[i_] + S_[j_]) % 256;
  return S_[t];
}



// Convertir el numero decimal a binario.
std::vector<std::bitset<8>> RC4::convertir_binario(std::vector<int> mensaje) {
  binario_.clear();
  for (int i = 0; i < mensaje.size(); i++) {
    binario_.push_back(std::bitset<8>(mensaje[i]));
  }
  return binario_;
}



std::vector<int> RC4::get_secuencia() {
  return cifrado_;
}



// Cifrado RC4
std::vector<int> RC4::cifrar(std::vector<int> mensaje) {
  // Inicialización del mensaje cifrado
  std::vector<int> secuencia(mensaje.size());
  cifrado_.resize(mensaje.size());
  int aux;
  // Suma XOR
  for (int i = 0; i < mensaje.size(); i++) {
    aux = PRGA();
    cifrado_[i] = aux;
    secuencia[i] = mensaje[i] ^ aux;
  }
  return secuencia;
}



// Descifrado RC4
std::vector<int> RC4::descifrar(std::vector<int> mensaje) {
  // Inicialización del mensaje cifrado
  std::vector<int> secuencia(mensaje.size());
  for (int i = 0; i < mensaje.size(); i++) {
    secuencia[i] = mensaje[i] ^ cifrado_[i];
  }
  return secuencia;
}



// Salida por pantalla
std::ostream& RC4::print(std::ostream &os, std::vector<int> v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) {
    if (i != v.size() - 1)
      os << v[i] << " , ";
    else
      os << v[i] << " ]";;
  }
  return os;
}




// Salida por pantalla
std::ostream& RC4::print(std::ostream &os, std::vector<std::bitset<8>> v) {
  os << "[ ";
  for (int i = 0; i < v.size(); i++) {
    if (i != v.size() - 1)
      os << v[i] << " , ";
    else
      os << v[i] << " ]" << std::endl;
  }
  return os;
}