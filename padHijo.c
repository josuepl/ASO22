#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pa, pb, pc;
int estado;

if((pa = fork()) == 0){//Proceso HIJOA
 printf("PA: Soy el proceso Hijo PID: %d, PPID:%d \n",getpid(),getppid());
}
else// Proceso Padre
{
 
 printf("PADRE: Cree proceso HIJO:%d \n",pa);
 //waitpid(PID, estado, 0);
 waitpid(pa, &estado, 0);
 //sleep(1);
 printf("PADRE: Ha finalizado HIJO:%d con estado: %d \n",pa, estado);
 if((pb = fork()) == 0){ //Proceso Hijo B
 printf("PB: Soy el proceso Hijo PID: %d, PPID:%d \n",getpid(),getppid());
 }
 else{//Proceso Padre
 waitpid(pb, &estado, 0);
 printf("PADRE: Ha finalizado HIJO:%d con estado: %d \n",pa, estado);
 
 }

}

return 0;
}

