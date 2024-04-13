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

/** @file test_API_commands.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */
#include "unity.h"
#include "API_commands.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
uint8_t cmd_buffer[2];
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
void test_es_valido_el_comando(void) {
    cmd_buffer[1] = 'a';
    TEST_ASSERT_EQUAL_INT(1, validar_comando(cmd_buffer[1]));
}

void test_no_es_valido_el_comando(void) {
    cmd_buffer[1] = 'g';
    TEST_ASSERT_EQUAL_INT(0, validar_comando(cmd_buffer[1]));
}
/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */
