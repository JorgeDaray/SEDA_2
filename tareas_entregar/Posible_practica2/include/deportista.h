#ifndef DEPORTISTA_H
  #define DEPORTISTA_H
  #include <cstring>
  #include <string>

  using namespace std;
  using std::string;


  class Deportista
  {
      public:
          //constructor predeterminado
            Deportista(int = 0, string = "", int = 0, string = "");


          //funciones de acceso para NumeroDeSocio
          void establecerNumeroDeSocio(int);
          int obtenerNumeroDeSocio() const;

          //funciones de acceso para nombre
          void establecerNombre(string);
          string obtenerNombre() const;

          //funciones de acceso para edad
          void establecerEdad(int);
          int obtenerEdad() const;

          //funciones de acceso para deporte
          void establecerDeporte(string);
          string obtenerDeporte() const;


      private:
          int numeroDeSocio;
          char nombre[15];
          int edad;
         char deporte[15];

 };//Fin de la clase Deportista

  #endif // DEPORTISTA_H

