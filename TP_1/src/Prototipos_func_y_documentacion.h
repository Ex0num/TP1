/*
 * Prototipos_func_y_documentacion.h
 *
 *  Created on: 30 mar. 2021
 *      Author: gabil
 */

#ifndef PROTOTIPOS_FUNC_Y_DOCUMENTACION_H_
#define PROTOTIPOS_FUNC_Y_DOCUMENTACION_H_

//PROTOTIPOS.

int sumar (float operador1, float operador2, float* direccionMem);

int restar (float operador1, float operador2, float* direccionMem );

int multiplicar (float operador1, float operador2, float* direccionMem);

int dividir (float operador1, float operador2, float* direccionMem);

int factorial (float operador1, float* direccionMem);

//DOCUMENTACION. (ESTILO BASADO: Doxygen)

//sumar
/** \brief - Recibe dos numeros para sumarlos y una direccion de memoria para mostrar el resultado.
 *  \param - operador1 - Es el primer numero a sumar.
 *  \param - operador2 - Es el segundo numero a sumar.
 *  \return - Retorna 0 como un valor representativo a que salió todo bien.
*/

//restar
/** \brief - Recibe dos numeros para restarlos y una direccion de memoria para mostrar el resultado.
 *  \param - operador1 - Es el primer numero el cual sera restado.
 *  \param - operador2 - Es el segundo numero el cual restara al primero.
 *  \return - Retorna 0 como un valor representativo a que salió todo bien.
*/

//multiplicar
/** \brief - Recibe dos numeros para multiplicarlos entre si, y una direccion de memoria para mostrar el resultado.
 *  \param - operador1 - Es el primer numero a multiplicarse por el segundo.
 *  \param - operador2 - Es el segundo numero a multiplicarse por el primero.
 *  \return - Retorna 0 como un valor representativo a que salió todo bien.
*/

//dividir
/** \brief - Recibe dos numeros para divir el primero por el segundo y una direccion de memoria para mostrar el resultado.
 *  \param - operador1 - Es el primer numero el cual sera dividido por el segundo.
 *  \param - operador2 - Es el segundo numero el cual dividira al primero.
 *  \return - Retorna 0 como un valor representativo a que salió todo bien.
*/

//factorial
/** \brief - Recibe un numero para obtener su factorial y una direccion de memoria para mostrar el resultado.
 *  \param - operador1 - Es numero del cual se obtendra su factorial.
 *  \return - Retorna 0 como un valor representativo a que salió todo bien.
*/

#endif /* PROTOTIPOS_FUNC_Y_DOCUMENTACION_H_ */
