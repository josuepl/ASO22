#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
int fd; // Descriptor de archivo - referencia y acceso a un archivo 

char *buffer; // Nuestro almacenamiento de cadenas

fd = open("Datos.txt", O_WRONLY | O_CREAT, S_IRUSR |S_IWUSR);
printf("Ingresa una cadena: \n");


return 0;
}
