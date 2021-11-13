
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o arraylist NULL

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2; // no pudo abrir el file
		pFile = fopen(path, "r");

		if (pFile != NULL) {
			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o arraylist NULL

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2; // no pudo abrir el file
		pFile = fopen(path, "rb");

		if (pFile != NULL) {
			retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pNuevoEmpleado;
	char idParaAsignar[11];

	retorno = -4;
	if (pArrayListEmployee != NULL) {
		retorno = -3;

		if (!ObtenerUltimoId("ultimoId.csv", idParaAsignar) && !IncrementarUltimoId(idParaAsignar)) { // obtengo el último ID del archivo y lo incremento en 1
			retorno = -2;

			pNuevoEmpleado = employee_create(idParaAsignar);
			if (pNuevoEmpleado != NULL) {
				retorno = -5;
				if (!ActualizarUltimoId("ultimoId.csv", idParaAsignar)) {
					retorno = ll_add(pArrayListEmployee, pNuevoEmpleado);
				} else {
					employee_delete(pNuevoEmpleado); // si no pude actualizar el ID, borro al empleado. no tiene sentido agregarlo si no puedo tener seguimiento del ID
				}
			}
		}
	}
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleadoAModificar;
	int idAModificar;
	int indiceAModificar;

	retorno = -4; // linkedlist nula o vacía

	if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {

		retorno = -3; // error en ingreso de datos ID
		if (PedirIntConRangoConReintentos("Ingrese ID del empleado a modificar: ", &idAModificar, 1, 1000, 3)) { // 1000 después va a ser "ID Máximo"
			// hacer lo que hice en el parcial c/ localidades
			retorno = -2; // error, no se encuentra el empleado
			indiceAModificar = employee_findById(pArrayListEmployee, idAModificar);
			if (indiceAModificar != -1) {
				pEmpleadoAModificar = (Employee*) ll_get(pArrayListEmployee, indiceAModificar); // no verifico que sea != NULL porque prácticamente lo hizo el if de arriba
				employee_printEmployee(pEmpleadoAModificar);
				retorno = employee_edit(pEmpleadoAModificar); // -1 si no se modificó el empleado, 0 si se modificó
			}
		}
	}
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleadoABorrar;
	int idABorrar;
	int indiceABorrar;
	char confirmacion;

	retorno = -4;

	if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
		retorno = -3;

		if (PedirIntConRangoConReintentos("Ingrese ID del empleado a borrar: ", &idABorrar, 1, 1000, 3)) {

			retorno = -2;
			indiceABorrar = employee_findById(pArrayListEmployee, idABorrar);
			if (indiceABorrar != -1) {

				pEmpleadoABorrar = (Employee*) ll_get(pArrayListEmployee, indiceABorrar);
				employee_printEmployee(pEmpleadoABorrar);
				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea dar de baja al siguiente empleado?\n[S] Si\n[N] No\n"));

				if (confirmacion == 's') {
					ll_remove(pArrayListEmployee, indiceABorrar); // borro el nodo
					employee_delete(pEmpleadoABorrar); // borro el dato (ya que no va a ser usado para otra lista)
					retorno = 0;
				} else {
					retorno = -1;
				}
			}
		}
	}


    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* auxEmployee;
	int len;

	retorno = -2;
	len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee != NULL && len > 0) {

		if (len > 0) {
			printf("ID     Nombre           Hs Trab.   Sueldo\n");
			for (int i = 0; i < len; i++) {
				auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				employee_printEmployee(auxEmployee);
			}
			retorno = 0;
		}
	}
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	char opcionIngresada;

	retorno = -2; // LL nula
	if (pArrayListEmployee != NULL) {
		employee_printSubMenuSort();
		opcionIngresada = tolower(PedirCaracterSoloLetra("Ingrese opción: "));

		retorno = employee_sortEmployees(pArrayListEmployee, opcionIngresada);
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3;

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2;
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			retorno = saveAsText(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}

    return retorno;
}

int saveAsText(FILE* pFile, LinkedList* pArrayListEmployee) {
	int retorno;
	int longitud;
	Employee* pEmpleado;
	int idAGuardar;
	char nombreAGuardar[128];
	int horasAGuardar;
	int sueldoAGuardar;

	retorno = -1;
	longitud = ll_len(pArrayListEmployee);

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for (int i = 0; i < longitud; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if (!employee_getAll(pEmpleado, &idAGuardar, nombreAGuardar, &horasAGuardar, &sueldoAGuardar) &&
					fprintf(pFile,"%d,%s,%d,%d\n", idAGuardar, nombreAGuardar, horasAGuardar, sueldoAGuardar)) {
				retorno = 0;
			}
		}
	}
	return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	
	retorno = -3; // path o LL NULOS
	
	if (path != NULL && pArrayListEmployee != NULL){
		retorno = -2;
		pFile = fopen(path, "wb");
	
		if (pFile != NULL) {
			retorno = saveAsBinary(pFile, pArrayListEmployee);
			fclose(pFile);
		}
	}
    return retorno;
}

int saveAsBinary(FILE* pFile, LinkedList* pArrayListEmployee) {
	int retorno;
	int longitud;
	Employee* pEmpleado;

	longitud = ll_len(pArrayListEmployee);

	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL && longitud > 0) {
		for (int i = 0; i < longitud; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmpleado, sizeof(Employee), 1, pFile);
		}
		retorno = 0;
	}

	return retorno;
}

//--------------------------------------------------ULTIMO ID-------------------------------------------------------

int ObtenerUltimoId(char* path, char* idParaAsignar) {
	int retorno;
	FILE* pFile;

	pFile = fopen(path, "r");

	retorno = -1;
	if (pFile != NULL && idParaAsignar != NULL) {
		fscanf(pFile, "%[^\n]\n", idParaAsignar);
		retorno = 0;

		fclose(pFile);
	}

	return retorno;
}

int IncrementarUltimoId(char* idParaAsignar) {
	int idAAumentar;
	int retorno;

	retorno = -1;

	if (idParaAsignar != NULL) {
		idAAumentar = atoi(idParaAsignar);
		idAAumentar++;
		itoa(idAAumentar, idParaAsignar, 10);
		retorno = 0;
	}

	return retorno;
}

int ActualizarUltimoId(char* path, char* idParaAsignar) {
	FILE* pFile;
	int retorno;

	pFile = fopen(path, "w");

	retorno = -1;
	if (pFile != NULL) {
		fprintf(pFile, "%s\n", idParaAsignar);
		retorno = 0;
		fclose(pFile);
	}

	return retorno;
}

