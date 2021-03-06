// Laboratorio de Arreglos, Struct y Colecciones dinámicas
// Colección estática con archivos
// Katerine Guzmán Flores (2019390523), Jose Pablo Agüero Mora (2021126372) / Grupo 2 /

// archivos_en_C.cpp : main project file VC2012
// programa que permite guardar y cargar desde un archivo los datos en un archivo fisico en disco duro
#include "StdAfx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

struct cedula {
	int numero;
	char nombre[25];
	bool activo;
};

cedula arreglo[50];
int cont = 0;

/* En archivos: analogamente se escribe en un documento los parametros que quiero guardar y al momento de guardarlos se leen en el orden en que se escribieron*/
void guardararchivo(cedula Arreglo[], int cont) {
	system("CLS");//limpia la pantalla
	cout << endl << endl;
	FILE* archcedulas; // se crea un archivo puntero a una variable de tipo archivo
	// fopen_s se usa para abrir un archivo fisico y relacionarlo con la variable que se creo antes
	// "w" indica que se abre para escritura (write) y el + indica que se cree sino se ha creado
	fopen_s(&archcedulas, "cedulas.txt", "w+");

	// recorre la coleccion estatica e imprime en cedulas.txt primero el numero de cedula y despues el nombre
	for (int y = 0; y<cont; y++) {
		if (Arreglo[y].activo == true) { // solo se guardaran aquellas personas que esten activas
			// printf escribe en el archivo lo que esta guardando
			printf("Cedula: %i Nombre:  %s		-guardado- \n", arreglo[y].numero, arreglo[y].nombre);
			// va a escribir en archivo de cedulas el nombre
			fprintf_s(archcedulas, "%s", Arreglo[y].nombre);
			if (y == (cont - 1)) { fprintf_s(archcedulas, "\n%i", Arreglo[y].numero); }// se eliminan los enter al final del archivo de texto
			// escribe el numero de cedula
			else fprintf_s(archcedulas, "\n%i\n\n", Arreglo[y].numero);
		}
	}
	fclose(archcedulas); // se cierra el archivo
	cout << endl << " Presione una tecla para continuar..." << endl;
}

void cargararchivo(cedula arreglo[], int &cont) {//El arreglo no debe ingresar como referencia, pero el contador si para que su valor cambie respecto a lo que se hace en la funcion
	system("CLS");
	FILE*archcedulas; // se crea el archivo logico archcedulas
	fopen_s(&archcedulas, "cedulas.txt", "r"); // se abre el archivo
	if (archcedulas == NULL) { // si ese archivo no existe manda mensaje de no se encontro
		cout << "no se encontro el archivo" << endl;
	}
	else { // en caso de que si encuentre el archivo se cargan los datos
		while (!feof(archcedulas)) { // mientras que no llega al final del archivo
			// se hace escaneo en el archivo archcedulas por string y lo guarda en un arreglo con una posicion determinada en espacio nombre con una longitud maxima de 25
			fscanf_s(archcedulas, "%s", arreglo[cont].nombre, 25);//cont al inicio esta en cero
			// se escanea el numero de cedula en formato entero y se guarda en arreglo de numeros de cedula
			fscanf_s(archcedulas, "%i", &arreglo[cont].numero);
			// se imprime en pantalla para que el usuario vea lo que se esta cargando
			printf("\n\n  Cedula: %i Nombre:  %s		-cargado- \n", arreglo[cont].numero, arreglo[cont].nombre);
			arreglo[cont].activo = true;// Activa de nuevo a la persona
			cont++; // aumenta el contador
		}
		fclose(archcedulas); // se cierra el archivo
	}
	cout << endl << " Presione una tecla para continuar..." << endl;
}

void insertar(cedula arreglof[], int &cont) {
	system("CLS");
	cout << endl << " ----------------  Ingresar persona  ----------------" << endl;
	cout << endl << " Digite el nombre de la persona: ";
	cin >> arreglof[cont].nombre;
	cout << endl << " Digite el numero de cedula: ";
	cin >> arreglof[cont].numero;
	arreglo[cont].activo = true;// activa a la persona
	cont++;
}

