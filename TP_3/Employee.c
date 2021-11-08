
#include "Employee.h"

//----------------------------------------CONSTRUCTORES------------------------------------------------

Employee* employee_new() {
	Employee* pNuevoEmpleado;

	pNuevoEmpleado = NULL;
	pNuevoEmpleado = (Employee*) calloc(sizeof(Employee), 1);

	return pNuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {

	Employee* pNuevoEmpleado;
	int auxID;
	int auxHoras;
	int auxSueldo;

	pNuevoEmpleado = NULL;
	pNuevoEmpleado = employee_new();

	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL) {
		auxID = atoi(idStr);
		auxHoras = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldoStr);

		employee_setId(pNuevoEmpleado, auxID);
		employee_setNombre(pNuevoEmpleado, nombreStr);
		employee_setHorasTrabajadas(pNuevoEmpleado, auxHoras);
		employee_setSueldo(pNuevoEmpleado, auxSueldo);

		// usar empleado local auxiliar > si los setters salen bien, igualar
	}

	return pNuevoEmpleado;
}

//----------------------------------------DESTRUCTORES------------------------------------------------

void employee_delete(Employee* this) {
	if (this != NULL) {
		free(this);
	}
}

void employee_deleteAll(LinkedList* pArrayListEmployee) {
	Employee* this;
	int longitud;

	if (pArrayListEmployee != NULL) {
		longitud = ll_len(pArrayListEmployee);
		for (int i = 0; i < longitud; i++) {
			this = (Employee*) ll_get(pArrayListEmployee, i);
			free(this);
		}
	}
}

//----------------------------------------GETTERS Y SETTERS------------------------------------------------

