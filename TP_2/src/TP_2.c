/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 6

int main(void) {

	setbuf(stdout, NULL);

	int contadorId;
	Employee arrayEmployees[TAM];

	contadorId = 1;

	if (!initEmployees(arrayEmployees, TAM)) {
		//HardcodearEmpleados(arrayEmployees, 6);
		printf("Bienvenido a la empresa efímera\n");
		MostrarMenuPrincipal(arrayEmployees, TAM, &contadorId);
	}

	return EXIT_SUCCESS;
}
