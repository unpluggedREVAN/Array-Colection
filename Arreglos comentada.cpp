// Laboratorio de Arreglos, Struct y Colecciones dinámicas
// Colección estática original comentada
// Katerine Guzmán Flores (2019390523), Jose Pablo Agüero Mora (2021126372) / Grupo 2 /
// Arreglos-Structs-1.cpp 


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

// CONSTANTES
const int Max = 100; // constante maxima para el arreglo
const float Pi = 3.1416; // constante para arreglo de flotantes

//Un STRUCT es una coleccion de elementos de distinto tipo de dato.
typedef struct RegistroTSE { // este es el nuevo tipo de dato
    // subcampos del struct 
    int cedula;
    string nombre;
    string apellido;
    bool sexo;
    float altura;
} *PtrRegistroTSE; // el * define de que es un puntero, y apunta a RegistroTSE

int main()
{

    int i;//contador 

    //Un arreglo es una coleccion de elementos del mismo tipo de dato.

    /*ARREGLO DE ENTEROS--------------------------*/
    int arregloEnteros[Max];
    // Cargando arreglo Enteros
    cout << "Cargando arreglo de Enteros" << endl;
    for (i = 0; i <= Max - 1; i++)
    {
        arregloEnteros[i] = i;
    }
    // Pintando arreglo Enteros
    cout << "Pintando arreglo de Enteros" << endl;
    for (i = 0; i <= Max - 1; i++)
    {
        cout << arregloEnteros[i] << ", "; // se van imprimiendo los enteros con comas
    }
    cout << endl; // cambio linea

    /*ARREGLO DE CARACTERES----------------------------*/
    char arregloCaracteres[Max]; // se declara el arreglo de tamano max con elemtnos char
    // Cargando arreglo Caracteres
    cout << "Cargando arreglo de Caracteres" << endl; // Se pinta en pantalla el rotulo
    for (i = 0; i <= Max - 1; i++)
    {
        arregloCaracteres[i] = char(i + 32); //  se le suman 32 porque en la tabla ASCII los primeros 32 bits no son visibles
    }
    // Pintando arreglo Caracteres
    cout << "Pintando arreglo de Caracteres" << endl; // Una vez que se cargan se pintan
    for (i = 0; i <= Max - 1; i++) // ciclo for desde 0 hasta 99
    {
        cout << arregloCaracteres[i] << ", "; // se empiezan a imprimir con una coma cada caracter
    }
    cout << endl; // se imprime cambio de linea

    /*ARREGLO DE FLOTANTES-------------------------------*/
    float arregloReales[Max];
    // Cargando arreglo Flotantes o Reales
    cout << "Cargando arreglo de Flotantes" << endl; // se carga arreglo de enteros
    for (i = 0; i <= Max - 1; i++)
    {
        arregloReales[i] = i * Pi; // Aqui se multiplica el valor del indice por 3.1416
    }
    // Pintando arreglo Flotantes o Reales
    cout << "Pintando arreglo de Flotantes" << endl; // Se pinta arreglo que va multiplicando de 0 a 99 por PI la constante
    for (i = 0; i <= Max - 1; i++)
    {
        cout << arregloReales[i] << ", ";
    }
    cout << endl;

    /*ARREGLO DE BOOLEANOS------------------------------*/
    bool arregloBooleanos[Max]; // Se declara como arreglo de booleanos de dimension max de tipo bool
    // Cargando arreglo Booleanos
    cout << "Cargando arreglo de Booleanos" << endl;
    for (i = 0; i <= Max - 1; i++)
    {
        if (i % 2 == 0) // se pregunta si el numero es par
            arregloBooleanos[i] = true; // se le asigna 1
        else
            arregloBooleanos[i] = false; // sino se le asigna un cero
    }// Pintando arreglo Booleanos
    cout << "Pintando arreglo de Booleanos" << endl; // Se pintan intercalados unos y ceros
    for (i = 0; i <= Max - 1; i++)
    {
        cout << arregloBooleanos[i] << ", ";
    }
    cout << endl;


    /*STRUCT ESTATICO DE VOTANTE DEL TSE-------------------*/
    RegistroTSE Votante; // se declara una variable estatica de tipo RegistroTSE, ya ocupa memoria el registro
    // Cargando Struct ESTATICO de 1 Votante del TSE, se denota valor por valor
    cout << "Cargando Struct Estatico de 1 Votante del TSE" << endl;
    // los subcampos se acceden con el punto en los registros(struct) estaticos
    Votante.cedula = 9999;
    Votante.nombre = "Lucifer";
    Votante.apellido = "Coronavirus";
    Votante.sexo = true;
    Votante.altura = 1.90;
    // Pintando Struct ESTATICO de 1 Votante del TSE
    cout << "Pintando Struct Estatico de 1 Votante del TSE" << endl; // se imprime toda la info del votante
    cout << Votante.cedula << " / " << Votante.nombre << " / " <<
        Votante.apellido << " / " << Votante.sexo << " / " << Votante.altura;
    cout << endl;
    cout << endl;


    /* Cargando Struct Estatico de 1 Votante del TSE
       Pintando Struct Estatico de 1 Votante del TSE
       9999 / Lucifer / Coronavirus / 1 / 1.9
    */

    /*STRUCT DINAMICO DE VOTANTE DEL TSE------------*/

    PtrRegistroTSE Puntero_a_Votante; // al ser puntero es un espacio en memoria que sirve para almacenar una direccion en memoria a otra variable
    // sl puntero votante le inicializamos un nuevo espacio de memoria que toma forma dinamica con 5 campos
    // A esos 5 espacios en memoria el puntero nos devuelve la coordenada del primer byte de esa agrupacion
    Puntero_a_Votante = new(RegistroTSE);

    // Cargando Struct DINAMICO de 1 Votante del TSE
    cout << "Cargando Struct Dinamico de 1 Votante del TSE" << endl;
    // La forma de llegarle a los campos internos de la struct es con ->
    Puntero_a_Votante->cedula = 6666;
    Puntero_a_Votante->nombre = "Damian";
    Puntero_a_Votante->apellido = "Covid";
    Puntero_a_Votante->sexo = false;
    Puntero_a_Votante->altura = 1.50;

    // Pintando Struct DINAMICO de 1 Votante del TSE
    // Se usa el puntero para todo porque es el unico que conoce donde esta ubicado el struct
    cout << "Pintando Struct Dinamico de 1 Votante del TSE" << endl;
    cout << Puntero_a_Votante->cedula << " / " << Puntero_a_Votante->nombre << " / " <<
        Puntero_a_Votante->apellido << " / " << Puntero_a_Votante->sexo << " / " <<
        Puntero_a_Votante->altura;


    /*
       Cargando Struct Estatico de 1 Votante del TSE
       Pintando Struct Estatico de 1 Votante del TSE
       6666 / Damian / Covid / 0 / 1.5

    */
    // una vez que hicimos uso del puntero debemos indicarle al sistema operativo que ya no ocupamos mas el puntero
    delete(Puntero_a_Votante); // liberamos la memoria del puntero 
    Puntero_a_Votante = NULL; // le indicamos al puntero para que olvide a quien estaba apuntando

}

