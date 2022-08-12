// Quiz 1 y 2 Estructuras de datos
// Hecho por Jose Pablo Barquero Diaz

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct vagon
{
    char nombre;
    int asientos[6][6];
};

// Funcion que enlista los asientos disponibles
// en el formato [Nombre del vagon][# de fila]/[# de asiento]
void listDisponible(vagon train[])
{
    int count, c10 = 0, aux[6], fila, jCopia;
    string nFila, nAsiento, last10[10], first10[10];
    bool salir = false;

    // I Ciclo: Encontrar los 10 primeros asientos disponibles
    // Iteracion por vagon
    for (int i = 0; i < 2; i++) {

        // Iteracion por fila del vagon
        count = 0;
        for (const auto &fila : train[i].asientos) {
            count++;
            
            // Iteracion por asiento de la fila del vagon
            for (int j = 1; j < 7; j++) {

                // Finalizar una vez encontrados los 10 primeros
                if (c10 == 10)
                {
                    salir = true;
                    break;
                }

                // Revision del estado del asiento
                jCopia = j - 1;
                if (fila[jCopia] == 0)
                {
                    // Creacion de un string con los datos del asiento
                    string name(1, train[i].nombre);

                    stringstream ff;
                    ff << count;  
                    ff >> nFila;  
                    name += nFila;
                    name += "/";
                    stringstream aa;
                    aa << j;  
                    aa >> nAsiento;  
                    name += nAsiento;

                    // Insercion de los datos del asiento a la lista
                    first10[c10] = name;
                    c10++;
                }      
            }
            if (salir){break;} 
        }
        if (salir){break;}
    }
  

    // II Ciclo: Encontrar los 10 ultimos asientos disponibles
    // Iteracion por vagon
    c10 = 0; 
    salir = false;
    for (int i = 1; i >= 0; i--) {  

        // Iteracion por fila del vagon
        for (int f = 5; f >= 0; f--) {
            fila = f + 1;
    
            // Iteracion por asiento de la fila del vagon
            for (int j = 6; j >= 1; j--) {

                // Finalizar una vez encontrados los 10 primeros
                if (c10 == 10)
                {
                    salir = true;
                    break;
                }

                jCopia = j - 1;
                if (train[i].asientos[f][jCopia] == 0)
                {   
                    // Creacion de un string con los datos del asiento                    
                    string name(1, train[i].nombre);

                    stringstream ff;
                    ff << fila;  
                    ff >> nFila;  
                    name += nFila;
                    name += "/";
                    stringstream aa;
                    aa << j;  
                    aa >> nAsiento;  
                    name += nAsiento;

                    // Insercion de los datos del asiento a la lista
                    last10[c10] = name;
                    c10++;
                }    
            };
            if (salir){break;} 
        };
        if (salir){break;} 
    };
    
};

int main()
{
    vagon train[] = {
        {0x41, // Vagon A
//Asiento 1 2 3 4 5 6
        {{1,0,0,0,0,0},   // Fila 1
         {0,1,0,0,0,0},   // Fila 2
         {0,0,1,0,0,0},   // Fila 3
         {0,0,0,1,0,0},   // Fila 4
         {0,0,0,0,1,0},   // Fila 5
         {0,0,0,0,0,1}}}, // Fila 6
        {0x42, // Vagon B
//Asiento 1 2 3 4 5 6
        {{0,0,0,0,0,1},   // Fila 1
         {0,0,0,0,1,0},   // Fila 2
         {0,0,0,1,0,0},   // Fila 3
         {0,0,1,0,0,0},   // Fila 4
         {0,1,0,0,0,0},   // Fila 5
         {1,0,0,0,0,0}}}, // Fila 6

    };
    // Llamado a la funcion
    cout << "Procesando...\n";
    listDisponible(train);
    cout << "Proceso finalizado\n";
    return 0;
}

