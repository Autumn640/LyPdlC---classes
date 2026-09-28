

public class Ovni {
    //atributos
    private String tipo;
    private String origen;



Ovni(String tipo, String origen){ //constructor con parametros para inicializar los atributos de la clase
    this.tipo = tipo;
    this.origen = origen;
   
}

Ovni(){}

public void setTipo(String tipo) { //metodo setter para asignar un valor al atributo tipo
    this.tipo = tipo;
}

public void setOrigen(String origen) { //metodo setter para asignar un valor al atributo origen
    this.origen = origen;
}

public String getTipo() { //metodo getter para obtener el valor del atributo tipo
    return tipo;
}

public String getOrigen() { //metodo getter para obtener el valor del atributo origen
    return origen;
}


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
