#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
// v1
int main(){
pid_t pa;
char *buffer;
char buff[100];
int fd[2]; //[0]-> read, [1]->write

pipe(fd);
if((pa = fork()) == 0){// hijo
 printf("HIJO->Ingresa una cadena que quieras enviar al Proceso-padre: \n");
 fflush(stdin);
 //scanf("%*c%[^\n]",buffer);
 fgets(buff,100,stdin);
 printf("HIJO->la cadena leida es %s \n",buffer);
 int tam = strlen(buff);
 char tamC[2];
 tamC[0] = tam + '0';
 write(fd[1],tamC,1);
 printf("HIJO-> TamC: %s \n",tamC);
 write(fd[1],buff,tam-1);
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
