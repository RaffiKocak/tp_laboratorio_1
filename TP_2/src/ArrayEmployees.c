/*
 * Employee.c
 *
 *  Created on: 4 oct 2021
 *      Author: Raffi
 */

#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len) {
	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
		for(int i=0; i<len; i++){
	        list[i].isEmpty = TRUE;
	    }
	}

	return retorno;
}

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector) {

	int posicion;

	posicion = BuscarEspacioLibre(list, len);

	if(list != NULL && len > 0) {
		if (posicion != -1) {
			list[posicion].id = id;
			strcpy(list[posicion].name, name);
			strcpy(list[posicion].lastName, lastName);
			list[posicion].salary = salary;
			list[posicion].sector = sector;
			list[posicion].isEmpty = FALSE;

			printf("Empleado cargado exitosamente\n");
		}
	}

	return posicion;
}

int findEmployeeById(Employee list[], int len, int id) {

	int posicion;

	posicion = -1;

	if (list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(list[i].id == id && !list[i].isEmpty) {
				posicion = i;
				break;
			}
		}
	}

	return posicion;
}

int removeEmployee(Employee list[], int len, int id) {

	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		if (id != -1 && !list[id].isEmpty) {
			list[id].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

int sortEmployees(Employee list[], int len, int order)
{
	int retorno;
	Employee aux;

	retorno = -1;

	if (list != NULL && len > 0) {

		retorno = 0;

		//if (VerificarArrayCargado(list, len)) { // No haría falta porque la función "MostrarSubMenuInformes" que implementa esta función
													//ya realiza la verificación antes de ejecutar esta función
			if (order) { // ASCENDENTE
				for (int i = 0; i < len -1; i++) {
						for (int j = i+1; j < len; j++) {
							if (strcmp(list[i].lastName, list[j].lastName) > 0 ||
									(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector)) {
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							} /*else if (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector) {
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}*/
						}
				}
			} else { // DESCENDENTE
				for (int i = 0; i < len -1; i++) {
					for (int j = i+1; j < len; j++) {
						if (strcmp(list[i].lastName, list[j].lastName) < 0 ||
								(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						} /*else if (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}*/
					}
				}
			}
	//	} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
	//		printf("No hay empleados en la lista");
	//	}
	} // FIN IF VERIF. ARRAY NO SEA NULL ETC

	return retorno;
}

int printEmployees(Employee list[], int len) {

	int retorno;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;

	//	if (VerificarArrayCargado(list, len)) { // No haría falta porque la función "MostrarSubMenuInformes" que implementa esta función
												//ya realiza la verificación antes de ejecutar esta función
			printf("---------------------------------------------------------------------------------\n");
			printf("ID\t\tNombre\t\tApellido\t\tSalario\t\tSector\n");
			for(int i = 0; i < len; i++) {
				if (!list[i].isEmpty) {
					PrintEmployeeIndividual(list[i]);
				}
			}
			printf("---------------------------------------------------------------------------------\n");
	//	} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
	//		printf("La lista de empleados está vacía");
	//	}
	}

	return retorno;
}

int MostrarMenuPrincipal(Employee list[], int len, int *contadorDeID) {

	int retorno;
	int opcionIngresada;

	retorno = -1;

	if (list != NULL && len > 0) {

		retorno = 0;
		do{
				printf("-------------------------------------------------\n");
				printf("[1] Alta de empleados\n"
						"[2] Modificar empleado\n"
						"[3] Baja de empleados\n"
						"[4] Informes\n"
						"[5] Salir del sistema\n");
				printf("-------------------------------------------------\n");
				opcionIngresada = PedirInt("Ingrese qué desea hacer: ");
				printf("-------------------------------------------------\n");

				switch(opcionIngresada) {
					case 1:
						AltaEmployee(list, 6, contadorDeID);
						break;

					case 2:
						EditEmployee(list, 6);
						break;

					case 3:
						BajaEmployee(list, 6);
						break;

					case 4:
						MostrarSubMenuInformes(list, 6);
						break;

					case 5:
						printf("Todos los empleados que estaban aquí desaparecerán, pero gracias por usar este sistema!");
						break;

					default:
						printf("Opción incorrecta, por favor reingrese.\n");
						break;
				}
			} while(opcionIngresada != 5);
	} // FIN IF VERIF. ARRAY NO SEA NULL ETC

	return retorno;
}

int EditEmployee(Employee list[], int len) {

	int retorno;
	int idABuscar;
	int posicionAEditar;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
		if (VerificarArrayCargado(list, len)) {
			if (PedirIntConReintentos("Ingrese el ID del empleado a modificar: ", &idABuscar, 3)){

				posicionAEditar = findEmployeeById(list, len, idABuscar);

				if (posicionAEditar != -1) {
					MostrarSubMenuEdit(list, len, posicionAEditar);
					printf("Los datos del empleado con ID Nª %d son: \n", idABuscar);
					printf("---------------------------------------------------------------------------------\n");
					printf("ID\t\tNombre\t\tApellido\t\tSalario\t\tSector\n");
					PrintEmployeeIndividual(list[posicionAEditar]);
				} else { // ELSE POSICION A EDITAR =! -1
					printf("No existe un empleado con ese ID\n");
				}
			} else { // ELSE INGRESAR ID CON REINT.
				printf("Error en carga de datos, regresando al menú principal...\n");
			}
		} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
			printf("No hay empleados para editar.\n");
		}
	} // FIN IF VERIF. ARRAY NO SEA NULL ETC
	return retorno;
}

