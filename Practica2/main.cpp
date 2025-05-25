   /*Equipo 4:
   Munguía Guízar Marlon Uriel
   Padilla Perez Jorge Daray
   Pérez Palacios Perla Michelle
   Pulido Tobías Rafael Agustín
   Sección: D19
   Calendario: 2022B
   */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>

using namespace std;

struct stRegistro {
	//Etiqueta-NumeroId, Titulo, compositor(es), Artista
   char valido;  // Campo que indica si el registro es valido S->Válido, N->Inválido
   char EtiquetaYNumeroId[35];
   char titulo[34];
   char compositor[34];
   char artista[34];
};

struct stIndice {
   char EtiquetaYNumeroId[10];
   long indice;
};

int Menu();
void Capturar(stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void Leer(FILE *fa, stRegistro &reg, char *EtiquetaYNumeroId);
void Insertar(FILE *fa, stRegistro &reg);
void Mostrar(stRegistro &reg);
void ReconstruirIndices(FILE *fa);
// Funciones para ordenar el fichero de índices:
void Intercambia(FILE *fa, long iz, long de);
char *LeeCampo(FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);

int main()
{
   stRegistro reg;
   FILE *fa;
   int opcion;
   char EtiquetaYNumeroId[10];

   fa = fopen("discos.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("discos.dat", "w+b");  // si el fichero no existe, lo crea.

   do {
      opcion = Menu();
      switch(opcion) {
         case '1': // Insertar registro
            Capturar(reg);
            Insertar(fa, reg);
            break;
         case '2': // Buscar registro
            //system("cls");
            printf("\nBuscar registro: ");
            do {
               fgets(EtiquetaYNumeroId, 10, stdin);
               EliminarRetornoLinea(EtiquetaYNumeroId);
            } while(strlen(EtiquetaYNumeroId) < 1);
            Leer(fa, reg, EtiquetaYNumeroId);
            Mostrar(reg);
            getch();
            break;

      }
   } while(opcion != '0');
   fclose(fa);
   return 0;
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];

   do {
      //system("cls");
      printf("\nMENU PRINCIPAL\n");
      printf("-------------\n");
      printf("1- Altas\n");
      printf("2- Consultas individuales\n");
      printf("0- Salir\n");
      printf("-------------\n");
      printf("Elige tu opcion...");
      fgets(resp, 20, stdin);
   } while(resp[0] < '0' && resp[0] > '5');
   return resp[0];
}

// Permite que el usuario introduzca un registro por pantalla
void Capturar(stRegistro &reg)
{
   //system("cls");
   printf("\n\nLeer registro:\n\n");
   reg.valido = 'S';
   printf("Etiqueta-NumeroId: ");
   fgets(reg.EtiquetaYNumeroId, 10, stdin);
   EliminarRetornoLinea(reg.EtiquetaYNumeroId);
   printf("titulo: ");
   fgets(reg.titulo, 34, stdin);
   EliminarRetornoLinea(reg.titulo);
   printf("Compositor(es): ");
   fgets(reg.compositor, 34, stdin);
   EliminarRetornoLinea(reg.compositor);
   printf("Artista: ");
   fgets(reg.artista, 34, stdin);
   EliminarRetornoLinea(reg.artista);
}

// Elimina los caracteres de retorno de línea al final de cadena
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(stRegistro &reg)
{
   int i;

   if(reg.valido == 'S') {
   		printf("\n\nEtiqueta-NumeroId: %s\n", reg.EtiquetaYNumeroId);
      	printf("titulo: %s %s %s\n", reg.titulo, "\nCompositor: ", reg.compositor);
		printf("Artista: %s", reg.artista);
   }

}

// Lee el registro desde el fichero de datos con el teléfono dado
void Leer(FILE *fa, stRegistro &reg, char *EtiquetaYNumeroId)
{
   FILE *fi;
   stIndice ind;
   long inf, sup, n, nRegs;

   fi = fopen("indices.ind", "rb");
   fseek(fi, 0, SEEK_END);
   nRegs = ftell(fi)/sizeof(stIndice);
   // Búsqueda binaria:
   inf = 0;
   sup = nRegs-1;
   do {
      n = inf+(sup-inf)/2;
      fseek(fi, n*sizeof(stIndice), SEEK_SET);
      fread(&ind, sizeof(stIndice), 1, fi);
      if(strcmp(ind.EtiquetaYNumeroId, EtiquetaYNumeroId) < 0) inf = n+1;
      else sup = n-1;
   } while(inf <= sup && strcmp(ind.EtiquetaYNumeroId, EtiquetaYNumeroId));
   // Si se encontró el teléfono, lee el registro, si no muestra mensaje.
   if(!strcmp(ind.EtiquetaYNumeroId, EtiquetaYNumeroId)) {
      fseek(fa, ind.indice*sizeof(stRegistro), SEEK_SET);
      fread(&reg, sizeof(stRegistro), 1, fa);
   }
   else {
      reg.valido = 'N';
      printf("Registro no encontrado\n");
   }
   fclose(fi);
}

// Añade un registro al archivo de datos y reconstruye los índices
void Insertar(FILE *fa, stRegistro &reg)
{
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(stRegistro), 1, fa);
   ReconstruirIndices(fa);
}

