#include <iostream>
using namespace std;

// primera clase c++
int a = 5;
int *b = &a; //es a = b ? no! ya que un puntero solo guarda direcciones de memoria. Por que está entonces guardado como "int"? por que la direccion de memoria a la que apunta contiene un entero.

//ejemplo 

int betaValue;
int *intPtr = &betaValue; // intPtr es un puntero a un entero, y almacena la dirección de memoria de beta


//referenciar vs desreferenciar
//referenciar: obtener la dirección de memoria de una variable
//desreferenciar: obtener el valor almacenado en la dirección de memoria a la que apunta un puntero

int x = 10;
int *ptr = &x; // ptr es un puntero a un entero, y almacena la dirección de memoria de x
int y = *ptr; // y obtiene el valor almacenado en la dirección de memoria a la que apunta ptr, que es 10

int main() {
    //tambien se puede modificar el valor de x a través del puntero ptr
    *ptr = 20; // ahora x es igual a 20
    cout << y << endl; // esto imprimirá 10 en la consola

    //aritmetica de punteros 
    *ptr = 1; // esto asigna el valor 1 a x
    *ptr++; // esto incrementa el valor de x a 2
    cout << *ptr << endl; // esto imprimirá 2 en la consola
    

    return 0;
} 

//"<<" y ">>" son operadores de flujo de entrada y salida en C++. Se utilizan para leer y escribir datos desde y hacia la consola, respectivamente.
//"cin" es un objeto de flujo de entrada que se utiliza para leer datos desde la consola, mientras que "cout" es un objeto de flujo de salida que se utiliza para escribir datos en la consola. Por ejemplo, "cin >> variable;" lee un valor desde la consola y lo almacena en la variable, mientras que "cout << variable;" escribe el valor de la variable en la consola.

//delete x libera el espacio de memoria ocupado por la variable x, pero no elimina la variable en sí. En C++, cuando se utiliza "new" para asignar memoria dinámicamente, es importante liberar esa memoria utilizando "delete" para evitar fugas de memoria. Sin embargo, en el caso de variables locales como x, no es necesario usar "delete", ya que su memoria se libera automáticamente cuando la función termina.
