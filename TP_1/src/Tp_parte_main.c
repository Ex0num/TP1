/*
 ============================================================================
 Name        : TP_parte_main.c
 Author      : Gabriel Lopez G
 Version     :
 Copyright   : GLG
 Description : Hello World in C, Ansi-style
 ============================================================================
 Hacer una calculadora. Para ello el programa iniciará y contará con un
 a) Calcular la suma
 b) Calcular la resta
 c) Calcular la division
 d) Calcular la multiplicacion
 e) Calcular el factorial
 */

#include <stdio.h>
#include <stdlib.h>
#include "Prototipos_func_y_documentacion.h"

#define BIENVENIDA "Bienvenido/a. \nEn esta calculadora es posible calcular la suma, resta, division, multiplicacion, y factorial de dos numeros.\n"
#define INGRESOop "Primeramente, ingrese la letra que represente operacion a realizar.\nSuma (+)\nResta (-)\nMultiplicacion (*)\nDivision (/)\nFactorial (!)\n"
#define ERRORINGRESO1 "Hubo un error en el ingreso de su primer numero.\nReingreselo por favor.\n"
#define ERRORINGRESO2 "Hubo un error en el ingreso de su segundo numero.\nReingreselo por favor.\n"
#define INGRESENUM1 "Ingrese el primer numero.\n"
#define INGRESENUM2 "\nIngrese el segundo numero.\n"
#define ADVERTENCIAINGRESOFACTORIAL "Tenga en cuenta tambien, que no se puede obtener el factorial de un numero menor a 0.\n"
#define MENSAJE1ERNUM "Usted cargo satisfactoriamente como primer parametro el numero: %f"
#define MENSAJE2DONUM "Usted cargo satisfactoriamente como segundo parametro el numero: %f"

	int main(void)
	{
		setbuf(stdout,NULL);

		char operacionIngresada;
		float numero1Ingresado;
		float numero2Ingresado;
		int comprobacionNumero1;
		int comprobacionNumero2;
		float resultadoOperacion;

		printf (BIENVENIDA);
		printf (INGRESOop);
		fflush(stdin);
		scanf ("%c", &operacionIngresada);

		while (operacionIngresada != '+' && operacionIngresada != '-' && operacionIngresada != '*' && operacionIngresada != '/' && operacionIngresada != '!')
		{
			printf ("Error. Reingrese la operacion a realizar. (+) (-) (*) (/) (!)\n");
			fflush(stdin);
			scanf ("%c", &operacionIngresada);
		}

		switch (operacionIngresada)
		{
			case '+':
				{
					printf ("Necesitara dos numeros para realizar la suma.\n");
					printf (INGRESENUM1);
					fflush(stdin);
					comprobacionNumero1 = scanf ("%f", &numero1Ingresado);

					while (comprobacionNumero1 != 1)
					{
						printf (ERRORINGRESO1);
						fflush(stdin);
						comprobacionNumero1 = scanf ("%f", &numero1Ingresado);
					}

					printf (MENSAJE1ERNUM,numero1Ingresado);

					printf (INGRESENUM2);
					fflush(stdin);
					comprobacionNumero2 = scanf ("%f", &numero2Ingresado);

					while (comprobacionNumero2 != 1)
					{
						printf (ERRORINGRESO2);
						fflush(stdin);
						comprobacionNumero2 = scanf ("%f", &numero2Ingresado);
					}

					printf (MENSAJE2DONUM,numero2Ingresado);

					sumar (numero1Ingresado, numero2Ingresado, &resultadoOperacion);
					printf ("\nEl resultado de su suma es %f.", resultadoOperacion);
					break;
				}

			case '-':
				{
					printf ("Necesitara dos numeros para realizar la resta.\n");
					printf (INGRESENUM1);
					fflush(stdin);
					comprobacionNumero1 = scanf ("%f", &numero1Ingresado);

					while (comprobacionNumero1 != 1)
						{
							printf (ERRORINGRESO1);
							fflush(stdin);
							comprobacionNumero1 = scanf ("%f", &numero1Ingresado);
						}

					printf (MENSAJE1ERNUM,numero1Ingresado);

					printf (INGRESENUM2);
					fflush(stdin);
					comprobacionNumero2 = scanf ("%f", &numero2Ingresado);

					while (comprobacionNumero2 != 1)
						{
							printf (ERRORINGRESO2);
							fflush(stdin);
							comprobacionNumero2 = scanf ("%f", &numero2Ingresado);
						}

					printf (MENSAJE2DONUM,numero2Ingresado);

					restar (numero1Ingresado, numero2Ingresado, &resultadoOperacion);
					printf ("\nEl resultado de su resta es %f", resultadoOperacion);
					break;
				}

			case '*':
				{
					printf ("Necesitara dos numeros para realizar la multiplicacion.\n");
					printf (INGRESENUM1);
					fflush(stdin);
					comprobacionNumero1 = scanf ("%f", &numero1Ingresado);

					while (comprobacionNumero1 != 1)
						{
							printf (ERRORINGRESO1);
							fflush(stdin);
							comprobacionNumero1 = scanf ("%f", &numero1Ingresado);
						}

					printf (MENSAJE1ERNUM,numero1Ingresado);

					printf (INGRESENUM2);
					fflush(stdin);
					comprobacionNumero2 = scanf ("%f", &numero2Ingresado);

					while (comprobacionNumero2 != 1)
						{
							printf (ERRORINGRESO2);
							fflush(stdin);
							comprobacionNumero2 = scanf ("%f", &numero2Ingresado);
						}

					printf (MENSAJE2DONUM,numero2Ingresado);

					multiplicar (numero1Ingresado, numero2Ingresado, &resultadoOperacion);
					printf ("\nEl resultado de su multiplicacion es %f", resultadoOperacion);
					break;
				}

			case '/':
				{
					printf ("Necesitara dos numeros para realizar la division.\n");
					printf (INGRESENUM1);
					fflush(stdin);
					comprobacionNumero1 = scanf ("%f", &numero1Ingresado);

					while (comprobacionNumero1 != 1)
						{
							printf (ERRORINGRESO1);
							fflush(stdin);
							comprobacionNumero1 = scanf ("%f", &numero1Ingresado);
						}

					printf (MENSAJE1ERNUM,numero1Ingresado);

					printf (INGRESENUM2);
					fflush(stdin);
					comprobacionNumero2 = scanf ("%f", &numero2Ingresado);

					while (comprobacionNumero2 != 1 || numero2Ingresado == 0)
						{
							printf (ERRORINGRESO2);
							printf ("Tenga en cuenta tambien, que no se puede divir por 0.\n");
							fflush(stdin);
							comprobacionNumero2 = scanf ("%f", &numero2Ingresado);
						}

					printf (MENSAJE2DONUM,numero2Ingresado);

					dividir (numero1Ingresado, numero2Ingresado, &resultadoOperacion);
					printf ("\nEl resultado de su division es %f", resultadoOperacion);
					break;
				}

			case '!':
				{
					printf ("Necesitara dos numeros para realizar el factorial de cada uno de ellos.\n");
					printf (INGRESENUM1);
					fflush(stdin);
					comprobacionNumero1 = scanf ("%f", &numero1Ingresado);

					while (comprobacionNumero1 != 1 || numero1Ingresado < 0)
						{
							printf (ERRORINGRESO1);
							printf (ADVERTENCIAINGRESOFACTORIAL);
							fflush(stdin);
							comprobacionNumero1 = scanf ("%f", &numero1Ingresado);
						}

					printf (MENSAJE1ERNUM,numero1Ingresado);

					printf (INGRESENUM2);
					fflush(stdin);
					comprobacionNumero2 = scanf ("%f", &numero2Ingresado);

					while (comprobacionNumero2 != 1 || numero2Ingresado < 0)
						{
							printf (ERRORINGRESO2);
							printf (ADVERTENCIAINGRESOFACTORIAL);
							fflush(stdin);
							comprobacionNumero2 = scanf ("%f", &numero2Ingresado);
						}

					printf (MENSAJE2DONUM,numero2Ingresado);

					factorial (numero1Ingresado, &resultadoOperacion);
					printf ("\nEl factorial de su primer numero es %f\n", resultadoOperacion);

					factorial (numero2Ingresado, &resultadoOperacion);
					printf ("El factorial de su segundo numero es %f\n", resultadoOperacion);
					break;
				}
		}
	}