// Reconstruye el archivo de índices
void ReconstruirIndices(FILE *fa)
{
   long n=0;
   FILE *fi;
   stRegistro reg;
   stIndice ind;

   // Crea el fichero de índices a partir del archivo de datos:
   fi = fopen("indices.ind", "w+b");
   rewind(fa); /*La función rewind( ) pone el puntero de L/E del fichero al comienzo del mismo, equivale a:
fseek(archivológico,0L,SEEK_SET); con la excepción de que rewind( ) desactiva los indicadores de error y de fin de fichero,
y fseek( ) no.*/

   while(fread(&reg, sizeof(stRegistro), 1, fa)) {
      strcpy(ind.EtiquetaYNumeroId, reg.EtiquetaYNumeroId);
      ind.indice = n++;
      fwrite(&ind, sizeof(stIndice), 1, fi);
   }
   // Ordena usando el algoritmo Quicksort:
   QuickSort(fi, 0, n-1);
   fclose(fi);
}

// Implementación del algoritmo Quicksort para fichero de índices
void QuickSort(FILE *fi, long inicio, long final)
{
   long iz, de;
   char mitad[10];
   static char cad[10];

   iz = inicio;
   de = final;
   strcpy(mitad, LeeCampo(fi, (iz+de)/2, cad));
   do {
      while(strcmp(LeeCampo(fi, iz, cad), mitad) < 0 && iz < final) iz++;
      while(strcmp(mitad, LeeCampo(fi, de, cad)) < 0 && de > inicio) de--;
      if(iz < de) Intercambia(fi, iz, de);
      if(iz <= de) {
         iz++;
         de--;
      }
   } while(iz <= de);
   if(inicio < de) QuickSort(fi, inicio, de);
   if(iz < final) QuickSort(fi, iz, final);
}

char *LeeCampo(FILE *fi, long n, char *buf)
{
   stIndice ind;

   fseek(fi, n*sizeof(stIndice), SEEK_SET);
   fread(&ind, sizeof(stIndice), 1, fi);
   strcpy(buf, ind.EtiquetaYNumeroId);
   return buf;
}

void Intercambia(FILE *fi, long iz, long de)
{
   stIndice reg1, reg2;

   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fread(&reg1, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fread(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, iz*sizeof(stIndice), SEEK_SET);
   fwrite(&reg2, sizeof(stIndice), 1, fi);
   fseek(fi, de*sizeof(stIndice), SEEK_SET);
   fwrite(&reg1, sizeof(stIndice), 1, fi);
}
