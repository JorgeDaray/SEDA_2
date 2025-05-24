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
            archivoDeportistasEntrada.seekg(0);//Reposiciona el puntero al inicio del archivo

		system("cls");

		cout<<"\n>>>>>>>>>> Menu Asociacion de Deportistas Tapatios <<<<<<<<<<\n"<<endl;
		cout<<"1.- Mostrar deportistas menores de edad (5-17). "<<endl;
		cout<<"2.- Mostrar deportistas mayores de edad(18-59). "<<endl;
		cout<<"3.- Mostrar Mostrar deportistas menores de edad(60-85). "<<endl;
		cout<<"0.- Salir. "<<endl;
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>> Elige tu opcion <<<<<<<<<<<<<<<<<<<<<<\n"<<endl;
		cout<<endl;

		cin>>seleccion;

		switch(seleccion)
		{
		    archivoDeportistasEntrada.clear();//Limpia cin y establece el bit goodbit para permitir el flujo
			case 0:
				system("cls");
				cout<<"\n>>>>>>>>>>>>>> Saliendo <<<<<<<<<<<<<<\n"<<endl;
				getch();
			break;

			case 1:
				system("cls");
				cout<<"Deportistas menores de edad:"<<endl;
				cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(!archivoDeportistasEntrada.eof())//mientras no se llegue a end of file
				{
				    mostrarLinea(nombre,edad,deporte);

					if (edad<18 && edad>4)
					{
					    archivoDeportistasEntrada >> nombre >> edad >> deporte;
					}

				}

				getch();
			break;

			case 2:
				system("cls");
				cout<<"Deportistas mayores de edad:"<<endl;
				cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(!archivoDeportistasEntrada.eof())//mientras no se llegue a end of file
				{
				    mostrarLinea(nombre,edad,deporte);
					if (edad>17 && edad<60)
					{
					    archivoDeportistasEntrada >> nombre >> edad >> deporte;

					}

				}

				getch();
			break;

			case 3:
			system("cls");
			cout<<"Deportistas adultos mayores:"<<endl;
			cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;//imprime la cabecera de la tabla

				while(!archivoDeportistasEntrada.eof())//mientras no se llegue a end of file
				{
                    mostrarLinea(nombre,edad,deporte);
					if (edad>59 && edad<86)
					{
					    archivoDeportistasEntrada >> nombre >> edad >> deporte;
					}

				}

				getch();
			break;
		}

	}while(seleccion != 0);

	return 0;
}//main



/*void recuperarDeportistas()
{

		//tres campos que conforman	un registro
	char nombre [30];
	int edad;
	char deporte [20];

	ifstream archivoDeportistasEntrada; //archivo lógico
	archivoDeportistasEntrada.open ("deportistas.txt", ios::in);

	//salir del programa si no se puede crear el archivo
	if (!archivoDeportistasEntrada) //operador ! sobrecargado
	{
		cerr<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}

	//imprime la cabecera de la tabla
	cout<<left<<setw(10)<<"NOMBRE"<<setw(13)<<"EDAD"<<"DEPORTE"<<endl<<fixed<<showpoint;

//mostrar cada registro del archivo
while (archivoDeportistasEntrada>>nombre>>edad>>deporte)
mostrarLinea(nombre,edad,deporte);

archivoDeportistasEntrada.close();

getch();
getch();

}//fin funcion recuperarClientes*/


// muestra un solo registro del archivo
void mostrarLinea(const char * const nombre, int edad, const char * const deporte)
{	cout<<left<<setw(10)<<nombre<<setw(13)<<edad<<setw(7)<<deporte<<endl;
}//mostrar linea
