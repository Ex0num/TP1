/*
 ============================================================================
 Name        : TP_2.c
 Author      : Gabriel Lopez G
 Version     :
 Copyright   : GLG
 Description : Hello World in C, Ansi-style
 ============================================================================
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
Datos:

El sistema deberá tener el siguiente menú de opciones:

	1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
	de Id. El resto de los campos se le pedirá al usuario.
	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
	o Salario o Sector
	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
	4. INFORMAR:
	1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
	2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
	carga de algún empleado.

  ============================================================================
 */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "Employee.h"
	#include "FuncionesEstandar.h"

	#define QTY_EMPLOYEES 1000


	int main(void)
	{
		setbuf(stdout,NULL);
		Employee employees[QTY_EMPLOYEES];

		initEmployees (employees, QTY_EMPLOYEES);

		strncpy (employees[0].name,"DULFONSO",51);
		strncpy (employees[0].lastName,"MARTINEZ",51);
		employees[0].idEmployee = 1;
		employees[0].salary = 10000;
		employees[0].sector = 2;
		employees[0].isEmpty = 0;

		strncpy (employees[1].name,"BABRIEL",51);
		strncpy (employees[1].lastName,"LOPEZ",51);
		employees[1].idEmployee = 2;
		employees[1].salary = 10000;
		employees[1].sector = 4;
		employees[1].isEmpty = 0;

		strncpy (employees[2].name,"BATEO",51);
		strncpy (employees[2].lastName,"HERNANDEZ",51);
		employees[2].idEmployee = 3;
		employees[2].salary = 10000;
		employees[2].sector = 1;
		employees[2].isEmpty = 0;

		strncpy (employees[3].name,"CLFONSIN",51);
		strncpy (employees[3].lastName,"LOPEZ",51);
		employees[3].idEmployee = 4;
		employees[3].salary = 10000;
		employees[3].sector = 3;
		employees[3].isEmpty = 0;

		strncpy (employees[4].name,"AONSA",51);
		strncpy (employees[4].lastName,"CUBRETE",51);
		employees[4].idEmployee = 5;
		employees[4].salary = 10000;
		employees[4].sector = 2;
		employees[4].isEmpty = 0;

		int idEmployees = 6;
		int ordenDeMenu;
		int ordenDeMenu2;

		 printEmployees (employees,QTY_EMPLOYEES);

		do
		{
			print_menu1 ();
			utn_obtener_validar_Orden ("\n Ingrese la orden a realizar.\n", "\n Error en el ingreso de su orden. \n", &ordenDeMenu);

			switch (ordenDeMenu)
			{

			case 1:
				{
					//ALTA
					addEmployees (employees, QTY_EMPLOYEES, &idEmployees);
					break;
				}
			case 2:
				{
					//BAJA
					removeEmployee (employees, QTY_EMPLOYEES);
					break;
				}

			case 3:
				{
					//MODIFICACION
					modificateEmployee (employees, QTY_EMPLOYEES);
					break;
				}

			case 4:
				{
					//INFORMES

					print_menu2();
					utn_obtener_validar_Orden2 ("\n Ingrese la orden a realizar.\n", "\n Error en el ingreso de su orden. \n", &ordenDeMenu2);

					switch (ordenDeMenu2)
					{
					case 1:
						{
							// Listado de los empleados ordenados alfabéticamente por Apellido y Sector. //FALTA
							sortEmployees (employees, QTY_EMPLOYEES, ordenDeMenu2);
							break;
						}

					case 2:
						{
							// Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
							sortEmployees (employees, QTY_EMPLOYEES, ordenDeMenu2);
							break;
						}

					case 3:
						{
							// SALIR.
							//No hago nada, salgo.
							break;
						}
					}



					break;
				}

			case 5:
				{
					// SALIR
					ordenDeMenu = 5;
					print_bye();
					break;
				}
			}

		}while( ordenDeMenu != 5 );

	}



/*
	void ordenarEmpleados(Empleado list[], int tam)
	{

	    Empleado auxEmpleado;

	    for(int i=0; i<tam -1; i++)
	    {
	        for(int j=i+1; j<tam; j++)
	        {
	            {
	                if(list[i].isEmpty==0 && list[i].sector>list[j].sector){

	                    auxEmpleado=list[i];
	                    list[i]=list[j];
	                    list[j]=auxEmpleado;

	                }else
	                    if(list[i].sector == list[j].sector && strcmp(list[i].apellido,list[j].apellido)>0){

	                    auxEmpleado=list[i];
	                    list[i]=list[j];
	                    list[j]=auxEmpleado;
	                }
	            }
	        }
	    }

	    mostrarEmpleados(list,tam);
	}
*/
