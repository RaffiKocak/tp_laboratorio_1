
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* nuevoEmpleado;
	char id[11];
	char nombre[128];
	char horasTrabajadas[11];
	char sueldo[11];

	retorno = -1;

	// no pregunto si pFile es nulo porque ya lo atajo en el controller
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); // falsa lectura para el header
	while (!feof(pFile)) {

		if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4 && VerificarInt(id)  && VerificarNombre(nombre)
			&& VerificarInt(horasTrabajadas) && VerificarInt(sueldo)) {

			nuevoEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			if (nuevoEmpleado != NULL && ll_add(pArrayListEmployee, nuevoEmpleado) != -1) {
				retorno = 0;
			} // hacer un else con un remove nuevoEmpleado si no pudo parsearlo por el motivo que sea? Me suena a que el puntero queda sin referencia
				// si no entra al if
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* nuevoEmpleado;

	retorno = -1;
	// no pregunto si pFile es nulo porque ya lo atajo en el controller
	while (!feof(pFile)) {
		nuevoEmpleado = employee_new();
		if (nuevoEmpleado != NULL && fread(nuevoEmpleado, sizeof(Employee), 1, pFile) == 1 && ll_add(pArrayListEmployee, nuevoEmpleado)) {
			retorno = 0;
		} // idem pregunta else de parser texto
	}
    return retorno;
}

//--------------------------------------------------ULTIMO ID-------------------------------------------------------

int parser_ObtenerUltimoId(FILE* pFile, char* idParaAsignar) {
	int retorno;

	retorno = -1;
	if (pFile != NULL) {
		fscanf(pFile, "%[^\n]\n", idParaAsignar);
		retorno = 0;
	}

	return retorno;
}

void parser_IncrementarUltimoId(char* idParaAsignar) {
	int idAAumentar;

	idAAumentar = atoi(idParaAsignar);
	idAAumentar++;
	itoa(idAAumentar, idParaAsignar, 10);
}

int parser_ActualizarUltimoId(FILE* pFile, char* idParaAsignar) {
	int retorno;

	retorno = -1;
	if (pFile != NULL) {
		fprintf(pFile, "%s\n", idParaAsignar);
		retorno = 0;
	}

	return retorno;
}