int AltaEmployee(Employee list[], int len, int *idPrincipal) {
	int retorno;
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	retorno = -1;

	if (list != NULL && len > 0) {

		retorno = 0;

		if (BuscarEspacioLibre(list, len) != -1) { // Si pudiera pasaría la posición por parámetro a la función "addEmployee", así no la llamo ahí adentro también
									// Con el uso de esta función, no tengo que cargar los datos innecesariamente para después enterarme que el array está lleno
			if (PedirNombreOApellidoConReintentos("Ingrese nombre: ", name, sizeof(name), 3) &&
					PedirNombreOApellidoConReintentos("Ingrese apellido: ", lastName, sizeof(lastName), 3) &&
					PedirFloatConRangoConReintentos("Ingrese salario [1000 - 30000]: ", &salary, 1000, 30000, 3)) {

				printf("[1] Jefatura\n"
						"[2] Comercial\n"
						"[3] Inspectores\n");
				if (PedirIntConRangoConReintentos("Ingrese sector: ", &sector, 1, 3, 3)){
					addEmployee(list, len, *idPrincipal, name, lastName, salary, sector);
					*idPrincipal += 1;
				} else { // ELSE SEGUNDO IF CON EL ÚLTIMO DATO
					printf("Error en carga de datos.\n");
				}
			} else { // ELSE PRIMER IF CON LOS PRIMEROS 3 DATOS
				printf("Error en carga de datos.\n");
			}
		} else { // ELSE VERIF. ARRAY LLENO (BuscarEspacioLibre)
			printf("La lista de empleados está llena.\n");
		}
	}

	return retorno;
}

int BajaEmployee(Employee list[], int len) {

	int retorno;
	int idABorrar;
	int posicionABorrar;
	char confirmacion;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
		if (VerificarArrayCargado(list, len)){
			idABorrar = PedirInt("Ingrese el ID del empleado a dar de baja: ");
			posicionABorrar = findEmployeeById(list, len, idABorrar);

			if (posicionABorrar != -1) {
				printf("Empleado a borrar: \n");
				PrintEmployeeIndividual(list[posicionABorrar]);
				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea borrar al empleado?\n[S] Si\n[N] No\nRespuesta: "));

				if (confirmacion == 's') {
					removeEmployee(list, len, posicionABorrar);
					printf("El empleado se ha eliminado exitosamente.\n");
				} else {
					printf("Eliminación cancelada.\n");
				}
			} else { // ELSE POSICION A BORRAR =! -1
				printf("No existe un empleado con ese ID\n");
			}
		} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
			printf("No existen empleados para borrar.\n");
		}
	}

	return retorno;
}

