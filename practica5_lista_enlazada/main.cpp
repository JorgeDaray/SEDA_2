/*Equipo 4:
   Munguia Guizar Marlon Uriel
   Padilla Perez Jorge Daray
   Perez Palacios Perla Michelle
   Pulido Tobias Rafael Agustin
   Seccion: D19
   Calendario: 2022B
   */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#define TAMLISTA 20

using namespace std;

void menu();

struct Alumno
{
    char nombre[30];
    unsigned int edad;
    char sexo[1];
    unsigned int bandera;
    //struct Alumno *next;
}datos[TAMLISTA];

struct Lista
{
    Alumno datos[TAMLISTA];
    void inicializa();
    bool vacia();
    bool llena();
    void insertar(int pos);
    void elimina(int pos);
    int ultimo;
    int primero;
    int guarda_m,guarda_h;
    void imprimir();
    void anular();
    void burbuja_mejorada();
    bool lista_ordenada ();
    Lista()//Constructor
    {
        inicializa();
    }
};

//Inicializa la lista con sus variables
void Lista::inicializa()
{
    ultimo = -1;
    primero = 0;
    guarda_h = 1,guarda_m = 0;
}

//Verifica si la lista esta vacia
bool Lista::vacia()
{
    return ultimo == -1;
}

//Verifica si la lista esta llena
bool Lista::llena()
{
    return ultimo == TAMLISTA - 1;
}

//Elimina toda la lista
void Lista::anular()
{
    ultimo = -1;
}

//Inserta alumno por posicion
void Lista::insertar(int pos){
    if (llena() || pos < 0 || pos > ultimo + 1)
    {
        cout<<"Ingresa un elemento consecutivo valido"<<endl;
        return;
    }
    char cadena_h[TAMLISTA]{'M'};
    char cadena_m[TAMLISTA]{'F'};
    //Recorre la posicion de la lista si ya existe para no sobreescribir
    for(int i = ultimo+1 ; i > pos ; i-- )
    {
        datos[i] = datos[i - 1];
    }
    cout << "Ingresa el nombre: "<<endl;
    cin >> datos[pos].nombre;
    cout << "Ingresa la edad: "<<endl;
    cin >> datos[pos].edad;
    cout << "Ingresa el sexo 'f' para femenino o 'm' para masculino: "<<endl;
    cin >> datos[pos].sexo;
    //0x5F Quita el 32 a nivel bits para hacer mayusculas
    if (*datos[pos].sexo = ( *datos[pos].sexo >= 'a' && *datos[pos].sexo <= 'z')? *datos[pos].sexo & 0x5F : *datos[pos].sexo)//cadena de entrada rango, entonces hace un if corto
    ;
    //Compara si sexo es masculino o femenino
     if ( strcmp(datos[pos].sexo, cadena_m) ==0 )
    {
        datos[pos].bandera = guarda_m;
        guarda_m = guarda_m + 2;
    }
    else if ( strcmp(datos[pos].sexo, cadena_h) ==0 )
    {
        datos[pos].bandera = guarda_h;
        guarda_h = guarda_h + 2;
    }
    else
    {
        cout<<"Ingresa un elemento valido"<<endl;
        return;
    }
        ultimo++;
}


void Lista::elimina(int pos)
{
    if (vacia() || pos < 0 || pos > ultimo ){
        cout<<"La lista esta vacia"<<endl;
        return;
    }

    for (int i = pos ; i <= ultimo ; i++){
    datos[i] = datos[i + 1];
    }
    ultimo--;
}

void Lista::imprimir()
{
    if (vacia()){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    for(int i = primero ; i <= ultimo ; i++)
    {
        cout << "Posicion numero: "<<i+1<<endl;
        cout << "nombre: "<<datos[i].nombre<<endl;
        cout << "edad: "<<datos[i].edad<<endl;
        cout << "sexo: "<<datos[i].sexo<<endl;
    }
}

bool Lista::lista_ordenada(){
    int j = primero, i = ultimo;
        while (j < i){
            if (datos[j].bandera > datos[j+1].bandera){
                    return 0;
            }
            j++;
        }
        i--;
    return 1
    ;
}

void Lista::burbuja_mejorada()
{
    if (vacia()){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    if(lista_ordenada())
    {
        cout<<"La lista esta intercalada, no hace falta intercalar"<<endl;
        return;
    }
        int i = ultimo, j;
        Alumno mi_alumno;
        bool cambio;
        do{
            cambio = false;
            j = 0;
            while (j < i){
                if (datos[j].bandera > datos[j+1].bandera){
                    mi_alumno = datos[j];
                    datos[j] = datos[j+1];
                    datos[j+1] = mi_alumno;
                    cambio = true;
                }
                j++;
            }
            i--;
        }while(cambio);
        cout << "Alumnos intercalados correctamente"<<endl;
}


int main()
{
    menu();
    return 0;
}

struct Lista mi_lista;
void menu(){
	FILE *archivo;//Creacion de archivo logico
    archivo = fopen("alumnos.dat","w+");//Creacion de archivo fisico a traves del archivo logico en modo escritura y lectura
	int i=0;
	int opc=0;
	    while(opc != 4)
	    {
	    system("cls");
	     int pos;
	     char cambio[5];
	        cout<<" Menú - Sistema Control Escolar"<<endl;
	        cout<<"1) Insertar alumnos"<<endl;
	        cout<<"2) Mostrar todos los alumnos"<<endl;
	        cout<<"3) Transformar la lista original (Intercalar)"<<endl;
	        cout<<"4) Salir"<<endl;
	        cout<<"Seleccione opcion:"<<endl;
	        cin>>opc;
	        switch(opc)
	        {
	            case 1:
	            {
	                system("cls");
	                fflush(stdin);
	                cout<<"En que posicion desea insertar el alumno?, Inicio en 1."<<endl;
	                gets(cambio);
	                pos = atoi(cambio);//atoi convierte de char* a int, si no hay un entero lo pasa a 0 por default.
	                pos = pos-1;
	                mi_lista.insertar(pos);
	                i++;
	                system("pause");
	            }
				break;
	            case 2:
	            {
	                system("cls");
	                mi_lista.imprimir();
	                system("pause");
	            }break;
	            case 3:
	            {
	                system("cls");
	                mi_lista.burbuja_mejorada();
	                system("pause");
	            }break;
	            case 4:break;

	            default:
	                cout<<"La opcion: "<<opc<<"No existe"<<endl;
	        }
	    }

	    if (archivo){
	    	fwrite(reinterpret_cast <const char*> (&mi_lista),sizeof(struct Alumno),i,archivo);
	    	fclose(archivo);
		}
}
