/*
 * Desarrollo_func_tp_.c
 *
 *  Created on: 30 mar. 2021
 *      Author: gabil
 */

#include <stdio.h>
#include <stdlib.h>
#include "Prototipos_func_y_documentacion.h"


	int sumar (float operador1, float operador2, float* direccionMem)
	{
		float resul;

		resul = operador1 + operador2;
		(*direccionMem) = resul;

		return 0;
	}

	int restar (float operador1, float operador2, float* direccionMem )
	{
		float resul;

		resul = operador1 - operador2;
		*direccionMem = resul;

		return 0;
	}

	int multiplicar (float operador1, float operador2, float* direccionMem)
	{
		float resul;
		resul = operador1 * operador2;
		*direccionMem = resul;

		return 0;
	}

	int dividir (float operador1, float operador2, float* direccionMem)
	{
		int retornoDeError;
		float resul;

		retornoDeError = -1;

		if (operador2 == 0)
		{
			printf ("\nNo se puede divir a un numero por 0.\n");
		}
		else
		{
			resul = operador1 / operador2;
			*direccionMem = resul;
			retornoDeError = 0;
		}

		return retornoDeError;
	}

	int factorial (float operador1, float* direccionMem)
	{
		int retornoDeError;
		retornoDeError = -1;

		if (operador1 < 0)
		{
			printf ("\nNo se puede obtener el factorial de un numero menor a 0.\n");
		}
		else
		{
			float resultadoFactorial;
			float multiplicacion;

			multiplicacion = 1;

			for (float i = 1 ; i <= operador1 ; i++ )
					{
						multiplicacion =  multiplicacion*i;
					}

			resultadoFactorial = multiplicacion;
			*direccionMem = resultadoFactorial;
			retornoDeError = 0;
		}

		return retornoDeError;
	}
