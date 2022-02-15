#include "Vernam.h"


int main() {
  int aleatorio;
  std::string mensaje, clave;

  std::cout << "Introduzca la entrada:\n";
  std::cin >> mensaje;
  // Clave aleatoria
  srand(time(NULL));
  for (int i = 0; i < mensaje.size(); i++) {
    aleatorio = rand() % 64;
    std::bitset<8> clave_bitset(aleatorio);
    clave += clave_bitset.to_string();
  }

  // Cifrado Vernam
  Vernam vernam(clave);

  int operacion = 0;
  bool salir = false;

  // Menu
  while (!salir) {
    std::cout << "\n¿Qué desea hacer?\n";
    std::cout << "[0] Salir.\n";
    std::cout << "[1] Cifrar mesaje.\n";
    std::cout << "[2] Descifrar mensaje.\n";
    std::cin >> operacion;
  
    switch(operacion) {
      case 0: 
        salir = true;
        exit(1);
        break;

      case 1:
        vernam.cifrar(mensaje);
        vernam.print_cifrado();
        break;

      case 2: 
        std::cout << "Introduzca la entrada cifrada:\n";
        std::cin >> mensaje;

        vernam.descifrar(mensaje);
        vernam.print_descifrado();
        break;
    }
  }
}