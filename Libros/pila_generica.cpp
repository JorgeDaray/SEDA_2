#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
typedef Tipo TipoDeDato;
using namespace std;
 
#define MAX 10

template <class T>
class PilaGenerica
{
	 class NodoPila
	 {
		 public:
		 NodoPila* siguiente;
		 T elemento;
		 NodoPila(T x){
			 elemento = x;
			 siguiente = NULL;
		 }
	 };
		 NodoPila* cima;
		 public:
		 PilaGenerica (){
		 	cima = NULL;
		 }
	 void insertar(T elemento);
	 T quitar();
	 T cimaPila(); const
	 bool pilaVacia(); const
	 void limpiarPila();
	 ~PilaGenerica()
	 {
	 	limpiarPila();
	 }
};


template <class T>
bool PilaGenerica<T>::pilaVacia() const
{
 	return cima == NULL;
}

template <class T>
void PilaGenerica<T>::insertar(T elemento)
{
	 NodoPila* nuevo;
	 nuevo = new NodoPila(elemento);
	 nuevo -> siguiente = cima;
	 cima = nuevo;
}

template <class T>
T PilaGenerica<T>::quitar()
{
	 if (pilaVacia())
	 throw "Pila vacía, no se puede extraer.";
	 T aux = cima -> elemento;
	 cima = cima -> siguiente;
	 return aux;
}

template <class T>
T PilaGenerica<T>:: cimaPila(); const
{
	 if (pilaVacia())
	 throw "Pila vacía";
	 return cima -> elemento;
}

template <class T>
void PilaGenerica<T>:: limpiarPila(){
		 NodoPila* n;
		 while(!pilaVacia())
	 {
		 n = cima;
		 cima = cima -> siguiente;
		 delete n;
	 }
}

class libro (){
	private:
		char nombre[20];
		char autor[20];
		char Editorial[15];
	public:
		libro(char[],char[],char);
		libro();
		~libro();
};




int main ()
{
    Libro mi_pila;
     char Libro[20];
     char autor[20];
     char Editorial[20];
    int opcion = 0;
    do{
		cout<<endl<<"Menu-Sistema de cuentas"<<endl;
	    cout<<"1.- Insertar"<<endl;
	    cout<<"2.- Eliminar "<<endl;
	    cout<<"3.- Salir"<<endl;
	    cout<<"Elige tu opcion:" ;
	    cin>>opcion;
	
	    switch (opcion) {
	        case 1:
	        	cout<<"Ingrese el nombre del Libro "<< endl;
	        	cin>>Libro;
	        	cout<<"Ingrese el nombre del autor "<< endl;
	        	cin>>
	        	cout<<"Ingrese el nombre de la editorial "<< endl;
	        	cin>>
	        	mi_pila.insertar();
	        break;
	
	        case 2:
	            break;
	
	        case 3:
	            break;
	
	        }
	    system("pause");
	    system("cls");
	}while(opcion!=3);
	
}
