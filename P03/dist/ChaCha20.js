"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ChaCha20 = void 0;
/**
 * Representa los colores
 */
const chalk = require('chalk');
/**
 * Clase que representa el cifrado ChaCha20
 */
class ChaCha20 {
    /**
     * @param inicial {number[]} Estado inicial 512 bits
     * @param clave {number[]} Clave 256 bits
     * @param contador {number[]} Contador de 32 bits
     * @param nonce {number[]} Nonce de 96 bits
     * @param constante {number[]} Constante de 128
    */
    constructor(inicial, clave, contador, nonce, constante) {
        this.inicial = inicial;
        this.clave = clave;
        this.contador = contador;
        this.nonce = nonce;
        this.constante = constante;
        /**
         * @constant ROUNDS
         * @readonly
         */
        this.ROUNDS = 20;
        for (let i = 0; i < this.constante.length; i++) {
            this.inicial[i] = this.constante[i];
        }
        for (let j = 0; j < this.clave.length; j++) {
            this.inicial[j + 4] = this.clave[j];
        }
        this.inicial[12] = this.contador[0];
        for (let k = 0; k < this.nonce.length; k++) {
            this.inicial[k + 13] = this.nonce[k];
        }
    }
    /**
     * Devuelve el estado inicial.
     * @returns {number[]} Estado inicial
     */
    getInicial() {
        return this.inicial;
    }
    /**
     * Método que lleva a cabo la rotación.
     * @param a {number} Numero que rota
     * @param b {number} Cantidad de desplazamiento
     * @returns {number} Desplazamiento
     */
    ROTL(a, b) {
        return (((a) << (b)) | ((a) >> (32 - (b))));
    }
    /**
     * Toma una entrada de 4 palabras, y la actualiza como salida de 4 palabras
     * @param a {number} Palabra 1
     * @param b {number} Palabra 2
     * @param c {number} Palabra 3
     * @param d {number} Palabra 4
     * @param x {UintArray32} estado inicial 512 bits
     */
    QRound(a, b, c, d, x) {
        // Array de 4 palabras cada una de 32 bits
        const array = new Uint32Array(4);
        array[0] = x[a];
        array[1] = x[b];
        array[2] = x[c];
        array[3] = x[d];
        // Suma de 32 bits y ROTL
        array[0] += array[1];
        array[3] ^= array[0];
        array[3] = this.ROTL(array[3], 16);
        array[2] += array[3];
        array[1] ^= array[2];
        array[1] = this.ROTL(array[1], 12);
        array[0] += array[1];
        array[3] ^= array[0];
        array[3] = this.ROTL(array[3], 8);
        array[2] += array[3];
        array[1] ^= array[2];
        array[1] = this.ROTL(array[1], 7);
        x[a] = array[0];
        x[b] = array[1];
        x[c] = array[2];
        x[d] = array[3];
    }
    /**
     * Método que realiza el cifrado ChaCha20
     * @param input {number[]} Estado inicial
     * @returns {Uint32Array} Mensaje cifrado
     */
    chachaBlock(input) {
        const x = new Uint32Array(16);
        const out = new Uint32Array(16);
        for (let i = 0; i < 16; ++i) {
            x[i] = input[i];
        }
        console.log(chalk.bold.green(`Estado inicial= `));
        this.print(x);
        // 10 iteraciones x 2 rounds/loop = 20 iteraciones
        for (let i = 0; i < this.ROUNDS; i += 2) {
            // Odd round
            this.QRound(0, 4, 8, 12, x); // Column 0
            this.QRound(1, 5, 9, 13, x); // Column 1
            this.QRound(2, 6, 10, 14, x); // Column 2
            this.QRound(3, 7, 11, 15, x); // Column 3
            // Even Round
            this.QRound(0, 5, 10, 15, x); // Column 0
            this.QRound(1, 6, 11, 12, x); // Column 1
            this.QRound(2, 7, 8, 13, x); // Column 2
            this.QRound(3, 4, 9, 14, x); // Column 3
        }
        console.log(chalk.bold.green(`Estado tras 20 iteraciones= `));
        this.print(x);
        // Suma XOR entre estado inicial y el bloque
        for (let i = 0; i < 16; ++i) {
            out[i] = x[i] + input[i];
        }
        console.log(chalk.bold.green(`Estado de salida del generador= `));
        this.print(out);
        return out;
    }
    /**
     * Imprime la salida por pantalla
     * @param ouput {Uint32Array} Array a imprimir
     * @returns {string} Cadena con el estado
     */
    print(ouput) {
        let str = '';
        for (let i = 0; i < ouput.length; i++) {
            if (i % 4 === 0) {
                str += '\n';
            }
            str += ouput[i].toString(16);
            str += ' ';
        }
        console.log(str);
    }
}
exports.ChaCha20 = ChaCha20;
