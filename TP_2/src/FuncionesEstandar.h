/*
 * Independiente-Funciones.h
 *
 *  Created on: 1 may. 2021
 *      Author: gabil
 */

	#ifndef FUNCIONESESTANDAR_H_
	#define FUNCIONESESTANDAR_H_

	int print_bye(void);
	int print_menu1 (void);
	int print_menu2 (void);
	int print_submenu (void);

	int utn_obtener_validar_Orden (char mensajeParaPedido[], char mensajeParaError[], int* pOrdenValidada);
	int utn_obtener_validar_Orden2 (char mensajeParaPedido[], char mensajeParaError[], int* pOrdenValidada);
	int utn_obtener_validar_orden_menu (char mensajeParaPedido[], char mensajeParaError[], int* pOrdenValidada);
	int utn_obtener_validar_Nombre (char mensajeParaPedido[], char mensajeParaError[], char* pCadenaAGuardar, int longitudCadenaAGuardar, int reintentos);
	int utn_obtener_validar_Edad (char mensajeParaPedido[], char mensajeParaError[], int* pEdadValidada, int reintentos);
	int utn_obtener_validar_Apellido (char mensajeParaPedido[], char mensajeParaError[], char* pCadenaAGuardar, int longitudCadenaAGuardar, int reintentos);
	int utn_obtener_validar_Cuit (char* mensajePedido, char* mensajeError, char* pGuardarCuit, int limitePunteroGuardarCuit, int reintentos);
	int utn_obtener_validar_Texto (char mensajeParaPedido[], char mensajeParaError[], char* pCadenaAGuardar, int longitudCadenaAGuardar, int reintentos);
	int utn_obtener_orden_si_no (char* mensajePedido, char* mensajeError, int reintentos);
	int utn_obtener_orden_A_to_C (char* mensajePedido, char* mensajeError);
	int utn_obtener_validar_Precio_Salario (char mensajeParaPedido[], char mensajeParaError[], float* pPrecioValidado, int reintentos);

	//int utn_obtener_validar_IdCliente

	#endif /* FUNCIONESESTANDAR_H_ */
