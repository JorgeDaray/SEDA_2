#include <iostream>
#include <string.h>
using namespace std;


int guarda_h,guarda_m;
typedef struct Alumno
    {
        unsigned int codigo;
        char nombre[30];
        unsigned int edad;
        char direccion[40];
        char sexo[1];
        unsigned int bandera;
        struct Alumno *next;
    }Alumno;
    Alumno * first;

struct Lista{
void inicializa();
bool vacia();
void inserta(int pos);
void Imprime();
void eliminateNode();
void anular();
void inserfirst();
void insertpos();
void intercalar();
Alumno *first;
Alumno *last;
Lista(){
inicializa();
}
};

void Lista::inicializa(){
    first = nullptr;
    guarda_h = 1,guarda_m = 0;
};

bool Lista::vacia(){
    return first == nullptr;
}

Lista mi_lista;
int main()
{
    int opc, pos = 0;
    do{
    cout << "\tIntroduce una opcion: "<<endl;
    cout << "\n0.-Salir\n1.-Inserta por posicion\n2.-Imprimir nodos\n3.-Intercalar"<<endl;
    cin >>opc;
    switch(opc){
        case 0:
                break;
        case 1:
                cout << "Posicion a insertar:\n"<<endl;
                cin >>pos;
                mi_lista.inserta(pos);
                break;
        case 2:
                mi_lista.Imprime();
                system("pause");
                break;
       case 3:
                mi_lista.intercalar();
                system("pause");
                break;
        default:
                break;
    }
    system("cls");
    }while(opc!=0);


    return 0;
}

void Lista::inserta(int pos)
{
    Alumno *aux = nullptr;
    aux = new Alumno;
    char cadena_h[10]{'h'};
    char cadena_m[10]{'m'};
    if (pos == 0)
    {
        Alumno *in_first = nullptr;
            in_first = new Alumno;
            cout << "Ingresa el codigo: "<<endl;
            cin >> in_first->codigo;
            cout << "Ingresa el nombre: "<<endl;
            cin >> in_first->nombre;
            cout << "Ingresa la edad: "<<endl;
            cin >> in_first->edad;
            cout << "Ingresa la direccion: "<<endl;
            cin >> in_first->direccion;
            cout << "Ingresa el sexo: "<<endl;
            cin >> in_first->sexo;
            if ( strcmp(in_first->sexo, cadena_m) ==0 )
            {
                in_first->bandera = guarda_m;
                guarda_m = guarda_m + 2;
            }
            else if ( strcmp(in_first->sexo, cadena_h) ==0 )
            {
                in_first->bandera = guarda_h;
                guarda_h = guarda_h + 2;
            }
        if(first == NULL){
            first = in_first;
            first ->next = NULL;
            last = in_first;
        }
        else{
            in_first->next = first;
            first=in_first;
        }
    }
    else
    {
        cout << "Ingresa el codigo: "<<endl;
        cin >> aux->codigo;
        cout << "Ingresa el nombre: "<<endl;
        cin >> aux->nombre;
        cout << "Ingresa la edad: "<<endl;
        cin >> aux->edad;
        cout << "Ingresa la direccion: "<<endl;
        cin >> aux->direccion;
        cout << "Ingresa el sexo: "<<endl;
        cin >> aux->sexo;
        if ( strcmp(aux->sexo, cadena_m) == 0 )
        {
            aux->bandera = guarda_m;
            guarda_m = guarda_m + 2;
        }
        else if ( strcmp(aux->sexo, cadena_h) ==0 )
        {
            aux->bandera = guarda_h;
            guarda_h = guarda_h + 2;
        }
        Alumno *aux2, *aux3;
        aux2 = first;
        for (int i=0; i<pos; i++)
        {
            aux3 = aux2;
            aux2 = aux2->next;
        }
        aux3->next = aux;
        aux->next = aux2;
    }
}

void Lista::Imprime()
{
    Alumno *temp = nullptr;
    temp = first;
    if (not vacia()){
        int i = 0;
        cout << "ancla ->" << endl;
        while (temp != NULL){
            cout << "Posicion : "<<i<<endl;
            cout << "codigo: "<<temp->codigo<<endl;
            cout << "nombre: "<<temp->nombre<<endl;
            cout << "edad: "<<temp->edad<<endl;
            cout << "direccion: "<<temp->direccion<<endl;
            cout << "sexo: "<<temp->sexo<<endl;
            cout << "bandera: "<<temp->bandera<<endl<<endl;
            temp = temp ->next;
            i++;
        }
        cout << "-> nullptr"<< endl;
    }
    else{
        cout << "\n La lista esta vacia "<<endl;
    }
}

void Lista::eliminateNode()
{
    Alumno *actual = nullptr;
    actual = first;

    Alumno *before =nullptr;

    int found = 0 ;
    char cadena[50];
        cout << " Introduce el nombre del alumno que desea eliminar: "<<endl;
        cin >> cadena;
    if(not vacia()){
        while(actual != NULL && found != 1){

            if ( strcmp(actual->nombre, cadena)==0 ){

                if(actual == first){
                    first = first ->next;
                }
                else{
                    before -> next = actual -> next;
                }
                found = 1;
            }
            before = actual;
            actual = actual ->next;
        }
        if(found == 0){
            cout << "\nEl nodo no se encontro\n"<<endl;
        }
        else{
            free(before);
        }
    }
    else{
        cout << "\n La lista esta vacia "<<endl;
    }
    printf("\n");
}

void Lista::anular()
{
    Alumno *actual = nullptr;
    actual = first;

    Alumno *before = nullptr;

    if(not vacia())
        {
            while(actual != NULL)
            {
                before = actual;
                actual = actual ->next;
                free(before);
            }
        }
        else
        {
        cout << "\n La lista esta vacia "<<endl;
        }
    printf("\n");
    inicializa();
}

void Lista::intercalar()
{
    Alumno *Actual = nullptr;
    Actual = first;
    Alumno *before = nullptr;
    before = first;

    Alumno *auxiliar = nullptr;
    if(not vacia())
        {
            while(Actual->next != NULL)
            {
                while(before->next->next != NULL)
                {
                    if(before->bandera < before->next->bandera)
                    {
                        auxiliar = before;
                        before = before->next;
                        before->next = auxiliar;
                        cout << "Bandera: "<<auxiliar->bandera;
                    }
                    before = before->next->next;
                }
                Actual = Actual->next;
                before = first;
                cout << "Bandera dentro: "<<auxiliar->bandera;
            }
            cout << "Bandera fuera: "<<auxiliar->bandera;
        }
        else
        {
        cout << "\n La lista esta vacia "<<endl;
        }
}



