#!/usr/bin python3
# -*- coding: utf-8 -*-
# Generador C/A de GPS
#----------------------------------------------------------------------------
# @author: Marco Antonio Cabrera Hernández
# @email: alu0101327372@ull.edu.es
# Executio: python3 GPS_CA.py
# ---------------------------------------------------------------------------
import os

class CA_GPS:
  GS = {
    1: [2,6],
    2: [3,7],
    3: [4,8],
    4: [5,9],
    5: [1,9],
    6: [2,10],
    7: [1,8],
    8: [2,9],
    9: [3,10],
    10: [2,3],
    11: [3,4],
    12: [5,6],
    13: [6,7],
    14: [7,8],
    15: [8,9],
    16: [9,10],
    17: [1,4],
    18: [2,5],
    19: [3,6],
    20: [4,7],
    21: [5,8],
    22: [6,9],
    23: [1,3],
    24: [4,6],
    25: [5,7],
    26: [6,8],
    27: [7,9],
    28: [8,10],
    29: [1,6],
    30: [2,7],
    31: [3,8],
    32: [4,9]
  }

  feedback_ = []

  def __init__(self, id_, size):
    self.id_ = id_
    self.size = size

  # Método que realiza el desplazamiento a la derecha
  def desplazamiento(self, LFSR, feedback, out):
    # Calculo de la salida
    output = [LFSR[i - 1] for i in out]
    if len(output) > 1:
      output = sum(output) % 2
    else:
      output = output[0]

    # Suma de la retroalimentación
    feed = sum([LFSR[i-1] for i in feedback]) % 2

    # Desplazamiento a la derecha
    for i in reversed(range(len(LFSR[1:]))):
      LFSR[i + 1] = LFSR[i]

    LFSR[0] = feed
    self.feedback_.append(LFSR[0])
    return output

  # Método que define el generador PRN
  def PRN(self):
    # Inicialización de los registers LFSR1 y LFSR2.
    LFSR1 = [1 for i in range(10)]
    LFSR2 = [1 for i in range(10)]

    # Creamos el vector que contendra el resultado lo denominamos C/A
    result = []

    # Desplazamiento de la secuencia para cada longitud
    for i in range(self.size):
      # Realizamos el desplazamiento G1
      G1 = self.desplazamiento(LFSR1, [3, 10], [10])
      G2 = self.desplazamiento(LFSR2, [2, 3, 6, 8, 9, 10], self.GS[self.id_])
      # Suma en modulo dos
      result.append((G1 + G2) % 2)

    feedback_G1 = []
    feedback_G2 = []

    for i in range(0, len(self.feedback_), 2):
      feedback_G1.append(self.feedback_[i])

    for i in range(1, len(self.feedback_), 2):
      feedback_G2.append(self.feedback_[i])

    print("Realimentación G1: ", feedback_G1)
    print("Realimentación G1: ", feedback_G2)
    print()

    # Mostramos la secuencia generada
    print("El resultado es: ", result)

# Función principal
def main():
  # Pedimos por teclado el ID del satélite y la longitud de la secuencia
  id_ = int(input("Introduzca el ID del Satélite: "))
  size = int(input("Introduzca la longitud de la secuencia de salida: "))
  print()
  CA = CA_GPS(id_, size)
  CA.PRN()

main()