  /*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "../../tareas_entregar/Posible_practica2/include/deportista.h"

using namespace std;

void imprimirLinea( ostream&, const Deportista & ); // prototipo

int main()
  {
      int opc = 0;
    Deportista d;//objeto o registro Deportista
    ifstream archdeportEntrada; //archivo logico
    archdeportEntrada.open ("deportistas.dat", ios::in | ios::binary);
    //ifstream archdeportEntrada( "deportistas.dat", ios::in | ios::binary );//el constructor abre el archivo

    // sale del programa si ifstream no puede abrir el archivo
  if ( !archdeportEntrada)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit( 1 );
    } // fin de if
    do{
        system("cls");
        cout << "1) Consulta individual (numero de socio)" << endl;
        cout << "2) Consultas generales" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresar opcion: "<<endl;
        cin>> opc;
        archdeportEntrada.clear();
        archdeportEntrada.seekg(0, archdeportEntrada.beg);
        switch(opc)
        {
        case 1:
            {
                system("cls");
                cout << "Consulta individual" << endl;
                int numero;
                cout << "Dame el numero de socio: "<<endl;
                cin >> numero;
                d.establecerNumeroDeSocio(numero);
                cout << left << setw( 10 ) << "Numero de socio" << setw( 16 )
                << "Nombre" << setw( 11 ) << "Edad" << left
                << setw( 10 ) << right << "Deporte" << endl;
                archdeportEntrada.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista),ios::beg); //seekp(n, ios::beg);
                // lee el siguiente registro del archivo
                    archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
                if ( d.obtenerNumeroDeSocio() != 0)
                    {
                        imprimirLinea( cout, d);
                    }
                else
                    {
                        cout << "EL NUMERO DE SOCIO NO EXISTE"<<endl;
                    }
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                cout << "Consulta general" << endl;
                cout << left << setw( 10 ) << "Numero de socio" << setw( 16 )
                << "Nombre" << setw( 11 ) << "Edad" << left
                << setw( 10 ) << right << "Deporte" << endl;
                // lee el primer registro del archivo
                    archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
                // lee todos los registros del archivo
                while ( archdeportEntrada && !archdeportEntrada.eof() )
                {
                    // muestra un registro
                    if ( d.obtenerNumeroDeSocio() != 0)
                    {
                        imprimirLinea( cout, d);
                    }
                    // lee el siguiente registro del archivo
                    archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
                } // fin de while
                system("pause");
            }
            break;
        }
    }while(opc != 3);
    cout << "Saliendo..."<<endl;
    return 0;
} // fin de main

    // muestra un solo registro
    void imprimirLinea( ostream &salida, const Deportista &registro )
    {
    salida << left << setw( 10 ) << registro.obtenerNumeroDeSocio()
    << setw( 16 ) << registro.obtenerNombre()
    << setw( 11 ) << registro.obtenerEdad()
    << setw( 10 ) << setprecision( 2 ) << right << fixed
    << showpoint << registro.obtenerDeporte() << endl;
    } // fin de la función imprimirLinea
