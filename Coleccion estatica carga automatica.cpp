// Laboratorio de Arreglos, Struct y Colecciones dinámicas
// Colección estática modificada
// Katerine Guzmán Flores (2019390523), Jose Pablo Agüero Mora (2021126372) / Grupo 2 /
// EstructuraEstatica.cpp : Defines the entry point for the console application.

//importa las librerias

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

/*esta es la estructura de los datos q poseen los Productos*/
// cuando declaro tipo de dato no estoy usando nada en memoria todavia
typedef struct T_Producto { //5 campos del registro o estructura
	int Codigo;
	char Descripcion[50];
	float Precio;
	int Disponible;
	bool Activo;
} X; // solo es para que no salga warning

const int Max = 100; // constante de entero que inicia en 100 / El máximo permitido es: 14932 (en esta terminal)
int Ultimo = 0; // El indice del primer espacio disponible

void CargaAutomaticaDatosProducto(int cod, int desc, float prec, int disp, T_Producto& Pieza) // Se crea la función que genera datos automáticos según la variable Max que define el arreglo
{
	char Texto[65]; // Se declara una variable le cual va a incluir el string del código de producto

	_itoa_s(cod, Texto, 65, 10); // Convierte el tipo de dato de la variable cod (int) a string y lo guarda en la variable Texto
	char NombreAutomatico[65] = "Producto_"; // Se declara una variable tipo char a la cual se le va a concatenar el código
	strcat_s(NombreAutomatico, Texto); // Concatena la ambas variables de tipo char

	//printf("El texto es  %s\n", NombreAutomatico); /  Línea de prueba / No es necesario
	strcpy_s(Pieza.Descripcion, 50, NombreAutomatico); // Guarda el contenido concatenado de NombreAutomatico en la descripción dentro de el struct actual

	Pieza.Codigo = cod; // Le asigna un valor a la "variable" Codigo dentro del struct que define la variable Pieza dentro del arreglo
	Pieza.Precio = prec; // Le asigna un valor a la "variable" Precio dentro del struct que define la variable Pieza dentro del arreglo
	Pieza.Disponible = disp; // Le asigna un valor a la "variable" Disponible dentro del struct que define la variable Pieza dentro del arreglo
	Pieza.Activo = true; // Le asigna un valor a la "variable" Activo dentro del struct que define la variable Pieza dentro del arreglo
}

void CapturarElemento(T_Producto& Pieza) // recibe una pieza que es un struct de tipo T_producto 
										// pero se esta pasando por referencia
{
	system("CLS"); //  borramos pantalla
	cout << "Captura de una Pieza" << endl; // Mensaje de Capturar los datos de una pieza 
	cout << "" << endl;

	system("CLS");
	cout << "Captura de una Pieza" << endl;
	cout << "" << endl;
	cout << "CodigoProducto:"; // Se solicita a usuario codigo de producto
	cin >> Pieza.Codigo;  cout << "" << endl; // como es struct estatico, vamos llenando el subcampo codigo
	cout << "DescripcionProducto:"; // Se pide la descripcion del producto
	cin >> Pieza.Descripcion; // Se llena descripcion
	cout << "" << endl;
	cout << "PrecioProducto:"; // Se pide el precio del producto
	cin >> Pieza.Precio; // Se guarda el precio
	cout << "" << endl;
	cout << "DisponibleProducto:"; // Se pide que se indique si esta disponible o no
	cin >> Pieza.Disponible;  cout << "" << endl; // Se guarda disponibilidad
	Pieza.Activo = true; // como estamos creando un producto pieza.activo es true

}

// Siempre que pasemos un arreglo por parametro a una funcion en lenguaje C, se le inserta un & invisible
// al insertar el & se hace parametro por referencia
void Listar(T_Producto Inventario[Max]) { // los elementos del inventario son de tipo T_Producto
	system("CLS"); // limpia pantalla
	int conta = 0; // variable que se usa para poder paginar
	cout << "Listado de  Productos" << endl;
	for (int i = 0; i < Ultimo; i++) { // en cada vuelta va aumentando al contador hasta que llega al ultimo espacio disponible y le resta uno para capturar el ultimo
		if (Inventario[i].Activo) { // Si s eomite la igualdad es True siempre, si inventario esta activo se pinta
			cout << Inventario[i].Codigo << " " << Inventario[i].Descripcion << " " << Inventario[i].Precio << " "
				<< Inventario[i].Disponible << " " << endl;
			conta++;
			if (conta == Max) { // Se pinta el max de lineas y se frena hasta que se toque cualquier tecla
				cout << "-----------------------------------" << endl;
				cout << "Presione cualquier tecla para continuar..." << endl;
				system("pause"); // Espera tecla
				system("CLS"); // borra pantalla

				conta = 0; // reinicia el contador
			}
		}
	}
	system("pause"); // espera tecla
}


