/*
 * funcionesEntradaSalida.c
 *
 *  Created on: 5 sept 2021
 *      Author: Raffi
 */

#include "funcionesGenerales.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/// @brief Se muestra un menú predeterminado de una calculadora, el cual consta de 4 variantes, que
/// 	se mostrarán dependiendo de los parámetros ingresados.
///
/// @param Dato de tipo entero, representa un "flag" correspondiente a la primer opción del menú.
/// 	Cuando su estado es 0, el "primer operando" dentro del menu se muestra como "A=x".
/// 	Si su estado es 1, la "x" tomará el valor numérico que el usuario haya ingresado.
///
/// @param Dato de tipo entero, representa un "flag" flag correspondiente a la segunda opción del menú.
/// 	Cuando su estado es 0, el "segundo operando" dentro del menu se muestra como "B=y".
/// 	Si su estado es 1, la "y" tomará el valor numérico que el usuario haya ingresado.
///
/// @param Dato de tipo flotante que se usará para mostrar el valor del primer operando "A".
/// @param Dato de tipo flotante que se usará para mostrar el valor del segundo operando "B".
void MenuPrincipal(int banderaUno, int banderaDos, float numeroUno, float numeroDos) {

	if (banderaUno == 0 && banderaDos == 0) {

		printf ("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=y)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion(A*B) \n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n");

	} else if (banderaUno == 1 && banderaDos == 0) {

		printf ("1. Ingresar 1er operando (A=%.2f)\n"
					"2. Ingresar 2do operando (B=y)\n"
					"3. Calcular todas las operaciones\n"
					"a) Calcular la suma (A+B)\n"
					"b) Calcular la resta (A-B)\n"
					"c) Calcular la division (A/B)\n"
					"d) Calcular la multiplicacion (A*B)\n"
					"e) Calcular el factorial (A!)\n"
					"4. Informar resultados\n"
					"5. Salir\n", numeroUno);

	} else if (banderaUno == 0 && banderaDos == 1) {

		printf ("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=%.2f)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion (A*B)\n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n", numeroDos);
	} else {

		printf ("1. Ingresar 1er operando (A=%.2f)\n"
				"2. Ingresar 2do operando (B=%.2"
				"f)\n"
				"3. Calcular todas las operaciones\n"
				"a) Calcular la suma (A+B)\n"
				"b) Calcular la resta (A-B)\n"
				"c) Calcular la division (A/B)\n"
				"d) Calcular la multiplicacion (A*B)\n"
				"e) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"5. Salir\n", numeroUno, numeroDos);
	}
}

/// @brief Se verifica que un número flotante tenga decimales o es un número "redondo".
///
/// @param numeroIngresado El número a evaluar.
/// @return Se retorna 1 si tiene decimales o 0 si es un número "redondo".
int TieneDecimales(float numeroIngresado) {

	int numeroSinDecimales;
	int tieneDecimales;

	numeroSinDecimales = numeroIngresado;
	tieneDecimales = 1;

	numeroIngresado = numeroIngresado - numeroSinDecimales;

	if (numeroIngresado == 0) {
		tieneDecimales = 0;
	}

	return tieneDecimales;
}

/// @brief Se pide un número de tipo entero acompañado de un mensaje,
/// 	verificando que no se ingresen otros caracteres.
///
/// @param mensaje El mensaje a mostrar al usuario.
/// @return Se retorna el número que el usuario ingresó.
int PedirEntero (char mensaje[]) {
	char numeroAVerificar[15]; // el máximo de INT son 14 caracteres
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroAVerificar);

	while (!VerificarInt(numeroAVerificar)) {
		printf("ERROR! No se ingresó un número válido.\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroAVerificar);
	}

	numeroIngresado = atoi(numeroAVerificar);

	return numeroIngresado;
}

/// @brief Se pide un número de tipo flotante acompañado de un mensaje,
/// 	verificando que no se ingresen otros caracteres.
///
/// @param mensaje El mensaje a mostrar al usuario.
/// @return Se retorna el número que el usuario ingresó.
float PedirFlotante (char mensaje[]) {
	char numeroAVerificar[100];
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", numeroAVerificar);

	while (!VerificarFloat(numeroAVerificar)) {
		printf("ERROR! No se ingresó un número válido.\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", numeroAVerificar);
	}

	numeroIngresado = atof(numeroAVerificar);

	return numeroIngresado;

}

/// @brief Se verifica que la cadena de caracteres ingresada contenga
/// 	 caracteres que correspondan a un número entero.
///
/// @param numeroAVerificar El número a verificar.
/// @return Se retorna 1 si la cadena contiene caracteres que cumplen
/// 	con la condición, o se retorna 0 en el caso contrario.
int VerificarInt(char numeroAVerificar[]) {
	int esInt;
	int longitud;

	esInt = 1;
	longitud = strlen(numeroAVerificar);


	if (isdigit(numeroAVerificar[0]) || (numeroAVerificar[0] == '-' && longitud > 1)) {
		for(int i = 1; i < longitud; i++) {
				if (!isdigit(numeroAVerificar[i])) {
					esInt = 0;
					break;
				}
		}
	} else {
		esInt = 0;
	}

	return esInt;
}

/// @brief Se verifica que la cadena de caracteres ingresada contenga
/// 	caracteres que correspondan a un número flotante.
///
/// @param numeroAVerificar El número a verificar.
/// @return Se retorna 1 si la cadena contiene caracteres que cumplen con
/// 	la condición, o se retorna 0 en el caso contrario.
int VerificarFloat(char numeroAVerificar[]) {
	int esFloat;
	int contadorPuntos;
	int longitud;

	esFloat = 1;
	contadorPuntos = 0;
	longitud = strlen(numeroAVerificar);

	/*verificar que cadena empiece con número o símbolo negativo. que el símbolo negativo tenga "algo" después.
	si ese "algo" es un punto, que ese punto tenga "algo" después también*/
	if (isdigit(numeroAVerificar[0]) || (numeroAVerificar[0] == '-' && ((numeroAVerificar[1] != '.' && longitud > 1) || (numeroAVerificar[1] == '.' && longitud > 2)))) {
			for (int i = 1; i < longitud; i++) {
				if (!isdigit(numeroAVerificar[i])) { // no es un número
					if (numeroAVerificar[i] == '.') { // es un punto
						contadorPuntos++;
						if (contadorPuntos > 1) {
							esFloat = 0; // más de un punto = no es un float
							break;
						}
					} else {
						esFloat = 0; // no es número ni punto = no es un float
						break;
					}
				}
			} // fin bucle for
		} else {
			esFloat = 0; // si no empieza como un número o un negativo ni siquiera cicla
		}

	return esFloat;
}
