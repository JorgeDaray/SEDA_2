#include "../extras/Arches.h"
#include "../extras/Funscads.h"
#include "../extras/Tomarc.h"
#define LONG_REG 64
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);
#define campo_a_sin_deli(br,cad) strcat(br,cad);
#define EXITO 1
#define FRACASO 0

static char *solicitud[]={
    "\t Número de Identificacion: ",
    "\t Titulo: ",
    "\t Compositor(res); ",
    "\t Artista(s): ",
    "\t Marca: ",
    ""
};

static int fd, indice;
char buffreg[TAM_MAX_REG + 1];
long lseek();
static struct
{
    short cont_reg;
    char relleno[30];
}encabezado;

int main()
{
    int i, menu_elec, nrr, byte_pos;
    char nomarch[15];
    char nombre_archivo[15] = "Indice";
    printf("Proporcione el nombre del archivo: ");
    gets(nomarch);
    //Inicializacion del archivo
    if((fd=open(nomarch,LECTESCRIT))<0)
    {
        fd=creat(nomarch,PMODE);//si no existe, lo crea
        encabezado.cont_reg = 0; //inicializa el encabezado
        write(fd, &encabezado,sizeof(encabezado));//escribe el registro del encabezado
    }
    else // se abre el archivo existente y lee el encabezado
    {
        read(fd,&encabezado,sizeof(encabezado));
    }
    //Iniciailizacion del Indice
    strcat(nomarch,nombre_archivo);
    if((indice = open(nomarch,LECTESCRIT))<0)
    {
        indice=creat(nomarch,PMODE);//si no existe, lo crea
        encabezado.cont_reg = 0; //inicializa el encabezado
        write(indice, &encabezado,sizeof(encabezado));//escribe el registro del encabezado
    }
    else // se abre el archivo existente y lee el encabezado
    {
        read(indice,&encabezado,sizeof(encabezado));
    }

    //ciclo del programa principal llama al menu y salta las opciones
    while((menu_elec = menu()) < 3)
    {
        switch(menu_elec)
        {
        case 1: //agrega un registro nuevo
            {
                printf("Proporcione la informacion del registro nuevo: \n\n");
                pide_info(buffreg);
                byte_pos = encabezado.cont_reg * LONG_REG + sizeof(encabezado);
                lseek(fd,(long) byte_pos, 0);
                write(fd,buffreg,LONG_REG);
                encabezado.cont_reg++;
                //clasifram();
                break;
            }
        case 2://actualiza un registro existente
            {
                nrr = pide_nrr();
                //si el NRR es muy grande, imprime mensaje de error
                if (nrr >= encabezado.cont_reg)
                {
                    printf("El numero de registro es demasiado grande");
                    printf("...se vuelve al menu...");
                    break;
                }

                //En caso contrario, se coloca el registro...
                byte_pos = nrr * LONG_REG + sizeof(encabezado);
                lseek(fd, (long) byte_pos, 0);

                //lo despliega y pide cambios
                lee_y_muestra();
                if (cambio())
                {
                    printf("\n\n proporcione los valores revisados: \n\n");
                    pide_info(buffreg);
                    lseek(fd, (long) byte_pos, 0);
                    write(fd,buffreg,LONG_REG);
                }
                break;
            }
        }
    }
    //reescribe la suma de registros correcta en el encabezado
    //antes de terminar
    lseek(fd,0L,0);
    write(fd,&encabezado,sizeof(encabezado));
    write(indice,&encabezado,sizeof(encabezado));
    close(fd);
    close(indice);
    return 0;
}

int menu()
{
    int eleccion;
    char respuesta[10];
    printf("\n\n\n\n\t Programa de actualizacion del archivo\n");
    printf("\n Encabezado: \n");
    printf("NRR (Registros disponibles): %i\n",encabezado.cont_reg);
    printf("\n\n Puede elegir: \n\n");
    printf("\n 1) Agregar un registro al final del archivo\n");
    printf("\n 2) Extraer un registro para actualizarlo\n");
    printf("\n 3) Salir del programa\n\n");
    printf("Proporcione el numero de su eleccion: ");
    gets(respuesta);
    eleccion = atoi(respuesta);
    return(eleccion);
};

