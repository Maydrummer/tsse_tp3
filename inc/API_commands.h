/************************************************************************************************
Copyright (c) 2024, Anthony Maisincho <thonymmj21@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file  API_commands.h
 ** @brief Este modulo otorga funciones de validacion de comandos, inicializacion de trama de datos
 **        conversion ascii to int para cuando se recepte el byte con la informacion del numero de
 *bytes
 **        Este modulo sirve para el handshake I2C entre mcu slave y sbc master
 **/

/* === Headers files inclusions ================================================================ */
#include "stdint.h"
/* === Cabecera C++ ============================================================================ */

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
// Estructura para los metadatos de un motor
typedef struct {
    uint8_t duty_cycle;
    uint8_t duration[2];
    uint8_t min_voltage_start;
    uint8_t min_voltage_runtime;
    uint8_t delay_start_measurement;
    uint8_t max_current_M1;
} metadata_frame_motores_t;

// Estructura para los metadatos de motores m1 y m2
typedef struct {
    metadata_frame_motores_t m1;
    metadata_frame_motores_t m2;
} metadata_motores_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Valida si el comando es permitido
 * @param byte_recibido Byte que se va a chequear
 * @return uint8_t Retorna 1 si el comando es permitido, caso contrario retorna 0.
 */
uint8_t validar_comando(uint8_t byte_recibido);

/**
 * @brief Calcula el xor total de (nbytes-1) y lo compara con el de la trama
 * @param nbytes Numero de bytes que tiene la trama
 * @param buffer_frame puntero de la trama
 * @return uint8_t retorna 1 si el CRC que se encuentra en el bytes numero nbytes
 *                 es igual al calculado por la funcion, caso contrario retorna 0
 */
uint8_t check_crc_frame(uint8_t nbytes, uint8_t * buffer_frame);

/**
* @brief Convierte de ascii a entero del 1 al 9
* @param buffer_nbytes byte a convertir a entero del 0 al 9
* @return uint8_t retorna valor de 1 al 9 si el buffer_nbytes esta en el rango 1-9,
                  caso contrario, para cualquier byte retorna un 0
 */
uint8_t receive_nbytes_frame(uint8_t * buffer_nbytes);

/**
 * @brief Inicializa la variable que contiene la estructura de un metadata con todos
 *        sus campos en cero
 * @param metadata puntero con la direccion de memoria de la estructura
 * @return void no retorna valor alguno
 */
void inicializar_metadata(metadata_motores_t * metadata);
/* === End of documentation ==================================================================== */
