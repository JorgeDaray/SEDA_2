/*Practica 12 Dispersión
  Menu para registrar Alumnos con los siguientes datos:
  su codigo de estudiante usado como llave para asignarle una direccion, nombre, apellido, curso, y edad.

  Seccion: D19
  Calendario: 2022B

  Munguía Guízar Marlon Uriel
  Padilla Perez Jorge Daray
  Pulido Tobias Rafael Agustín
  */

  #include <iostream>
  #include <conio.h>
  #include <fstream>
  #include <string.h>
  #define NUMREGISTROS 100
  #define CONTENEDOR 4

  using namespace std;

  class Alumno
  {
	  private:
		  char codigo[ 12 ];
		  char nombre[ 35 ];
		  char apellido[ 35 ];
		  char curso[ 35 ];
	   	  char edad[ 35 ];

		  int dispersion( const char llave[ 12 ] );
		  long int buscarCodigo( const string & );

	  public:
		  Alumno ( void );
		  Alumno( const Alumno & );
		  void setCodigo( const string & );
		  void setnombre( const string & );
		  void setapellido( const string & );
		  void setCurso( const string & );
		  void setEdad( const string & );
		  friend ostream &operator<<( ostream &, const Alumno & );

		  bool registrar( const Alumno & );
		  void mostrar( void );
		  bool buscar( const string &, Alumno & );
		  bool eliminar( const string &, Alumno & );
		  bool modificar( const string &, const Alumno & );
		  void mostrarIndice( void );
		  Alumno pedirRegistro( void );
		  bool contiene( const string & );
		  void genera( void );
  };

  Alumno::Alumno( void )
  {
	  for( int i = 0; i < sizeof( codigo ); codigo[ i++ ] = '\0');
	  for( int i = 0; i < sizeof( nombre ); nombre[ i++ ] = '\0');
	  for( int i = 0; i < sizeof( apellido ); apellido[ i++ ] = '\0');
	  for( int i = 0; i < sizeof( curso ); curso[ i++ ] = '\0');
	  for( int i = 0; i < sizeof( edad ); edad[ i++ ] = '\0');
  }

  bool Alumno::contiene( const string &idABuscar )
  {
	  if( buscarCodigo( idABuscar ) == -1 )
	  return false;
	  return true;
  }

  Alumno Alumno::pedirRegistro( void )
  {
	  Alumno registroARetornar;
	  string cadena;

	  cout << endl << "Codigo: ";
	  fflush( stdin );
	  getline( cin, cadena );
	  while( contiene( cadena ) || cadena.size() == 0 )
	  {
		  cout << "\n\nEse jugador ya existe o la cadena es invalida, ingresar nuevamente.\n ";
		  cout << endl << "Codigo: ";
		  fflush( stdin );
		  getline( cin, cadena );
	  }
	  registroARetornar.setCodigo( cadena );

	  cout<< "Nombre: ";
	  fflush( stdin );
	  getline( cin, cadena );
	 registroARetornar.setnombre( cadena );

	  cout << "apellido: ";
	 fflush( stdin );
	  getline( cin, cadena );
	 registroARetornar.setapellido( cadena );

	  cout << "curso: ";
	 fflush( stdin );
	  getline( cin, cadena );
	 registroARetornar.setCurso( cadena );

	 cout << "edad: ";
	 fflush( stdin );
	  getline( cin, cadena );
	 registroARetornar.setEdad( cadena );

	 return registroARetornar;
 }

 void Alumno::genera( void )
 {
	 Alumno promo;
	 int contador = 0;
	 ofstream archEntSalEstudiantes( "estudiantes.txt", ios::out );
	 if( !archEntSalEstudiantes )
	 	cout << "No se pudo crear el archivo" << endl;
	 else
		 for( int i = 0; i < NUMREGISTROS; i++ )
		 {
			 // indica cuantos registros hay en el contenedor
			 archEntSalEstudiantes.write( ( char * ) &contador, sizeof( int ) );
			 for( int j = 0; j < CONTENEDOR; j++ )
			 {
			 	archEntSalEstudiantes.write( ( char * ) &promo, sizeof( Alumno ) );
			 }
		 }
	 archEntSalEstudiantes.close();
 }

 int Alumno::dispersion( const char llave[ 12 ] )
 {
	 // llena el sobrante de la llave con espacios

	 char llaveCopia[ 12 ];
	 strcpy( llaveCopia, llave );
	 if( strlen( llaveCopia ) < 12 )
	 	for( int i = strlen( llaveCopia ); i < 12; i++ )
	 		llaveCopia[ i ] = ' ';
	 llaveCopia[ 12 ] = '\0';

	 // realiza el algoritmo
	 long sum = 0;
	 int j = 0;
	 while( j < 12 )
	 {
		 sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] ) % 20000;
		 j += 2;
	 }
	 return ( sum % 99 );
 }

 long int Alumno::buscarCodigo( const string &idABuscar )
 {
	 Alumno promo;
	 int contador, posIndice;
	 long int posByte;

	 ifstream archEntSalEstudiantes( "estudiantes.txt", ios::in );
	 if( !archEntSalEstudiantes )
	 {
		 cout << "El archivo no existe" << endl;
		 archEntSalEstudiantes.close();
		 return -1;
	 }

	 posIndice = dispersion( idABuscar.c_str() );
	 posByte = posIndice * ( ( sizeof( Alumno ) * CONTENEDOR ) + sizeof( int ) );
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
	 if( contador > 0 )
	 {
		 for( int i = 0; i < CONTENEDOR; i++ )
		 {
			 archEntSalEstudiantes.read( ( char * ) &promo, sizeof( Alumno ) );
			 if( strcmp( promo.codigo, idABuscar.c_str() ) == 0 )
			 {
				 posByte = ( long )archEntSalEstudiantes.tellg() - sizeof( Alumno );
				 archEntSalEstudiantes.close();
				 return posByte;
			 }
		 }
	 }

	 archEntSalEstudiantes.close();
	 return -1;
 }

 void Alumno::setCodigo( const string &valorId )
 {
	 int longitud = valorId.size();
	 longitud = ( longitud < 12 ? longitud : 11 );
	 valorId.copy( codigo, longitud );
	 codigo[ longitud ] = '\0';
 }

 void Alumno::setnombre( const string &valornombre )
 {
	 int longitud = valornombre.size();
	 longitud = ( longitud < 35 ? longitud : 34 );
	 valornombre.copy( nombre, longitud );
	 nombre[ longitud ] = '\0';
 }

 void Alumno::setapellido( const string &valorapellido )
 {
	 int longitud = valorapellido.size();
	 longitud = ( longitud < 35 ? longitud : 34 );
	 valorapellido.copy( apellido, longitud );
	 apellido[ longitud ] = '\0';
 }

 void Alumno::setCurso( const string &valorCurso )
 {
	 int longitud = valorCurso.size();
	 longitud = ( longitud < 35 ? longitud : 34 );
	 valorCurso.copy( curso, longitud );
	 curso[ longitud ] = '\0';
 }

 void Alumno::setEdad( const string &valorEdad )
 {
	 int longitud = valorEdad.size();
	 longitud = ( longitud < 35 ? longitud : 34 );
	 valorEdad.copy( edad, longitud );
	 edad[ longitud ] = '\0';
 }

 ostream &operator<<( ostream &salida, const Alumno &Alumno )
 {
	 salida << "Codigo de estudiante: " << Alumno.codigo << endl
	 << "nombre: " << Alumno.nombre << endl
	 << "apellido: " << Alumno.apellido << endl
	 << "curso: " << Alumno.curso << endl
	 << "edad: " << Alumno.edad << endl;

	 return salida;
 }

 bool Alumno::registrar( const Alumno &nuevoJugador )
 {
	 Alumno promo;
	 string cadena;
	 int posIndice, contador;
	 long int posByte;
	 string idString = nuevoJugador.codigo;

	 if( contiene( idString ) )
	 	return false;

	 fstream archEntSalEstudiantes( "estudiantes.txt", ios::in | ios::out );
	 posIndice = dispersion( nuevoJugador.codigo );
	 cout << "\nSe guardara en la posicion indice: " << posIndice << endl;
	 posByte = posIndice * ( sizeof( Alumno ) * CONTENEDOR + sizeof( int ) );
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
	 if( contador < CONTENEDOR ) // si el contenedor no esta lleno
	 {
		 // aumenta el contador y lo escribe
		 contador++;
		 archEntSalEstudiantes.seekg( posByte, ios::beg );
		 archEntSalEstudiantes.write( ( char * ) &contador, sizeof( int ) );

		 // escribe el nuevo registro en el contenedor
		 for( int i = 0; i < CONTENEDOR; i++ )
		 {
			 archEntSalEstudiantes.read( ( char * ) &promo, sizeof( Alumno ) );
			 if( promo.codigo[ 0 ] == '\0' )
			 {
				 archEntSalEstudiantes.seekg( ( long )archEntSalEstudiantes.tellg() - sizeof( Alumno ), ios::beg );
				 archEntSalEstudiantes.write( ( char * ) &nuevoJugador, sizeof( Alumno ) );
				 archEntSalEstudiantes.close();
				 return true;
			 }
		 }
	 }
	 else
	 	cout << endl << "\nNo hay mas espacio para este registro" << endl;
	 archEntSalEstudiantes.close();
	 return false;
 }

 void Alumno::mostrar( void )
 {
	 Alumno promo;
	 int contador;
	 long int posByte;

	 ifstream archEntSalEstudiantes( "estudiantes.txt", ios::in );
	 if( !archEntSalEstudiantes )
	 	cout << "\nNo existe el archivo" << endl;
	 else
	 {
		 cout << endl;
		 for( int i = 0; i < NUMREGISTROS; i++ )
		 {
			 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
			 if( contador > 0 )
			 {
				 for( int j = 0; j < CONTENEDOR; j++ )
				 {
					 archEntSalEstudiantes.read( ( char * ) &promo, sizeof( Alumno ) );
					 if( promo.codigo[ 0 ] != '\0' )
					 	cout << promo << endl;
				 }
			 }
			 else
			 archEntSalEstudiantes.seekg( sizeof( Alumno ) * CONTENEDOR, ios::cur );
		 }
	 }
	 archEntSalEstudiantes.close();
 }

 bool Alumno::buscar( const string &idABuscar, Alumno &JugadorEncontrada )
 {
	 long int posByte;

	 if( !contiene( idABuscar ) )
		 return false;

	 ifstream archEntSalEstudiantes( "estudiantes.txt", ios::in );
	 if( !archEntSalEstudiantes )
	 {
		 cout << "\nEl archivo no existe" << endl;
		 archEntSalEstudiantes.close();
		 return false;
	 }

	 posByte = buscarCodigo( idABuscar );
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.read( ( char * ) &JugadorEncontrada, sizeof( Alumno ) );
	 archEntSalEstudiantes.close();
	 return true;
  }

 bool Alumno::modificar( const string &idAModificar, const Alumno &JugadorNueva )
 {
	 Alumno registroLimpio, promo;
	 int posIndiceAntiguo, posIndiceNuevo, contador;
	 long int posByteAntiguo, posByteNuevo;

	 if( !contiene( idAModificar ) )
	 	return false;

	 fstream archEntSalEstudiantes( "estudiantes.txt", ios::in | ios::out );
	 if( !archEntSalEstudiantes )
	 {
	 	cout << "\nEl archivo no exite" << endl;
	 	archEntSalEstudiantes.close();
	 	return false;
	 }

	 posIndiceAntiguo = dispersion( idAModificar.c_str() );
	 posByteAntiguo = buscarCodigo( idAModificar );
	 posIndiceNuevo = dispersion( JugadorNueva.codigo );
	 posByteNuevo = posIndiceNuevo * ( sizeof( Alumno ) * CONTENEDOR + sizeof( int ) );

	 if( posByteAntiguo == posByteNuevo )
	 {
		 archEntSalEstudiantes.seekg( posByteAntiguo, ios::beg );
	 	archEntSalEstudiantes.write( ( char * ) &JugadorNueva, sizeof( Alumno) );
	 }
	 else
	 {

		 archEntSalEstudiantes.seekg( posByteAntiguo, ios::beg );
		 archEntSalEstudiantes.write( ( char * ) &registroLimpio, sizeof( Alumno) );
		 posByteAntiguo = posIndiceAntiguo * ( sizeof( Alumno ) * CONTENEDOR + sizeof( int ) );
		 archEntSalEstudiantes.seekg( posByteAntiguo, ios::beg );
		 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
		 contador--;
		 archEntSalEstudiantes.seekg( posByteAntiguo, ios::beg );
		 archEntSalEstudiantes.write( ( char * ) &contador, sizeof( int ) );

		 // intenta meter el nuevo registro en la nueva posicion
		 archEntSalEstudiantes.seekg( posByteNuevo, ios::beg );
		 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
		 if( contador < CONTENEDOR )
		 {
			 // aumenta el contador y lo escribe
			 contador++;
			 archEntSalEstudiantes.seekg( posByteNuevo, ios::beg );
			 archEntSalEstudiantes.write( ( char * ) &contador, sizeof( int ) );

			 // escribe el nuevo registro en el contenedor
			 for( int i = 0; i < CONTENEDOR; i++ )
			 {
				 archEntSalEstudiantes.read( ( char * ) &promo, sizeof( Alumno ) );
				 if( promo.codigo[ 0 ] == '\0' )
				 {
					 archEntSalEstudiantes.seekg( ( long )archEntSalEstudiantes.tellg() - sizeof( Alumno ), ios::beg );
					 archEntSalEstudiantes.write( ( char * ) &JugadorNueva, sizeof( Alumno ) );
					 archEntSalEstudiantes.close();
					 return true;
				 }
			 }
		 }
		 else
		 return false;
	 }
 }

 bool Alumno::eliminar( const string &idAEliminar, Alumno &destinoEliminado )
 {
	 Alumno promo;
	 int posIndice, posByte, contador;

	 if( !contiene( idAEliminar ) )
		 return false;

	 fstream archEntSalEstudiantes( "estudiantes.txt", ios::in | ios::out );
	 if( !archEntSalEstudiantes )
	 {
		 cout << "\nEl archivo no exite" << endl;
		 archEntSalEstudiantes.close();
		 return false;
	 }

	 posIndice = dispersion( idAEliminar.c_str() );
	 posByte = buscarCodigo( idAEliminar );

	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.read( ( char * ) &destinoEliminado, sizeof( Alumno) );
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.write( ( char * ) &promo, sizeof( Alumno) );

	 posByte = posIndice * ( sizeof( Alumno ) * CONTENEDOR + sizeof( int ) );
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.read( ( char * ) &contador, sizeof( int ) );
	 contador--;
	 archEntSalEstudiantes.seekg( posByte, ios::beg );
	 archEntSalEstudiantes.write( ( char * ) &contador, sizeof( int ) );
	 archEntSalEstudiantes.close();
	 return true;
 }


 int main( void )
 {
	Alumno Alumno, JugadorBuscar, JugadorModificar, JugadorEliminar, registroregistrar;
	string idABuscar, idAModificar, idAEliminar;
	char opcion, op;

	Alumno.genera();
	system( "cls" );

	 do{
	 	 system( "cls" );
		 cout<<"\n\tMenu - Cursos de programacion\n";
		 cout<<"---------------------------------------------"<<endl;
		 cout<< "1. Registrar Alumno" << endl;
		 cout<< "2. Buscar Alumno" << endl;
		 cout<< "3. Modificar Alumno" << endl;
		 cout<< "4. Eliminar Alumno" << endl;
		 cout<< "5. Mostrar Alumnos" << endl;
		 cout<< "6. Salir" << endl;
		 cout<<"---------------------------------------------"<<endl;
		 cout<<"Seleccione su opcion." << endl;
		 cout<< endl;
		 cin >> opcion;
		 switch( opcion )
		 {
			 case '1':
				 registroregistrar = Alumno.pedirRegistro();
				 if( Alumno.registrar( registroregistrar ) )
				 	cout << "\nAlumno registrado con exito\n\n" << endl;
				 else
				 	cout << "\nNo se agrego el alumno" << endl;
				getch();
			 break;

			 case '2':
				 cout << "\nIngrese el cod. de estudiante a buscar: ";
				 fflush( stdin );
				 getline( cin, idABuscar );
				 if( Alumno.buscar( idABuscar, JugadorBuscar ) )
				 	cout << endl << JugadorBuscar << endl;
				 else
				 	cout << "\nNo existe el registro" << endl;
				getch();
			 break;

			 case '3':
				 cout << "\nIngrese el cod. de estudiante a modificar: ";
				 fflush( stdin );
				 getline( cin, idAModificar );
				 if( Alumno.buscar( idAModificar, JugadorBuscar ) )
				 {
					 cout << endl << JugadorBuscar << endl;
					 cout << "\nDesea modificarlo?" << endl;
					 cout << "1) Si" << endl;
					 cout << "2) No\n" << endl;
					 cin >> op;
					 if( op == '1' )
					 {
						 JugadorModificar = Alumno.pedirRegistro();
						 if( Alumno.modificar( idAModificar, JugadorModificar ) )
							 cout << endl << "\nAlumno modificado con exito" << endl;
						 else
							 cout << endl << "\nNo se pudo modificar" << endl;
					 }
				 }
				 else
				 	cout << "\nNo existe el registro" << endl;
				 getch();
			 break;

			 case '4':
				 cout << "\nIngrese el cod. de estudiante a eliminar: ";
				 fflush( stdin );
				 getline( cin, idAEliminar );
				 if( Alumno.buscar( idAEliminar, JugadorBuscar ) )
				 {
					 cout << endl << JugadorBuscar << endl;
					 cout << "\nDesea eliminarlo?" << endl;
					 cout << "1) Si" << endl;
					 cout << "2) No\n" << endl;
					 cin >> op;
					 if( op == '1' )
					 	if( Alumno.eliminar( idAEliminar, JugadorEliminar ) )
					 		cout << endl << JugadorEliminar << endl << "\nSE ELIMINO CORRECTAMENTE\n" << endl;
						else
					 		cout << "\nNO SE PUDO ELIMINAR\n" << endl;
				 }
				 else
					 cout << "\nNo existe el registro" << endl;
				 getch();
			 break;

			 case '5':
				Alumno.mostrar();
				getch();
			 break;

			 case '6':
			 	cout <<"\nSaliendo...";
			 break;
		 }

		 cout << endl;
	 }while(opcion != '6');
 }
