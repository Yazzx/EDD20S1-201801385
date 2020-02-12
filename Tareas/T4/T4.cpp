#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace::std;

void OpcionesMenu();

struct cajita{
    char dato;
    cajita *a_siguiente;
    cajita *a_anterior;
}*a_primera, *a_ultima, *a_actual, *a_aux;

// 1

void buscar (string cadena){
    //cout<< cadena[0];
    char buscando = cadena[0];
    int contador = 0;

    if(!a_primera){
        cout<< "la lista está vacía :C";
        getch();
    }
    a_actual = a_primera;
    a_aux = NULL;

    while(a_actual->a_siguiente && a_actual->dato<buscando){
        a_aux = a_actual;
        a_actual = a_actual->a_siguiente;
        contador++;
    }

    cout<<"Posicion: "<< contador << " - Elemento: " << a_actual->dato<<endl;


}

void insertarInicio(char caracter){



    if(a_primera == NULL){

        a_primera = new(cajita); // reservar memoria

        a_primera->a_siguiente = NULL;
        a_primera->dato = caracter;


    } else {

        cajita *nueva = new cajita(); // reservar memoria
        nueva->dato = caracter; // asignacion de informacion

        nueva ->a_siguiente = a_primera;
        a_primera->a_anterior = nueva;

        nueva->a_anterior = NULL;

        a_primera = nueva;
    }
}

void mostrarLista(){
    int contador = 0;

    if(a_primera == NULL){
        cout<< "La lista está vacía :c"<<endl;
    }
    else{
        cout<<"\t \t LISTA DE CARACTERES"<<endl;
        cout<<" "<<endl;

        a_actual = a_primera;
         bool ultimo = false;

         while(!ultimo){
             cout<< "Correlativo: " << contador++ << " - Valor: '"<< a_actual->dato <<"'"<< endl;
            a_actual = a_actual->a_siguiente;

             if(a_actual == a_ultima){
                ultimo = true;
                break;
            }
         }

    }


}

void eliminarFinal(){

    //a_actual = new cajita;
    //a_aux = new cajita;

    a_actual = a_primera;

    while(a_actual->a_siguiente != NULL){

         a_aux= a_actual;
        a_actual = a_actual->a_siguiente;

    }

    a_ultima = a_aux;
    a_ultima->a_siguiente=NULL;
    delete(a_actual);

}

int main() {
    cout<< "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA"<<endl;
    cout<< "FACULTAD DE INGENIERIA"<<endl;
    cout<< "ESTRUCTURAS DE DATOS"<< endl;
    cout<< "TAREA  4"<< endl;
    cout<< "YASMON ELISA MONTERROSO ESCOBEDO"<< endl;
    cout<< "201801385" << endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    OpcionesMenu();
    return 0;
}

void OpcionesMenu(){


    cout<<"MENU DEL PROGRAMA:"<<endl;
    cout<<"1. Insertar nodo"<<endl;
    cout<<"2. Eliminar último"<<endl;
    cout<<"3. Buscar nodo"<<endl;
    cout<<"4. Ver lista"<<endl;
    cout<<"5. Salir"<<endl;

    int opcion;
    cin>>opcion;

    char c;
    bool corriendo;
    string busqueda;

    switch (opcion){
        case 1:
            corriendo = true;
            cout<<"El caracter de finalizacion es = '#'"<<endl;
            while (corriendo){

                cout<<"Ingresa un caracter"<<endl;
                cin>> c;

                if(c == '#'){
                    corriendo == false;
                    break;
                } else{
                    insertarInicio(c);
                }
            }

            mostrarLista();
            getch();
            OpcionesMenu();
            // aqui referencio las cosas que están en la clase Lista Doble
            break;
        case 2:
            eliminarFinal();
            mostrarLista();
            getch();
            OpcionesMenu();
            break;
        case 3:
            cout<<"Escribe a lo que quieras referenciar: "<<endl;
            cin>> busqueda;

            buscar(busqueda);
            getch();
            OpcionesMenu();

            break;
        case 4:
            mostrarLista();
            getch();
            OpcionesMenu();
            break;
        case 5:
            cout<<"Haz salido del programa :D"<<endl;
            exit(0);
        default:
            cout<<"No puedes escoger esto :c"<<endl;
            getch();
            OpcionesMenu();
    }

}
