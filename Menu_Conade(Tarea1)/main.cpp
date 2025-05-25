//arch securo.cpp - creación de un archivo secuencial

#include <iostream>
#include <fstream>
#include <cstdlib>//exit
#include <iomanip>

using namespace std;

void ingresar() {

// tres campos que conforman un registro

char nombre [30];

int edad;

char deporte [20];

ofstream archivoDeportistasSalida; //archivo logico

archivoDeportistasSalida.open ("deportistas.txt", ios:: out);

//salir del programa si no se puede crear el antivo
 if ( ! archivoDeportistasSalida )
 { // operador I sobrecargado
     cerr<< "No se pudo abrir el archivo " << endl;
     exit (1);
}

cout << "Escriba el nombre, la edad y el deporte."<<endl
<<"Escriba fin de archivo para terminar la entrada.\n?";

//leer nombre, edad y deporte de cin, despues colocarla en el archivo
 while (cin>> nombre >> edad >> deporte)
  {
       archivoDeportistasSalida << nombre <<' '<< edad         <<' '<< deporte <<endl;
       cout << "? ";

  }//Fin while

archivoDeportistasSalida.close();
}//Final funcion ingresar

void mostrarLinea (const char*const, int, const char * const);
void recuperar() {

// tres campos que conforman un registro

char nombre [30];

int edad;

char deporte [20];

ifstream archivoDeportistasEntrada; //archivo logico
archivoDeportistasEntrada.open ("deportistas.txt", ios:: in);

//salir del programa si no se puede crear el antivo
 if ( ! archivoDeportistasEntrada )
 { // operador I sobrecargado
     cerr<< "No se pudo abrir el archivo " << endl;
     exit (1);
}

// Imprimir cabecera de la tabla
cout << left << setw(10) << "Nombre" << setw(13)
<< "Edad" << "Deporte" << endl << fixed << showpoint;

// mostrar cada registro del archivo
 while (archivoDeportistasEntrada>> nombre >> edad >> deporte)
    {
        mostrarLinea(nombre,edad,deporte);
    }

       archivoDeportistasEntrada.close();
}//Final funcion recuperar

//mostrar cada registro
void mostrarLinea(const char* const nombre, int edad, const char* const deporte)
{
    cout<<left<<setw(10)<<nombre<<setw(13)<<edad
    <<setw(7)<<deporte<<endl;

}//Final mostrar registro


void menu()
{
    int opc;
    do{
    cout << "0.-Salir\n1.-Ingresar Deportistas\n2.-Recuperar Deportistas\n"<<endl;
    cout << "\tINTRODUCE una opcion:\n"<<endl;
    cin >> opc;

    switch(opc){
        case 0: printf("\tAdios");
                system("pause");
                break;
        case 1: printf("\tIngresar Deportistas\n\n");
                ingresar();
                cin.clear();
                break;
        case 2: printf("\tRecuperar Deportistas\n\n");
                recuperar();
                system("pause");
                break;

        default: printf("\tChoose a correct value");
                break;
    }//Final switch
    system("cls");
    }while(opc!=0);

}//Final funcion menu

int main()
{
    menu();
    return 0;
}//Final main
