/*
 * Input.h
 *
 *  Created on: 4 oct 2021
 *      Author: Raffi
 */


#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//--------------------------NUMEROS----------------------------
/// @brief Pide un número entero con una cantidad determinada de reintentos, en un rango determinado.
///
/// @param mensaje
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirIntConRangoConReintentos(char mensaje[], int *numeroIngresado, int minimo, int maximo, int intentos);

/// @brief Pide un número flotante con una cantidad determinada de reintentos, en un rango determinado.
///
/// @param mensaje
/// @param numeroIngresado
/// @param minimo
/// @param maximo
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirFloatConRangoConReintentos(char mensaje[], float *numeroIngresado, int minimo, int maximo, int intentos);

/// @brief Pide un número entero con una cantidad determinada de reintentos.
///
/// @param mensaje
/// @param numeroIngresado
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirIntConReintentos(char mensaje[], int *numeroIngresado, int intentos);

/// @brief Pide un número flotante con una cantidad determinada de reintentos.
///
/// @param mensaje
/// @param numeroIngresado
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirFloatConReintentos(char mensaje[], float *numeroIngresado, int intentos);

/// @brief Pide un número entero que se encuentre en un rango determinado.
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return Retorna el número entero ingresado dentro del rango establecido.
int PedirIntConRango (char mensaje[], int minimo, int maximo);

/// @brief Pide un número flotante que se encuentre en un rango determinado.
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return Retorna el número flotante ingresado dentro del rango establecido.
float PedirFloatConRango (char mensaje[], float minimo, float maximo);

/// @brief Pide un número entero.
///
/// @param mensaje
/// @return Retorna el número entero ingresado.
int PedirInt (char mensaje[]);

/// @brief Pide un número flotante.
///
/// @param mensaje
/// @return Retorna el número flotante ingresado.
float PedirFloat (char mensaje[]);

/// @brief Función auxiliar. Verifica que el número ingresado cumpla con todas las propiedades correspondientes a un número entero.
///
/// @param numeroAVerificar
/// @return Retorna 1 si el número cumple con las condiciones de número entero, o 0 si no las cumple.
int VerificarInt(char numeroAVerificar[]);

/// @brief Función auxiliar. Verifica que el número ingresado se encuentre dentro del rango establecido.
///
/// @param numeroAVerificar
/// @param numeroADevolver
/// @param minimo
/// @param maximo
/// @return Retorna 1 si el número se encuentra dentro del rango o 0 si no cumple con esta condición.
int VerificarRangoInt(char numeroAVerificar[], int *numeroADevolver, int minimo, int maximo);

/// @brief Función auxiliar. Verifica que el número ingresado cumpla con todas las propiedades correspondientes a un número flotante.
///
/// @param numeroAVerificar
/// @return Retorna 1 si el número cumple con las condiciones de número entero, o 0 si no las cumple.
int VerificarFloat(char numeroAVerificar[]);

/// @brief Función auxiliar. Verifica que el número ingresado se encuentre dentro del rango establecido.
///
/// @param numeroAVerificar
/// @param numeroADevolver
/// @param minimo
/// @param maximo
/// @return Retorna 1 si el número se encuentra dentro del rango o 0 si no cumple con esta condición.
int VerificarRangoFloat(char numeroAVerificar[], float *numeroADevolver, float minimo, float maximo);
//--------------------------STRINGS----------------------------
/// @brief Función auxiliar para tomar cadenas de caracteres a través del buffer. Evita el desbordamiento de memoria.
///
/// @param string
/// @param len
/// @return Retorna -1 si la cadena ingresada por el usuario es más larga que la cadena donde el dato se almacenará, de lo contrario retorna 0.
int GetString(char string[], int len);

/// @brief Pide una cadena de caracteres, pudiendo ser un nombre o apellido en general, con una cantidad determinada de intentos.
/// El dato ingresado será una cadena que contenga su primer letra mayúscula, y el resto de las letras en minúscula.
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirNombreOApellidoConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres, pudiendo ser un nombre o apellido en general.
/// El dato ingresado será una cadena que contenga su primer letra mayúscula, y el resto de las letras en minúscula.
/// @param mensaje
/// @param cadena
/// @param tam
void PedirNombreOApellido(char mensaje[], char cadena[], int tam);

/// @brief Función auxiliar. Convierte la primer letra de una cadena de caracteres a mayúscula, y el resto de las letras en minúscula.
///
/// @param cadena
void EmprolijarPalabra(char cadena[]);

/// @brief Pide una cadena de caracteres que no contenga nada más que letras, con una determinada cantidad de reintentos.
///
/// @param mensaje
/// @param cadena
/// @param tam
/// @param intentos
/// @return Retorna 1 si se ingresó el número correctamente dentro de la cantidad de reintentos o 0 si hubo demasiados intentos fallidos.
int PedirCadenaSoloLetrasConReintentos(char mensaje[], char cadena[], int tam, int intentos);

/// @brief Pide una cadena de caracteres que no contenga nada más que letras.
///
/// @param mensaje
/// @param cadena
/// @param tam
void PedirCadenaSoloLetras(char mensaje[], char cadena[], int tam);

/// @brief Pide un caracter que solamente pueda ser una letra.
///
/// @param mensaje
/// @return Retorna la letra ingresada.
char PedirCaracterSoloLetra (char mensaje[]);

/// @brief Pide un caracter que solamente pueda ser una 's', 'S', 'n' o 'N'. Para confirmaciones.
///
/// @param mensaje
/// @return Retorna la letra ingresada.
char PedirCaracterSiONo (char mensaje[]);

/// @brief Función auxiliar. Verifica que en una cadena ingresada sólo se hayan ingresado caracteres de tipo letra.
///
/// @param cadena
/// @return Retorna 1 si el caracter solamente tiene letras, y 0 si no cumple con esa condición.
int VerificarCadenaSoloLetras(char cadena[]);



#endif /* INPUT_H_ */
