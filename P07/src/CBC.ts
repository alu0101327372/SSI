var scanf = require('scanf');
import { AES } from './AES';

class CBC extends AES {
  private IV: string[][] = [[], [], [], []];
  private textBlock: string[][][] = [[], []];
  private CipherBlock: string[][] = [];
  private texto: string[];

  /**
   * Inicializa el objeto y las matrices.
   * @param key_ clave
   * @param text_ bloque de texto
   * @param IV_ bloque
   */
  constructor(
    key_: string,
    text_: string[],
    IV_: string
  ) {
    super(key_, text_[0]);

    this.texto = text_;
    for (let i = 0; i < text_.length; i++) {
      this.textBlock[i] = this.setMatrix(text_[i]);
    }
    this.IV = this.setMatrix(IV_);
  }

  /**
   * Inicializa una matriz.
   * @param inputArray entrada para establecer la matriz
   * @returns matriz establecida
   */
  private setMatrix(inputArray: string): string[][] {
    let result: string[][] = [[], [], [], []];
    let k = 0; let l = 2;

    for (let i = 0; i < 4; i++) {
      for (let j = 0; j < 4; j++) {
      result[i][j] = inputArray.slice(k, l);
      k += 2; l += 2;
      }
    }
    k = 0; l = 2;
    return this.transpose(result);
  }

  /**
   * Realiza el modo CBC de operación en cifrado en bloque.
   */
  public encryptCBC(): void {
    let outputAES: string[][] = this.IV;
    let textsize: string[][] = [];

    for (let i = 0; i < this.textBlock.length; i++) {
      textsize.push(this.matrixtoArray(this.textBlock[i]));
    }

    for (let k = 0; k < this.textBlock.length; k++) {
      if (textsize[k].length >= 16 ) {
      // XOR entre texto y IV
      this.text = this.xor(this.textBlock[k], outputAES);
      outputAES = this.encrypt();
      this.CipherBlock.push(this.matrixtoArray(outputAES));

      } else {
        let lastBlock = this.CipherBlock[k-1];
        let actualBlock = this.matrixtoArray(this.textBlock[k]);
        let cipher: string[] = [];

        /**
         * XOR (último bloque ^ lastcipherblock)
         */
        for (let i = 0; i < textsize[k].length; i++) {
          let firstByte = parseInt(actualBlock[i], 16).toString(2).padStart(8, '0') ;
          let secondByte = parseInt(lastBlock[i], 16).toString(2).padStart(8, '0');
          cipher[i] = this.xorBit2Bit(firstByte, secondByte);
        }

        // Pasar a hexadecimal
        for (let j = 0; j < textsize[k].length; j++) {
          cipher[j] = parseInt(cipher[j], 2).toString(16).padStart(2, '0');
        }

        // Añadir la parte robada
        for (let i = textsize[k].length; i < 16; i++){
          cipher[i] = lastBlock[i];
        }
        // Aplicar el AES
        this.text = this.transpose(this.arraytoMatrix(cipher));
        outputAES = this.encrypt();
        this.CipherBlock.push(this.matrixtoArray(outputAES));

        // Recortar el penultimo bloque
        let lastBlock2 = this.CipherBlock[k-1].splice(0, textsize[k].length)
        this.CipherBlock.push(lastBlock2);
        this.CipherBlock.shift();
      }
    }
    this.print();
  }

  /**
   * Convierte una matriz en un Array
   * @param matrix
   * @returns resultado
   */
  private matrixtoArray(matrix: string[][]): string[] {
    let result: string[] = [];
    for(let i = 0; i < matrix.length; i++) {
      for(let j = 0; j < matrix.length; j++) {
        if (matrix[j][i] != '') {
          result.push(matrix[j][i]);
        }
      }
    }
    return result;
  }

  /**
   * Convierte un Array en una matriz
   * @param array
   * @returns resultado
   */
  private arraytoMatrix(array: string[]): string[][] {
    let result: string[][] = [];
     let i = 0;
     let k = 0;
    for (i = 0, k=-1; i < 16; i++) {
      if (i % 4 === 0) {
        k++;
        result[k] = [];
      }
      result[k].push(array[i]);
    }
    return result;
   }

  /**
    * Realiza la xor entre dos matrices
    * @param a matriz
    * @param b matriz
    * @returns matriz resultado
    */
  private xor(a: string[][], b: string[][]): string[][] {
    let result: string[][] = [[], [], [], []];
    for (let i = 0; i < 4; i++) {
      for (let j = 0; j < 4; j++) {
        let inputblock = parseInt(a[i][j].charAt(0), 16).toString(2).padStart(4, '0') + parseInt(a[i][j].charAt(1), 16).toString(2).padStart(4, '0');
        let keyblock = parseInt(b[i][j].charAt(0), 16).toString(2).padStart(4, '0') + parseInt(b[i][j].charAt(1), 16).toString(2).padStart(4, '0');
        result[i][j] = (parseInt(inputblock, 2) ^ parseInt(keyblock, 2)).toString(16).padStart(2, '0');
      }
    }
    return result;
  }

  /**
   * Imprime la infomracion
   */
  public print(): void {
    console.log('\nEntrada:');
    this.printKey();
    console.log(`IV: ${this.transpose(this.IV)}`);
    for (let i = 0; i < this.textBlock.length; i++) {
      console.log(`Bloque Texto Original ${i + 1}:  ${this.transpose(this.textBlock[i])}`);
    }

    console.log('\nSalida');
    for (let i = 0; i < this.CipherBlock.length; i++) {
      console.log(`Bloque Texto Cifrado ${i + 1}:  ${this.CipherBlock[i]}`);
    }
  }
}

// Menu principal
console.log('Introduce la clave de entrada (16 bytes): ');
var clave = scanf('%s');
console.log('Introduce la entrada IV (16 bytes): ');
var IV = scanf('%s');
console.log('Introduce la entrada texto original: ');
var texto = scanf('%s');

let defaultClave = '000102030405060708090A0B0C0D0E0F';
let defaultText = '00112233445566778899AABBCCDDEEFF';
let defaultIV = '00000000000000000000000000000000';

let bloque = [defaultText, '00000000000000000000000000000000'];
const cipher = new CBC(defaultClave, bloque, defaultIV);
cipher.encryptCBC();