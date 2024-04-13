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
/* === Private variable declarations =========================================================== */
uint8_t cmd_buffer[2];
metadata_motores_t metadata_prueba;
/* === Private function implementation ========================================================= */

/**
 * @test este test valida si el comando es valido ingresandole un comando valido
 */
void test_es_valido_el_comando(void) {
    cmd_buffer[1] = 'a';
    TEST_ASSERT_EQUAL_INT(1, validar_comando(cmd_buffer[1]));
}

/**
 * @test este test valida si se obtiene una respuesta de comando no valido, al
 *       ingresar un comando no valido.
 */
void test_no_es_valido_el_comando(void) {
    cmd_buffer[1] = 'g';
    TEST_ASSERT_EQUAL_INT(0, validar_comando(cmd_buffer[1]));
}

/**
 * @test este test valida si la funcion da un 1, ya que se envio un frame con
 *       un crc correcto.
 */
void test_crc_frame_ok(void) {
    uint8_t buffer_prueba[] = {0x68, 0x6F, 0x6C, 0x61, 0x0A};
    TEST_ASSERT_EQUAL_INT(1, check_crc_frame(5, buffer_prueba));
}

/**
 * @test este test valida si la funcion da un 0, ya que se envio un frame con
 *       un crc incorrecto.
 */
void test_crc_frame_failed(void) {
    uint8_t buffer_prueba[] = {0x68, 0x6F, 0x6C, 0x61, 0x01};
    TEST_ASSERT_EQUAL_INT(0, check_crc_frame(5, buffer_prueba));
}

/**
 * @test este test valida si convierte a int correctamente el ascii que le pasemos
 *       se pasaran ascii del 1 al 9
 */

void test_convertir_ascii_int(void) {
    TEST_ASSERT_EQUAL_INT(1, receive_nbytes_frame("1"));
    TEST_ASSERT_EQUAL_INT(2, receive_nbytes_frame("2"));
    TEST_ASSERT_EQUAL_INT(3, receive_nbytes_frame("3"));
    TEST_ASSERT_EQUAL_INT(4, receive_nbytes_frame("4"));
    TEST_ASSERT_EQUAL_INT(5, receive_nbytes_frame("5"));
    TEST_ASSERT_EQUAL_INT(6, receive_nbytes_frame("6"));
    TEST_ASSERT_EQUAL_INT(7, receive_nbytes_frame("7"));
    TEST_ASSERT_EQUAL_INT(8, receive_nbytes_frame("8"));
    TEST_ASSERT_EQUAL_INT(9, receive_nbytes_frame("9"));
}

/**
 * @test este test valida si la funcion ascii_to_int retorna un 0 para valores fuera de rango
 */

void test_ascii_to_int_failed(void) {
    TEST_ASSERT_EQUAL_INT(0, receive_nbytes_frame("a"));
    TEST_ASSERT_EQUAL_INT(0, receive_nbytes_frame("b"));
    TEST_ASSERT_EQUAL_INT(0, receive_nbytes_frame("c"));
}

/**
 * @test inicializo una variable con valor distinto de cero, prueba que efectivamente esten
 *       con el valor que setee luego reseteo y verifico si la funcion resetea sus campos
 */
void test_inicializar_metadata(void) {
    metadata_prueba.m1.duty_cycle = 30;
    metadata_prueba.m2.duty_cycle = 30;
    metadata_prueba.m1.duration[0] = 23;
    metadata_prueba.m2.duration[0] = 25;
    TEST_ASSERT_EQUAL_UINT8(30, metadata_prueba.m1.duty_cycle);
    TEST_ASSERT_EQUAL_UINT8(30, metadata_prueba.m2.duty_cycle);
    TEST_ASSERT_EQUAL_UINT8(23, metadata_prueba.m1.duration[0]);
    TEST_ASSERT_EQUAL_UINT8(25, metadata_prueba.m2.duration[0]);
    inicializar_metadata(&metadata_prueba);
    TEST_ASSERT_EQUAL_UINT8(0, metadata_prueba.m1.duty_cycle);
    TEST_ASSERT_EQUAL_UINT8(0, metadata_prueba.m2.duty_cycle);
    TEST_ASSERT_EQUAL_UINT8(0, metadata_prueba.m1.duration[0]);
    TEST_ASSERT_EQUAL_UINT8(0, metadata_prueba.m2.duration[0]);
}

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */
