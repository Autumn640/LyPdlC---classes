#include <iostream> 
#include "Student.h"
#include <string>
using namespace std;

struct student{ //structura student
    string nombre;
    string carrera; 
    int edad; 
    int semestre;
};


int main(){
    student stud1;
    Student *obj1 = new Student();
    obj1->estudiar();

    cout << "Ingrese el nombre del estudiante: ";
    cin >> stud1.nombre;

    cout << "Ingrese la carrera del estudiante: ";
    cin >> ws;                    // descarta espacios/salto de línea sobrantes
    getline(cin, stud1.carrera);  // permite "ing sistemas" completo

    cout << "Ingrese la edad del estudiante: ";
    cin >> stud1.edad;

    cout << "Ingrese el semestre del estudiante: ";
    cin >> stud1.semestre;

    cout << "hola!" << stud1.nombre << " de " << stud1.carrera 
         << " y tiene " << stud1.edad << " años y está en el semestre " 
         << stud1.semestre << endl;

    return 0; 
}