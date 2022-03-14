"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Menu = void 0;
/**
 * @author Marco Antonio Cabrera Hernández <alu0101327372@ull.edu.es>
 */
const inquirer_1 = __importDefault(require("inquirer"));
const ChaCha20_1 = require("./ChaCha20");
class Menu {
    constructor() { }
    async run() {
        await this.mainMenu();
    }
    async mainMenu() {
        console.clear();
        console.log('=== PROGRAMA DE ENCRIPTADO DE ChaCha20 ===');
        // Clave
        const clave = await inquirer_1.default.prompt({
            type: 'number',
            name: 'clave',
            message: 'Introduzca la clave: ',
            default: [0x03020100, 0x07060504, 0x0b0a0908, 0x0f0e0d0c, 0x13121110, 0x17161514, 0x1b1a1918, 0x1f1e1d1c]
        });
        // Contador
        const contador = await inquirer_1.default.prompt({
            type: 'number',
            name: 'contador',
            message: 'Introduzca el contador: ',
            default: [0x00000001]
        });
        // Nonce
        const nonce = await inquirer_1.default.prompt({
            type: 'number',
            name: 'nonce',
            message: 'Introduzca el nonce: ',
            default: [0x09000000, 0x4a000000, 0x00000000]
        });
        // Constante
        const constante = await inquirer_1.default.prompt({
            type: 'number',
            name: 'constante',
            message: 'Introduzca la constante: ',
            default: [0x61707865, 0x3320646e, 0x79622d32, 0x6b206574]
        });
        // ChaCha20
        let inicial = [];
        const chacha20 = new ChaCha20_1.ChaCha20(inicial, clave['clave'], contador['contador'], nonce['nonce'], constante['constante']);
        inicial = chacha20.getInicial();
        chacha20.chachaBlock(inicial);
    }
}
exports.Menu = Menu;
const menu = new Menu();
menu.run();
