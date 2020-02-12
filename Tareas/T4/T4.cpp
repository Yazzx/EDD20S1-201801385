#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace::std;

void OpcionesMenu();

struct cajita{
    char dato;
    cajita *a_siguiente;
    cajita *a_anterior;
}*a_primera, *a_ultima, *a_actual;

// 1

void insertarInicio(char caracter){

    cajita *nueva = new cajita(); // reservar memoria
    nueva->dato = caracter; // asignacion de informacion

    if(!a_primera){

        nueva->a_siguiente = NULL; // indica que está al final
        nueva->a_anterior = NULL; // indica que esta al inicio

        a_primera = nueva; // se le asigna como primero
        a_ultima = nueva; // se le asigna como último
    } else {

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

    a_ultima->a_anterior = a_actual;

    a_actual->a_siguiente = NULL;
    free(a_ultima);
    // si algo da clavo es lo de arriba

    a_ultima = a_actual;
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

    switch (opcion){
        case 1:
            corriendo = true;
            while (corriendo){

                cout<<"Ingresa los caracteres que deseas agregar"<<endl;
                cin>> c;

                if(c == 'e'){
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
            getch();
            OpcionesMenu();
            break;
        case 3:
            break;
        case 4:
            mostrarLista();
            getch();
            OpcionesMenu();
            break;
        case 5:
            cout<<"Haz salido del programa :D"<<endl;
            getch();
        default:
            cout<<"No puedes escoger esto :c"<<endl;
            getch();
            OpcionesMenu();
    }

}
