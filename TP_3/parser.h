/*
 * parser.h
 *
 *  Created on: 3 nov 2021
 *      Author: Raffi
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_ObtenerUltimoId(FILE* pFile, char* idParaAsignar);
void parser_IncrementarUltimoId(char* idParaAsignar);
int parser_ActualizarUltimoId(FILE* pFile, char* idParaAsignar);


#endif /* PARSER_H_ */
