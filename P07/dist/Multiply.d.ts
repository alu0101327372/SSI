/**
 * @class Clase encargada de la multiplicación en Snow 3G o AES
 */
export declare class Multiply {
    private byte1;
    private byte2;
    private result;
    private algorithm;
    /**
     * Constructor
     * @param byte1 Multiplicando
     * @param byte2 Multiplicador
     * @param algorithm Algoritmo a usar
     * @param result Resultado de la multiplicación
     */
    constructor(byte1: number, byte2: number, result?: number);
    getResult(): string;
    multiplication(): void;
    /**
     * Método para descomponer en factores un byte para aplicar distributiva
     * @returns
     */
    private descompose;
    /**
     * Convertir una tupla en un array
     * @param byte2Descompose tupla a convertir
     * @returns array de string
     */
    private tuplatoString;
    /**
     * Método encargado de desplazar y XOR
     * @param first Multplicando
     * @param second byte que indica el desplazamiento a realizar
     * @returns Resultado de aplizar respectivos desplazamientos y XORs
     */
    private distributiva;
    /**
     * Convertir una pos Array a un número
     * @param inputArray Array a convertir
     * @returns número resultante
     */
    private convertArraytoNumber;
}
