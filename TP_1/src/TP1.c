/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcionesAritmeticas.h"
#include "funcionesGenerales.h"

#define TRUE 1
#define FALSE 0

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	setbuf(stdout, NULL);

	// variables pricipales
	int opcion;
	float numeroUno;
	float numeroDos;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;

	//variables resultado
	float suma;
	float resta;
	float division;
	float multiplicacion;
	int factorialUno;
	int factorialDos;

	//inicialización de variables que hagan falta
	banderaOpcionUno = FALSE;
	banderaOpcionDos = FALSE;
	banderaOpcionTres = FALSE;

	printf("Bienvenido/a a la CalcuRaffi 2000! (patente pendiente)\n");
	do {
		printf("-------------------------------------------------\n");
		MenuPrincipal(banderaOpcionUno, banderaOpcionDos, numeroUno, numeroDos);
		printf("-------------------------------------------------\n");
		opcion = PedirEntero("Ingrese opción: ");
		printf("-------------------------------------------------\n");

		switch (opcion) {
			case 1: //----------------OPCION 1---------------
				numeroUno = PedirFlotante("Ingrese el número A: ");

				banderaOpcionUno = TRUE;
				break;

			case 2: //----------------OPCION 2---------------
				numeroDos = PedirFlotante("Ingrese el número B: ");

				banderaOpcionDos = TRUE;
				break;

			case 3: //----------------OPCION 3---------------
				if (banderaOpcionUno == TRUE && banderaOpcionDos == TRUE) {
					printf("Calculando operaciones...\n");
					suma = SumarDosNumeros(numeroUno, numeroDos);

					resta = RestarDosNumeros(numeroUno, numeroDos);

					division = DividirDosNumeros(numeroUno, numeroDos);

					multiplicacion = MultiplicarDosNumeros(numeroUno, numeroDos);

					factorialUno = FactorialUnNumero(numeroUno);

					factorialDos = FactorialUnNumero(numeroDos);

					banderaOpcionTres = TRUE;

					printf("Cálculos realizados!\n");
				} else {
					printf("Ingrese ambos números para poder operar correctamente \n");
				}

				break;

			case 4: //----------------OPCION 4---------------
				if (banderaOpcionTres == TRUE) {
					printf("a) El resultado de %.2f + %.2f es: %.2f\n", numeroUno, numeroDos, suma);
					printf("b) El resultado de %.2f - %.2f es: %.2f\n", numeroUno, numeroDos, resta);

					if (numeroDos != 0) {
						printf("c) El resultado de %.2f / %.2f es: %.2f\n", numeroUno, numeroDos, division);
					} else {
						printf("c) No es posible dividir por cero\n");
					}

					printf("d) El resultado de %.2f * %.2f es: %.2f\n", numeroUno, numeroDos, multiplicacion);

					if (factorialUno != 0) {
						printf("e) El factorial de %.2f es %d", numeroUno, factorialUno);
					} else {
						printf("e) No es posible calcular el factorial de %.2f", numeroUno);
					}

					if (factorialDos != 0) {
						printf(" y el factorial de %.2f es %d\n", numeroDos, factorialDos);
					} else {
						printf(" y no es posible calcular el factorial de %.2f\n", numeroDos);
					}
				} else {
					printf ("Aún no se calcularon los resultados.\n");
				}

				break;

			case 5: //----------------OPCION 5---------------
				printf("Gracias por utilizar la CalcuRaffi 2000!(patente pendiente)\n");
				break;

			default: //----------------OPCION OTRA---------------
				printf("Opción inválida! Por favor ingrese una opción del 1 al 5\n");
				break;
		}


	} while (opcion != 5);

	return EXIT_SUCCESS;
}