/*
Cargando arreglo de Enteros
Pintando arreglo de Enteros
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
Cargando arreglo de Caracteres
Pintando arreglo de Caracteres
, !, ", #, $, %, &, ', (, ), *, +, ,, -, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, ;, <, =, >, ?, @, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, [, \, ], ^, _, `, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, {, |, }, ~, ⌂, Ç, ü, é, â,
Cargando arreglo de Flotantes
Pintando arreglo de Flotantes
0, 3.1416, 6.2832, 9.4248, 12.5664, 15.708, 18.8496, 21.9912, 25.1328, 28.2744, 31.416, 34.5576, 37.6992, 40.8408, 43.9824, 47.124, 50.2656, 53.4072, 56.5488, 59.6904, 62.832, 65.9736, 69.1152, 72.2568, 75.3984, 78.54, 81.6816, 84.8232, 87.9648, 91.1064, 94.248, 97.3896, 100.531, 103.673, 106.814, 109.956, 113.098, 116.239, 119.381, 122.522, 125.664, 128.806, 131.947, 135.089, 138.23, 141.372, 144.514, 147.655, 150.797, 153.938, 157.08, 160.222, 163.363, 166.505, 169.646, 172.788, 175.93, 179.071, 182.213, 185.354, 188.496, 191.638, 194.779, 197.921, 201.062, 204.204, 207.346, 210.487, 213.629, 216.77, 219.912, 223.054, 226.195, 229.337, 232.478, 235.62, 238.762, 241.903, 245.045, 248.186, 251.328, 254.47, 257.611, 260.753, 263.894, 267.036, 270.178, 273.319, 276.461, 279.602, 282.744, 285.886, 289.027, 292.169, 295.31, 298.452, 301.594, 304.735, 307.877, 311.018,
Cargando arreglo de Booleanos
Pintando arreglo de Booleanos
1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
Cargando Struct Estatico de 1 Votante del TSE
Pintando Struct Estatico de 1 Votante del TSE
9999 / Lucifer / Coronavirus / 1 / 1.9

Cargando Struct Dinamico de 1 Votante del TSE
Pintando Struct Dinamico de 1 Votante del TSE
6666 / Damian / Covid / 0 / 1.5
C:\Users\Katerine\Documents\Estructuras de Datos\Semana 2\Arreglos\Debug\Arreglos.exe(proceso 12408) se cerró con el código 0.
Para cerrar automáticamente la consola cuando se detiene la depuración, habilite Herramientas->Opciones->Depuración->Cerrar la consola automáticamente al detenerse la depuración.
Presione cualquier tecla para cerrar esta ventana. . .
*/ 

/* Se ejemplifica cada uno de los arreglos impresos en consola */