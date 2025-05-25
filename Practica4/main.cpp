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
#include "../../tareas_entregar/Posible_practica2/include/deportista.h"

using std::fstream;

  using namespace std;
  void menu();
  void altas(fstream&);
  void bajas(fstream&, fstream&);
  void cambios(fstream&, fstream&);
  void consultas(fstream&,int);
  void imprimirLinea( ostream &salida, const Deportista &registro );
  Deportista d;//un objeto o registro Deportista
  Deportista blanco;//un objeto o registro Deportista

int main()
{
    menu();
    return 0;
}

void altas(fstream&archDeportSalida )
{
  int numeroDeSocio = 1;
  char nombre[15];
  int edad;
  char deporte[15];
  while(numeroDeSocio != 0)
  {
    archDeportSalida.clear();
    archDeportSalida.seekg(0, archDeportSalida.beg);
            system("cls");
            cout<<"Escriba el numero de socio(De 1 a 100, 0 para terminar la entrada)\n?";
              cin>>numeroDeSocio;
              d.establecerNumeroDeSocio(numeroDeSocio);
              //buscar la posicion en el archivo de registro especificado por el usuario
              if(d.obtenerNumeroDeSocio()>=1 && d.obtenerNumeroDeSocio()<=100)
              {
            archDeportSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista),ios::beg); //seekp(n, ios::beg);
            // lee el siguiente registro del archivo
            archDeportSalida.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
            if ( d.obtenerNumeroDeSocio() != 0)
                {
                     cout << left << setw( 10 ) << "Num socio" << setw( 16 )
                    << "Nombre" << setw( 11 ) << "Edad" << left
                    << setw( 10 ) << right << "Deporte" << endl;
                    imprimirLinea( cout, d);
                    cout << "\n\n Numero de socio existente pruebe con otro"<< endl;
                    system("pause");
                }
            else
                {
                    d.establecerNumeroDeSocio(numeroDeSocio);
                    cout << "EL NUMERO DE SOCIO NO EXISTE"<<endl;
                      cout<<"Teclea nombre, edad y deporte\n?";
                      cin>>setw(15)>>nombre;
                      cin>>edad;
                      cin>>setw(15)>>deporte;
                      //establecer los valores nombre, edad y deporte del registro
                      d.establecerNombre(nombre);
                      d.establecerEdad(edad);
                      d.establecerDeporte(deporte);
                      //buscar la posicion en el archivo de registro especificado por el usuario
                      archDeportSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista)); //seekp(n, ios::beg);
                     //escribir la información especificada por el usuario en el archivo
                      archDeportSalida.write(reinterpret_cast<const char *>(&d),sizeof(Deportista));
                      cout << "EL NUMERO DE SOCIO SE AGREGO CORRECTAMENTE"<<endl;
                      system("pause");
                }//while
            }
    }
          //El usuario proporciona la información que se guarda en el archivo
  archDeportSalida.clear();
}//main

void bajas(fstream&archDeportSalida, fstream&archdeportEntrada)
{
    archdeportEntrada.clear();
    archdeportEntrada.seekg(0, archdeportEntrada.beg);
    int numero;
    int elim;
        cout << "Dame el numero de socio: "<<endl;
        cin >> numero;
        d.establecerNumeroDeSocio(numero);
        archdeportEntrada.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista),ios::beg); //seekp(n, ios::beg);
        // lee el siguiente registro del archivo
            archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
        if ( d.obtenerNumeroDeSocio() != 0)
            {
                cout << left << setw( 10 ) << "Num socio" << setw( 16 )
                << "Nombre" << setw( 11 ) << "Edad" << left
                << setw( 10 ) << right << "Deporte" << endl;
                imprimirLinea( cout, d);
                cout << "Desea eliminar el socio ? '1' si, '0' no" << endl;
                cin >> elim;
                if (elim == 1)
                {
                    archDeportSalida.clear();
                    archDeportSalida.seekp(0, archDeportSalida.beg);
                    d.establecerNumeroDeSocio(numero);
                      //buscar la posicion en el archivo de registro especificado por el usuario
                      archDeportSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista)); //seekp(n, ios::beg);
                     //escribir la información especificada por el usuario en el archivo
                      archDeportSalida.write(reinterpret_cast<const char *>(&blanco),sizeof(Deportista));
                  cout << "Borrado corectamente" << endl;
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

