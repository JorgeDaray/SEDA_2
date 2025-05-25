#include "Pila.h"
#include "Nodo.h"
#include "Libro.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include<cstdlib>

using namespace std;
using std::fstream;
Libro *blanco = new Libro();
Libro *mi_libro = new Libro();
Pila *mi_pila = new Pila();

void menu();
void altas(fstream&);
void bajas(fstream&, fstream&);

/*int main ()
{
    int cont=0;
    fstream archLibroENSA;
    archLibroENSA.open("libros.dat", ios::out | ios::in );
    if ( !archLibroENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if

    //Variables
    char nombre_libro[15];
    char nombre_autor[15];
    char nombre_editorial[15];
    int opcion = 0;
    do{
        system("cls");
		cout<<endl<<"Menu-Sistema de cuentas"<<endl;
	    cout<<"1.- Insertar (push)"<<endl;
	    cout<<"2.- Eliminar (pop)"<<endl;
	    cout<<"3.- Mostrar"<<endl;
	    cout<<"4.- Salir"<<endl;
	    cout<<"Elige tu opcion:";
	    cin>>opcion;

	    switch (opcion)
	    {
	        case 1:
	            {
	                archLibroENSA.clear();
                    archLibroENSA.seekg(0, archLibroENSA.beg);
                    fflush(stdin);
                    cout<<"Ingrese el nombre del Libro "<< endl;
                    getline(cin,nombre_libro);
                    cout<<"Ingrese el nombre del autor "<< endl;
                    getline(cin,nombre_autor);
                    cout<<"Ingrese el nombre de la editorial "<< endl;
                    getline(cin,nombre_editorial);
                    mi_libro->establecerposicion(cont);
                    mi_libro->establecernombre(nombre_libro);
                    mi_libro->establecerautor(nombre_autor);
                    mi_libro->establecereditorial(nombre_editorial);
                    //lee el siguiente registro del archivo
                    //archLibroENSA.read( reinterpret_cast< char * >(&mi_libro), sizeof(Libro));
                    mi_pila->push(*mi_libro);
                    cont++;
                    //buscar la posicion en el archivo de registro especificado por el usuario
                    archLibroENSA.seekp((mi_libro->obtenerposicion())*sizeof(Libro)); //seekp(n, ios::beg);
                    //escribe en el archivo
                    archLibroENSA.write(reinterpret_cast <const char*>(&mi_libro),sizeof(Libro));
	            }
	        break;

	        case 2:
	            mi_pila->pop();
            break;

	        case 3:
	            mi_pila->mostrar();
                system("pause>>cls");
                cout << "Consulta general" << endl;
                // lee el primer registro del archivo
                    archLibroENSA.read( reinterpret_cast< char * >( &mi_libro ), sizeof( Libro ) );
                // lee todos los registros del archivo
                while ( archLibroENSA && !archLibroENSA.eof() )
                {
                    // muestra un registro
                    if ( mi_libro->obtenerposicion() != 0)
                    {
                        cout << left << setw( 10 ) << mi_libro->obtenerposicion()
                        << setw( 16 ) << mi_libro->obtenernombre()
                        << setw( 11 ) << mi_libro->obtenerautor()
                        << setw( 10 ) << setprecision( 2 ) << right << fixed
                        << showpoint << mi_libro->obtenereditorial() << endl;
                    }
                    // lee el siguiente registro del archivo
                    archLibroENSA.read( reinterpret_cast< char * >( &mi_libro ), sizeof( Libro ) );
                } // fin de while
                system("pause");
            break;

            case 4:
            break;

        }
        system("pause>>cls");
	}while(opcion!=4);
	archLibroENSA.close();
    return 0;
}*/

int main()
{
    menu();
    return 0;
}

int pos = 1;

void altas(fstream&archDeportSalida)
{
    char nombre_libro[15];
    char nombre_autor[15];
    char nombre_editorial[15];
    archDeportSalida.clear();
    archDeportSalida.seekg(0, archDeportSalida.beg);
            system("cls");
            mi_libro->establecerposicion(pos);
            if (mi_libro->obtenerposicion()!= 0)
                {
                    cout<<"Teclea nombre, autor y editorial\n?";
                    cin>>setw(15)>>nombre_libro;
                    cin>>setw(15)>>nombre_autor;
                    cin>>setw(15)>>nombre_editorial;
                  //establecer los valores nombre, edad y deporte del registro
                    mi_libro->establecernombre(nombre_libro);
                    mi_libro->establecerautor(nombre_autor);
                    mi_libro->establecereditorial(nombre_editorial);
                    mi_pila->push(*mi_libro);
                    pos++;;
                  //buscar la posicion en el archivo de registro especificado por el usuario
                    archDeportSalida.seekp((mi_libro->obtenerposicion())*sizeof(Libro)); //seekp(n, ios::beg);
                 //escribir la información especificada por el usuario en el archivo
                    archDeportSalida.write(reinterpret_cast<const char *>(&mi_libro),sizeof(Libro));
                    cout << "EL LIBRO SE AGREGO CORRECTAMENTE"<<endl;
                    system("pause");
                }//while
  archDeportSalida.clear();
}//main

void bajas(fstream&archDeportSalida, fstream&archdeportEntrada)
{
    mi_pila->pop();
}

void menu()
{
    fstream archLibroENSA("Libros.dat", ios::out | ios::binary | ios::in );
    if ( !archLibroENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if

    int opc;
    do
    {
    system("cls");
        cout<<endl<<"Menu-Sistema de cuentas"<<endl;
	    cout<<"1.- Insertar (push)"<<endl;
	    cout<<"2.- Eliminar (pop)"<<endl;
	    cout<<"3.- Mostrar"<<endl;
	    cout<<"4.- Salir"<<endl;
	    cout<<"Elige tu opcion:";
        cin>> opc;
    switch(opc)
        {
        case 1:
            {
                altas(archLibroENSA);
                break;
            }
        case 2:
            {
                bajas(archLibroENSA,archLibroENSA);
                break;
            }
        case 3:
            {
                system("cls");
                mi_pila->mostrar();
                system("pause");
                cout << "Consulta general" << endl;
                cout << left << setw( 15 ) << "nombre"
                << setw( 15 ) << "autor" << setw( 15 ) << right << fixed
                << showpoint << "editorial" << endl;
                // lee el primer registro del archivo
                archLibroENSA.read(reinterpret_cast<char*>(&mi_libro), sizeof(Libro));
                // lee todos los registros del archivo
                while (archLibroENSA && !archLibroENSA.eof())
                {
                    // muestra un registro
                    if ( mi_libro->obtenerposicion() != 0)
                    {
                        cout << left << setw( 10 ) << mi_libro->obtenerposicion()
                        << setw( 16 ) << mi_libro->obtenernombre()
                        << setw( 11 ) << mi_libro->obtenerautor()
                        << setw( 10 ) << setprecision( 2 ) << right << fixed
                        << showpoint << mi_libro->obtenereditorial() << endl;
                    }
                    // lee el siguiente registro del archivo
                    archLibroENSA.read( reinterpret_cast< char * >( &mi_libro ), sizeof( Libro ) );
                } // fin de while
                system("pause");
                break;
            }
        case 4:
            {
                cout << "saliendo..."<<endl;
                archLibroENSA.close();
                exit(1);
                break;
            }
        }
    }while(opc!=4);
}