int employee_setId(Employee* this, int id) {
	int retorno;

	retorno = -1;

	if (id >= 0 && this != NULL) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this, int* id) {
	int retorno;

	retorno = -1;

	if (id != NULL && this != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre) {
	int retorno;

	retorno = -1;

	if (nombre != NULL && strlen(nombre) > 0 && this != NULL) {
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}

	return retorno;
}
int employee_getNombre(Employee* this, char* nombre) {
	int retorno;

	retorno = -1;

	if (nombre != NULL && this != NULL) {
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas) {
	int retorno;

	retorno = -1;

	if (horasTrabajadas >= 0 && this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas) {
	int retorno;

	retorno = -1;

	if (horasTrabajadas != NULL && this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo) {
	int retorno;

	retorno = -1;

	if (sueldo >= 0 && this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this, int* sueldo) {
	int retorno;

	retorno = -1;

	if (sueldo != NULL && this != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo) {
	int retorno;

	retorno = -1; // si el puntero es nulo o algún setter falla

	if (this != NULL &&
		!employee_setId(this, id) &&
		!employee_setNombre(this, nombre) &&
		!employee_setHorasTrabajadas(this, horasTrabajadas) &&
		!employee_setSueldo(this, sueldo)) {

		retorno = 0; // OK
	}

	return retorno;
}

int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo) {
	int retorno;

	retorno = -1; // si el puntero es nulo o algún getter falla

	if (this != NULL &&
			!employee_getId(this, id) &&
			!employee_getNombre(this, nombre) &&
			!employee_getHorasTrabajadas(this, horasTrabajadas) &&
			!employee_getSueldo(this, sueldo)) {

		retorno = 0; // OK
	}

	return retorno;
}


//----------------------------------------PRINT------------------------------------------------
void employee_imprimirEmployee(Employee* this) {
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;

	if (!employee_getAll(this, &auxId, auxNombre, &auxHorasTrabajadas, &auxSueldo)) {
		printf("%d --- %s --- %d --- %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
	}
}

void employee_printSubMenuEdit() {
	printf("-----------------------------\n"
			"Modificar empleado\n"
			"-----------------------------\n"
			"[A] Modificar nombre\n"
			"[B] Modificar horas trabajadas\n"
			"[C] Modificar salario\n"
			"[D] Volver al menú principal\n");
}

void employee_printSubMenuSort() {
	printf("-----------------------------\n"
			"Ordenar lista empleados\n"
			"-----------------------------\n"
			"[A] Ordenar por ID\n"
			"[B] Ordenar por nombre\n"
			"[C] Ordenar por horas trabajadas\n"
			"[D] Ordenar por salario\n"
			"[E-Z] Volver al menú principal\n");
}

//----------------------------------------ADD Y EDIT------------------------------------------------

Employee* employee_create(char* idParaAsignar) {
	Employee* pEmployee;
	char auxNombre[128];
	char auxHorasTrabajadas[11];
	char auxSueldo[11];

	pEmployee = NULL;

	if (PedirNombreConReintentos(auxNombre, sizeof(auxNombre), "Ingrese nombre del nuevo empleado: ", 3) &&
		PedirIntConRangoConReintentosTexto(auxHorasTrabajadas, "Ingrese la cantidad de horas trabajadas [0 - 500]: ", 0, 500, 3) &&
		PedirIntConRangoConReintentosTexto(auxSueldo, "Ingrese el sueldo [1000 - 100000]: ", 1000, 100000, 3)) {

		pEmployee = employee_newParametros(idParaAsignar, auxNombre, auxHorasTrabajadas, auxSueldo);
	}

	return pEmployee;
}

int employee_edit(Employee* pEmployeeAModificar) {
	int retorno;
	char opcionMenu;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo; // estos 2 aux int podrían ser uno solo. lo dejo así por el bien de que se entienda

	retorno = -1;

	//if (pEmployeeAModificar != NULL) { // creo que no haría falta, viene verificado de arriba
		// CAMBIAR RETORNO, SI ES QUE EL IF VA
		do {
			employee_printSubMenuEdit();

			opcionMenu = tolower(PedirCaracterSoloLetra("Ingrese una opción para editar al empleado: "));
			switch(opcionMenu) {
				case 'a':
					if (PedirNombreConReintentos(auxNombre, sizeof(auxNombre), "Ingrese el nombre que desea asignar: ", 3)) {
						employee_setNombre(pEmployeeAModificar, auxNombre);
						retorno = 0;
					}
				break;

				case 'b':
					if (PedirIntConRangoConReintentos("Ingrese la cantidad de horas trabajadas [0 - 500]: ", &auxHorasTrabajadas, 0, 500, 3)) {
						employee_setHorasTrabajadas(pEmployeeAModificar, auxHorasTrabajadas);
						retorno = 0;
					}
				break;

				case 'c':
					if (PedirIntConRangoConReintentos("Ingrese el nuevo sueldo: ", &auxSueldo, 1000, 100000, 3)) {
						employee_setSueldo(pEmployeeAModificar, auxSueldo);
						retorno = 0;
					}
				break;

				case 'd':
					printf("Volviendo al menú principal...\n");
				break;

				default:
					printf("Ingrese una opción válida por favor\n");
					break;
			}
		} while (opcionMenu != 'd');
	//}
	return retorno;
}

//----------------------------------------FIND------------------------------------------------

int employee_findById(LinkedList* pArrayListEmployee, int idABuscar) {
    int retorno;
    int auxId;
    int longitud;

    Employee* pEmpleado;
    longitud = ll_len(pArrayListEmployee);
    retorno = -1;

    for(int i = 0; i < longitud; i++){
        pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
        if(!employee_getId(pEmpleado, &auxId) && auxId == idABuscar){
            retorno = i;
            break;
        }
    }
    return retorno;
}

//----------------------------------------SORT Y COMPARACIONES------------------------------------------------

int employee_sortEmployees(LinkedList* pArrayListEmployee, int opcionIngresada) {
	int retorno;
	int orden;

	retorno = -1;

	switch(opcionIngresada) {
		case 'a':
			orden = PedirIntConRango("[0] Orden descendente\n[1] Orden ascendente\n Orden: ", 0, 1);
			if (orden == 1 || orden == 0) {
				printf("Ordenando...\n");
				ll_sort(pArrayListEmployee, employee_compareById, orden);
				retorno = 0;
			}
			break;

		case 'b':
			orden = PedirIntConRango("[0] Orden descendente\n[1] Orden ascendente", 0, 1);
			if (orden == 1 || orden == 0) {
				printf("Ordenando...\n");
				ll_sort(pArrayListEmployee, employee_compareByNombre, orden);
				retorno = 0;
			}
			break;

		case 'c':
			orden = PedirIntConRango("[0] Orden descendente\n[1] Orden ascendente", 0, 1);
			if (orden == 1 || orden == 0) {
				printf("Ordenando...\n");
				ll_sort(pArrayListEmployee, employee_compareByHoras, orden);
				retorno = 0;
			};
			break;

		case 'd':
			orden = PedirIntConRango("[0] Orden descendente\n[1] Orden ascendente", 0, 1);
			if (orden == 1 || orden == 0) {
				printf("Ordenando...\n");
				ll_sort(pArrayListEmployee, employee_compareBySueldo, orden);
				retorno = 0;
			}
			break;

		default:
			printf("Volviendo al menú principal.\n");
			break;
	}

	return retorno;
}

int employee_compareById(void* primerEmpleado, void* segundoEmpleado) {
	int comparacion;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int idUno;
	int idDos;

	comparacion = 0;

	if (primerEmpleado != NULL && segundoEmpleado != NULL) {
		pPrimerEmpleado = (Employee*) primerEmpleado;
		pSegundoEmpleado = (Employee*) segundoEmpleado;

		employee_getId(pPrimerEmpleado, &idUno);
		employee_getId(pSegundoEmpleado, &idDos);

		if (idUno > idDos) {
			comparacion = 1;
		} else if (idUno < idDos) {
			comparacion = -1;
		}
	}

	return comparacion;
}

int employee_compareByNombre(void* primerEmpleado, void* segundoEmpleado) {
	int comparacion;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	char nombreUno[128];
	char nombreDos[128];

	comparacion = 0;

	if (primerEmpleado != NULL && segundoEmpleado != NULL) {
		pPrimerEmpleado = (Employee*) primerEmpleado;
		pSegundoEmpleado = (Employee*) segundoEmpleado;

		employee_getNombre(pPrimerEmpleado, nombreUno);
		employee_getNombre(pSegundoEmpleado, nombreDos);

		comparacion = strcmp(nombreUno, nombreDos);
	}

	return comparacion;
}

int employee_compareByHoras(void* primerEmpleado, void* segundoEmpleado) {
	int comparacion;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int horasUno;
	int horasDos;

	comparacion = 0;

	if (primerEmpleado != NULL && segundoEmpleado != NULL) {
		pPrimerEmpleado = (Employee*) primerEmpleado;
		pSegundoEmpleado = (Employee*) segundoEmpleado;

		employee_getHorasTrabajadas(pPrimerEmpleado, &horasUno);
		employee_getHorasTrabajadas(pSegundoEmpleado, &horasDos);

		if (horasUno > horasDos) {
			comparacion = 1;
		} else if (horasUno < horasDos) {
			comparacion = -1;
		}
	}

	return comparacion;
}

int employee_compareBySueldo(void* primerEmpleado, void* segundoEmpleado) {
	int comparacion;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int sueldoUno;
	int sueldoDos;

	comparacion = 0;

	if (primerEmpleado != NULL && segundoEmpleado != NULL) {
		pPrimerEmpleado = (Employee*) primerEmpleado;
		pSegundoEmpleado = (Employee*) segundoEmpleado;

		employee_getSueldo(pPrimerEmpleado, &sueldoUno);
		employee_getSueldo(pSegundoEmpleado, &sueldoDos);

		if (sueldoUno > sueldoDos) {
			comparacion = 1;
		} else if (sueldoUno < sueldoDos) {
			comparacion = -1;
		}
	}
	return comparacion;
}
