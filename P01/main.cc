#include "Vernam.h"


int main() {
  int opcion;
  int aleatorio;
  std::string mensaje, clave;
  std::cout << "¿Desea introducir la clave manual o de forma aleatoria?\n";
  std::cout << "[0] Manual\n";
  std::cout << "[1] Aleatoria\n";
  std::cin >> opcion;
  if (opcion == 0) {
    std::cout << "Introduzca la entrada:\n";
    std::cin >> mensaje;
    std::cout << "Introduzca la clave:\n";
    std::cin >> clave;
  }
  else {
    std::cout << "Introduzca la entrada:\n";
    std::cin >> mensaje;

    srand(time(NULL));
    for (int i = 0; i < mensaje.size(); i++) {
      aleatorio = rand() % 64;
      std::bitset<8> clave_bitset(aleatorio);
      clave += clave_bitset.to_string();
    }
  }

  // Cifrado
  Vernam cifrado(clave);

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
        cifrado.cifrar(mensaje);
        cifrado.print_cifrado();
        break;

      case 2: 
        std::cout << "Introduzca la entrada cifrada:\n";
        std::cin >> mensaje;

        cifrado.descifrar(mensaje);
        cifrado.print_descifrado();
        break;
    }
  }
}