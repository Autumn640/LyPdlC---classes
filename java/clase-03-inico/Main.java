public class Main {





    public static void main(String[] args) {

        Ovni ovni1 = new Ovni("No humano", "Marte"); //construccion de un objeto de la clase Ovni
        Ovni ovni2 = new Ovni(); //construccion de un objeto de la clase Ovni




        ovni1.volar(20000); //llamado al metodo volar de la clase Ovni
        ovni1.abducirVacas();

        
        ovni2.volar(15000); //llamado al metodo volar de la clase Ovni
        ovni2.abducirAlumno();




    }
}