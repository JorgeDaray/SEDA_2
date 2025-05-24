/*
Equipo numero 4:
Munguía Guízar Marlon Uriel
Pérez Palacios Perla Michelle
Padilla Perez Jorge Daray
Pulido Tovias Rafael Regular

Seccion D19
Calendario 2022B
*/

#include <iostream>
#include <fstream>
#include <iomanip> //left, setw, fixed, showpoint
#include <cstdlib> //exit
#include <conio.h>

using namespace std;

void mostrarLinea(const char * const, int, const char * const); //prototipos

int main()
{
	int seleccion, edad;
	char nombre [30];
	char deporte [20];

	ifstream archivoDeportistasEntrada; //archivo lógico
	archivoDeportistasEntrada.open ("deportistas.txt", ios::in);

	//salir del programa si no se puede crear el archivo
	if (!archivoDeportistasEntrada) //operador ! sobrecargado
	{
		cerr<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	do
	{

		system("cls");

		cout<<"\n>>>>>>>>>> Menu Asociacion de Deportistas Tapatios <<<<<<<<<<\n"<<endl;
		cout<<"1.- Mostrar deportistas menores de edad (5-17). "<<endl;
		cout<<"2.- Mostrar deportistas mayores de edad(18-59). "<<endl;
		cout<<"3.- Mostrar Mostrar deportistas menores de edad(60-85). "<<endl;
		cout<<"0.- Salir. "<<endl;
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>> Elige tu opcion <<<<<<<<<<<<<<<<<<<<<<\n"<<endl;
		cout<<endl;

		cin>>seleccion;

		archivoDeportistasEntrada.clear();//Limpia cin y establece el bit goodbit para permitir el flujo
		archivoDeportistasEntrada.seekg(0);//Reposiciona el puntero al inicio del archivo

		switch(seleccion)
		{
			case 0:
				system("cls");
				cout<<"\n>>>>>>>>>>>>>> Saliendo <<<<<<<<<<<<<<\n"<<endl;
				getch();
			break;

			case 1:
				system("cls");
				cout<<"Deportistas menores de edad:"<<endl;
				cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(archivoDeportistasEntrada>>nombre>>edad>>deporte)
				{
					if (edad<18 && edad>4)
					{
						mostrarLinea(nombre,edad,deporte);
					}

				}

				getch();
				getch();
			break;

			case 2:
				system("cls");
				cout<<"Deportistas mayores de edad:"<<endl;
				cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(archivoDeportistasEntrada >> nombre >> edad >> deporte)
				{

					if (edad>17 && edad<60)
					{
						mostrarLinea(nombre,edad,deporte);
					}

				}

				getch();
				getch();
			break;

			case 3:
			system("cls");
			cout<<"Deportistas adultos mayores:"<<endl;
			cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(archivoDeportistasEntrada >> nombre >> edad >> deporte)
				{

					if (edad>59 && edad<86)
					{
						mostrarLinea(nombre,edad,deporte);

					}

				}

				getch();
				getch();
			break;
		}

	}while(seleccion != 0);

	return 0;
}//main


// muestra un solo registro del archivo
void mostrarLinea(const char * const nombre, int edad, const char * const deporte)
{	cout<<left<<setw(10)<<nombre<<setw(13)<<edad<<setw(7)<<deporte<<endl;
}//mostrar linea

