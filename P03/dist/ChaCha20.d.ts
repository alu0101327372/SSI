/**
 * Clase que representa el cifrado ChaCha20
 */
export declare class ChaCha20 {
    private inicial;
    private clave;
    private contador;
    private nonce;
    private constante;
    /**
     * @constant ROUNDS
     * @readonly
     */
    readonly ROUNDS: number;
    /**
     * @param inicial {number[]} Estado inicial 512 bits
     * @param clave {number[]} Clave 256 bits
     * @param contador {number[]} Contador de 32 bits
     * @param nonce {number[]} Nonce de 96 bits
     * @param constante {number[]} Constante de 128
    */
    constructor(inicial: number[], clave: number[], contador: number[], nonce: number[], constante: number[]);
    /**
     * Devuelve el estado inicial.
     * @returns {number[]} Estado inicial
     */
    getInicial(): number[];
    /**
     * Método que lleva a cabo la rotación.
     * @param a {number} Numero que rota
     * @param b {number} Cantidad de desplazamiento
     * @returns {number} Desplazamiento
     */
    ROTL(a: number, b: number): number;
    /**
     * Toma una entrada de 4 palabras, y la actualiza como salida de 4 palabras
     * @param a {number} Palabra 1
     * @param b {number} Palabra 2
     * @param c {number} Palabra 3
     * @param d {number} Palabra 4
     * @param x {UintArray32} estado inicial 512 bits
     */
    QRound(a: number, b: number, c: number, d: number, x: Uint32Array): void;
    /**
     * Método que realiza el cifrado ChaCha20
     * @param input {number[]} Estado inicial
     * @returns {Uint32Array} Mensaje cifrado
     */
    chachaBlock(input: number[]): Uint32Array;
    /**
     * Imprime la salida por pantalla
     * @param ouput {Uint32Array} Array a imprimir
     * @returns {string} Cadena con el estado
     */
    print(ouput: Uint32Array): void;
}
