/*
 * Desarrollo_func_tp_.c
 *
 *  Created on: 30 mar. 2021
 *      Author: gabil
 */

#include <stdio.h>
#include <stdlib.h>
#include "Prototipos_func_y_documentacion.h"

	/*
	 * \brief Suma los 2 valores recibidos en parametros y devuelve el resultado por referencia.
	 * \param operador1 float valor del operador 1.
	 * \param operador2 float valor del operador 2.
	 * \param direccionMem float* puntero a la variable resultado.
	 * \return int Retorna 0 al haber realizado la operacion.
	 */
	int sumar (float operador1, float operador2, float* direccionMem)
	{
		float resul;

		resul = operador1 + operador2;
		(*direccionMem) = resul;

		return 0;
	}


	/*
	 * \brief Resta los 2 valores recibidos en parametros y devuelve el resultado por referencia.
	 * \param operador1 float valor del operador 1.
	 * \param operador2 float valor del operador 2.
	 * \param direccionMem float* puntero a la variable resultado.
	 * \return int Retorna 0 al haber realizado la operacion.
	 */
	int restar (float operador1, float operador2, float* direccionMem )
	{
		float resul;

		resul = operador1 - operador2;
		*direccionMem = resul;

		return 0;
	}


	/*
	 * \brief Multiplica los 2 valores recibidos en parametros y devuelve el resultado por referencia.
	 * \param operador1 float valor del operador 1.
	 * \param operador2 float valor del operador 2.
	 * \param direccionMem float* puntero a la variable resultado.
	 * \return int Retorna 0 al haber realizado la operacion.
	 */
	int multiplicar (float operador1, float operador2, float* direccionMem)
	{
		float resul;
		resul = operador1 * operador2;
		*direccionMem = resul;

		return 0;
	}

	/*
	 * \brief Divide los 2 valores recibidos en parametros y devuelve el resultado por referencia.
	 * \param operador1 float valor del operador 1.
	 * \param operador2 float valor del operador 2.
	 * \param direccionMem float* puntero a la variable resultado.
	 * \return int Retorna 0 si la division entre los operadores fue posible, sino -1.
	 */
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

	/*
	 * \brief Obtiene el factorial de los 2 valores recibidos en parametros y devuelve el resultado por referencia.
	 * \param operador1 float valor del operador 1.
	 * \param operador2 float valor del operador 2.
	 * \param direccionMem float* puntero a la variable resultado.
	 * \return int Retorna 0 si el factorial de ambos operadores fue posible de expresarse, sino -1. (ya que int tiene un valor max)
	 */
	int factorial (float operador1, float* direccionMem)
	{
		int retornoDeError;
		retornoDeError = -1;

		if (operador1 < 0)
		{
			printf ("\nNo se puede obtener el factorial de un numero menor a 0.\n");
			retornoDeError = -2;
		}
		else if (operador1 > 20)
		{
			printf ("\nEl numero ingresado para factoriar es muy grande.\n");
			retornoDeError = -3;
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
