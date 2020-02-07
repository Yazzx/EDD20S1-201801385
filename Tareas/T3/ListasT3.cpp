// AVISO: el código está super super comentado para entender y
//      usarlo de referencia después :D

#include <iostream>
#include <stdlib.h>
using namespace std;

// para la estructura
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// OBJETO ESTUDIANTE 

class Alumno {
    private: // Atributos

        int carnet;
        string nombre;

    public: // metodos

    Alumno(long, string); // contructor
    Alumno();
    void getNombre(); // asi se inicializan los métodos
    void getCarnet();
};

Alumno::Alumno(){
    carnet = 201800000;
    nombre = "John Doe";
}
Alumno::Alumno(long _carnet, string _nombre){
    carnet = _carnet;
    nombre = _nombre;
}
void Alumno::getNombre(){
    cout<<"Mi nombre es: "<<nombre<<endl;
}
void Alumno::getCarnet(){
    cout<<"Mi nombre es: "<<carnet<<endl;
}

// LISTA

struct nodo{
    string i;
    // el alumno solo me funciona con una string :C
    nodo *s; // siguiente
    // abajo está la declaración del puntero
} *a, *i, *p, *e;
// actual, inicio, posicion, anterior

int buscar(string dato_proporcionado);
void insertar(string insertado);
void borrar(void);
void mostrar(void);
void MenuOpciones(void);
Alumno alumno;

// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN 

int main() {

    Alumno a1 = Alumno(201801385, "Yasmin");
    Alumno a2(20202017, "Peque");
    Alumno a3(201801386, "Manu");

    a1.estudiar();
    a2.estudiar();
    a3.estudiar();

    MenuOpciones();


    return 0;
}

// Menú desplegable 

void MenuOpciones(void) {
    int opcion;
    string nombre;

    do {
        string adato;
        string anombre;
        long acarnet;

        cout << "0- Salir" << endl;
        cout << "1- Inserar Alumno" << endl;
        cout << "2- Buscar Alumno" << endl;
        cout << "3- Eliminar Alumno" << endl;
        cout << "4- Ver lista" << endl;
        cin >> opcion;

        switch (opcion) {
            case 0:
                cout << "Has escogido salir :C" << endl;
                // tengo que eliminar la lista!!!

                exit(0);
            case 1:
                cout << "Ingrese el nombre del alumno" << endl;
                cin >> anombre;
                //alumno = Alumno(acarnet, anombre);
                insertar(anombre);
                break;
            case 2:
                cout << "Ingrese el nombre del alumno" << endl;
                cin >> adato;

                if (buscar(adato)) {
                    cout << "El alumno ya está registrado";
                } else {
                    cout << "El alumno no está ingresado aún :C";
                }
                getch();
                break;
            case 3:
                borrar();
                break;
            case 4:
                mostrar();
                break;
            default:
                cout << "Eso no se pone :C";
                getch();
        }
    } while (opcion);
}

// Opciones del menú

void mostrar(void){
    int contador = 1;
    if(!i){
        // SI NO HAY NODO CABEZA/INICO
        cout<< "no hay alumnos registrados :C";
        getch();
        return;
    }
    p = i;
    // p = nodo actual
    cout<< endl;
    while(p)
    {
        cout<< contador++<< " - Valor = " << p -> i << endl;
        p=p->s;
        // The -> operator in C or C++ gives the value 
        // held by variable_name to structure or union variable pointer_name.
    }
    cout<<"Ya! :D pulsa enter para continuar "<<endl;
    getch();
}

int buscar(string nombre){
    if(!i){
        cout<< "no hay alumnos registrados :C";
        getch();
        return(0);
    }
    p = i;
    a = NULL;
    // a = nodo auxiliar, como en Java!
    while(p->s && p->i<nombre){
        a = p;
        p = p->s;
    }
    return(p->i==nombre?1:0);
}

void borrar(void){
    string nombre;
    cout<<"Ingrese dato a eliminar: "<<endl;
    cin>>nombre;
    if(buscar(nombre))
    {
        if(a)
            a->s=p->s;
        else
            i=p->s;
        delete(p);
        // Delete is an operator that is used to 
        // destroy array and non-array(pointer) objects which are created by new expression.
        cout<<"Alumno borrado :D "<<endl;
    }
    else
        cout<<"El alumno no estudia acá xd"<<endl;
    getch();
}

void insertar (string insertado){

    if(!i)
    {
        // si no hay nada
        i=new(nodo);
        // crea el nodo cabeza
        i->s=NULL;
        // el siguiente del cabeza es null
        i->i=insertado;
        // asigna valor a nodo cabeza
        return;
    }

    // Metiendo un nodo nuevo a la cabeza

    e=new(nodo);
    e->i=insertado;
    // if a is a pointer to an object,
    // then a->b is accessing the property b of the object that points to.

    if(p == i){
        e->s=p;
        i=e;
        return;
    }

}



