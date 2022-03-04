#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
int fd; // Descriptor de archivo - referencia y acceso a un archivo 

char buffer[10]; // Nuestro almacenamiento de cadenas

fd = open("Datos.txt", O_RDONLY);
//printf("Ingresa una cadena: \n");
//Problemas -- buffer de entrada de datos
//scanf("%s",buffer);
//fgets(buffer,10,stdin);
read(fd,buffer,sizeof(buffer));
printf("CADENA: %s\n",buffer);
//write(fd,&buffer,sizeof(buffer));
close(fd);
return 0;
}
