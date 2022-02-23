// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Sistemas de Seguiridad Informática // Curso: 3º
// Práctica 2: Cifrado RC4
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.edu.es
#include "RC4.h"

RC4::RC4(std::vector<int> clave) : clave_(clave) {}



RC4::~RC4(void) {
  destroy();
}


void RC4::destroy(void) {
  S_.clear();
  K_.clear();
}


// Key Scheduling Algorihm
void RC4::ksa(void) {
  // Iterate over the range [0, 256]
  for (int i = 0; i < 256; i++) {
    S_.push_back(i);
  }
  int j = 0;
  for (int i = 0; i < 256; i++) {
    // Encontrar la clave
    j = (j + S_[i] + K_[i]) % 256;
    // Intermcabiar i y j
    std::swap(i, j);
  }
}



// Generación de Secuencia Cifrante
int RC4::prga(void) {
  int i = 0, j = 0;
  i = (i + 1) % 256;
  j = (j + S_[i]) % 256;
  // Intermcabiar S_[i] y S_[j]
  std::swap(S_[i], S_[j]);
  int t = (S_[i] + S_[j]) % 256;
  return S_[t];
}