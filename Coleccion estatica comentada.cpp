// Laboratorio de Arreglos, Struct y Colecciones dinámicas
// Colección estática original comentada
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

const int Max = 100; // constante de entero que inicia en 100 / El máximo permitido es: 14932
int Ultimo = 0; // El indice del primer espacio disponible

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
			if (conta == 7) { // Se pintan 7 lineas y se frena hasta que se toque cualquier tecla
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
		cout << "1. Insertar pieza" << endl;
		cout << "2. Listar Piezas " << endl;
		cout << "3. Borrar Piezas " << endl;
		cout << "4. Salir " << endl;
		cin >> opcion;//captura el numero introducido

		switch (opcion) { // switch es un if multiple para elementos de tipo numerativo(char, int)

		case 1: // insertar pieza
			system("cls"); // limpia pantalla
			CapturarElemento(Elemento); // se captura, el elemento entra vacio pero luego sale modificado cuando se capta desde el teclado
			InsertarElemento(PiezasFerreteria, Elemento); // se llama a esta funcion para que busque donde acomodar el elemento
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

/* Solo se muestra el menú ya que las demás opciones toman datos de teclado para guardarlo, imprimen tales 
datos en la opción 2 y borran un elemento deseado (si existe el elemento ingresado) */