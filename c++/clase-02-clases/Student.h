#include <iostream>
using namespace std;

class Student {
    protected: //atributos de la clase
        string nombre;
        string carrera; 
        int edad; 
        int semestre;

    public: //metodos de la clase
        Student(); //constructor
        void estudiar(); //metodo

};