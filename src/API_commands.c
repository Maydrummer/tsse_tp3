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

/** @file API_commands.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */

#include "API_commands.h"

/* === Macros definitions ====================================================================== */
#define MIN_NBYTE 0x31
#define MAX_NBYTE 0x39
/* === Private data type declarations ========================================================== */
enum device_commands {
    DEVICE_CMD_DUMMY = 0x61,
    DEVICE_CMD_MOTOR_1,
    DEVICE_CMD_MOTOR_2,
    DEVICE_CMD_VOLTAGE_SENSOR,
    DEVICE_CMD_RGB_CONTROL,
    DEVICE_CMD_READ_DATA
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

uint8_t validar_comando(uint8_t byte_recibido) {
    uint8_t byte_entero = (uint8_t)byte_recibido;
    switch (byte_entero) {
    case DEVICE_CMD_DUMMY:
    case DEVICE_CMD_MOTOR_1:
    case DEVICE_CMD_MOTOR_2:
    case DEVICE_CMD_VOLTAGE_SENSOR:
    case DEVICE_CMD_RGB_CONTROL:
    case DEVICE_CMD_READ_DATA:
        return 1; // El byte recibido coincide con un valor enumerado
    default:
        return 0; // El byte recibido no coincide con ningún valor enumerado
    }
}

uint8_t check_crc_frame(uint8_t nbytes, uint8_t * buffer_frame) {
    uint8_t crc_value;
    for (uint8_t i = 0; i < (nbytes - 1); i++) {

        crc_value ^= *buffer_frame;
        buffer_frame++;
    }

    if (*(buffer_frame) == crc_value) {
        return 1;
    } else {
        return 0;
    }
}

uint8_t receive_nbytes_frame(uint8_t * buffer_nbytes) {
    if ((*buffer_nbytes >= MIN_NBYTE) && (*buffer_nbytes <= MAX_NBYTE)) {
        return *buffer_nbytes - '0';
    } else {
        return 0;
    }
}

void inicializar_metadata(metadata_motores_t * metadata) {
    *metadata = (metadata_motores_t){0};
}

/* === End of documentation ==================================================================== */
