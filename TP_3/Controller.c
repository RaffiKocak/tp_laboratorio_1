
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o arraylist NULL

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2; // no pudo abrir el file
		pFile = fopen(path, "r");

		if (pFile != NULL) {

			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee); // -1 si parseó mal, 0 si salió bien (al menos una vez)

			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o arraylist NULL

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2; // no pudo abrir el file
		pFile = fopen(path, "rb");

		if (pFile != NULL) {

			retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee); // -1 si parseó mal, 0 si salió bien (al menos una vez)

			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pNuevoEmpleado;
	FILE* pFile;
	char idParaAsignar[11];

	retorno = -4; // lista NULL

	if (pArrayListEmployee != NULL) {
		retorno = -3; // no se pudo recuperar último ID empleado
		pFile = fopen("ultimoId.csv", "r");

		if (!parser_ObtenerUltimoId(pFile, idParaAsignar)) {
			fclose(pFile);
			retorno = -2; // no se pudo crear el empleado

			parser_IncrementarUltimoId(idParaAsignar);
			pNuevoEmpleado = employee_create(idParaAsignar);
			if (pNuevoEmpleado != NULL) {
				retorno = ll_add(pArrayListEmployee, pNuevoEmpleado); // -1 si no se pudo agregar LL, 0 si se agregó con éxito

				if (retorno == 0) { // si salió todo bien, actualizo el último ID con el que asigné
					pFile = fopen("ultimoId.csv", "w");

					if (pFile != NULL) {
						parser_ActualizarUltimoId(pFile, idParaAsignar);

						fclose(pFile);
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

			retorno = -2; // error, no se encuentra el empleado
			indiceAModificar = employee_findById(pArrayListEmployee, idAModificar);
			if (indiceAModificar != -1) {

				pEmpleadoAModificar = (Employee*) ll_get(pArrayListEmployee, indiceAModificar); // no verifico que sea != NULL porque prácticamente lo hizo el if de arriba
				employee_imprimirEmployee(pEmpleadoAModificar);
				retorno = employee_edit(pEmpleadoAModificar); // -1 si no se modificó el empleado, 0 si se modificó
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleadoABorrar;
	int idABorrar;
	int indiceABorrar;
	char confirmacion;

	retorno = -4; // LL nula o vacía

	if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee)) {
		retorno = -3; // error en ingreso de datos ID

		if (PedirIntConRangoConReintentos("Ingrese ID del empleado a borrar: ", &idABorrar, 1, 1000, 3)) {

			retorno = -2; // no se encuentra el empleado
			indiceABorrar = employee_findById(pArrayListEmployee, idABorrar);
			if (indiceABorrar != -1) {

				pEmpleadoABorrar = (Employee*) ll_get(pArrayListEmployee, indiceABorrar);
				employee_imprimirEmployee(pEmpleadoABorrar);
				confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea dar de baja al siguiente empleado?\n[S] Si\n[N] No\n"));

				if (confirmacion == 's') {
					ll_remove(pArrayListEmployee, indiceABorrar); // borro el nodo
					employee_delete(pEmpleadoABorrar); // borro el dato (ya que no va a ser usado para otra lista)
					retorno = 0; // empleado borrado exitosamente
				} else {
					retorno = -1; // eliminación cancelada
				}
			}
		}
	}


    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* auxEmployee;
	int len;

	retorno = -2; // LL NULA o LL sin cargar
	len = ll_len(pArrayListEmployee);
	if (pArrayListEmployee != NULL && len > 0) {

		if (len > 0) {
			for (int i = 0; i < len; i++) {
				auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				employee_imprimirEmployee(auxEmployee); // si imprime al menos 1, retorna 0. Si no, -1
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	char opcionIngresada;

	retorno = -2; // LL nula
	if (pArrayListEmployee != NULL) {
		employee_printSubMenuSort();
		opcionIngresada = tolower(PedirCaracterSoloLetra("Ingrese opción: "));

		retorno = employee_sortEmployees(pArrayListEmployee, opcionIngresada); // -1 si no ordenó, 0 si ordenó
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;

	retorno = -3; // path o LL null

	if (path != NULL && pArrayListEmployee != NULL) {
		retorno = -2; // no se puede abrir el archivo
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			retorno = saveAsText(pFile, pArrayListEmployee); // -1 si no pudo guardar nada, 0 si pudo
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

	fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
	for (int i = 0; i < longitud; i++) {
		pEmpleado = ll_get(pArrayListEmployee, i);
		if (!employee_getAll(pEmpleado, &idAGuardar, nombreAGuardar, &horasAGuardar, &sueldoAGuardar)) {
			fprintf(pFile,"%d,%s,%d,%d\n", idAGuardar, nombreAGuardar, horasAGuardar, sueldoAGuardar); // validar retorno?
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	Employee* pEmpleado;
	int longitud;
	
	retorno = -3; // path o LL NULOS
	
	if (path != NULL && pArrayListEmployee != NULL){
		retorno = -2; // no se pudo abrir el archivo
		pFile = fopen(path, "wb");
	
		if (pFile != NULL) {
			// a partir de acá que sea una función
			longitud = ll_len(pArrayListEmployee);
			for (int i = 0; i < longitud; i++) {
				pEmpleado = ll_get(pArrayListEmployee, i);
				fwrite(pEmpleado, sizeof(Employee), 1, pFile);
			}
			// hasta acá
			fclose(pFile);

			retorno = 0;
		}
	}
    return retorno;
}

