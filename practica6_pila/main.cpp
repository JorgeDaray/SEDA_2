/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include <iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include "Libro.h"
#include "Pila.h"
#include "Nodo.h"

using std::fstream;

  using namespace std;
  void menu();
  void altas(fstream&);
  void bajas(fstream&, fstream&);
  void cambios(fstream&, fstream&);
  void consultas(fstream&,int);
  void imprimirLinea( ostream &salida, const Libro &registro );
  void recuperar(fstream&);
  Libro d;//un objeto o registro Libro
  Libro blanco;//un objeto o registro Libro
  Pila mi_pila;//un objeto o registro Pila

int main()
{
    menu();
    return 0;
}

int numeroDeSocio = 1;
void altas(fstream&archDeportSalida )
{
    system("cls");
    char nombre[40];
    char autor[40];
    char editorial[40];
    //Pone el puntero al inicio del archivo
    archDeportSalida.clear();
    archDeportSalida.seekg(0, archDeportSalida.beg);
        d.establecerposicion(numeroDeSocio);
            cout<<"Teclea nombre, autor y editorial\n?";
            cin>>setw(40)>>nombre;
            cin>>setw(40)>>autor;
            cin>>setw(40)>>editorial;
            //establecer los valores nombre, autor y editorial del registro
            d.establecernombre(nombre);
            d.establecerautor(autor);
            d.establecereditorial(editorial);
            mi_pila.push(d);
            //buscar la posicion en el archivo de registro especificado por el usuario
            archDeportSalida.seekp((d.obtenerposicion()-1)*sizeof(Libro)); //seekp(n, ios::beg);
            //escribir la información especificada por el usuario en el archivo
            archDeportSalida.write(reinterpret_cast<const char *>(&d),sizeof(Libro));
            numeroDeSocio++;
  archDeportSalida.clear();
}//main

void bajas(fstream&archDeportSalida, fstream&archdeportEntrada)
{
    if (numeroDeSocio == 1)
    {
        cout << "Lista vacia"<<endl;
        system("pause");
        return;
    }
    //Pone el puntero al inicio
    archdeportEntrada.clear();
    archdeportEntrada.seekg(0, archdeportEntrada.beg);
    int elim;
        d.establecerposicion(numeroDeSocio-1);
        //Busca la posicion dada del registro
        archdeportEntrada.seekg((d.obtenerposicion()-1)*sizeof(Libro),ios::beg); //seekp(n, ios::beg);
        // lee el siguiente registro del archivo
        archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Libro ) );
        if ( d.obtenerposicion() != 0)
            {
                cout << left << setw( 40 ) << "Nombre" << setw( 40 )
                << "Autor" << setw( 40 ) << "Editorial"<< endl;
                imprimirLinea( cout, d);
                cout << "Desea eliminar el socio ? '1' si, '0' no" << endl;
                cin >> elim;
                if (elim == 1)
                {
                    //Pone el puntero al inicio
                    archDeportSalida.clear();
                    archDeportSalida.seekp(0, archDeportSalida.beg);
                    d.establecerposicion(numeroDeSocio);
                    //buscar la posicion en el archivo de registro especificado por el usuario
                    archDeportSalida.seekp((d.obtenerposicion()-1)*sizeof(Libro)); //seekp(n, ios::beg);
                    //escribir la información especificada por el usuario en el archivo
                    archDeportSalida.write(reinterpret_cast<const char *>(&blanco),sizeof(Libro));
                  cout << "Borrado corectamente" << endl;
                  mi_pila.pop();
                  numeroDeSocio--;
                  system("pause");
                }
                else
                {
                    cout << "Regresando al menu..." << endl;
                    system("pause");
                }
            }
        else
            {
                cout << "EL NUMERO DE SOCIO NO EXISTE"<<endl;
                system("pause");
            }
    archdeportEntrada.clear();
}

void consultas(fstream&archdeportEntrada, int opc)
{
    //Pone el puntero al inicio
        archdeportEntrada.clear();
        archdeportEntrada.seekg(0, archdeportEntrada.beg);
        switch(opc)
        {
        case 4:
            {
                system("cls");
                cout << "Consulta individual" << endl;
                int numero;
                cout << "Dame el numero de socio: "<<endl;
                cin >> numero;
                d.establecerposicion(numero);
                archdeportEntrada.seekg((d.obtenerposicion()-1)*sizeof(Libro),ios::beg); //seekp(n, ios::beg);
                // lee el siguiente registro del archivo
                    archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Libro ) );
                if ( d.obtenerposicion() != 0)
                    {
                        cout << left << setw( 40 ) << "Nombre" << setw( 40 )
                        << "Autor" << setw( 40 ) << "Editorial"<< endl;
                        imprimirLinea( cout, d);
                    }
                else
                    {
                        cout << "EL NUMERO DE SOCIO NO EXISTE"<<endl;
                    }
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                mi_pila.mostrar();
                system("pause");
            }
            break;
        }
    archdeportEntrada.clear();
} // fin de consultas

    // muestra un solo registro
    void imprimirLinea( ostream &salida, const Libro &registro )
    {
    salida << left << setw( 40 ) << registro.obtenernombre()
    << setw( 40 ) << registro.obtenerautor()
    << setw( 40 ) << registro.obtenereditorial()<<endl;
    } // fin de la función imprimirLinea

void recuperar(fstream&archlibro)
{
    system("cls");
    // lee el primer registro del archivo
    archlibro.read( reinterpret_cast< char * >( &d ), sizeof( Libro ) );
    // lee todos los registros del archivo
    while ( archlibro && !archlibro.eof() )
    {
        // muestra un registro
        if ( d.obtenerposicion() != 0)
        {
            mi_pila.push(d);
            numeroDeSocio++;
        }
        // lee el siguiente registro del archivo
        archlibro.read( reinterpret_cast< char * >( &d ), sizeof( Libro ) );
    } // fin de while
    system("pause");
}

void menu()
{
    fstream archDeportENSA("Libros.dat", ios::out | ios::binary | ios::in );
    if ( !archDeportENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if
    recuperar(archDeportENSA);

    int opc;
    do
    {
    system("cls");
    cout << "MENU LIBRERIA CUCEI"<<endl;
    cout << "1) Comprar libros (insertar)" << endl;
    cout << "2) Vender libros (eliminar)" << endl;
    cout << "3) Consultas generales" << endl;
    cout << "4) Salir" << endl;
    cout << "Ingresar opcion: "<<endl;
    cin>> opc;
    switch(opc)
        {
        case 1:
            {
                altas(archDeportENSA);
                break;
            }
        case 2:
            {
                bajas(archDeportENSA,archDeportENSA);
                break;
            }
        case 3:
            {
                consultas(archDeportENSA,opc);
                break;
            }
        case 4:
            {
                cout << "saliendo..."<<endl;
                archDeportENSA.close();
                exit(1);
                break;
            }
        }
    }while(opc!=4);
}

