	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "LinkedList.h"


	static Node* getNode(LinkedList* this, int nodeIndex);
	static int addNode(LinkedList* this, int nodeIndex,void* pElement);

	/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
	 *
	 *  \param void
	 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
	 *                      o el puntero al espacio reservado
	 */
	LinkedList* ll_newLinkedList(void)
	{
		LinkedList* this;

		this = (LinkedList*)malloc(sizeof(LinkedList));

		if (this != NULL)
		{
			//Inicializo el puntero al primer nodo con null y el size en 0
			this->pFirstNode = NULL;
			this->size = 0;
		}
		return this;
	}

	/** \brief Retorna la cantidad de elementos de la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
	 *
	 */
	int ll_len(LinkedList* this)
	{
		int retorno = -1;

		if(this!=NULL)
		{
			//Retorno el campo size
			retorno = this->size;
		}
		return retorno;
	}


	/** \brief  Obtiene un nodo de la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param index int Indice del nodo a obtener
	 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							(pNode) Si funciono correctamente
	 */
	static Node* getNode(LinkedList* this, int indiceNodo)
	{
		Node* nodo = NULL; //Inicializo en NULL

		if(this != NULL && indiceNodo >= 0 && indiceNodo < ll_len(this))
		{
			//Guardo en nodo el primer nodo
			nodo = this->pFirstNode;

			for(int i = 0 ; i < indiceNodo ; i++)
			{
				//Reemplazo a nodo con el valor de next node hasta que llegue al indiceNodo.
				nodo = nodo->pNextNode;
			}
		}
		return nodo;
	}

	/** \brief  Permite realizar el test de la funcion getNode la cual es privada
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param index int Indice del nodo a obtener
	 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							(pElement) Si funciono correctamente
	 *
	 */
	Node* test_getNode(LinkedList* this, int nodeIndex)
	{
		return getNode(this, nodeIndex);
	}


	/** \brief Agrega y enlaza un nuevo nodo a la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
	 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							( 0) Si funciono correctamente
	 *
	 */
	static int addNode(LinkedList* this, int indiceNodo, void* pElement)
	{
		int retorno = -1;

		Node* nuevoNodo;
		Node* nodoAnterior;

		if(this != NULL && indiceNodo >= 0 && indiceNodo <= ll_len(this))
		{
			//Pido nuevo nodo
			nuevoNodo = (Node*)malloc(sizeof(Node));

			if(nuevoNodo != NULL)
			{
				//Le asgino el puntero al elemento
				nuevoNodo->pElement = pElement;

				//Si es el primer nodo
				if(indiceNodo == 0)
				{
					//Simplemente intercambio valores
					nuevoNodo->pNextNode = this->pFirstNode;
					this->pFirstNode = nuevoNodo;
				}
				else
				{
					//Si no es el primero busco el nodo anterior al indice.
					nodoAnterior = getNode(this,indiceNodo-1);

					if(nodoAnterior != NULL)
					{
						//En el nuevo nodo.nextNode guardo el nextNode del nodo anterior
						nuevoNodo->pNextNode = nodoAnterior->pNextNode;

						//Y en el nodo anterior nexNode guardo el puntero que vale nuevoNodo
						nodoAnterior->pNextNode = nuevoNodo;
					}
				}

				//Incremento el size en uno.
				this->size++;

				retorno = 0;
			}
		}
		return retorno;
	}

	/** \brief Permite realizar el test de la funcion addNode la cual es privada
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
	 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
	  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							( 0) Si funciono correctamente
	 *
	 */
	int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
	{
		return addNode(this,nodeIndex,pElement);
	}


	/** \brief  Agrega un elemento a la lista
	 * \param pList LinkedList* Puntero a la lista
	 * \param pElement void* Puntero al elemento a ser agregado
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							( 0) Si funciono correctamente
	 *
	 */
	int ll_add(LinkedList* this, void* pElement)
	{
		int retorno = -1;

		if(this != NULL)
		{
			int resultadoAddNode;

			//Agrego un nodo con el indice igual al largo de la lista (y el elemento)
			resultadoAddNode = addNode(this,ll_len(this),pElement);

			if(resultadoAddNode == 0)
			{
				retorno = 0;
			}
		}
		return retorno;
	}

	/** \brief Permite realizar el test de la funcion addNode la cual es privada
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion del elemento a obtener
	 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
								(pElement) Si funciono correctamente
	 *
	 */
	void* ll_get(LinkedList* this, int index)
	{
		void* retorno = NULL;

		Node* nodoAux;

		if(this != NULL && index >= 0 && index < ll_len(this))
		{
			//En el pNodoAux guardo el nodo que me devolvio el getNode con el index
			nodoAux = getNode(this,index);

			//Si lo encontre
			if(nodoAux != NULL)
			{
				//Devuelvo el elemento
				retorno = nodoAux->pElement;
			}
		}
		return retorno;
	}


	/** \brief Modifica un elemento de la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion del elemento a modificar
	 * \param pElement void* Puntero al nuevo elemento
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							( 0) Si funciono correctamente
	 *
	 */
	int ll_set(LinkedList* this, int index,void* pElement)
	{
		int retorno = -1;
		Node *pNodeAux;

		if (this != NULL && index >= 0 && index < ll_len(this))
		{
			//Obtengo el puntero al Nodo con el indice ingresado en param
			pNodeAux = getNode(this, index);

			//Si existe el nodo en ese indice
			if (pNodeAux != NULL)
			{
				//Cambio el valor del puntero al Elemento del nodo encontrado por el nuevo.
				pNodeAux->pElement = pElement;
				retorno = 0;
			}
		}

		return retorno;
	}


	/** \brief Elimina un elemento de la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion del elemento a eliminar
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							( 0) Si funciono correctamente
	 *
	 */
	int ll_remove(LinkedList* this,int index)
	{
		int retorno = -1;

		Node* pNodoAux;
		Node* pNodeAnterior;

		if(this != NULL && index>= 0 && index < ll_len(this))
		{
			//Obtengo el nodo del cual pertenece al indice de parametros.
			pNodoAux = getNode(this,index);

			//Si existe
			if(pNodoAux != NULL)
			{

				//Si es el primero
				if(index == 0)
				{
					//En el pPrimerNodo guardo el 2do nodo (como primero).
					this->pFirstNode = pNodoAux->pNextNode;
				}
				else //Si no es el primero
				{
					//Guardo el nodo anterior (index-1)
					pNodeAnterior = getNode(this,index-1);
					if(pNodeAnterior != NULL)
					{
						pNodeAnterior->pNextNode = pNodoAux->pNextNode;
					}
				}

				//Libero la memoria del nodo que pertenecia al elemento.
				free(pNodoAux);

				//Decremento el size de la ll.
				this->size--;

				retorno = 0;
			}
		}
		return retorno;
	}


	/** \brief Elimina todos los elementos de la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							( 0) Si funciono correctamente
	 *
	 */
	int ll_clear(LinkedList* this)
	{
		int retorno = -1;

		if(this!=NULL)
		{
			int resultadoRemove;

			for(int i = 0 ; i < ll_len(this) ; i++)
			{
				//Remuevo el nodo y elemento del valor de I. (Hasta el largo de la ll)
				resultadoRemove = ll_remove(this,i);

				//Si el remove salio bien
				if(resultadoRemove == 0)
				{
					retorno = 0;
				}
				else
				{
					//Si en alguna ocasion sale mal, retorno error.
					retorno = -1;
					break;
				}
			}
		}
		return retorno;
	}


	/** \brief Elimina todos los elementos de la lista y la lista
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							( 0) Si funciono correctamente
	 *
	 */
	int ll_deleteLinkedList(LinkedList* this)
	{
		int retorno = -1;

		if(this != NULL)
		{
			int resultadoClear;

			//Hago un clear de la linkedList.
			resultadoClear = ll_clear(this);

			//Si sale bien y ya libere la memoria de todos los nodos y elementos
			if(resultadoClear == 0)
			{
				//Libero finalmente la linkedlist.
				free(this);
				retorno = 0;
			}
		}
		return retorno;
	}

	/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param pElement void* Puntero al elemento
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							(indice del elemento) Si funciono correctamente
	 *
	 */
	int ll_indexOf(LinkedList* this, void* pElemento)
	{
		int retorno = -1;

		//Me creo un elemento auxiliar
		void* pElementAux;

		if(this != NULL)
		{
			for(int i = 0 ; i < ll_len(this) ; i++)
			{
				//En el elemento auxiliar guardo lo que obtenga del get en el indice I
				pElementAux = ll_get(this,i);

				//Si el pElemento del get coincide con el ingresado en param, corto el for y devuelvo el index.
				if(pElementAux == pElemento)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
	}

	/** \brief Indica si la lista esta o no vacia
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							( 0) Si la lista NO esta vacia
							( 1) Si la lista esta vacia
	 *
	 */
	int ll_isEmpty(LinkedList* this)
	{
		int retorno = -1;

		if(this != NULL)
		{
			//Simplemente obtengo el largo de la linkedlist.
			int longitudll;
			longitudll = ll_len(this);

			//Si su longitud es 0
			if(longitudll == 0)
			{
				//Lista vacia
				retorno = 1;
			}
			else if (longitudll > 0)
			{
				//Lista con 1 o mas elementos
				retorno = 0;
			}
		}
		return retorno;
	}

	/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
	 * \param pElement void* Puntero al nuevo elemento
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
							( 0) Si funciono correctamente
	 *
	 */
	int ll_push(LinkedList* this, int index, void* pElement)
	{
		int retorno = -1;

		if(this != NULL && index>=0 && index<=ll_len(this))
		{
			int resultadoAddNode;

			//LLamo a mi funcion add node y le ingreso el elemento y el indice
			resultadoAddNode = addNode(this,index,pElement);

			//Si sale bien el add
			if(resultadoAddNode == 0)
			{
				retorno = 0;
			}
		}
		return retorno;
	}


	/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param nodeIndex int Ubicacion del elemento eliminar
	 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
								(pElement) Si funciono correctamente
	 *
	 */
	void* ll_pop(LinkedList* this,int index)
	{
		void* retorno = NULL;
		void* pElementAux;

		if(this != NULL && index>=0 && index<ll_len(this))
		{
			//Primero verifico si existe el elemento de la posicion indicada y lo obtengo
			pElementAux = ll_get(this,index);

			if (pElementAux != NULL) //Si existe
			{
				//Lo remuevo
				int resultadoRemove;
				resultadoRemove = ll_remove(this,index);

				//Si el remove salio bien
				if(resultadoRemove == 0)
				{
					retorno = pElementAux;
				}
			}
		}
		return retorno;
	}


	/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param pElement void* Puntero del elemento a verificar
	 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
							( 1) Si contiene el elemento
							( 0) si No contiene el elemento
	*/
	int ll_contains(LinkedList* this, void* pElement)
	{
		int retorno = -1;

		if(this != NULL)
		{
			//Verifico el indice del elemento
			int indiceElemento;
			indiceElemento = ll_indexOf(this,pElement);

			//Si el valor que devuelve es mayor o igual a 0
			if(indiceElemento >= 0)
			{
				retorno = 1;
			}
			else
			{
				//Si no encontro ningun elemento retorna -1
				retorno = 0;
			}

		}
		return retorno;
	}

	/** \brief  Determina si todos los elementos de la lista (this2)
				estan contenidos en la lista (this)
	 *
	 * \param this LinkedList* Puntero a la lista
	 * \param this2 LinkedList* Puntero a la lista
	 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
							( 1) Si los elementos de (this2) estan contenidos en la lista (this)
							( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
	*/
	int ll_containsAll(LinkedList* this, LinkedList* this2)
	{
		int retorno = -1;

		if(this != NULL && this2 != NULL)
		{
			void* pElemento;
			retorno = 1;

			//Recorro hasta el size de la ll-2
			for(int i = 0 ; i < ll_len(this2) ; i++)
			{
				//Obtengo cada elemento
				pElemento = ll_get(this2, i);

				//Pregunto si existe el elemento y pregunto si NO existe en la ll-1
				if(pElemento != NULL && ll_contains(this, pElemento) == 0)
				{
					retorno = 0;
					break;
				}

				//Hago lo mismo con el siguiente elemento de la lista.
			}
		}
		return retorno;
	}

	/** \brief Crea y retorna una nueva lista con los elementos indicados
	 *
	 * \param pList LinkedList* Puntero a la lista
	 * \param from int Indice desde el cual se copian los elementos en la nueva lista
	 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
	 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
									o (si el indice from es menor a 0 o mayor al len de la lista)
									o (si el indice to es menor o igual a from o mayor al len de la lista)
							 (puntero a la nueva lista) Si ok
	*/
	LinkedList* ll_subList(LinkedList* this,int from,int to)
	{
		//Creo el puntero donde guardo la nueva ll
		LinkedList* pNewll = NULL;

		if(this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this) && from < to)
		{
			//Creo el un puntero a elemento que voy a usar para el traspaso.
			void* pElement;

			//Creo nueva ll
			pNewll = ll_newLinkedList();

			//Si se creo bien
			if (pNewll != NULL)
			{

				for(int i = from ; i < to ; i++)
				{
					//Obtengo el elemento de la primera ll
					pElement = ll_get(this, i);

					//Si existe
					if(pElement != NULL)
					{
						//Lo agrego a la nueva ll
						ll_add(pNewll,pElement);
					}

					//Hago ese "traspaso" con todos los elementos de la ll de param. (Desde from hasta to).
				}
			}
		}

		return pNewll;
	}



	/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
	 *
	 * \param pList LinkedList* Puntero a la lista
	 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
									(puntero a la nueva lista) Si ok
	*/
	LinkedList* ll_clone(LinkedList* this)
	{
		//Creo el puntero a la nueva ll clonada.
		LinkedList* pllClonada = NULL;

		if(this != NULL)
		{
			//Le otorgo el valor de sublist para que cree una linked list desde el indice 0 hasta el ultimo.
			pllClonada = ll_subList(this,0,ll_len(this));
		}

		return pllClonada;
	}


	/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
	 * \param pList LinkedList* Puntero a la lista
	 * \param pFunc (*pFunc) Puntero a la funcion criterio
	 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
	 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
									( 0) Si ok
	 */
	int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
	{
		int retorno =-1;

		if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
		{
			int flagEstadoDesordenado = 1;
			int criterio;

			void* pElement;
			void* pElement2;

			//Mientras que el flag de desorden este en 1
			while (flagEstadoDesordenado == 1)
			{
				//Flag desorden vale 0
				flagEstadoDesordenado = 0;

				//Recorro la ll hasta su ultimo elemento
				for (int i = 0; i < ll_len(this)- 1; i++)
				{
					//Obtengo el el elemento
					pElement = ll_get(this,i);

					//Obtengo el elemento siguiente
					pElement2 = ll_get(this,i+1);

					//Guardo mi resultado de la funcion criterio pasada
					criterio = pFunc(pElement,pElement2);

					//Si el orden es 1 (ascendente) y el criterio es 1 o El orden es 0 (descendente) y el criterio es -1
					if ( (order == 1 && criterio == 1) || (order == 0 && criterio == -1))
					{
						//Seteo el segundo elemento donde iba el primero y el primero donde iba el segundo, (los invierto).
						ll_set(this,i,pElement2);
						ll_set(this,i+1,pElement);

						//Pongo el flag en desordenado
						flagEstadoDesordenado = 1;
					}

					//Hago esto con cada elemento.
				}

				//Hago esto cada vez que se intercambie un elemento. Si ya no se intercambio ninguno, termina el sort.
			}
			retorno = 0;
		}
		return retorno;
	}

