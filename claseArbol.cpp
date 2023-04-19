#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"abb.h"
using namespace std;

//crear una funcion menu que permita al usuario elegir entre las opciones:
//1. insertar un nodo
//2. eliminar un nodo
//3. buscar un nodo
//4. mostrar el arbol
//5. recorrer el arbol en EN-orden
//6. recorrer el arbol en PRE-orden
//7. recorrer el arbol en POST-orden
//8. salir

int main()
{
    ABB arbol = NULL; //crear un arbol vacio
    int x;
    int op;
    do
    {
        cout << "1. insertar un nodo" << endl;
        cout << "2. eliminar un nodo" << endl;
        cout << "3. buscar un nodo" << endl;
        cout << "4. mostrar el arbol" << endl;
        cout << "5. recorrer el arbol en EN-orden" << endl;
        cout << "6. recorrer el arbol en PRE-orden" << endl;
        cout << "7. recorrer el arbol en POST-orden" << endl;
        cout << "8. salir" << endl;
        cout << "ingrese una opcion: ";
        cin >> op;
        cout<<endl;
        switch(op)
        {
            case 1:
                cout << "ingrese un numero: ";
                cin >> x;
                insertar(arbol, x);
                break;
            case 2:
                cout << "ingrese un numero: ";
                cin >> x;
                eliminar(arbol, x);
                break;
            case 3:
                cout << "ingrese un numero: ";
                cin >> x;
                buscar(arbol, x);
                break;
            case 4:
                cout << "mostrar el arbol" << endl<<endl;
                verArbol(arbol, 0);
                break;
            case 5:
                cout << "recorrer el arbol en EN-orden" << endl;
                enOrden(arbol);
                break;
            case 6:
                cout << "recorrer el arbol en PRE-orden" << endl;
                preOrden(arbol);
                break;
            case 7:
                cout << "recorrer el arbol en POST-orden" << endl<<endl;
                postOrden(arbol);
                break;
            case 8:
                cout << "salir" << endl;
                break;
            default:
                cout << "opcion incorrecta" << endl;
                break;
        }
        cout << endl;
        system("pause");
	    system("cls");
    }while(op!=8);
    return 0;
}