void pide_info(char buffreg[])
{
    char c;
    int cont_campos, i, nc = 0;
    char respuesta[50];
    char tiempo[50];
    //limpia el buffer del registro
    for (i = 0; i < LONG_REG; buffreg[i++] = '\0')
        ;
    //fflush(stdin);
    for (i = 0; *solicitud[i] != '\0';i++)
    {
        printf("%s",solicitud[i]);
        gets(respuesta);
        campo_a_buffreg(buffreg,respuesta);
    }
        cont_campos = LONG_REG - strlen(buffreg);
        printf("Te quedan %i caracteres para la info \n",cont_campos);
}

int pide_nrr()
{
    int nrr;
    char respuesta[10];

    printf("\n\n Digite el numero relativo del registro\n");
    printf("\t que desee actualizar: ");
    gets(respuesta);
    nrr = atoi(respuesta);
    return(nrr);
}

void lee_y_muestra()
{
    char buffreg[TAM_MAX_REG + 1], campo[TAM_MAX_REG + 1], otro_campo[TAM_MAX_REG + 1];
    int pos_bus = 0, long_datos, i = 0;
    read(fd, buffreg, LONG_REG);
    printf("\n\n\n\n Contenido del registro existente\n");
    buffreg[LONG_REG] = '\0';//se asegura que el registro termine en nulo
    long_datos = strlen(buffreg);

    while((pos_bus = toma_campo(campo, buffreg, pos_bus, long_datos)) > 0)
    {
        printf("\t%s\n",campo);
    }
}

int cambio()
{
    char respuesta[10];
    printf("\n\n Desea modificar este registro?\n");
    printf("Conteste S o N, seguido por <ENTER> ==>");
    gets(respuesta);
    mayusculas(respuesta,respuesta);
    return((respuesta[0] == 'S') ? 1:0);
}

void clasifram()
{
    int encontro = FRACASO, long_reg = 0, byte_pos;
    char llave_enc[30];
    char registros[TAM_MAX_REG + 1], nodos_llave[TAM_MAX_REG + 1], Indice[TAM_MAX_REG + 1];
    //char llave_primaria[TAM_MAX_REG + 1];
    int i = 0, x;
    byte_pos = encabezado.cont_reg - 1 * LONG_REG + sizeof(encabezado);
    lseek(fd, (long) byte_pos, 0);
    //Leer los registros, llenar los arreglos
    while (i != encabezado.cont_reg)
    {
        read(indice, buffreg, LONG_REG);
        printf("\n\n\n\n Contenido del registro existente\n");
        buffreg[LONG_REG] = '\0';//se asegura que el registro termine en nulo
        long_reg = strlen(buffreg);
        for (x = 0; x < 4; x++)
        {
            registros[x] = buffreg[x];
        }
        registros[x++] = '\0';
        strcpy(nodos_llave,registros);
        Indice[i] = i;
        i++;
    }
    //Ordenar indice por valores clave

    //Escribir los registros
    i = 0;
    while (i != encabezado.cont_reg)
    {
        write(indice,registros,LONG_REG);
        i++;
    }
}

/*
encontro = FRACASO;
        while (!encontro && (long_reg = toma_reg(fd,buffreg)) > 0)
        {
            pos_bus = 0;
            pos_bus = toma_campo(pelicula,buffreg,pos_bus,long_reg);
            pos_bus = toma_campo(protagonista,buffreg,pos_bus,long_reg);
            hazllave(pelicula,protagonista, llave_enc);
            if(strcmp(llave_enc,nodos_llave) == 0)
                encontro = EXITO;
        }

        if (encontro)
        {
            printf("se encontro el registro\n");
            pos_bus = 0;

            while ((pos_bus = toma_campo(campo,buffreg,pos_bus,long_reg)) > 0)
                printf("\t%s\n",campo);
        }
        else
        {
            printf("no se encontro");
        }
*/
