#include <iostream> 
#include "Student.h"
using namespace std;

struct student{ //structura student
    string nombre;
    string carrera; 
    int edad; 
    int semestre;
};


int main(){
    student stud1; //objeto simple de la estructura student
        Student *obj1 = new Student();
        obj1->estudiar(); //llamando al metodo estudiar de la clase Student



    cout << "Ingrese el nombre del estudiante: ";
    cin >> stud1.nombre;
    cout << "Ingrese la carrera del estudiante: ";
    cin >> stud1.carrera;
    cout << "Ingrese la edad del estudiante: ";
    cin >> stud1.edad;
    cout << "Ingrese el semestre del estudiante: ";
    cin >> stud1.semestre;

    cout << "hola! " << stud1.nombre << " de " << stud1.carrera << " y tiene " << stud1.edad << " años y está en el semestre " << stud1.semestre << endl;

    return 0; 
}