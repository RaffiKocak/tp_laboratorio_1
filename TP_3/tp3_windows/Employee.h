#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "Input.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);
void employee_deleteAll(LinkedList* pArrayListEmployee);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setAll(Employee* this, int id, char* nombre, int horasTrabajadas, int sueldo);
int employee_getAll(Employee* this, int* id, char* nombre, int* horasTrabajadas, int* sueldo);

void employee_imprimirEmployee(Employee* this);
void employee_printSubMenuEdit();
void employee_printSubMenuSort();

Employee* employee_create();
int employee_edit(Employee* pEmployeeAModificar);

int employee_findById(LinkedList* pArrayListEmployee, int idABuscar);

int employee_sortEmployees(LinkedList* pArrayListEmployee, int opcionIngresada);

int employee_compareById(void* primerEmpleado, void* segundoEmpleado);
int employee_compareByNombre(void* primerEmpleado, void* segundoEmpleado);
int employee_compareByHoras(void* primerEmpleado, void* segundoEmpleado);
int employee_compareBySueldo(void* primerEmpleado, void* segundoEmpleado);

#endif // employee_H_INCLUDED