// Se recibe una coleccion con tamano max de elemtnos T_Producto y se busca un codigo llamado cual
// Siempre que sea un algoritmo de busqueda se tiene un flag al inicio
int BuscarElemento(T_Producto Inventario[Max], int Cual)
{
	bool Encontro = false; // flag normalmente empieza en false porque no encuentra niguna igualdad al inicio
	int Cont = 0; // para saber si nos hemos salido de rango de los indices

	// hay dos formas de salirse en una funcion de buscar: me salgo del ciclo de busqueda cuando encuentro 
	// el elemento, o porque nos salimos del rango

	while ((!Encontro) && (Cont < Ultimo)) // si no lo encontro y esta dentro del rango de busqueda
	{
		// si ese elemento esta en inventario y es el codigo que me piden buscar 
		if ((Inventario[Cont].Activo == true) && (Inventario[Cont].Codigo == Cual))
			Encontro = true; // pone que ya lo encontro
		else
			Cont++; // sino sigue buscando 
	}

	if (Encontro == true) // si se salio del ciclo porque ya lo encontro 
		return Cont; // devuelve el indice donde esa igualdad se dio 
	else
		return -1; // se salio por fuera de rango porque debe cumplir las dos coindiciones del while
				  // y se da cuando el contador se incrementa tanto que es igual al ultimo(ya comparo con todos)

}
//Recibe por parametro de referencia por ser arreglo
// El elemento a insertar se llama unidad
// Warning: Perimite los repetidos
void InsertarElemento(T_Producto Inventario[Max], T_Producto Unidad) // no devuelve nada
{
	// copia un struct dentro de otro con todos los campos y una vez que hace eso incrementa el ultimo
	Inventario[Ultimo] = Unidad; // al campo disponible le asigna los subcampos
	Ultimo++;
}

// Recibe coleccion por referencia de elementos de Tipo de Producto, y el elemento que vamos a borrar
void BorrarElemento(T_Producto Inventario[Max], int Cual)
{
	int PorBorrar; // variable local
	PorBorrar = BuscarElemento(Inventario, Cual); // variable local obtiene el elemento por borrar con el codigo cual

	if (PorBorrar != -1) // Si buscar me devuelve -1 si significa que no lo encontro, porque los codigos van de 0 hasta el limite
		Inventario[PorBorrar].Activo = false; // a inventario le metemos el indice por borrar. activo y en es moemtno le decimos que ya no esta disponible(false)

}


void main() {

	T_Producto PiezasFerreteria[Max]; // declara una coleccion llamada piezas de ferreteria con dimension max de elemtnos tipo T producto
	T_Producto Elemento; // sirve para capturar datos del teclado que se guardan en elemento y luego elemento se manda como parametro en la funcion insertar en la coleccion estatica
	int opcion = 0;

	while (opcion < 4) {

		system("cls");//limpia la pantalla
		cout << "******Menu principal******" << endl; // opciones que se pintan en pantalla
		cout << "1. Cargar productos de prueba" << endl;
		cout << "2. Listar Piezas " << endl;
		cout << "3. Borrar Piezas " << endl;
		cout << "4. Salir " << endl;
		cin >> opcion;//captura el numero introducido

		switch (opcion) { // switch es un if multiple para elementos de tipo numerativo(char, int)

		case 1: // insertar pieza
			system("cls"); //limpia la pantalla
			for (int i = 0; i < Max; i++) { // Se inicia un ciclo for que va desde 0 hasta Max - 1 
				CargaAutomaticaDatosProducto(i, i, i, i, Elemento); // Llama a la función CargaAutomaticaDatosProducto
				InsertarElemento(PiezasFerreteria, Elemento); // Llama a la función InsertarElemento
			}
			cout << "Procesando la informacion" << endl; // Envía un mensaje para retroalimentar al usuario
			system("PAUSE");
			break;

		case 2: // listar
			system("cls"); // limpia pantalla
			Listar(PiezasFerreteria); // De 0 al ultimo menos uno, lista todos aquellos cuyo campo activo es igual a True
			break;
		case 3: // cuando quiero que un usuario digite el codigo a borrar
			system("CLS"); // limpia pantalla
			int CodigoEscogido;
			cout << "Digite el codigo del Producto a Borrar" << endl;
			cout << "" << endl;
			cout << "CodigoProducto:" << endl;
			cin >> CodigoEscogido; // se captura el codigo
			BorrarElemento(PiezasFerreteria, CodigoEscogido); // se llama la funcion borrar con el codigo escogido
			break;
		}
	}
}

