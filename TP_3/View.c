/*
 * View.c
 *
 *  Created on: 8 nov 2021
 *      Author: Raffi
 */

#include "View.h"


/// @brief Muestra mensajes determinados según el retorno del controller de carga de datos que llama
///
/// @param output
/// @param loadType
void view_returnsFromLoad(int output, char* loadType) {
	switch(output) {
		case -3:
			printf("Path o ArrayList nulo en carga de tipo: %s\n", loadType);
			break;

		case -2:
			printf("No se pudo abrir el archivo en carga de tipo: %s\n", loadType);
			break;

		case -1:
			printf("No se pudo cargar empleados a la lista en carga de tipo: %s\n", loadType);
			break;

		case 0:
			printf("Carga de datos desde archivo %s ejecutada exitosamente\n", loadType);
			break;
	}
}


/// @brief Muestra mensajes determinados según el retorno del controller de ABM que llama
///
/// @param output
/// @param ABMType
void view_returnsFromABM(int output, char* ABMType) {


	switch(output) {
		case -5:
			printf("No se pudo crear al nuevo empleado. ARCHIVO ID SIN PODER ACTUALIZAR\n");
			break;
		case -4:
			printf("LinkedList NULA o VACÍA en operación de tipo: %s\n", ABMType);
			break;

		case -3:
			if (!strcmp(ABMType, "ALTA")) {
				printf("No se puede acceder al archivo contenedor del último ID\n");
			} else {
				printf("Error en ingreso de ID en operación de tipo: %s\n", ABMType);
			}
			break;

		case -2:
			if (!strcmp(ABMType, "ALTA")) {
				printf("No se pudo crear al empleado\n");
			} else {
				printf("El empleado con ese ID no existe, en operación de tipo: %s\n", ABMType);
			}
			break;

		case -1:
			if (!strcmp(ABMType, "ALTA")) {
				printf("No se pudo agregar al empleado a la lista\n");
			} else if (!strcmp(ABMType, "MODIFICACION")) {
				printf("El empleado no ha sido modificado\n");
			} else {
				printf("Eliminación de empleado cancelada\n");
			}

			break;

		case 0:
			if (!strcmp(ABMType, "ALTA")) {
				printf("Empleado creado exitosamente\n");
			} else if (!strcmp(ABMType, "MODIFICACION")) {
				printf("Empleado modificado exitosamente\n");
			} else {
				printf("Empleado eliminado exitosamente\n");
			}
			break;
		}
}

/// @brief Muestra mensajes determinados según el retorno del controller de Sort que llama
///
/// @param output
/// @param ListOrSort
void view_returnsFromListSort(int output, char* ListOrSort) {

	switch (output) {
		case -2:
			printf("LinkedList nula en operación: %s\n", ListOrSort);
			break;

		case -1:
			printf("Operación de tipo %s falló\n", ListOrSort);
			break;

		case 0:
			printf("Operación de tipo %s se realizó exitosamente\n", ListOrSort);
			break;
	}
}


/// @brief Muestra mensajes determinados según el retorno del controller de guardado que llama
///
/// @param output
/// @param saveType
void view_returnsFromSave(int output, char* saveType) {

	switch(output) {
		case -3:
			printf("Path o ArrayList nulo en guardado de tipo: %s\n", saveType);
			break;

		case -2:
			printf("No se pudo abrir el archivo en guardado de tipo: %s\n", saveType);
			break;

		case -1:
			printf("No se pudo guardar empleados al archivo %s\n", saveType);
			break;

		case 0:
			printf("Guardado de datos a archivo de tipo %s ejecutada exitosamente\n", saveType);
			break;
	}

}

