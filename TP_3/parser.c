
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* nuevoEmpleado;
	char id[11];
	char nombre[128];
	char horasTrabajadas[11];
	char sueldo[11];

	retorno = -1;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); // falsa lectura para el header
		while (!feof(pFile)) {

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4 && VerificarInt(id)  && VerificarNombre(nombre)
				&& VerificarInt(horasTrabajadas) && VerificarInt(sueldo)) {

				nuevoEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if (nuevoEmpleado != NULL) {
					if (ll_add(pArrayListEmployee, nuevoEmpleado) != -1) { // tuve que fragmentar el if, porque no puedo hacer un free de NULL
						retorno = 0;
					} else {
						employee_delete(nuevoEmpleado);
					}
				}
			}
		}
	}
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* nuevoEmpleado;

	retorno = -1;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		while (!feof(pFile)) {
			nuevoEmpleado = employee_new();
			if (nuevoEmpleado != NULL && fread(nuevoEmpleado, sizeof(Employee), 1, pFile) == 1) {
				if (ll_add(pArrayListEmployee, nuevoEmpleado) != -1) { // tuve que fragmentar el if, porque no puedo hacer un free de NULL
					retorno = 0;
				} else {
					employee_delete(nuevoEmpleado);
				}
			}
		}
	}
    return retorno;
}



