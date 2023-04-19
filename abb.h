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
