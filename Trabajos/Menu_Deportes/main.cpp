//arch securo.cpp - creación de un archivo secuencial

#include <iostream>
#include <fstream>
#include <cstdlib>//exit
#include <iomanip>

using namespace std;

void ingresar() {

// tres campos que conforman un registro

char deporte [20];

ofstream archivoDeporteSalida; //archivo logico

archivoDeporteSalida.open ("deportes.txt", ios:: out);

//salir del programa si no se puede crear el antivo
 if ( ! archivoDeporteSalida )
 { // operador I sobrecargado
     cerr<< "No se pudo abrir el archivo " << endl;
     exit (1);
}

cout << "Escriba el nombre, la edad y el deporte."<<endl
<<"Escriba fin de archivo para terminar la entrada.\n?";

//leer nombre, edad y deporte de cin, despues colocarla en el archivo
 while (cin>> deporte)
  {
       archivoDeporteSalida << deporte <<' '<<endl;
       cout << "? ";

  }//Fin while

archivoDeporteSalida.close();
}//Final funcion ingresar

void mostrarLinea (const char * const, int, int);
void recuperar() {

// tres campos que conforman un registro

char deporte [20];

ifstream archivoDeporteEntrada; //archivo logico
archivoDeporteEntrada.open ("deportes.txt", ios:: in);

//salir del programa si no se puede crear el antivo
 if ( ! archivoDeporteEntrada )
 { // operador I sobrecargado
     cerr<< "No se pudo abrir el archivo " << endl;
     exit (1);
}

// Imprimir cabecera de la tabla
cout << left << setw(16) << "|Deporte|" << setw(18) << "|Vocales|" << setw(15) << "|Consonantes|\n"<<  fixed << showpoint <<endl;

// mostrar cada registro del archivo
 while (archivoDeporteEntrada>> deporte)
    {
        int vocales = 0, consonantes = 0;
        for(int i = 0; i < deporte[i]; i++)
        {
            switch(deporte[i])
            {
                case 'a': case 'A': vocales++; break;
                case 'e': case 'E': vocales++; break;
                case 'i': case 'I': vocales++; break;
                case 'o': case 'O': vocales++; break;
                case 'u': case 'U': vocales++; break;
            }
            consonantes = i+1 - vocales;
        }
        mostrarLinea(deporte, vocales, consonantes);
    }

       archivoDeporteEntrada.close();
}//Final funcion recuperar

//mostrar cada registro
void mostrarLinea(const char* const deporte, int vocales, int consonantes)
{
    cout<<left<<setw(20)<<deporte<<setw(20)<<vocales<<setw(20)<<consonantes<<endl;

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
        case 1: printf("\tIngresar Deportes\n\n");
                ingresar();
                cin.clear();
                break;
        case 2: printf("\tRecuperar Deportes\n\n");
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