void cambios(fstream&archDeportSalida, fstream&archdeportEntrada)
{
    archdeportEntrada.clear();
    archdeportEntrada.seekg(0, archdeportEntrada.beg);
    int numero;
    char nombre[15];
    int edad;
    char deporte[15];
    int elim;
        cout << "Dame el numero de socio: "<<endl;
        cin >> numero;
        d.establecerNumeroDeSocio(numero);
        archdeportEntrada.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista),ios::beg); //seekp(n, ios::beg);
        // lee el siguiente registro del archivo
            archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
        if ( d.obtenerNumeroDeSocio() != 0)
            {
                cout << left << setw( 10 ) << "Num socio" << setw( 16 )
                << "Nombre" << setw( 11 ) << "Edad" << left
                << setw( 10 ) << right << "Deporte" << endl;
                imprimirLinea( cout, d);
                cout << "Desea cambiar el socio ? '1' si, '0' no" << endl;
                cin >> elim;
                if (elim == 1)
                {
                    archDeportSalida.clear();
                    archDeportSalida.seekp(0, archDeportSalida.beg);
                    d.establecerNumeroDeSocio(numero);
                       if(d.obtenerNumeroDeSocio()>=1 && d.obtenerNumeroDeSocio()<=100){
                          cout<<"Teclea nombre, edad y deporte\n?";
                          cin>>setw(15)>>nombre;
                          cin>>edad;
                          cin>>setw(15)>>deporte;
                          //establecer los valores nombre, edad y deporte del registro
                          d.establecerNombre(nombre);
                          d.establecerEdad(edad);
                          d.establecerDeporte(deporte);
                          //buscar la posicion en el archivo de registro especificado por el usuario
                          archDeportSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista)); //seekp(n, ios::beg);
                         //escribir la información especificada por el usuario en el archivo
                          archDeportSalida.write(reinterpret_cast<const char *>(&d),sizeof(Deportista));
                          cout << "Cambiado correctamente" << endl;
                          system("pause");
                          archDeportSalida.clear();
                        }
                        else
                        {
                            cout << "Numero de socio invalido..."<< endl;
                        }
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
                d.establecerNumeroDeSocio(numero);
                archdeportEntrada.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista),ios::beg); //seekp(n, ios::beg);
                // lee el siguiente registro del archivo
                    archdeportEntrada.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
                if ( d.obtenerNumeroDeSocio() != 0)
                    {
                         cout << left << setw( 10 ) << "Num socio" << setw( 16 )
                        << "Nombre" << setw( 11 ) << "Edad" << left
                        << setw( 10 ) << right << "Deporte" << endl;
                        imprimirLinea( cout, d);
                    }
                else
                    {
                        cout << "EL NUMERO DE SOCIO NO EXISTE"<<endl;
                    }
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                cout << "Consulta general" << endl;
                cout << left << setw( 10 ) << "Num socio" << setw( 16 )
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
    archdeportEntrada.clear();
} // fin de consultas

    // muestra un solo registro
    void imprimirLinea( ostream &salida, const Deportista &registro )
    {
    salida << left << setw( 10 ) << registro.obtenerNumeroDeSocio()
    << setw( 16 ) << registro.obtenerNombre()
    << setw( 11 ) << registro.obtenerEdad()
    << setw( 10 ) << setprecision( 2 ) << right << fixed
    << showpoint << registro.obtenerDeporte() << endl;
    } // fin de la función imprimirLinea

void menu()
{
        fstream archDeportENSA("deportistas.dat", ios::out | ios::binary | ios::in );
        if ( !archDeportENSA)
        {
            cerr << "No se pudo abrir el archivo ensa." << endl;
            exit( 1 );
        } // fin de if

    int opc;
    do
    {
    system("cls");
        cout << "1) altas" << endl;
        cout << "2) bajas" << endl;
        cout << "3) cambios" << endl;
        cout << "4) Consulta individual (numero de socio)" << endl;
        cout << "5) Consultas generales" << endl;
        cout << "6) Salir" << endl;
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
                cambios(archDeportENSA,archDeportENSA);
                break;
            }
        case 4:
            {
                consultas(archDeportENSA,opc);
                break;
            }
        case 5:
            {
                consultas(archDeportENSA,opc);
                break;
            }
        case 6:
            {
                cout << "saliendo..."<<endl;
                archDeportENSA.close();
                exit(1);
                break;
            }

        }
    }while(opc!=6);
}
