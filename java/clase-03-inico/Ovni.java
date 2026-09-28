

public class Ovni {
    //atributos
    private String tipo;
    private String origen;



Ovni(String tipo, String origen){
    this.tipo = tipo;
    this.origen = origen;
   
}

Ovni(){}



//metodos
    public String volar(int km){ //"string" es el tipo de dato que devuelve el metodo
        System.out.println("El ovni esta volando a " + km + " km");
        return "El ovni esta volando a " + km + " km";
    }

    void abducirVacas(){
        System.out.println("El ovni esta abduciendo vacas");

    }

    void abducirAlumno(){
        System.out.println("El ovni esta abduciendo un alumno");

    }

    
}
