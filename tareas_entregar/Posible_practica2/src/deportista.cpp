  #include <cstring>
  #include "../include/deportista.h"

  using namespace std;

  //Constructor
  Deportista::Deportista(int valorNumeroDeSocio, string valorNombre, int valorEdad, string valorDeporte)
  {
      establecerNumeroDeSocio(valorNumeroDeSocio);
      establecerNombre(valorNombre);
      establecerEdad(valorEdad);
      establecerDeporte(valorDeporte);
  }//fin constructor

  //Obtiene el valor del número de socio
  int Deportista::obtenerNumeroDeSocio() const{
      return numeroDeSocio;
  }//fin int obtenerNumeroDeSocio

  //Establece el valor del número de Socio
  void Deportista::establecerNumeroDeSocio(int valorNumeroDeSocio){
      numeroDeSocio=valorNumeroDeSocio;
  }//fin void establecerNumeroDeSocio

  //Obtiene el valor del nombre
  string Deportista::obtenerNombre() const{
      return nombre;
  }//fin string obtenerNombre

  //Establece el valor del nombre
  void Deportista::establecerNombre(string cadenaNombre){
      const char*valorNombre = cadenaNombre.data();
      int longitud = cadenaNombre.size();
      longitud = (longitud < 15 ? longitud : 14);
      strncpy(nombre, valorNombre, longitud);
      nombre[longitud] = '\0';
  }//fin void establecerNombre

  //Obtiene el valor de la edad
  int Deportista::obtenerEdad() const{
     return edad;
  }//fin int obtenerEdad

  //Establece el valor de la edad
  void Deportista::establecerEdad(int valorEdad){
      edad=valorEdad;
  }//fin void establecerEdad


  //Obtiene el valor del deporte
  string Deportista::obtenerDeporte() const{
      return deporte;
 }//fin string obtenerDeporte

  //Establece el valor del deporte
  void Deportista::establecerDeporte(string cadenaDeporte){
      const char*valorDeporte = cadenaDeporte.data();
      int longitud = cadenaDeporte.size();
      longitud = (longitud < 15 ? longitud : 14);
      strncpy(deporte, valorDeporte, longitud);
      deporte[longitud] = '\0';
  }//fin void establecerDeporte
