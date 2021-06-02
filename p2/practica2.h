struct evaluacion
{
 char id[16]; /* DNI o similar */
 char apellido1[32];
 char apellido2[32];
 char nombre[32];
 float nota1p; /* Nota 1er parcial */
 float nota2p; /* Nota 2do parcial */
 float notamedia; /* Nota media */
 char photofilename[20]; /* Nombre del JPEG */
 int photosize; /* Tamaño del JPEG */
 char photodata[16000]; /* Datos del JPEG */
};


int ordenanotas( int fd);
