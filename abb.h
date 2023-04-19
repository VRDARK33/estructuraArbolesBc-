/*Este es un programa en C++ que implementa un árbol binario de búsqueda (ABB) y ofrece las siguientes funciones:

crearNodo: crea un nuevo nodo en el árbol con el valor proporcionado.
insertar: inserta un nuevo nodo con el valor proporcionado en el árbol.
preOrden: imprime los valores de los nodos del árbol en preorden.
enOrden: imprime los valores de los nodos del árbol en orden.
postOrden: imprime los valores de los nodos del árbol en postorden.
verArbol: imprime el árbol de forma gráfica.
buscar: busca un valor en el árbol y devuelve true si lo encuentra, false en caso contrario.
eliminar: elimina un nodo con el valor proporcionado del árbol.
En cuanto a su implementación, se utiliza una estructura nodo que contiene el valor del nodo, 
así como dos punteros a otros nodos, uno para el hijo izquierdo y otro para el hijo derecho. Además, se define el tipo
ABB como un puntero a un nodo, para facilitar la manipulación del árbol.

La función insertar es la que se encarga de insertar un nuevo nodo en el árbol, siguiendo la regla del ABB
de insertar valores menores a la izquierda y valores mayores a la derecha. Las funciones de impresión
(preOrden, enOrden, postOrden y verArbol) utilizan los algoritmos correspondientes para recorrer
el árbol y mostrar los valores de los nodos en el orden deseado.

La función buscar recibe un valor a buscar y lo busca en el árbol siguiendo la misma regla del ABB.
La función devuelve true si el valor se encuentra en el árbol y false en caso contrario.

Finalmente, la función eliminar elimina un nodo con el valor proporcionado del árbol. Para ello, se comprueba
si el árbol está vacío, si el valor a eliminar es menor o mayor que el valor del nodo actual, o si el nodo
a eliminar tiene uno o dos hijos. En función de cada caso, se toman distintas acciones para mantener la estructura
del árbol.*/


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct nodo{
     int nro;
     nodo *izq;
	 nodo *der;
};
typedef nodo *ABB;

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     return nuevoNodo;
}
//-------------------------------------------------------------------
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}
//-------------------------------------------------------------------
void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}
//-------------------------------------------------------------------
void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}
//-------------------------------------------------------------------
void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}
//-------------------------------------------------------------------

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
         return;
     verArbol(arbol->der, n+1);
     for(int i=0; i<n; i++)
         cout<<"   ";
     cout<< arbol->nro <<endl;
     verArbol(arbol->izq, n+1);
}


//-------------------------------------------------------------------
 

bool buscar(ABB arbol, int dato)
{
     int r=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = buscar(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = buscar(arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}


void eliminar(ABB &arbol, int x)
{
    if(arbol == NULL)
        return;
    
    if(x < arbol->nro)
        eliminar(arbol->izq, x);
    else if(x > arbol->nro)
        eliminar(arbol->der, x);
    else
    {
        // caso 1: nodo sin hijos
        if(arbol->izq == NULL && arbol->der == NULL)
        {
            delete arbol;
            arbol = NULL;
        }
        // caso 2: nodo con un solo hijo
        else if(arbol->izq == NULL)
        {
            ABB aux = arbol;
            arbol = arbol->der;
            delete aux;
        }
        else if(arbol->der == NULL)
        {
            ABB aux = arbol;
            arbol = arbol->izq;
            delete aux;
        }
        // caso 3: nodo con dos hijos
        else
        {
            ABB sucesor = arbol->der;
            while(sucesor->izq != NULL)
                sucesor = sucesor->izq;
            
            arbol->nro = sucesor->nro;
            eliminar(arbol->der, sucesor->nro);
          }
     }
}
