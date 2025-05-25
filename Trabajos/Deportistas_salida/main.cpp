//arch securo.cpp - creación de un archivo secuencial

#include <iostream>
#include <fstream>
#include <cstdlib>//exit

using namespace std;

int main() {

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

//leer nombre, edad y deporte de cin, despues colocarlar en el archivo
 while (cin>> nombre >> edad >> deporte)
  {
       archivoDeportistasSalida << nombre <<' '<< edad         <<' '<< deporte <<endl;
       cout << "? ";

  }//while

archivoDeportistasSalida.close();
return 0;

}//main
