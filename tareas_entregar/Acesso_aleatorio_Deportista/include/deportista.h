#ifndef DEPORTISTA_H
#define DEPORTISTA_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
using std::string;

class Deportista
{
    public:

        Deportista(int = 0, string = "", int = 0, string = "");

        string convertir(char *);
        void establecernumerodesocio(int);
        int obtenernumerosocio();
        void establecernombre(string);
        string obtenernombre();
        void estableceredad(int);
        int obteneredad();
        void establecerdeporte(string);
        string obtenerdeporte();
        ~Deportista();

    private:
        int numerodesocio;
        char nombre[15];
        int edad;
        char deporte[15];
        string temporal = convertir(nombre);
        string temporal_d = convertir(deporte);
};

#endif // DEPORTISTA_H
