/*
 * Employee.c
 *
 *  Created on: 15 may. 2021
 *      Author: gabil
 */


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "Employee.h"
	#include "FuncionesEstandar.h"


	int initEmployees (Employee* arrayRecibido, int limite)
	{
		int retorno = -1;

		if (arrayRecibido != NULL && limite > 0)
		{
			retorno = 0;

			for (int i = 0 ; i < limite ; i++ )
			{
				arrayRecibido[i].isEmpty = 1;
				arrayRecibido[i].idEmployee = 0;
				arrayRecibido[i].sector = 0;
			}
		}
		return retorno;
	}

	 int findEmptyEmployeeIndex (Employee* arrayRecibido, int limite, int* pindiceVacioEncontrado)
	 	{
	 		int retorno = -1;

	 		if (arrayRecibido != NULL && limite > 0 && pindiceVacioEncontrado != NULL )
	 		{
	 			retorno = -2;

	 			for (int i = 0 ; i < limite ; i++)
	 			{
	 				if (arrayRecibido[i].isEmpty == 1)
	 				{
	 					*pindiceVacioEncontrado = i;
	 					retorno = 0;
	 					break;
	 				}
	 			}
	 		}

	 		return retorno;
	 	}

	  int printEmployeeByIndex (Employee* arrayClienteRecibido, int limiteArrayCliente, int indiceIngresadoParaImprimir)
	 	{
	 		int retorno = -1;

	 		if (arrayClienteRecibido != NULL && limiteArrayCliente > 0 && indiceIngresadoParaImprimir < limiteArrayCliente)
	 		{
	 			retorno = -2;

	 			printf ("\nLos datos del cliente son:\n "
	 					"Nombre: %s\n "
	 					"Apellido: %s\n "
	 					"Salario: %f \n "
	 					"Sector: %d\n "
	 					"ID-Cliente: %d\n"
	 					,arrayClienteRecibido[indiceIngresadoParaImprimir].name
						,arrayClienteRecibido[indiceIngresadoParaImprimir].lastName
						,arrayClienteRecibido[indiceIngresadoParaImprimir].salary
						,arrayClienteRecibido[indiceIngresadoParaImprimir].sector
						,arrayClienteRecibido[indiceIngresadoParaImprimir].idEmployee);

				retorno = 0;
	 		}
	 		return retorno;
	 	}

	  int printEmployees (Employee* arrayClienteRecibido, int limiteArrayRecibido)
	  {
		  int retorno = -1;

		  if (arrayClienteRecibido != NULL && limiteArrayRecibido > 0)
		  {
			  retorno = 0;

			  for ( int i = 0 ; i < limiteArrayRecibido ; i++ )
			  {
				  if (arrayClienteRecibido[i].isEmpty == 0) //Si encuentra alguno ocupado.
				  {
					  printEmployeeByIndex (arrayClienteRecibido, limiteArrayRecibido, i);
					  //printf ("\nINDICE DEL BUGEADO: %d\n",i);
				  }
			  }
		  }

		  return retorno;
	  }

	  int findEmployeeById (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, char* mensajeParaPedidoID, char* mensajeParaErrorID, int* valorIndiceID)
	   	 {
	   		 int retorno = -1;
	   		int flagErrorEnID = 0;

	   		 if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0 && mensajeParaPedidoID != NULL && mensajeParaErrorID != NULL && valorIndiceID != NULL) //Valido parametros
	   		 {
	   			retorno = -2;
	   			char buffer[1000]; //Creo un buffer para obtener la ensalada que me pueden ingresar.
	   			int resultadoDelBuffer;
	   			int numeroIntBuffer;

	   			printf ("%s", mensajeParaPedidoID);
	   			fflush(stdin);
	   			fgets (buffer,1000,stdin);

	   			resultadoDelBuffer = strnlen(buffer,1000); //Guardo en resultado del buffer la longitud de lo que hay.
	   			//printf ("\n EL LARGO DEL ID INGRESADO: %d\n", resultadoDelBuffer);

	   			 if( resultadoDelBuffer > 5 ) //Si hay mas de 5 digitos, es un chamuyo.
	   			 {
	   				 flagErrorEnID++;
	   			 }

	   			 for (int i = 0 ; i < resultadoDelBuffer-1 ; i ++) //Recorro el buffer para revisar que solo sean numeros (Porque es un ID), excluyo ese /0.
	   			 {
	   				if ( buffer[i] < '0' || buffer[i] > '9' )
	   				{
	   					flagErrorEnID++;
	   				}
	   			 }

	   			//printf ("\n HAY ERRORES EN CARACTERES ? -> %d \n", flagErrorEnID);

	   			if (flagErrorEnID == 0) //Si no hay errores.
	   			{
	   				retorno = -3;
	   				numeroIntBuffer = atoi(buffer); //Hacemos la conversion del char a int del ID ingresado.

	   				//HASTA ACA ES UN GET ID

	   				//AHORA VALIDAMOS SI ESE ID PARECE ESTAR O NO EN LA LISTA DE CLIENTES.




	   				for ( int j = 0 ; j < limiteArrayClienteRecibido ; j++ ) //Recorremos lista de clientes
	   				{
	   					if (arrayClienteRecibido[j].idEmployee == numeroIntBuffer && arrayClienteRecibido[j].isEmpty == 0) //Si encuentro que un ID en la lista coincide con el que ingreso el usuario y el campo de existencia da positivo.
	   					{
	   						//Entonces el ID ingresado no solo es valido, sino que tambien existe en la lista de clientes.
	   						retorno = numeroIntBuffer; //Devolvemos un numero >0 especificamente el ID ingresado si salio bien.

	   						*valorIndiceID = j; // Pasamos por referencia el resultado de donde se encuentra ese IDCliente en la lista de clientes.
	   						break;
	   					}
	   				}

	   			}
	   		 }

	   		 return retorno;

	   	 }

	int addEmployees (Employee* arrayClienteRecibido, int limiteArrayRecibido, int* pidIncrementableDeClientes)
	 {
		 int retorno = -1;

		 if (arrayClienteRecibido != NULL && limiteArrayRecibido > 0 && pidIncrementableDeClientes != NULL) // Verifico parametros.
		 {
			 retorno = -2;

			 int indiceVacioEncontrado;
			 int resultadoDeIndiceVacio;
			 resultadoDeIndiceVacio = findEmptyEmployeeIndex ( arrayClienteRecibido, limiteArrayRecibido, &indiceVacioEncontrado); // Buscar si hay lugar vacio para cliente y devolverlo en retorno.

			 if (resultadoDeIndiceVacio == 0)
			 {
				 Employee bufferDeEmployee; //Crear un buffer para guardar los datos.

				 // Obtener datos de cliente.
				 int resultadoObtencionNombre = utn_obtener_validar_Nombre ("\n Ingrese nombre \n", "\n Error en el ingreso del nombre \n", bufferDeEmployee.name, 51, 10);
				 int resultadoObtencionApellido = utn_obtener_validar_Apellido ("\n Ingrese apellido \n", "\n Error en el ingreso del apellido \n", bufferDeEmployee.lastName, 51, 10);
				 int resultadoObtencionSalario = utn_obtener_validar_Precio_Salario ("\n Ingrese salario \n", "\n Error en el ingreso del salario \n", &bufferDeEmployee.salary, 10);
				 int resultadoObtencionSector = utn_obtener_validar_Orden ("\nIngrese sector \n", "\nError en el ingreso de su sector. \n", &bufferDeEmployee.sector);


				 // Validar los datos de cliente.
				 if (resultadoObtencionNombre == 0 && resultadoObtencionApellido == 0 && resultadoObtencionSalario == 0 && resultadoObtencionSector == 0)
				 {

					bufferDeEmployee.idEmployee = *pidIncrementableDeClientes; // Hacer pasos finales como asignarle el ID en el buffer y poner el flagEmpty en 0
					bufferDeEmployee.isEmpty = 0;

					// Cargar datos del buffer a la posicion vacia encontrada anteiortemen del arrayRecibido
					arrayClienteRecibido[indiceVacioEncontrado] = bufferDeEmployee;

					// incrementar el id para la proxima alta.
					 (*pidIncrementableDeClientes)++;

					 // Aviso de que salio bien el alta e informar el valor de ID.
					 printf ("\n El cliente ha sido dado de alta de forma satisfactoria. \n Su numero ID es: %d \n", arrayClienteRecibido[indiceVacioEncontrado].idEmployee);
					 retorno = 0;
				 }
				 else
				 {
					printf ("\n Error en la obtencion de datos. \n");
					retorno = -4;

				 }
			 }
			 else
			 {
				 printf ("\n No hay suficiente espacio para otro cliente. \n");
				 retorno = -3;
			 }
		 }
		 return retorno;

	 }

	int modificateEmployee (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido)
	  {
		  int retorno = -1;

		  //Valido parametros
		  if ( arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0)
		  {
			  //Si solo si hay un cliente como minimo, continuo.
			  int cantidadEmpleadosExistentes;
			  cantidadEmpleadosExistentes = counterEmployeeOcuppiedIndex (arrayClienteRecibido, limiteArrayClienteRecibido);

			  if (cantidadEmpleadosExistentes > 0)
			  {
				//Pedir el ID del cliente que quiero modificar, y lo validamos para ver si existe o no ese cliente.
				int indiceIDClienteIngresado = -1;
				int resultadoObtencionIDCliente;
				resultadoObtencionIDCliente = findEmployeeById ( arrayClienteRecibido, limiteArrayClienteRecibido, "\n Ingrese ID del cliente a modificar. \n", "\n Error, no se pudo encontrar un cliente con esa ID. \n", &indiceIDClienteIngresado);

				if (resultadoObtencionIDCliente > 0) //Si la funcion salio bien
				{
					//Imprimir al usuario el cliente que va a modificar a continuacion.
					printEmployeeByIndex (arrayClienteRecibido, limiteArrayClienteRecibido, indiceIDClienteIngresado);

					//Permitimos ingresar un nuevo nombre, apellido y cuit.
					Employee bufferDeEmployee; //Creo un buffer que le voy a guardar los nuevos datos y el ID ya validado.

					// Obtener nuevos datos de cliente.
					int resultadoObtencionNombre = utn_obtener_validar_Nombre ("\n Ingrese el nuevo nombre \n", "\n Error en el ingreso del nuevo nombre \n", bufferDeEmployee.name, 51, 10);
					int resultadoObtencionApellido = utn_obtener_validar_Apellido ("\n Ingrese el nuevo apellido \n", "\n Error en el ingreso del nuevo apellido \n", bufferDeEmployee.lastName, 51, 10);
					int resultadoObtencionSalario = utn_obtener_validar_Precio_Salario ("\n Ingrese nuevo salario \n", "\n Error en el ingreso del nuevo salario \n", &bufferDeEmployee.salary, 10);
					int resultadoObtencionSector = utn_obtener_validar_Orden ("\nIngrese nuevo sector \n", "\n Error en el ingreso de su nuevo sector. \n", &bufferDeEmployee.sector);


					//Si los nuevos datos son validos y todo salio bien.
					if (resultadoObtencionNombre == 0 && resultadoObtencionApellido == 0 && resultadoObtencionSalario == 0 && resultadoObtencionSector == 0)
					{

						//Termino de asignar el id (que ya este mismo cliente tenia) al buffer. (Y obvio el flagIsEmty = 0)
						bufferDeEmployee.idEmployee = resultadoObtencionIDCliente; //Le asigno la ID que ya valide que existe y tiene un indice.
						bufferDeEmployee.isEmpty = 0;

						//Hago la asignacion final de todo.
						arrayClienteRecibido[indiceIDClienteIngresado] = bufferDeEmployee;

						retorno = 0;
					}
					else
					{
						retorno = -3;
						printf ("\nLa obtencion de los nuevos datos salio mal.\n");
					}

				}
				else
				{
					printf("\n Error, no se pudo encontrar un cliente con esa ID. \n");
					retorno = -2;
				}


			  }
			  else
			  {
				  retorno = -4;

				  printf ("\nNo es posible modificar un cliente sin la existencia de uno como minimo.\n");
			  }
		  }


		  return retorno;
	  }


	  int removeEmployee (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido)
	  {
		  int retorno = -1;

		  if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0) //Valido parametro
		  {
			  retorno = -2;

			  //Si solo si hay un cliente como minimo, continuo.
			  int cantidadEmpleadosExistentes;
			  cantidadEmpleadosExistentes = counterEmployeeOcuppiedIndex (arrayClienteRecibido, limiteArrayClienteRecibido);

			  if (cantidadEmpleadosExistentes > 0)
			  {
				  int indiceIDObtenido;
				  int idObtenido;
				  idObtenido = findEmployeeById (arrayClienteRecibido, limiteArrayClienteRecibido, "\n Ingrese el ID del cliente a eliminar.\n", "\n Error en el ingreso de su ID.\n", &indiceIDObtenido);

				  if (idObtenido > 0 && indiceIDObtenido >= 0 ) //Si el ID que se obtuvo es valido y existe.
				  {
					  for ( int i = 0 ; i < limiteArrayClienteRecibido ; i++ ) 	//Recorro lista de clientes
					  {
						 if (arrayClienteRecibido[i].idEmployee == idObtenido && arrayClienteRecibido[i].isEmpty == 0) //Si encuentro uno que coincida con el ID y existe
						 {
							 //Lo borro
							 arrayClienteRecibido[i].isEmpty = 1;
							 arrayClienteRecibido[i].idEmployee = 0;
							 retorno = 0;
							 break;
						 }
					  }
				  }
				  else
				  {
					  retorno = -3;
					  printf ("\n El id que se ingreso es invalido o no pudo ser borrado.\n");
				  }

				  if (retorno == 0)
				  {
					  printf ("\n El borrado del cliente ha sido satisfactorio.\n");
				  }
			  }
		  }

		  return retorno;
	  }


	  int counterEmployeeOcuppiedIndex (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido)
	  {
		  int retorno = -1;

		  if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0)
		  {
			  retorno = -2;
			  int contadorIndicesOcupados = 0;

			  for ( int i = 0 ; i<limiteArrayClienteRecibido ; i++ )
			  {
				 if (arrayClienteRecibido[i].isEmpty == 0)
				 {
					 contadorIndicesOcupados++;
				 }
			  }

			  if (contadorIndicesOcupados == 0)
			  {
				  retorno = -3;
			  }
			  else if (contadorIndicesOcupados > 0)
			  {
				  retorno = contadorIndicesOcupados;
			  }
		  }

		  return retorno;
	  }


	  int sortEmployees (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, int ordenObtenida)
	  {
		  int retorno = -1;

		if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0)
		{

		  //Si solo si hay un cliente como minimo, continuo.
		  int cantidadEmpleadosExistentes;
		  cantidadEmpleadosExistentes = counterEmployeeOcuppiedIndex (arrayClienteRecibido, limiteArrayClienteRecibido);

		  //printf ("\nEMPLEADOS EXISTENTES: %d\n",  cantidadEmpleadosExistentes);

		  if (cantidadEmpleadosExistentes > 0)
		  {
			  if (ordenObtenida == 1) //Si la orden de sort es 1/A
			  {

				  int flagSwap = 1;
				  int resultadoStringComparison;
				  Employee auxEmployee;

				  /*
				  do
				  {
					  flagSwap = 0;

					  for (int i = 0 ; i < limiteArrayClienteRecibido ; i++)
					  {

						  if (arrayClienteRecibido[i].sector > arrayClienteRecibido[i+1].sector)
						  {
							  auxEmployee = arrayClienteRecibido[i];
							  arrayClienteRecibido[i] = arrayClienteRecibido[i+1];
							  arrayClienteRecibido[i+1] = auxEmployee;
							  flagSwap = 1;
						  }
					  }


				  }while(flagSwap == 1);
				  */

				  //Fuera de este for Y do-while, ya estan ordenador por sector.

				 do
				 {
					 flagSwap = 0;

					  for (int i = 0 ; i < limiteArrayClienteRecibido-1 ; i++)
					  {
						  //Comparo un cliente con el siguiente y guardo el resultado
						  if (i + 1 != limiteArrayClienteRecibido)
						  {
							 resultadoStringComparison = strncmp (arrayClienteRecibido[i].name,arrayClienteRecibido[i+1].name,51);
						  }

						  //Si el primer string es mayor (en letras)
						  if (resultadoStringComparison > 0)
						  {
							  auxEmployee = arrayClienteRecibido[i];
							  arrayClienteRecibido[i] = arrayClienteRecibido[i+1];
							  arrayClienteRecibido[i+1] = auxEmployee;
							  flagSwap = 1;
						  }
					  }

			  	  }while(flagSwap == 1);

				  printEmployees (arrayClienteRecibido,limiteArrayClienteRecibido);

			  }
			  else if (ordenObtenida == 2) //Si la orden de sort es 2/B
			  {
				  // 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

				  //Calculamos todo
				  float resultadoSalarioPromedio;
				  calculateAverageSalary (arrayClienteRecibido, limiteArrayClienteRecibido, &resultadoSalarioPromedio);

				  float resultadoSalarioTotal;
				  calculateTotalSalary (arrayClienteRecibido, limiteArrayClienteRecibido, &resultadoSalarioTotal);

				  int contadorClienteConSueldoSuperioMedia;
				  counterEmployeesAbovePromediumSalary (arrayClienteRecibido, limiteArrayClienteRecibido, &contadorClienteConSueldoSuperioMedia, resultadoSalarioPromedio);

				  //Imprimimos todo
				  printf ("\n El salario promedio es de: %f"
						  "\n El salario total es de: %f "
						  "\n La cantidad de empleados con un sueldo mayor a la media es: %d \n", resultadoSalarioPromedio, resultadoSalarioTotal, contadorClienteConSueldoSuperioMedia);

			  }

		  }
		  else
		  {
			  printf ("\n No es posible modificar un cliente sin la existencia de uno como minimo.\n");
		  }

		}

		  return retorno;
	  }

	  int printEmployeesByLastName (Employee* arrayEmpleadoRecibido, int limiteArrayRecibido, int numeroAComparar)
	  {
		  int retorno = -1;

		  if (arrayEmpleadoRecibido != NULL && limiteArrayRecibido > 0 && numeroAComparar > 0)
		  {

			  for ( int i = 0 ; i < limiteArrayRecibido ; i++)
			  {
				  if (arrayEmpleadoRecibido[i].sector == numeroAComparar && arrayEmpleadoRecibido[i].isEmpty == 0)
				  {
					  printf ("\n Nombre: %s \n"
							  "\n Apellido: %s \n"
							  "\n Salario: %f \n"
							  "\n Sector: %d \n"
							  , arrayEmpleadoRecibido[i].name
							  , arrayEmpleadoRecibido[i].lastName
							  , arrayEmpleadoRecibido[i].salary
							  , arrayEmpleadoRecibido[i].sector);
				  }
			  }

		  }

		  return retorno;
	  }




	  int counterEmployeesAbovePromediumSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, int* pResultadoCantidadEmpleadosSobreSueldoPromedio, float valorSueldoPromedio)
	  {
		int retorno = -1;

		if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0 && pResultadoCantidadEmpleadosSobreSueldoPromedio != NULL && valorSueldoPromedio > 0)
		{
			int contadorEmpleados = 0;

			for ( int i = 0 ; i < limiteArrayClienteRecibido ; i++ )
			{
				if (arrayClienteRecibido[i].isEmpty == 0 && arrayClienteRecibido[i].salary > valorSueldoPromedio)
				{
					contadorEmpleados++;
				}
			}

			retorno = 0;
			*pResultadoCantidadEmpleadosSobreSueldoPromedio = contadorEmpleados;

		}

		return retorno;
	  }

	  int calculateTotalSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, float* pResultadoSalarioTotal)
	  {
		  int retorno = -1;

		  if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0 && pResultadoSalarioTotal != NULL)
		  {
			  retorno = -2;
			  int acumuladorDeSalario = 0;

			  for ( int i = 0 ; i < limiteArrayClienteRecibido ; i++ )
			  {
				  if (arrayClienteRecibido[i].isEmpty == 0)
				  {
					  acumuladorDeSalario = acumuladorDeSalario + arrayClienteRecibido[i].salary;
				  }
			  }

			  *pResultadoSalarioTotal = acumuladorDeSalario;
			  retorno = 0;
		  }


		  return retorno;
	  }

	  int calculateAverageSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, float* pResultado)
	  {
		int retorno = -1;

		if (arrayClienteRecibido != NULL && limiteArrayClienteRecibido > 0)
		{
			retorno = -2;

			 float acumuladorSalarios = 0;
			 int contadorDePersonasExistentes = 0;
			 float resultadoFinalSalarioPromedio;

			  //Acumulo todos los salarios de todos los clientes y cuento cuantos son.
			  for (int i = 0 ; i < limiteArrayClienteRecibido ; i++)
			  {
				  if (arrayClienteRecibido[i].isEmpty == 0) //Si encuentro un cliente, acumulo su salario al acumulador.
				  {
					  acumuladorSalarios =  + arrayClienteRecibido[i].salary + acumuladorSalarios;
					  contadorDePersonasExistentes++;
				  }
			  }

			  //Obtengo el promedio de salario.
			  resultadoFinalSalarioPromedio = acumuladorSalarios / contadorDePersonasExistentes;

			  //Lo retorno.
			  retorno = 0;
			  *pResultado = resultadoFinalSalarioPromedio;
		}

		  return retorno;
	  }
