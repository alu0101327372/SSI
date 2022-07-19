// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Sistemas de Seguiridad Informática // Curso: 3º
// Práctica 2: Cifrado RC4
// Autor: Marco Antonio Cabrera Hernández
// Correo: alu0101327372@ull.edu.es
#include "RC4.h"

#define VERDE   "\033[32m"
#define RESET   "\033[0m"

int main(void) {
  std::cout << "=== PROGRAMA DE ENCRIPTADO DE RC4 ===\n\n";
  // Semilla de clave
  std::vector<int> clave;
  int clave_size, cl;
  std::cout << "Introduzca tamaño de la semilla de clave: ";
  std::cin >> clave_size;
  clave.resize(clave_size);
  std::cout << "Introduzca la semilla de clave: ";
  for (int i = 0; i < clave.size(); i++) {
    std::cout << "-> Semilla[" << i << "] = ";
    std::cin >> cl;
    clave[i] = cl;
  }

  // Mensaje 
  std::vector<int> mensaje;
  int mensaje_size, msg;
  std::cout << "Introduzca tamaño del mensaje: ";
  std::cin >> mensaje_size;
  mensaje.resize(mensaje_size);
  std::cout << "Introduzca el mensaje: ";
  for (int i = 0; i < mensaje.size(); i++) {
    std::cout << "-> Semilla[" << i << "] = ";
    std::cin >> msg;
    mensaje[i] = msg;
  }
  std::cout << std::endl;
  // Cifrado RC4
  RC4 rc4(clave);
  std::vector<int> mensaje_cifrado = rc4.cifrar(mensaje);
  std::vector<int> mensaje_descifrado = rc4.descifrar(mensaje_cifrado);

  // Mostramos los datos
	std::cout << VERDE <<  "-> Semilla: ";
	rc4.print(std::cout, clave);
  std::cout << " Binario: ";
  rc4.print(std::cout, rc4.convertir_binario(clave));
  std::cout << std::endl;

	std::cout << "-> Mensaje: ";
	rc4.print(std::cout, mensaje);
  std::cout << " Binario: ";
  rc4.print(std::cout, rc4.convertir_binario(mensaje));
  std::cout << std::endl;

	std::cout << "-> Secuencia cifrante: ";
	rc4.print(std::cout, rc4.get_secuencia());
  std::cout << " Binario: ";
  rc4.print(std::cout, rc4.convertir_binario(rc4.get_secuencia()));
  std::cout << std::endl;

	std::cout << "-> Mensaje cifrado: ";
	rc4.print(std::cout, mensaje_cifrado);
  std::cout << " Binario: ";
  rc4.print(std::cout, rc4.convertir_binario(mensaje_cifrado));
  std::cout << std::endl;

	std::cout << "-> Mensaje descifrado: ";
	rc4.print(std::cout, mensaje_descifrado);
  std::cout << " Binario: ";
  rc4.print(std::cout, rc4.convertir_binario(mensaje_descifrado));
  std::cout << RESET << std::endl;

  return 0;
}