#include <iostream>
#include <fstream>
using namespace std;

/* Clase abstracta Ordenador, se utiliza para generar clases derivadas
que representan cada uno de los métodos de ordenación externa
estudiados. */
template <class T>
class Ordenador
{
    public:
    virtual void Ordena (char *) = 0;
};

/* Declaración de la clase derivada MezclaDirecta, en la cual el método
Ordena se define con el algoritmo correspondiente al método de
ordenación externa llamado mezcla directa. */
template <class T>
class MezclaDirecta: public Ordenador <T>
{
    public:
    void Ordena (char *);
    void Divide (fstream& , fstream*, fstream*, int);
    void Mezcla (fstream* , fstream& , fstream& , int);
};
/* Método de ordenación de la clase MezclaDirecta. Este método se apoya
en otros dos: Divide y Mezcla, los cuales implementan las dos
operaciones analizadas en el ejemplo anterior. Recibe como parámetro
el nombre del Arch0ivo a ordenar. */

template <class T>
void MezclaDirecta <T>::Ordena (char *NomArch0)
{
    fstream Arch0, Arch01, Arch02;
    int Partic, Maximo = 0;
    Arch0.open(NomArch0, ios::in | ios::out);
    Arch0.seekg(0, ios::end);
    /* Calcula el total de datos guardados en el Arch0ivo. */
    Maximo = Arch0.tellg();
    Partic= 1;
    while (Partic < Maximo)
    {
        Divide(Arch0, &Arch01, &Arch02, Partic);
        Mezcla(&Arch0, Arch01, Arch02, Partic);
        Partic= Partic * 2;
    }
    Arch0.close();
}
/* Método auxiliar que parte el Arch0ivo a ordenar en dos Arch0ivos, de
acuerdo a un tamaño de partición que recibe como parámetro, junto con
el Arch0ivo original y los dos que formará. */
template <class T>
void MezclaDirecta <T>::Divide (fstream& Arch0, fstream *Arch01, fstream *Arch02, int Partic)
{
    int Cont, Dato;
    Arch0.seekg(0, ios::beg);
    Arch01->open("MezclaDirAux1.txt", ios::out);
    Arch02->open("MezclaDirAux2.txt", ios::out);
    while (!Arch0.eof())
    {
        Cont= 0;
        while ((Cont < Partic) && (!Arch0.eof()))
        {
            Arch0.read(reinterpret_cast< char * >( &Dato ),sizeof(Dato));
            if (!!Arch0.eof())
            Arch01->write(reinterpret_cast<const char * >( &Dato ), sizeof(Dato));
            Cont++;
        }
        Cont= 0;
        while ((Cont < Partic) && (!Arch0.eof()))
        {
            Arch0.read(reinterpret_cast< char * >( &Dato ), sizeof(Dato));
            if (!Arch0.eof())
            Arch02->write(reinterpret_cast<const char * >( &Dato ), sizeof(Dato));
            Cont++;
        }
    }
    Arch01->close();
    Arch02->close();
}
/* Método auxiliar que mezcla dos Arch0ivos que recibe como parámetro y
genera otro el cual va quedando ordenado. */
template <class T>
void MezclaDirecta <T>::Mezcla (fstream *Arch0, fstream& Arch01, fstream&
Arch02, int Partic)
{
    int Dato1, Dato2, Part1, Part2, Band1, Band2;
    Arch0->seekp(0, ios::beg);
    Arch01.open("MezclaDirAux1.dat", ios::in);
    Arch02.open("MezclaDirAux2.dat", ios::in);
    Band1= 1;
    Band2= 1;
    Arch01.read(reinterpret_cast< char * >( &Dato1 ), sizeof(Dato1));
    if (!Arch01.eof())
    Band1= 0;
    Arch02.read(reinterpret_cast< char * >( &Dato2 ),sizeof(Dato2));
    if (!Arch02.eof())
    Band2= 0;
    while ( ((!Arch01.eof()) || (!Band1)) && ((!Arch02.eof()) || (!Band2)) )
    {
        Part1= 0;
        Part2= 0;
        while (((Part1 < Partic) && (!Band1)) && ((Part2 < Partic)
        && (!Band2)))

        if (Dato1 <= Dato2)
        {
            Arch0->write(reinterpret_cast< const char * >( &Dato1 ), sizeof(Dato1));
            Band1= 1;
            Part1++;
            Arch01.read(reinterpret_cast< char * >( &Dato1 ), sizeof(Dato1));
            if (!Arch01.eof())
            Band1= 0;
        }
        else
        {
            Arch0->write(reinterpret_cast< const char * >( &Dato2 ), sizeof(Dato2));
            Band2= 1;
            Part2++;
            Arch02.read(reinterpret_cast< char * >( &Dato2 ), sizeof(Dato2));
            if (!Arch02.eof())
            Band2= 0;
        }
    }
    while ((Part1 < Partic) && (!Band1))
    {
        Arch0->write(reinterpret_cast< const char * >( &Dato1 ), sizeof(Dato1));
        Band1= 1;
        Part1++;
        Arch01.read(reinterpret_cast< char * >( &Dato1 ), sizeof(Dato1));
        if (!Arch01.eof())
        Band1= 0;
    }
    while ((Part2 < Partic) && (!Band2))
    {
        Arch0->write(reinterpret_cast< const char * >( &Dato2 ), sizeof(Dato2));
        Band2= 1;
        Part2++;
        Arch02.read(reinterpret_cast< char * >( &Dato2 ), sizeof(Dato2));
        if (!Arch02.eof())
        Band2= 0;
    }
if (!Band1)
{
    Arch0->write(reinterpret_cast< const char * >( &Dato1 ), sizeof(Dato1));
}
if (!Band2)
{
    Arch0->write(reinterpret_cast< const char * >( &Dato2 ), sizeof(Dato2));
    Arch01.read(reinterpret_cast< char * >( &Dato1 ), sizeof(Dato1));
}
while (!Arch01.eof())
{
    Arch0->write(reinterpret_cast< const char * >( &Dato1 ), sizeof(Dato1));
    Arch01.read(reinterpret_cast< char * >( &Dato1 ), sizeof(Dato1));
}
Arch02.read(reinterpret_cast< char * >( &Dato2 ), sizeof(Dato2));
while (!Arch02.eof())
{
    Arch0->write(reinterpret_cast< const char * >( &Dato2 ), sizeof(Dato2));
    Arch02.read(reinterpret_cast< char * >( &Dato2 ), sizeof(Dato2));
    int length = Arch0->tellg();
    cout << length<<endl;
    if (length == -1){break;}
}
Arch01.close();
Arch02.close();
}

MezclaDirecta<fstream> mi_mezcla;

int main()
{
    fstream archSalEnt("Numeritos.txt",ios::out | ios::binary | ios::in );
        if (!archSalEnt)
        {
            cerr << "No se pudo abrir el archivo"<<endl;
            exit(1);
        }
    int opc;
    cout <<"Menu-Ordenacion externa"<<endl;
    cout <<"opcion 1) mezcla directa"<<endl;
    cout <<"opcion 2) mezcla Equilibrada"<<endl;
    cout <<"opcion 3) Salir "<<endl;
    cout << "Elige tu opcion: "<<endl;
    cin >> opc;
    switch(opc)
    {
        case 1:
            mi_mezcla.Ordena("Numeritos.txt");
            break;
    }
}
