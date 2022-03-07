#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(){
pid_t pa;
char *buffer;
int fd[2]; //[0]-> read [1]->write

pipe(fd);
if((pa = fork()) == 0){// hijo
 printf("HIJO->Ingresa una cadena que quieras enviar al Proceso-padre: \n");
 fflush(stdin);
 scanf("%*c%[^\n]",buffer);
 printf("HIJO->la cadena leida es %s \n",buffer);
 int tam = strlen(buffer);
 char tamC[2];
 tamC[0] = tam + '0';
 write(fd[1],tamC,1);
 printf("HIJO-> TamC: %s \n",tamC);
 write(fd[1],buffer,tam);
}
else{// padre
 char tamC[2];
 printf("La cadena buffer es: %s\n",buffer); 
 waitpid(pa,NULL,0);
 read(fd[0],tamC,1);
 int tam = tamC[0] - '0';
 printf("primer elemento: %s, tam: %d\n",tamC,tam);
 read(fd[0],buffer,tam);
 printf("La cadena obtenida es: %s \n",buffer);
}
return 0;
}
