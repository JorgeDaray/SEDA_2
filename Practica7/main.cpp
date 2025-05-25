/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include <iostream>
#include <fstream>
#include <time.h>
#include "ColaGenerica.h"
#define N 99
#define randomize (srand(time(NULL)))
#define random(num) (rand()%(num))
using namespace std;

ColaGenerica<int> mi_cola;

template <class T>
void ColaGenerica<T> :: mostrarCola(fstream&archivoSalida)
{
    int borrados = 0;
    while (! mi_cola.colaVacia())
    {
        int v;
        v = mi_cola.quitar();
        borrados++;
        cout << v << " ";
    }
    cout << endl;
}

template <class T>
void ColaGenerica<T> :: insertar(T elemento)
{
    NodoCola* nuevo;
    nuevo = new NodoCola (elemento);
    if (colaVacia())
    {
        frente = nuevo;
    }
    else
    {
        final -> siguiente = nuevo;
    }
    final = nuevo;
}

template <class T>
T ColaGenerica<T> :: quitar()
{
    if (colaVacia())
    throw "Cola vacía, no se puede extraer.";
    T aux = frente -> elemento;
    NodoCola* a = frente;
    frente = frente -> siguiente;
    delete a;
    return aux;
}

template <class T>
T ColaGenerica<T> :: frenteCola()const
{
    if (colaVacia())
    throw "Cola vacía";
    return frente -> elemento;
}

template <class T>
void ColaGenerica<T> :: borrarCola()
{
    for (;frente != NULL;)
    {
        NodoCola* a;
        a = frente;
        frente = frente -> siguiente;
        delete a;
    }
    final = NULL;
}

template <class T>
bool ColaGenerica<T> :: colaVacia() const
{
    return frente == NULL;
}

template <class T>
void ColaGenerica<T>::GenerarMostrar(fstream&archivoSalida)
{
	int n, n1, n2, i;
    randomize;
    // número inicial de elementos de la lista
    n = 11 + random(N);
    // se generan n números aleatorios
    for (int i = 1; i <= n; i++)
    {
        mi_cola.insertar(random(N * 3));
    }
    // se genera aleatoriamente el intervalo n1
    n1 = 1 + random(11);
    // se retiran de la cola elementos a distancia n1
    while (n1 <= n)
    {
        int nt;
        n2 = 0; // contador de elementos que quedan
        for (i = 1; i <= n; i++)
        {
            nt = mi_cola.quitar();
            if (i % n1 == 1)
            {
                cout << "\n Se quita " << nt << endl;
            }
            else
            {
                mi_cola.insertar(nt); // se vuelve a meter en la cola
                n2++;
            }
        }
        n = n2;
        n1 = 1 + random(11);
    }
    for (int m = 0;m < n;m++)
    {
        //buscar la posicion en el archivo de registro especificado por el usuario
        archivoSalida.seekp((m)*sizeof(int)); //seekp(n, ios::beg);
        //escribir la información especificada por el usuario en el archivo
        archivoSalida.write(reinterpret_cast<const char *>(&mi_cola),sizeof(int));
    }
    cout << "numeros contados: "<<n<<endl;
    cout << "\n\t Los números de la suerte: ";
    mi_cola.mostrarCola(archivoSalida);
}

template <class T>
void ColaGenerica<T>::recuperar()
{
    int numero;
    fstream archAleatENSA("Numeros_suerte1.txt", ios::in );
    if ( !archAleatENSA)
    {
        cerr << "No se pudo abrir el archivo ensa2." << endl;
        exit( 1 );
    } // fin de if
    int datos = 0;
    system("cls");
    // lee el primer registro del archivo
    archAleatENSA.read( reinterpret_cast<char*>( &mi_cola ), sizeof( int ));
    // lee todos los registros del archivo
    while ( archAleatENSA && !archAleatENSA.eof() )
    {
            mi_cola.insertar(numero);
            datos++;
        // lee el siguiente registro del archivo
        archAleatENSA.read( reinterpret_cast<char*>( &mi_cola ), sizeof( int ));
    } // fin de while
    system("pause");
}

int main()
{
    int seleccion;

	do
	{
    fstream archAleatENSA("Numeros_suerte1.txt", ios::out | ios::in );
    if ( !archAleatENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if

    cout<<"\n>>>>>>>>>>>>>> MENU Numeros de la suerte <<<<<<<<<<<<<<\n"<<endl;
		cout<<"1.- Generar y mostrar números de la suerte (Guardar en archivo 1). "<<endl;
		cout<<"2.- Cargar archivo 2,Generar y mostrar números de la suerte. "<<endl;
		cout<<"3.- Salir. "<<endl;
		cout<<"\n>>>>>>>>>>>> Elige tu opcion <<<<<<<<<<<<\n"<<endl;
		cout<<endl;

		cin>>seleccion;

		switch(seleccion)
		{

			case 1:
				mi_cola.GenerarMostrar(archAleatENSA);
			break;

			case 2:
                mi_cola.recuperar();
			break;

			case 3:
				cout<<"\n>>>>>>>>>>>>>> Saliendo <<<<<<<<<<<<<<\n";
			break;
		}

	}while(seleccion != 3);

    return 0;
}

