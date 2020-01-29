// aquí se meten las librerías
#include <iostream>
// esto es para el getch()
#include <conio.h>

// esto es para no poner std::cout

using namespace std;

int main() {
    int numerom;
    cout << "Por favor ingresa el numero de filas y columnas para su matriz :D" << endl;
    cin>> numerom;

    int matriz[numerom][numerom];

    //filas
    for (int i = 0; i < numerom; ++i) {
        
        //columnas
        for (int j = 0; j < numerom; ++j) {

            if( i == 0 ){
                matriz[0][j] = 1;
            }
            else if (i == numerom -1){
                matriz[numerom-1][j] = 1;
            }
            else{
                matriz[i][j] = 0;
            }

            if(j == 0){
                matriz[i][0] = 1;
            }
            else if (j == numerom-1){
                matriz[i][numerom-1] = 1;
            }

        }
    }

    // mostrando la matriz xd

    for (int k = 0; k < numerom; ++k) {
        for (int l = 0; l <numerom ; ++l) {
            cout<< matriz[k][l];
        }
        cout << "\n";
    }

    //cout << "\n";

    getch();
    return 0;

}
