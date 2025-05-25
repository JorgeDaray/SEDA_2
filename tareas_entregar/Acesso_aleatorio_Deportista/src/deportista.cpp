#include "deportista.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Deportista::Deportista(int valornumerosocio, string valornombre, int valoredad, string valordeporte)
{
    establecernumerodesocio(valornumerosocio);
    establecernombre(valornombre);
    estableceredad(valoredad);
    establecerdeporte(valordeporte);
}//ctor

        string Deportista::convertir(char * palabra)
        {
            int i;
            int palabra_size = sizeof(palabra) / sizeof(char);
            string s = "";
             for (i = 0; i < palabra_size; i++){
                s = s + palabra[i];
            }
            return s;
        }
        void Deportista::establecernumerodesocio(int valornumerodesocio){numerodesocio = valornumerodesocio;}
        int Deportista::obtenernumerosocio(){return numerodesocio;}
        void Deportista::establecernombre(string valornombre)
        {
            temporal = valornombre;
        }
        string Deportista::obtenernombre()
        {
            return temporal;
        }
        void Deportista::estableceredad(int valoredad){edad = valoredad;}
        int Deportista::obteneredad(){return edad;}
        void Deportista::establecerdeporte(string valordeporte)
        {
            temporal_d = valordeporte;
        }
        string Deportista::obtenerdeporte()
        {
            return temporal_d;
        }

Deportista::~Deportista()
{

}//dtor
