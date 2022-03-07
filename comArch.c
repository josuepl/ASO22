#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
pid_t pa,pb;
int fd;
char opcion, buffer[10];
printf("Selecciona la opcion deseada: \n");
printf("a) Escribir datos en archivo: \n");
printf("b) Leer datos en archivo: \n");
printf("-)  \n");

scanf("%s",&opcion);
printf("La opcion elegida es: %c \n",opcion);

switch(opcion){
 case 'a':
	if((pa = fork())== 0){//Proceso Hijo
	fd = open("datos.txt",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	printf("Ingresa la cadena a almacenar: \n");
	//fflush(stdin);
	scanf("%*c%[^\n]",&buffer);
	//fgets(buffer,10,stdin);
	write(fd,&buffer,sizeof(buffer));
	close(fd);
	}
	else{//Padre
	sleep(3);
	waitpid(pa,NULL,0);
	printf("Se ha almacenado la cadena \n");
	}
	break;
 case 'b':
	if((pb =fork())== 0){//Hijo
	fd = open("datos.txt",O_RDONLY);
	read(fd,&buffer,sizeof(buffer));
	printf("El archivo contiene %s \n",buffer);
	}
	else{//Padre
	sleep(3);
	waitpid(pb,NULL,0);
	printf("Se ha leido la cadena \n");


	}
	break;

}

waitpid(pa,NULL,0);
waitpid(pb,NULL,0);
return 0;
}

