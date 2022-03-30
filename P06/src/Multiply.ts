/**
 * @class Clase encargada de la multiplicación en Snow 3G o AES
 */
 export class Multiply {
  /**
   * Constructor
   * @param byte1 Multiplicando
   * @param byte2 Multiplicador
   * @param algorithm Algoritmo a usar
   * @param result Resultado de la multiplicación
   */
  constructor(
    private byte1: number,
    private byte2: number,
    private algorithm: string = '00011011',
    private result: number = 0) {}

  public getResult() {
    return this.result.toString().padStart(8, '0');
  }

  public multiplication(): void {
    // Obtener el segundo byte despuesto para aplicar propiedad distributiva
    const second = this.descompose();
    const result: number[] = [];
    const opDistributive: number[] = [];

    // XOR ROTATE
    for (let i = 0; i < second.length; i++) {
      opDistributive[i] = this.distributiva(this.byte1.toString(2).padStart(8, '0'), second[i]);
    }

    // SUMA XOR
    for (let i = 0; i < opDistributive.length; i++) {
      for (let j = 0; j < 8; j++) {
        result[j] ^= parseInt(opDistributive[i].toString().padStart(8, '0').charAt(j));
      }
    }
    this.result = this.convertArraytoNumber(result);
  }

  /**
   * Método para descomponer en factores un byte para aplicar distributiva
   * @returns
   */
  private descompose(): string[] {
    // Tupla de array de números
    const byte2Descompose: [number[]] = [[]];
    // Recorremos hasta encontrar un 1
    for (let i = 0; i < this.byte2.toString(2).padStart(8, '0').length; i++) {
      if (this.byte2.toString(2).padStart(8, '0').charAt(i) === '1') {
        // Array con todo 0
        const dist: number[] = new Array(8).fill(0);
        // Colocamos el 1 en la misma pos que lo encontramos en el segundo byte
        dist[i] = 1;
        // Agregos los dist (distributiva) a la tupla
        byte2Descompose.unshift(dist);
      }
    }
    // Pop para eliminar basura insertada al final
    byte2Descompose.pop();

    // Obtenemos los bytes para aplicar distributiva y retornamos
    return this.tuplatoString(byte2Descompose);
  }

  /**
   * Convertir una tupla en un array
   * @param byte2Descompose tupla a convertir
   * @returns array de string
   */
  private tuplatoString(byte2Descompose: [number[]]): string[] {
    const A: string[] = [];
    for (let j = 0; j < byte2Descompose.length; j++) {
      let a: string = '';
      for (let i = 0; i < 8; i++) {
        a += byte2Descompose[j][i].toString();
      }
      A[j] = a;
    }
    return A;
  }

  /**
   * Método encargado de desplazar y XOR
   * @param first Multplicando
   * @param second byte que indica el desplazamiento a realizar
   * @returns Resultado de aplizar respectivos desplazamientos y XORs
   */
   private distributiva(first: string, second: string): number {
    // Caso base
    if (second === '00000001') {
      return parseInt(first);
    }

    // Convertir string a Array para poder trabajar bit a bit
    const firstArray: number[] = [];
    for (let i = 0; i < first.length; i++) {
      firstArray[i] = parseInt(first.charAt(i));
    }

    // Index = índice donde se encuentra el único 1
    const index: number = 7 - second.indexOf('1');
    // Recorremos
    for (let i = 0; i < index; i++) {
      if (firstArray[0] === 1) {
        // Desplazar a la izquierda
        firstArray.shift();
        firstArray.push(0);

        // Xor bit a bit con el byte del algoritmo seleccionado
        for (let j = 0; j < 8; j++) {
          firstArray[j] = firstArray[j] ^ parseInt(this.algorithm.charAt(j))
        }
      } else if (firstArray[0] === 0) {
        // Desplazar a la izquierda
        firstArray.shift();
        firstArray.push(0);
      }
    }
    return this.convertArraytoNumber(firstArray);
  }

  /**
   * Convertir una pos Array a un número
   * @param inputArray Array a convertir
   * @returns número resultante
   */
  private convertArraytoNumber(inputArray: number[]) {
    let result: string = '';
    for (let i = 0; i < inputArray.length; i++) {
      result += inputArray[i];
    }
    return parseInt(result);
  }
}