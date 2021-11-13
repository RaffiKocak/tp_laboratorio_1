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

/// @brief Constructor por defecto de un empleado creado en memoria dinámica.
///
/// @return Retorna NULL [Sin lugar en memoria] o un puntero a la estructura Empleado.
Employee* employee_new();

/// @brief Constructor parametrizado  de un empleado creado en memoria dinámica.
///
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldoStr
/// @return Retorna NULL [Sin lugar en memoria o algún dato no se puede guardar] o un puntero a la estructura Empleado.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// @brief Elimina los datos de un empleado liberando su posición reservada en memoria RAM.
///
/// @param this
void employee_delete(Employee* this);

/// @brief Elimina los datos de todos los empleados liberando sus posiciones reservadas en memoria RAM.
///
/// @param pArrayListEmployee
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

void employee_printEmployee(Employee* this);
void employee_printSubMenuEdit();
void employee_printSubMenuSort();
void employee_printEmployeesAntesDespues (Employee* pEmployeeAntes, Employee* pEmployeeDespues);

Employee* employee_create();
int employee_edit(Employee* pEmployeeAModificar);
int employee_copy(Employee* pEmpleado, Employee* pEmpleadoACopiar);

int employee_findById(LinkedList* pArrayListEmployee, int idABuscar);

int employee_sortEmployees(LinkedList* pArrayListEmployee, int opcionIngresada);

int employee_compareById(void* primerEmpleado, void* segundoEmpleado);
int employee_compareByNombre(void* primerEmpleado, void* segundoEmpleado);
int employee_compareByHoras(void* primerEmpleado, void* segundoEmpleado);
int employee_compareBySueldo(void* primerEmpleado, void* segundoEmpleado);

#endif // employee_H_INCLUDED
