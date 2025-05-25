#include <iostream>
#include <cstring>
#include<iomanip>
#include<fstream>
#define TAMLISTA 20

using std::fstream;
using namespace std;

void menu();

typedef struct Alumno
{
    //unsigned int codigo;
    char nombre[30];
    //unsigned int edad;
    //char direccion[40];
    char sexo[1];
    unsigned int bandera;
    unsigned int posicion;
    //struct Alumno *next;
}datos[TAMLISTA];

struct Lista
{
    Alumno datos[TAMLISTA];
    void inicializa();
    bool vacia();
    bool llena();
    void insertar(int pos, fstream&);
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

struct Lista mi_lista;
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
void Lista::insertar(int pos, fstream&archAluSalida){
    if (llena() || pos < 0 || pos > ultimo + 1)
    {
        cout<<"Ingresa un elemento consecutivo valido"<<endl;
        system("pause");
        return;
    }
    char cadena_h[10]{'H'};
    char cadena_m[10]{'M'};
    archAluSalida.clear();
    archAluSalida.seekg(0, archAluSalida.beg);
    // lee el siguiente registro del archivo
    //archAluSalida.read( reinterpret_cast< char * >( &d ), sizeof( Deportista ) );
    for(int i = ultimo+1 ; i > pos ; i-- )
    {
        datos[i] = datos[i - 1];
    }
    cout << "Ingresa el nombre: "<<endl;
    cin >> datos[pos].nombre;
    cout << "Ingresa el sexo 'm' para mujer o 'h' para hombre: "<<endl;
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
        system("pause");
        return;
    }
    //escribir la información especificada por el usuario en el archivo
    archAluSalida.write(reinterpret_cast<const char *>(&mi_lista),sizeof(Alumno));
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
        cout << "Posicion numero: "<<i<<endl;
        cout << "nombre: "<<datos[i].nombre<<endl;
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

void menu()
{
    fstream archDeportENSA("deportistas.dat", ios::out | ios::binary | ios::in );
    if ( !archDeportENSA)
    {
        cerr << "No se pudo abrir el archivo ensa." << endl;
        exit( 1 );
    } // fin de if
int opc=0;
    while(opc != 4)
    {
    system("cls");
     int pos;
     char cambio[5];
        cout<<" Lista ligada"<<endl;
        cout<<"4) Salir"<<endl;
        cout<<"1) Insertar elemento (Por posicion)"<<endl;
        cout<<"2) Imprimir Lista"<<endl;
        cout<<"3) Intercalar alumnos"<<endl;
        cout<<"Seleccione opcion:"<<endl;
        cin>>opc;
        switch(opc)
        {
            case 1:
            {
                system("cls");
                fflush(stdin);
                cout << "La lista permite ingresar desde la posicion "<<mi_lista.primero<<" hasta la "<<mi_lista.ultimo+1<<endl;
                cout<<"En que posicion desea insertar el elemento?, default 0:"<<endl;
                gets(cambio);
                pos = atoi(cambio);//atoi convierte de char* a int, si no hay un entero lo pasa a 0 por default.
                mi_lista.insertar(pos,archDeportENSA);
            }break;
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
}

