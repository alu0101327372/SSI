var scanf = require('scanf');

import { DH } from './DH';

/**
 * @class ElGammal hereda de DiffiHellman para poder acceder
 * a sus atributos y métodos
 */
class ELGammal {
  private K: number = 0; // Clave compartida
  private ya: number = 0; // enteros intermedios
  private yb: number = 0; // enterios intermedios
  private C: number = 0; // Mensaje cifrado
  private inverseK: number = 0; // Inverso modular
  private M: number = 0; // Mensaje descifrado
  constructor(private p: number, private a: number, private k: number,
    private x: number, private mensaje: number) {
    // Calculamos los valores públicos de A y B es decir sus entertos intermedios
    const publicA = new DH(p, a, k);
    const publicB = new DH(p, a, x);
    this.ya = publicA.gety();
    this.yb = publicB.gety();
    // Calculamos la clave compartida K = (ya)^k (mod p)
    this.K = publicA.fastExponentiation(this.yb, k, p);
    // Encriptamos el mensaje
    this.encrypt();
    // Calculamos la inversa de K necesario para desencriptar
    this.inverseK = this.eucExt(this.K, p);
    // Desencriptamos M = K⁻¹ * K * m (mod p)
    this.decrypt();
  }

  /**
   * Message Encrypted
   * C = K * m (mod p)
   */
  private encrypt(): void {
    this.C = (this.K * this.mensaje) % this.p;
  }

  /**
   * Message Decrypted
   * M = K⁻¹ * K * M (mod p)
   */
  private decrypt(): void {
    this.M = (this.inverseK * this.C) % this.p;
  }

  /**
   * Obtener K = Clave secreta compartida
   * @returns {number} K
   */
  private getK(): number {
    return this.K;
  }

  /**
   * Obtener C = mensaje cifrado
   * @returns {number} C
   */
  private getC(): number {
    return this.C;
  }

  /**
   * Obtener el entero intemedio generado por A
   * @returns {number} yb
   */
  private getya(): number {
    return this.ya;
  }

  /**
   * Obtener el entero intermedio generado por B
   * @returns {number} ya
   */
  private getyb(): number {
    return this.yb;
  }

  /**
   * Calculo del inverso modular haciendo uso del algoritmo de euclides extendido
   * @param {number} a Número a obtener el inverso
   * @param {number} module
   * @returns {number} Inverso modular de a
   */
  private eucExt(a: number, module: number): number {
    // Inicalizar valores
    const x: number[] = [0, module, a];
    const z = [0, 1];

    let i = 2;
    // Mientras que el resto no de 0
    while (x[i-1] % x[i] != 0) {
      x[i+1] = x[i-1] % x[i];
      const div = Math.trunc(-x[i-1] / x[i]);
      z[i] = div * z[i-1] + z[i-2];

      while (z[i] < 0) {
        z[i] += module;
      }

      z[i] = z[i] % module;

      i++;
    }

    const mcd = x[i];

    /**
     * Comprobamos si el mcd === 1 significa que tiene inverso y
     * este es la última z calculada
     */

    if (mcd === 1) {
      return z[i-1];
    }
    return 0;
  }

  /**
   * Mostrar los resultados por pantalla
   */
  public print() {
    console.log(`Entrada: p = ${this.p}, a = ${this.a}, k = ${this.k}, x = ${this.x} m = ${this.mensaje}`);
    console.log(`Salida: yA = ${this.ya}, yB = ${this.yb}, K = ${this.K}, C = ${this.C}, K⁻¹ = ${this.inverseK} , M = ${this.M}`);
  }
}

// Menu principal
console.log('Introduce el número primo: ');
var p = scanf('%d');
console.log('Introduce el número entero a: ');
var a = scanf('%d');
console.log('Introduce el número secreto k: ');
var k = scanf('%d');
console.log('Introduce el número secreto x: ');
var x = scanf('%d');
console.log('Introduce el mensaje: ');
var m = scanf('%d');

const cypher = new ELGammal(p, a, k,  x, m);
cypher.print()