// busca si un nombre esta en la lista
void buscar_nombre(cedula arreglo[], int cont) {
	system("CLS");
	cout << endl << " ----------------  Buscar persona por nombre  ----------------" << endl << endl << endl;
	char cual[25]; // el nombre es string de maximo 25
	cout << " Digite el nombre que desea buscar: ";
	cin >> cual;
	cout << endl << endl;
	int i;
	// en este ciclo se va recorriendo la lista de nombre y la lista de cedulas
	for (i = 0; i < cont; i++) {
		// strcmp compara dos strings
		if ((strcmp(arreglo[i].nombre, cual) == 0) && (arreglo[i].activo == true)) {// compara el nombre y si esta activo
			cout << "El numero de cedula de " << cual << " es: " << arreglo[i].numero << endl; // indica cual es el nombre de la cedula buscada
			break;
		}
	}
	if (i == cont) { // si llega al final del arreglo y no lo encuentra envia el mensaje correspondiente
		cout << " El nombre no ha sido ingresado o fue borrado" << endl;
	}
}

// busca si una cedula esta en la lista
void buscar_cedula(cedula arreglo[], int cont, int cual) {
	int i;
	for (i = 0; i < cont; i++) {
		if ((arreglo[i].numero == cual) && (arreglo[i].activo == true)) { // si el numero de cedula esta activo
			cout << "El numero de cedula: " << cual << " corresponde a: " << arreglo[i].nombre << endl; // se imprime el nombre de la persona a quien pertenece la cedula
			break;
		}
	}
	if (i == cont) { // si se llega al final del arreglo y no encuentra la cedula, envia mensaje de no encontrado
		cout << " El numero de cedula no ha sido ingresado o fue borrado" << endl;
	}
}

void listarcedulas(cedula arreglo[], int cont) {
	system("CLS");
	cout << endl << " ----------------  Lista de personas  ----------------" << endl << endl;
	int numerador = 1;
	cout << "		# Cedula		Nombre" << endl << endl;
	if (cont == 0) { cout << endl << "		La lista esta vacia." << endl; }
	else {
		for (int i = 0; i<cont; i++) {
			if (arreglo[i].activo == true) {
				cout << "	" << numerador << "	" << arreglo[i].numero << "		" << arreglo[i].nombre << endl;
				numerador++;
			}
		}
	}
	cout << endl << endl << " ************** Fin de la lista  ***************" << endl;
}

int buscarparaborrar(cedula arreglo[], int &cont) { // Inicializa la función con un parámetro tipo struct y otro por referencia
	system("CLS"); // Limpia el estado actual de la consola
	cout << endl << " ----------------  Buscar persona para borrar  ----------------" << endl << endl;
	char cual[25]; // Almacena la persona solicitada para borrar
	cout << " Digite el nombre que desea buscar para eliminar: ";
	cin >> cual; // Toma los datos para almacenarlos
	cout << endl << endl;
	int i; // Se inicializa una variable contador
	for (i = 0; i<cont; i++) { // Inicia un ciclo for que va desde 0 hasta cont - 1
		if ((strcmp(arreglo[i].nombre, cual) == 0) && (arreglo[i].activo == true)) { // La condición compara dos cadenas y verifica si tiene un estado de activo
			cout << endl << " Persona borrada con exito" << endl << endl;
			cont--;//decrementa el contador para que la cuenta de personas sea precisa
			return i;//retorna el numero de lugar en el que esta el nombre en el arreglo
		}
	}
	if (i == cont) { // Se establece otro condicional que se cumple cuando i tenga el mismo valor del contador
		cout << " El nombre no ha sido ingresado o ya fue borrado" << endl;
		return -1;//retorna -1 ya q la funcion es tipo entero, y al ser llamada se esper un valor de regreso
	}
	else return -2;//Se escribe para evitar warning
}

