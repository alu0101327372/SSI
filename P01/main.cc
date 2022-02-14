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
  Vernam cifrado(mensaje, clave);

  int operacion = 0;
  bool salir = false;
  // Menu
  while (!salir) {
    std::cout << "\n¿Qué desea hacer?\n";
    std::cout << "[0] Salir.\n";
    std::cout << "[1] Cifrar mesaje.\n";
    std::cout << "[2] Descifrar mensaje.\n";
    std::cin >> operacion;
  }
  switch(operacion) {
    case 0: 
      salir = true;
      break;

    case 1:
      cifrado.cifrar(mensaje);
      std::cout << "Entrada\n";
      std::cout << "\tMensaje Original: " << mensaje << "\n";
      std::cout << "Salida\n";
      std::cout << "\tMensaje original en binario: " << "\n";
      std::cout << "\tLongitud del mensaje en binario: " << "\n";
      std::cout << "Entrada\n";
      std::cout << "\tClave Aleatoria: " << clave << "\n";
      std::cout << "\tMensaje cifrado en binario: " << "\n";
      std::cout << "\tMensaje cifrado: " << cifrado.get_mensaje_cifrado() << "\n";
      break;

    case 2: 
      std::cout << "Introduzca la entrada cifrada:\n";
      std::cin >> mensaje;

      cifrado.descifrar(mensaje);

      std::cout << "Entrada\n";
      std::cout << "\tMensaje Cifrado: " << mensaje << "\n";
      std::cout << "Salida\n";
      std::cout << "\tMensaje cifrado en binario: " << "\n";
      std::cout << "\tLongitud del mensaje en binario: " << "\n";
      std::cout << "Entrada\n";
      std::cout << "\tClave Aleatoria: " << "\n";
      std::cout << "\tMensaje cifrado en binario: " << "\n";
      std::cout << "\tMensaje cifrado: " << cifrado.get_mensaje_descifrado() << "\n";
  }
}