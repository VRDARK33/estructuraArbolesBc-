/*Este es un programa en C++ que implementa un menú para manejar un Árbol Binario de Búsqueda (ABB). 
El código incluye un archivo de encabezado "abb.h" que contiene las declaraciones de las funciones necesarias 
para operar el árbol.
La función main() implementa el menú mediante un ciclo do-while. En cada iteración, 
se muestra el menú y se lee la opción elegida por el usuario mediante la variable op. 
Luego, se ejecuta la acción correspondiente según la opción elegida.
A continuación, se describe brevemente cada opción del menú:

insertar un nodo: se lee un número entero desde la entrada estándar y se inserta en el árbol mediante
la función insertar().

eliminar un nodo: se lee un número entero desde la entrada estándar y se elimina
del árbol mediante la función eliminar().

buscar un nodo: se lee un número entero desde la entrada estándar y se busca en el árbol mediante
la función buscar(). Si se encuentra el número, se imprime un mensaje indicando que se ha encontrado; de lo contrario,
se imprime un mensaje indicando que no se ha encontrado.

mostrar el arbol: se imprime el árbol completo mediante la función verArbol().

recorrer el arbol en EN-orden: se recorre el árbol en orden ascendente y se imprime cada nodo
visitado mediante la función enOrden().

recorrer el arbol en PRE-orden: se recorre el árbol en preorden y se imprime cada nodo visitado
mediante la función preOrden().

recorrer el arbol en POST-orden: se recorre el árbol en postorden y se imprime cada nodo visitado
mediante la función postOrden().

salir: se sale del programa.

Después de ejecutar cada opción del menú, se limpia la pantalla mediante la función system("cls") y se espera a
que el usuario presione cualquier tecla para continuar mediante la función system("pause").

En resumen, este programa implementa un menú para manejar un Árbol Binario de Búsqueda y proporciona
varias opciones para operar el árbol.*/

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