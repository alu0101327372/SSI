/**
 * @class Realiza el cifrado AES.
 */
export declare class AES {
    private key;
    private text;
    private cipherText;
    private numOfRounds;
    private X;
    private S_box;
    private M_mixColum;
    private Rc;
    /**
    * Constructor encargado de convertir el texto y la key en una matriz.
    * @param key Clave
    * @param text Texto
    */
    constructor(key: string, text: string);
    /**
    * Método encargado de ejecutar la secuencia de pasos necesarios para cifrar el texto.
    */
    encrypt(): void;
    /**
     * OR-exclusiva byte a byte entre la cada uno de los byte de la clave dada y el texto dado.
     * @param key Clave en forma de matrix
     * @param text Texto en forma de matrix
     */
    private addRoundKey;
    /**
    * Sustitución no lineal de los bytes de estado basado en la caja S_box que para cada byte genera un nuevo byte.
    */
    private SubBytes;
    /**
    * Desplazar a la izquierda los bytes de las filas que conforman la matriz del estado actual.
    */
    private shiftRows;
    /**
    * Rotamos los valores del input a la izquierda tantas veces como diga el rotate.
    * @param input Array a desplazar
    * @param rotate Numero de veces a desplazar
    * @returns Array desplazado x veces
    */
    private rotateLeft;
    /**
    * Multiplicación de Matriz por columna usando la M_mixcolumn
    */
    private mixColumn;
    /**
    * Metodo encargado de multiplicar una matriz por una columna.
    * @param column
    * @returns
    */
    private multiplyMatrixColumn;
    /**
    * Aplicar la xor bit a bit entre dos bytes dados de manera binaria.
    * @param byte1 byte1 en binario
    * @param byte2 byte2 en binario
    * @returns byte1^byte2
    */
    private xorBit2Bit;
    /**
    * Método encargado de generar las subclaves necesarias
    * @returns 10 claves expandidas
    */
    private keyExpansion;
    /**
    * Método encargado de generar subclaves una a una en forma de matrix
    * @param iExpKey Suclave anterior
    * @param index índice de la subclave anterior
    * @returns subclave generada
    */
    private getExpandKey;
    /**
    * Aplicación del subByte a una sola columna dada por parámetro
    * @param temp columna dada
    * @returns columna una vez aplicada la sustitución
    */
    private SubBytes_ExpKey;
    /**
     * Calcular la traspuesta de una matrix
     * @param matrix
     * @returns Matriz traspuesta
     */
    private transpose;
}
