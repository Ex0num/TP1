/*
 * Employee.h
 *
 *  Created on: 15 may. 2021
 *      Author: gabil
 */

	#ifndef EMPLOYEE_H_
	#define EMPLOYEE_H_

	struct
	{

	int idEmployee;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

	}typedef Employee;

	// STARTER FUNCTIONS
	int initEmployees (Employee* arrayRecibido, int limite);

	// PRINTERS FUNCTIONS
	int printEmployeeByIndex (Employee* arrayClienteRecibido, int limiteArrayCliente, int indiceIngresadoParaImprimir);
	int printEmployees (Employee* arrayClienteRecibido, int limiteArrayRecibido);
	int printEmployeesByLastName (Employee* arrayEmpleadoRecibido, int limiteArrayRecibido, int numeroAComparar);

	// FINDERS FUNCTIONS
	int findEmptyEmployeeIndex(Employee* arrayRecibido, int limite, int* pindiceVacioEncontrado);
	int findEmployeeById (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, char* mensajeParaPedidoID, char* mensajeParaErrorID, int* valorIndiceID);

	// COUNTERS FUNCTIONS
	int counterEmployeeOcuppiedIndex (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido);
	int counterEmployeesAbovePromediumSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, int* pResultadoCantidadEmpleadosSobreSueldoPromedio, float valorSueldoPromedio);

	// ACOMMODATION FUNCTIONS
	 int sortEmployees (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, int ordenObtenida);

	// CALCULATION FUNCTIONS
	int calculateAverageSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, float* pResultado);
	int calculateTotalSalary (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido, float* pResultadoSalarioTotal);


	// [A-B-M || C-R-U-D] FUNCTIONS
	int addEmployees (Employee* arrayClienteRecibido, int limiteArrayRecibido, int* pidIncrementableDeClientes);
	int removeEmployee (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido);
	int modificateEmployee (Employee* arrayClienteRecibido, int limiteArrayClienteRecibido);


	#endif /* EMPLOYEE_H_ */
