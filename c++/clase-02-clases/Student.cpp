#include "Student.h"   

Student::Student() {
    nombre = " ";
    carrera = " ";
    edad = 0;
    semestre = 0;   
}

void Student::estudiar() { //metodo de la clase
    cout << "El estudiante " << nombre << " está estudiando." << endl;
}