/* Asi se muestra el menu principal
******Menu principal******
1. Insertar Pieza
2. Listar Piezas
3. Borrar Piezas
4. Salir
*/

/* Procesando la informacion
Presione una tecla para continuar . . .*/

/* Listado de  Productos
0 Producto_0 0 0
1 Producto_1 1 1
2 Producto_2 2 2
3 Producto_3 3 3
4 Producto_4 4 4
5 Producto_5 5 5
6 Producto_6 6 6
7 Producto_7 7 7
8 Producto_8 8 8
9 Producto_9 9 9
10 Producto_10 10 10
11 Producto_11 11 11
12 Producto_12 12 12
13 Producto_13 13 13
14 Producto_14 14 14
15 Producto_15 15 15
16 Producto_16 16 16
17 Producto_17 17 17
18 Producto_18 18 18
19 Producto_19 19 19
20 Producto_20 20 20
21 Producto_21 21 21
22 Producto_22 22 22
23 Producto_23 23 23
24 Producto_24 24 24
25 Producto_25 25 25
26 Producto_26 26 26
27 Producto_27 27 27
28 Producto_28 28 28
29 Producto_29 29 29
30 Producto_30 30 30
31 Producto_31 31 31
32 Producto_32 32 32
33 Producto_33 33 33
34 Producto_34 34 34
35 Producto_35 35 35
36 Producto_36 36 36
37 Producto_37 37 37
38 Producto_38 38 38
39 Producto_39 39 39
40 Producto_40 40 40
41 Producto_41 41 41
42 Producto_42 42 42
43 Producto_43 43 43
44 Producto_44 44 44
45 Producto_45 45 45
46 Producto_46 46 46
47 Producto_47 47 47
48 Producto_48 48 48
49 Producto_49 49 49
50 Producto_50 50 50
51 Producto_51 51 51
52 Producto_52 52 52
53 Producto_53 53 53
54 Producto_54 54 54
55 Producto_55 55 55
56 Producto_56 56 56
57 Producto_57 57 57
58 Producto_58 58 58
59 Producto_59 59 59
60 Producto_60 60 60
61 Producto_61 61 61
62 Producto_62 62 62
63 Producto_63 63 63
64 Producto_64 64 64
65 Producto_65 65 65
66 Producto_66 66 66
67 Producto_67 67 67
68 Producto_68 68 68
69 Producto_69 69 69
70 Producto_70 70 70
71 Producto_71 71 71
72 Producto_72 72 72
73 Producto_73 73 73
74 Producto_74 74 74
75 Producto_75 75 75
76 Producto_76 76 76
77 Producto_77 77 77
78 Producto_78 78 78
79 Producto_79 79 79
80 Producto_80 80 80
81 Producto_81 81 81
82 Producto_82 82 82
83 Producto_83 83 83
84 Producto_84 84 84
85 Producto_85 85 85
86 Producto_86 86 86
87 Producto_87 87 87
88 Producto_88 88 88
89 Producto_89 89 89
90 Producto_90 90 90
91 Producto_91 91 91
92 Producto_92 92 92
93 Producto_93 93 93
94 Producto_94 94 94
95 Producto_95 95 95
96 Producto_96 96 96
97 Producto_97 97 97
98 Producto_98 98 98
99 Producto_99 99 99
-----------------------------------
Presione cualquier tecla para continuar...
Presione una tecla para continuar . . . */

/* En la salida anterior se puede ver que se generaron datos con la primer opción utilizando un ciclo que carga 
datos automáticamente en el arreglo de struct, después se hace un listado para ver impresos los datos */