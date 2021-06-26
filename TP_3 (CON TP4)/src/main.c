
	#include <stdio.h>
	#include <stdlib.h>
	#include "LinkedList.h"
	#include "Controller.h"
	#include "Producto.h"
	#include "utn.h"

	/*********************************************************************************
		Menu:
		 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
		 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
		 3. Alta de empleado
		 4. Modificar datos de empleado
		 5. Baja de empleado
		 6. Listar empleados
		 7. Ordenar empleados
		 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
		 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
		10. Salir

	**********************************************************************************/

	int main()
	{
		setbuf(stdout,NULL);

		//Creo linkedList
		LinkedList* listaEmpleados = ll_newLinkedList();

		//Declaro variables del main.
		int opcionIngresada = 0;
		int idProximo = 1;

		do{
			//Imprimo menu y pido orden.
			printMenuPrincipal();
			utn_getNumero(&opcionIngresada,"","", 1, 10, 0);

			/*Reviso el valor del id maximo y si es mayor al maximo actual, lo actualizo. Hago esto cada vez que se usa una opcion
			para tener todo el tiempo el valor maximo del id.*/
			controller_findReplaceMaxId (listaEmpleados, &idProximo);

			//Realizo la orden
			switch(opcionIngresada)
			{
				case 1:
				{
					//CARGAR EMPLEADOS DE FORMA TXT
					controller_loadFromText("data.csv",listaEmpleados);
					break;
				}
				case 2:
				{
					//CARGAR EMPLEADOS DE FORMA BIN
					controller_loadFromBinary("data.bin",listaEmpleados);
					break;
				}
				case 3:
				{
					//ALTA EMPLEADO
					controller_addEmployee(listaEmpleados,idProximo);
					break;
				}
				case 4:
				{
					//MODIFICAR EMPLEADO
					controller_editEmployee(listaEmpleados);
					break;
				}
				case 5:
				{
					//BAJAR EMPLEADO
					controller_removeEmployee(listaEmpleados);
					break;
				}
				case 6:
				{
					//LISTAR EMPLEADOS
					controller_ListEmployee(listaEmpleados);
					break;
				}
				case 7:
				{
					//ORDENAR EMPLEADOS. (ORDENA DE MAYOR A MENOR POR ID)-[PUEDE TARDAR]
					controller_sortEmployee(listaEmpleados);
					break;
				}
				case 8:
				{
					//GUARDAR EMPLEADOS (BY TXT)
					controller_saveAsText("data.csv",listaEmpleados);
					break;
				}
				case 9:
				{
					//GUARDAR EMPLEADO (BY BIN)
					controller_saveAsBinary("data.bin",listaEmpleados);
					break;
				}
				case 10:
				{
					//SALIR
					controller_finalActions (listaEmpleados);
					break;
				}
			}

		}while (opcionIngresada != 10);

		return 0;
	}