void main() {
	bool menu = true;
	while (menu) {
		system("CLS");
		cout << endl << endl << "	-----------------	Menu Principal   -----------------" << endl << endl;
		cout << "		1. Agregar persona" << endl;
		cout << "		2. Buscar por nombre" << endl;
		cout << "		3. Buscar por cedula" << endl;
		cout << "		4. Listar todos" << endl;
		cout << "		5. Borrar una persona" << endl;
		cout << "		6. Guardar Arreglo a archivo" << endl;
		cout << "		7. Cargar Arreglo desde archivo " << endl;
		cout << "		8. Salir" << endl << endl;
		cout << "		Digite una opcion: ";
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			insertar(arreglo, cont);
			cout << endl << endl << " La persona fue ingresada correctamente." << endl << endl;
			cout << " Presione una tecla para continuar..." << endl;
			_getch();
			break;
		}
		case 2: {
			buscar_nombre(arreglo, cont);
			cout << endl << " Presione una tecla para continuar..." << endl;
			_getch();
			break;
		}
		case 3: {
			system("CLS");
			cout << endl << " ----------------  Buscar persona por #cedula  ----------------" << endl << endl << endl;
			int cual;
			cout << " Digite el numero de cedula que desea buscar: ";
			cin >> cual;
			cout << endl << endl;
			buscar_cedula(arreglo, cont, cual);
			cout << endl << " Presione una tecla para continuar..." << endl;
			_getch();
			break;
		}
		case 4: {
			listarcedulas(arreglo, cont);
			cout << endl << " Presione una tecla para continuar..." << endl;
			_getch();
			break;
		}
		case 5: {
			arreglo[buscarparaborrar(arreglo, cont)].activo = false;// desactiva persona
			cout << endl << " Presione una tecla para continuar..." << endl;
			_getch();
			break;
		}
		case 6: {
			guardararchivo(arreglo, cont);
			_getch();
			break;
		}
		case 7: {
			if (cont != 0) { // Se inicia un condicional que se cumple cuando el cont es diferente de 0
				cout << endl << endl << "  Se perderan los cambios realizados en esta sesion," << endl; 
				cout << "  desea continuar(S/N): ";
				char sino[2]; // Almacena el valor de la respuesta del usuario
				cin >> sino; // Pide la respuesta
				if ((strcmp(sino, "S") == 0) || (strcmp(sino, "s") == 0)) { // Compara la respuesta con "s" o "S"
					cont = 0; // Devuelve el contador a 0
					cargararchivo(arreglo, cont); // Llama a la función cargararchivo
				}
				else cout << " No se cargaran datos guardados. " << endl; // Excepción del condicional, imprime un mensaje pero no ejecuta otra instrucción
			}
			else cargararchivo(arreglo, cont); // Excepción del primer condicional que se cumple cuando el cont sea igual a 0
			_getch(); // Instrucción para leer cadenas de varios caracteres
			break; // Sale del caso
		}

		case 8: {
			menu = false;
			system("CLS");
			cout << endl << endl << endl << endl << "			***********************************" << endl;
			cout << "			*                                 *" << endl;
			cout << "			*   *******  *******   *******    *" << endl;
			cout << "			*      *     *         *          *" << endl;
			cout << "			*      *     *****     *          *" << endl;
			cout << "			*      *     *         *          *" << endl;
			cout << "			*      *     *******   *******    *" << endl;
			cout << "			*                                 *" << endl;
			cout << "			***********************************" << endl << endl << endl;
			cout << " Presione una tecla para salir..." << endl;
			_getch();
			break;
		}
		default: {
			cout << endl << "La opcion digitada no exite" << endl << endl;
			cout << " Presione una tecla para continuar..." << endl;
			_getch();
		}
		}
	}
}

/*
Al ejecutarse, aparece el siguiente menu

		-----------------       Menu Principal   -----------------

				1. Agregar persona
				2. Buscar por nombre
				3. Buscar por cedula
				4. Listar todos
				5. Borrar una persona
				6. Guardar Arreglo a archivo
				7. Cargar Arreglo desde archivo
				8. Salir

				Digite una opcion:

Al agregar a varias personas aparece lo siguiente si se pesiona la opcion 4 para ver la lista:

 ----------------  Lista de personas  ----------------

				# Cedula                Nombre

		1       66666666                Chucky
		2       555555555               Gaviota
		3       88888888                Chocolito


 ***** Fin de la lista  ******

 Presione una tecla para continuar...

*/

/* En este caso se repiten ciertos patrones en el código que no se comentaron ya que fueron comentados previamente. En este 
caso se introdujeron manualmente 3 personas y se listaron */