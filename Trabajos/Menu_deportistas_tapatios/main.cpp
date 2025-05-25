//arch securo.cpp - creación de un archivo secuencial

#include <iostream>
#include <fstream>
#include <cstdlib>//exit
#include <iomanip>
using namespace std;

void mostrarLinea (const char*const, int, const char * const);
void recuperar(int opcion_mostrar) {

// tres campos que conforman un registro

char nombre [30];

int edad;

char deporte [20];

ifstream archivoDeportistasEntrada; //archivo logico
archivoDeportistasEntrada.open ("deportistas.txt", ios:: in);

//salir del programa si no se puede encontrar
 if ( ! archivoDeportistasEntrada )
 { // operador I sobrecargado
     cerr<< "No se pudo abrir el archivo " << endl;
     exit (1);
}

// Imprimir cabecera de la tabla
cout << left << setw(10) << "Nombre" << setw(13)
<< "Edad" << "Deporte" << endl << fixed << showpoint;

// mostrar cada registro del archivo
int mostrados = 0;
 while (archivoDeportistasEntrada>> nombre >> edad >> deporte)
    {
        if (opcion_mostrar == 1)
        {
            if (edad > 4 && edad < 18)
            {
                mostrarLinea(nombre,edad,deporte);
                mostrados++;
            }//final if
        }

        else if (opcion_mostrar == 2)
        {
            if (edad > 17 && edad < 60)
            {
                mostrarLinea(nombre,edad,deporte);
                mostrados++;
            }//final if
        }

        else if (opcion_mostrar == 3)
        {
            if (edad > 59 && edad < 85)
            {
                mostrarLinea(nombre,edad,deporte);
                mostrados++;
            }//final if
        }
    }//final while mostrar
        if (mostrados == 0)
        {
            cout << "Ningun deportista encontrado"<<endl;
        }//final if
    archivoDeportistasEntrada.clear();// borra el flujo
    archivoDeportistasEntrada.seekg(0,ios::beg);//se reposiciona al inicio del archivo

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
    cout << "0.-Salir\n1.-Mostrar deportistas menores de edad"
    <<"\n2.-Mostrar deportistas mayores de edad\n3.-Mostrar deportistas adultos mayores\n"<<endl;
    cout << "\tINTRODUCE una opcion:\n"<<endl;
    cin >> opc;

    switch(opc){
        case 0: printf("\tAdios");
                system("pause");
                break;
        case 1: printf("\tIngresar Deportistas\n\n");
                recuperar(1);
                system("pause");
                break;
        case 2: printf("\tRecuperar Deportistas\n\n");
                recuperar(2);
                system("pause");
                break;
        case 3: printf("\tRecuperar Deportistas\n\n");
                recuperar(3);
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

