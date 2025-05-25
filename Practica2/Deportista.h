   /*Equipo 4:
   Munguía Guízar Marlon Uriel
   Padilla Perez Jorge Daray
   Pérez Palacios Perla Michelle
   Pulido Tobías Rafael Agustín
   Sección: D19
   Calendario: 2022B
   */
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


      protected:

      private:
          int numeroDeSocio;
          char nombre[15];
          int edad;
         char deporte[15];

 };//Fin de la clase Deportista

  #endif // DEPORTISTA_H

