#include <iostream>
#include <fstream>
#include <deportista.h>

using namespace std;

int main()
{
    ofstream archivoDeportSalida; //archivo logico
    archivoDeportSalida.open("deportistas.txt",ios::binary);
    Deportista deportistaEnBlanco;
    for(int i = 0; i < 5; i++)
        archivoDeportSalida.write(reinterpret_cast<const char *>(&deportistaEnBlanco),sizeof(Deportista));
    cout << "se guardaron 5 objetos deportista en blanco"<<endl;
    Deportista miDeportista(98765,"luis",46,"futbol");
    archivoDeportSalida.write(reinterpret_cast<const char *>(&miDeportista),sizeof(Deportista));
    cout << "se almaceno un objeto deportista con informacion"<<endl;
    archivoDeportSalida.close();
    return 0;
}