int InformarSalarios(Employee list[], int len) {

	int retorno;
	float promedioSalarios;
	float totalSalarios;
	int contadorEmpleadosArribaPromedio;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
	//	if (VerificarArrayCargado(list, len)) { // No haría falta porque la función "MostrarSubMenuInformes" que implementa esta función
												//ya realiza la verificación antes de ejecutar esta función
			contadorEmpleadosArribaPromedio = 0;

			PromediarSalarios(list, len, &totalSalarios, &promedioSalarios);

			for (int i = 0; i < len; i++) { // Cuenta cuántos empleados superan el salario promedio
				if (!list[i].isEmpty && (list[i].salary > promedioSalarios)){
					contadorEmpleadosArribaPromedio++;
				}
			}

			printf("-----------------------------\n");
			printf("La suma total de todos los salarios es %.2f\n", totalSalarios);
			printf("El promedio de los salarios es %.2f\n", promedioSalarios);
			printf("La cantidad de empleados que tienen un salario mayor al promedio es %d\n", contadorEmpleadosArribaPromedio);
			printf("-----------------------------\n");
	//	} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
	//		printf("No hay empleados cargados\n");
	//	}
	}

	return retorno;

}

int PromediarSalarios(Employee list[], int len, float *totalSalarios, float *promedioSalarios) {

	int retorno;
	float totalSalariosLocal;
	float promedioSalariosLocal;
	int contadorEmpleados;

	retorno = -1;

	if (list != NULL && len > 0) {

		totalSalariosLocal = 0;
		contadorEmpleados = 0;
		retorno = 0;

			for (int i = 0; i < len; i++) {
				if (!list[i].isEmpty) {
					totalSalariosLocal += list[i].salary;
					contadorEmpleados++;
				}
			}

			promedioSalariosLocal = totalSalariosLocal / contadorEmpleados;

			*totalSalarios = totalSalariosLocal;
			*promedioSalarios = promedioSalariosLocal;

		}

	return retorno;
}

int MostrarSubMenuInformes (Employee list[], int len) {

	int retorno;
	char opcionSubMenu;

	retorno = -1;

	if (list != NULL && len > 0) {
		retorno = 0;
		if (VerificarArrayCargado(list, len)) {

			do{
				printf("[A] Mostrar lista de empleados.\n"
						"[B] Ordenar empleados ascendente.\n"
						"[C] Ordenar empleados descendente.\n"
						"[D] Reporte de salarios.\n"
						"[E] Volver al menú principal\n");
				printf("-------------------------------------------------\n");
				opcionSubMenu = tolower(PedirCaracterSoloLetra("Ingrese la acción que desea realizar: "));
				printf("-------------------------------------------------\n");

				switch (opcionSubMenu) {
					case 'a':
						printEmployees(list, len);
						break;

					case 'b':
						sortEmployees(list, len, 1);
						printf("Empleados ordenados por apellido ASCENDENTE satisfactoriamente.\n");
						break;

					case 'c':
						sortEmployees(list, len, 0);
						printf("Empleados ordenados por apellido DESCENDENTE satisfactoriamente.\n");
						break;

					case 'd':
						InformarSalarios(list, len);
						break;

					case 'e':
						printf("Volviendo al menú principal...\n");
						break;

					default:
						printf("Opción no válida! Por favor reingrese.\n");
				}
			} while (opcionSubMenu != 'e');

		} else { // ELSE VERIF. EXISTENCIA EMPLEADOS
			printf("No hay empleados cargados para realizar informes.\n");
		}
	} // FIN IF VERIF. ARRAY NO SEA NULL ETC

	return retorno;
}

