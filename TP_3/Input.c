/*
 * Input.c
 *
 *  Created on: 4 oct 2021
 *      Author: Raffi
 */

#include "Input.h"

//--------------------------NUMEROS----------------------------
int PedirIntConRangoConReintentosTexto(char numeroADevolverTexto[], char mensaje[], int minimo, int maximo, int intentos) {
	char numeroAVerificar[11];
	int retorno;

	retorno = 1;

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarInt(numeroAVerificar) ||
			!VerificarRangoIntTexto(numeroAVerificar, minimo, maximo))) {
			printf("ERROR! %s", mensaje);
			intentos--;
	}

	if (intentos > 0) {
		strncpy(numeroADevolverTexto, numeroAVerificar, sizeof(numeroAVerificar)); // si por algún motivo hacen un array con más posiciones yo igual sé que puedo contener hasta 10 en un int
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int PedirIntConRangoConReintentos(char mensaje[], int *numeroIngresado, int minimo, int maximo, int intentos) {
	char numeroAVerificar[11];
	int numeroIngresadoLocal;
	int retorno;

	retorno = 1;

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarInt(numeroAVerificar) ||
			!VerificarRangoInt(numeroAVerificar, &numeroIngresadoLocal, minimo, maximo))) {
			printf("ERROR! %s", mensaje);
			intentos--;
	}

	if (intentos > 0) {
		*numeroIngresado = numeroIngresadoLocal;
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int PedirFloatConRangoConReintentos(char mensaje[], float *numeroIngresado, int minimo, int maximo, int intentos) {
	char numeroAVerificar[11];
	float numeroIngresadoLocal;
	int retorno;

	retorno = 1;

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarFloat(numeroAVerificar) ||
			!VerificarRangoFloat(numeroAVerificar, &numeroIngresadoLocal, minimo, maximo))) {
			printf("ERROR! %s", mensaje);
			intentos--;
	}

	if (intentos > 0) {
		*numeroIngresado = numeroIngresadoLocal;
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int PedirIntConReintentos(char mensaje[], int *numeroIngresado, int intentos) {
	char numeroAVerificar[11];
	int retorno;

	retorno = 1; // Si el retorno se mantiene en 1 el usuario ingresó un número válido, si no, el retorno será 0

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarInt(numeroAVerificar))) {
		printf("ERROR! %s", mensaje);
		intentos--;
	}

	if (intentos > 0) {
		*numeroIngresado = atoi(numeroAVerificar);
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int PedirFloatConReintentos(char mensaje[], float *numeroIngresado, int intentos) {
	char numeroAVerificar[11];
	int retorno;

	retorno = 1; // Si el retorno se mantiene en 1 el usuario ingresó un número válido, si no, el retorno será 0

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarFloat(numeroAVerificar))) {
		printf("ERROR! %s", mensaje);
		intentos--;
	}

	if (intentos > 0) {
		*numeroIngresado = atof(numeroAVerificar);
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int PedirIntConRango (char mensaje[], int minimo, int maximo) {
	char numeroAVerificar[11];
	int numeroIngresado;
	//int verifOverflow;

	printf("%s", mensaje);
	//verifOverflow = GetString(numeroAVerificar, sizeof(numeroAVerificar));

	while ((GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarInt(numeroAVerificar)) ||
			!VerificarRangoInt(numeroAVerificar, &numeroIngresado, minimo, maximo)) {
		printf("ERROR! %s", mensaje);
		//verifOverflow = GetString(numeroAVerificar, sizeof(numeroAVerificar));
	}

	//numeroIngresado = atoi(numeroAVerificar);

	return numeroIngresado;
}

float PedirFloatConRango (char mensaje[], float minimo, float maximo) {
	char numeroAVerificar[20];
	float numeroIngresado;

	printf("%s", mensaje);

	while ((GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarFloat(numeroAVerificar)) ||
			!VerificarRangoFloat(numeroAVerificar, &numeroIngresado, minimo, maximo)) {
		printf("ERROR! %s", mensaje);
	}

	//numeroIngresado = atof(numeroAVerificar);

	return numeroIngresado;

}

int PedirInt (char mensaje[]) {
	char numeroAVerificar[11];
	int numeroIngresado;
	//int verifOverflow;

	printf("%s", mensaje);
	//verifOverflow = GetString(numeroAVerificar, sizeof(numeroAVerificar));

	while (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarInt(numeroAVerificar)) {
		printf("ERROR! %s", mensaje);
		//verifOverflow = GetString(numeroAVerificar, sizeof(numeroAVerificar));
	}

	numeroIngresado = atoi(numeroAVerificar);

	return numeroIngresado;
}

float PedirFloat (char mensaje[]) {
	char numeroAVerificar[20];
	float numeroIngresado;

	printf("%s", mensaje);

	while (GetString(numeroAVerificar, sizeof(numeroAVerificar)) == -1 || !VerificarFloat(numeroAVerificar)) {
		printf("ERROR! %s", mensaje);
	}

	numeroIngresado = atof(numeroAVerificar);

	return numeroIngresado;

}



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

int VerificarRangoInt(char numeroAVerificar[], int *numeroADevolver, int minimo, int maximo) {

	int enRango;
	int numeroTransformado;

	enRango = 0;
	numeroTransformado = atoi(numeroAVerificar);

	if (numeroTransformado >= minimo && numeroTransformado <= maximo) {
		enRango = 1;
		*numeroADevolver = numeroTransformado;
	}

	return enRango;
}

int VerificarRangoIntTexto(char numeroAVerificar[], int minimo, int maximo) {

	int enRango;
	int numeroTransformado;

	enRango = 0;
	numeroTransformado = atoi(numeroAVerificar);

	if (numeroTransformado >= minimo && numeroTransformado <= maximo) {
		enRango = 1;
	}

	return enRango;
}

int VerificarFloat(char numeroAVerificar[]) {
	int esFloat;
	int contadorPuntos;
	int longitud;

	esFloat = 1;
	contadorPuntos = 0;
	longitud = strlen(numeroAVerificar);

	/*verificar que cadena empiece con número, punto o símbolo negativo. que el punto o el símbolo negativo tenga "algo" después.
	si ese "algo" es un punto, que ese punto tenga "algo" después también*/
	if (isdigit(numeroAVerificar[0])  || (numeroAVerificar[0] == '.' && longitud > 1)
			|| (numeroAVerificar[0] == '-' && ((numeroAVerificar[1] != '.' && longitud > 1) || (numeroAVerificar[1] == '.' && longitud > 2)))) {
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

int VerificarRangoFloat(char numeroAVerificar[], float *numeroADevolver, float minimo, float maximo) {

	int enRango;
	float numeroTransformado;

	enRango = 0;
	numeroTransformado = atof(numeroAVerificar);

	if (numeroTransformado >= minimo && numeroTransformado <= maximo) {
		enRango = 1;
		*numeroADevolver = numeroTransformado;
	}

	return enRango;
}

//--------------------------STRINGS----------------------------
int GetString(char string[], int len) {

	int retorno;
	int longitud;
 	char stringLocal[100]; // bufferString. El tamaño fijo de acá es temporal (hay que aprender memoria dinámica)

 	retorno = -1;
 	longitud = sizeof(stringLocal);

	if (string != NULL && len > 0) {

		fflush(stdin);
		if(fgets(stringLocal, longitud, stdin) != NULL) {

			if(stringLocal[strnlen(stringLocal, longitud)-1] == '\n') {
				stringLocal[strnlen(stringLocal, longitud)-1] = '\0';
			}

			if(strnlen(stringLocal, longitud) <= len && strlen(stringLocal) > 0) {
				strncpy(string, stringLocal, len);
				retorno = 0;
			}
		}
	}

	return retorno;
}

// sirve para cualquier palabra básicamente, reemplaza funciones anteriores bastante similares
int PedirNombreConReintentos(char nombreADevolver[], int tamNombreADevolver, char mensaje[], int intentos) {
	char nombreAVerificar[128];
	int retorno;

	retorno = 1;

	printf("%s", mensaje);

	while (intentos > 0 && (GetString(nombreAVerificar, sizeof(nombreAVerificar)) == -1 || !VerificarNombre(nombreAVerificar))) {
			printf("ERROR! %s", mensaje);
			intentos--;
	}

	if (intentos > 0) {
		EmprolijarNombre(nombreAVerificar);
		strncpy(nombreADevolver, nombreAVerificar, sizeof(nombreAVerificar));
	} else {
		printf("\nDemasiados intentos fallidos. Ingreso de dato cancelado.\n");
		retorno = 0;
	}

	return retorno;
}

int VerificarNombre(char cadena[]) {

	int esNombre;
	int longitud;

	esNombre = 1;
	longitud = strlen(cadena);

	for (int i = 0; i < longitud; i++) {
		if ((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] != ' ')) {
			esNombre = 0;
		}
	}

	return esNombre;
}

void EmprolijarNombre(char cadena[]) {

	int longitud;

	longitud = strlen(cadena);
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);
	for(int i=0; i < longitud; i++){
		if(cadena[i] == ' ') {
			cadena[i+1] = toupper(cadena[i+1]);
	    }
	}
}

char PedirCaracterSoloLetra (char mensaje[]) {

	char caracterIngresado;


	printf("%s", mensaje);

	while (GetString(&caracterIngresado, sizeof(caracterIngresado)) == -1 || !isalpha(caracterIngresado)) {
		printf("ERROR! %s", mensaje);
	}

	return caracterIngresado;
}

char PedirCaracterSiONo (char mensaje[]) {

	char caracterIngresado;

	printf("%s", mensaje);

	while (GetString(&caracterIngresado, sizeof(caracterIngresado)) == -1 || (caracterIngresado != 's' &&  caracterIngresado != 'S' &&
			caracterIngresado != 'n' && caracterIngresado != 'N')) {
		printf("ERROR! %s", mensaje);
	}

	return caracterIngresado;
}
