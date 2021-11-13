
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

#include "Controller.h"
#include "View.h"

int main()
{
	setbuf(stdout, NULL);
    int option;
    int flagLoadSave;
    int retornoFuncion;
    char confirmacion;
	LinkedList* listaEmpleados;

	listaEmpleados = ll_newLinkedList();
	flagLoadSave = 0;

	printf("Bienvenido/a al ABM que sí sirve (ponele) para hacer cambios permanentes!\n");
    do{
    	printf("-----------------------------\n"
    			"Menú principal\n"
    			"-----------------------------\n"
    			"[1] Cargar los datos a través de archivo tipo texto (data.csv)\n"
    			"[2] Cargar los datos a través de archivo tipo binario (data.bin)\n"
    			"[3] Alta de un empleado\n"
    			"[4] Modificar un empleado\n"
    			"[5] Baja de un empleado\n"
    			"[6] Mostrar lista de empleados\n"
    			"[7] Ordenar empleados según criterio\n"
    			"[8] Guardar los datos en un archivo de tipo texto (data.csv)\n"
    			"[9] Guardar los datos en un archivo de tipo binario (data.bin)\n"
    			"[10] Salir del sistema\n"
    			"-----------------------------\n");

    	option = PedirIntConRango("Ingrese una opción: ", 1, 10);

        switch(option)
        {
            case 1:
            	if (flagLoadSave == 0) {
            		retornoFuncion = controller_loadFromText("data2.csv", listaEmpleados);
            		view_returnsFromLoad(retornoFuncion, "TEXTO");
            		if (!retornoFuncion) {
            			flagLoadSave = 2;
            		}
            	} else {
            		printf("No se puede cargar 2 veces el mismo archivo sin guardarlo primero!\n");
            	}

                break;


            case 2:
            	if (flagLoadSave == 0) {
            		retornoFuncion = controller_loadFromBinary("data2.bin", listaEmpleados);
            		view_returnsFromLoad(retornoFuncion, "BINARIO");
            		if (!retornoFuncion) {
						flagLoadSave = 2;
					}
				} else {
					printf("No se puede cargar 2 veces el mismo archivo sin guardarlo primero!\n");
				}
            	break;

            case 3:

            	if (flagLoadSave == 1 || flagLoadSave == 2) {
            		retornoFuncion = controller_addEmployee(listaEmpleados);
            		view_returnsFromABM(retornoFuncion, "ALTA");
            		if (!retornoFuncion) {
            			flagLoadSave = 1;
            		}
            	} else {
            		printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
            	}

            	break;


            case 4:
            	if (flagLoadSave == 1 || flagLoadSave == 2) {
            		retornoFuncion = controller_editEmployee(listaEmpleados);
            		view_returnsFromABM(retornoFuncion, "MODIFICACION");
            		if (!retornoFuncion) {
						flagLoadSave = 1;
					}
				} else {
					printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
				}
            	break;


            case 5:
            	if (flagLoadSave == 1 || flagLoadSave == 2) {
            		retornoFuncion = controller_removeEmployee(listaEmpleados);
            		view_returnsFromABM(retornoFuncion, "BAJA");
            		if (!retornoFuncion) {
						flagLoadSave = 1;
					}
				} else {
					printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
				}
            	break;


            case 6:
            	if (flagLoadSave == 1 || flagLoadSave == 2) {
            		view_returnsFromListSort(controller_ListEmployee(listaEmpleados), "LISTAR");
				} else {
					printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
				}
            	break;


            case 7:
            	if (flagLoadSave == 1 || flagLoadSave == 2) {
            		view_returnsFromListSort(controller_sortEmployee(listaEmpleados), "ORDENAR");
				} else {
					printf("Por favor cargue su lista de empleados primero para realizar esta acción.\n");
				}
            	break;

            case 8:
            	if (flagLoadSave == 1) {
            		view_returnsFromSave(controller_saveAsText("data2.csv", listaEmpleados), "TEXTO");
            		view_returnsFromSave(controller_saveAsBinary("data2.bin", listaEmpleados), "BINARIO");

            		flagLoadSave = 2;
            	} else if (flagLoadSave == 0){
            		printf("No se puede guardar si no se cargó el archivo primero!\n");
            	} else {
            		printf("El archivo se encuentra actualizado\n");
            	}

            	break;


            case 9:
            	if (flagLoadSave == 1) {
            		view_returnsFromSave(controller_saveAsBinary("data2.bin", listaEmpleados), "BINARIO");
            		view_returnsFromSave(controller_saveAsText("data2.csv", listaEmpleados), "TEXTO");

					flagLoadSave = 0;
				} else if (flagLoadSave == 0){
            		printf("No se puede guardar si no se cargó el archivo primero!\n");
            	} else {
            		printf("El archivo se encuentra actualizado\n");
            	}

            	break;

            case 10:
            	if (flagLoadSave == 1) {
            		confirmacion = tolower(PedirCaracterSiONo("No ha guardado cambios!\nEstá seguro que desea salir del programa?\n[S] Sí\n[N] No\n"));
				} else {
					confirmacion = tolower(PedirCaracterSiONo("Está seguro que desea salir del programa?\n[S] Sí\n[N] No\n"));
				}

        		if (confirmacion == 's') {
        			employee_deleteAll(listaEmpleados);
        			ll_deleteLinkedList(listaEmpleados);

        			printf("Nos vemos!");
        		}
            	break;

            default:
            	printf("Ingrese una opción válida por favor\n");

            	break;
        }
    }while(confirmacion != 's');

    return 0;
}