int MostrarSubMenuEdit (Employee list[], int len, int posicionAEditar) {

	int retorno;
	int opcionMenuEditar;

	retorno = -1;

	if (list != NULL && len > 0) { // para lo único que sirve len en esta función es para verificar el largo del array acá
		retorno = 0;
		do {
			printf("---------------------------------------------------------------------------------\n");
			printf("ID\t\tNombre\t\tApellido\t\tSalario\t\tSector\n");
			PrintEmployeeIndividual(list[posicionAEditar]);
			printf("---------------------------------------------------------------------------------\n");
			printf("-----------------------------\n"
					"Modificar Empleado\n"
					"-----------------------------\n"
					"[A] Modificar nombre\n"
					"[B] Modificar apellido\n"
					"[C] Modificar salario\n"
					"[D] Modificar sector\n"
					"[E] Volver al menú principal\n");
			opcionMenuEditar = tolower(PedirCaracterSoloLetra("Ingrese una opción para modificar: "));

			switch(opcionMenuEditar) {
				case 'a':
				printf("Nombre actual: %s\n", list[posicionAEditar].name);
				if (PedirNombreOApellidoConReintentos("Ingrese nombre modificado: ", list[posicionAEditar].name, sizeof(list[posicionAEditar].name), 3)) {
					printf("Nombre actualizado: %s\n", list[posicionAEditar].name);
				} else {
					printf("Dato inválido, operación cancelada.\n");
				}
					break;

				case 'b':
				printf("Apellido actual: %s\n", list[posicionAEditar].lastName);
				if (PedirNombreOApellidoConReintentos("Ingrese apellido modificado: ", list[posicionAEditar].lastName, sizeof(list[posicionAEditar].lastName), 3)) {
					printf("Apellido actualizado: %s\n", list[posicionAEditar].lastName);
				} else {
					printf("Dato inválido, operación cancelada.\n");
				}
					break;

				case 'c':
					printf("Salario actual: %.2f\n", list[posicionAEditar].salary);
					if (PedirFloatConRangoConReintentos("Ingrese el salario modificado del empleado: ", &list[posicionAEditar].salary, 1, 300000, 3)) {
						printf("Salario actualizado: %.2f\n", list[posicionAEditar].salary);
					} else {
						printf("Dato inválido, operación cancelada.\n");
					}
						break;

				case 'd':
					printf("Sector actual: %d\n", list[posicionAEditar].sector);
					if (PedirIntConRangoConReintentos("Ingrese nuevo sector del empleado: ", &list[posicionAEditar].sector, 1, 3, 3)) {
						printf("Sector actualizado: %d\n", list[posicionAEditar].sector);
					} else {
						printf("Dato inválido, operación cancelada.\n");
					}
					break;

				case 'e':
					printf("Edición de empleado terminada.\n");
					break;

				default:
				printf("Opción no válida, intente nuevamente por favor.\n");
					break;
				}
		} while (opcionMenuEditar != 'e');

	}
	return retorno;

}

int BuscarEspacioLibre(Employee list[], int len) {
	int posicionLibre;

	posicionLibre = -1;

	if (list != NULL && len > 0) {
		for(int i=0 ; i < len ; i++) {
			if(list[i].isEmpty) {
				posicionLibre = i;
				break;
			}
		}
	}

	return posicionLibre;
}

int VerificarArrayCargado(Employee list[], int len) {
	int estaCargado;

	estaCargado = 0;

	if (list != NULL && len > 0) {
		for(int i=0 ; i < len ; i++) {
			if(!list[i].isEmpty) {
				estaCargado = 1;
				break;
			}
		}
	}
	return estaCargado;
}

void PrintEmployeeIndividual (Employee employee) {
	printf("---------------------------------------------------------------------------------\n");
	printf("%-15d %-15s %-23s %-15.2f %d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

void HardcodearEmpleados (Employee lista[], int tam) {

	Employee hardcode[] = {
	    {10, "Chayanne", "Figueroa", 12.34, 1, 0},
	    {11, "Antonio", "Rios", 55.55, 3, 0},
		{12, "Ricky", "Martin", 33.3, 5, 0},
	    {13, "Britney", "Spears", 1234, 2, 0},
	    {14, "Christina", "Aguilera", 500, 1, 0},
		{15, "Travis", "Baker", 500, 1, 0}
	};

	for (int i = 0; i < 6; ++i) {
		lista[i] = hardcode[i];
	}
}
