#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/// @brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
///
/// @param pFile
/// @param pArrayListEmployee
/// @return Retorna ERROR (-1) [Punteros NULOS o no es posible conseguir datos de empleados para escritura], (0) si la operación sale bien.
int saveAsText(FILE* pFile, LinkedList* pArrayListEmployee);

/// @brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
///
/// @param pFile
/// @param pArrayListEmployee
/// @return Retorna ERROR (-1) [Punteros NULOS o no es posible conseguir datos de empleados para escritura], (0) si la operación sale bien.
int saveAsBinary(FILE* pFile, LinkedList* pArrayListEmployee);

/// @brief Accede al archivo contenedor del último ID y obtiene el valor en una cadena de caracteres.
///
/// @param path
/// @param idParaAsignar
/// @return Retorna ERROR (-1) [Punteros NULOS o no se puede acceder al archivo], (0) si la operación sale bien.
int ObtenerUltimoId(char* path, char* idParaAsignar);

/// @brief Aumenta en 1 el dato del último ID asignado para usarlo en la creación de un nuevo empleado.
///
/// @param idParaAsignar
/// @return Retorna ERROR (-1) [Puntero NULO], (0) si la operación sale bien.
int IncrementarUltimoId(char* idParaAsignar);

/// @brief Accede al archivo contenedor del último ID y escribe el valor en una cadena de caracteres.
///
/// @param path
/// @param idParaAsignar
/// @return Retorna ERROR (-1) [Punteros NULOS o no se puede acceder al archivo], (0) si la operación sale bien.
int ActualizarUltimoId(char* path, char* idParaAsignar);

#endif /* CONTROLLER_H_ */
