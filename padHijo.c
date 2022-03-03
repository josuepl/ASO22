#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
pid_t pa, pb, pa1;
int estado;

if((pa = fork()) == 0){//Proceso HIJO A
 printf("PA: Soy el proceso Hijo PID: %d, PPID:%d \n",getpid(),getppid());
 if((pa1 = fork()) == 0 ){//Proceso Nieto A1
 printf("PA1: Soy el proceso Nieto PID: %d, PPID:%d \n",getpid(),getppid()); 
 }
 else{//Proceso Hijo A - Padre A
  printf("PADRE A: Cree proceso NIETO:%d, PID:%d PPID:%d \n",pa1,getpid(),getppid());
     //waitpid(PID, estado, 0);
  waitpid(pa1, &estado, 0);
  printf("PADRE A: Ha finalizado NIETO:%d con estado: %d \n",pa, estado);

 }
}
else// Proceso Padre
{
 
 printf("PADRE: Cree proceso HIJO:%d, PID:%d PPID:%d \n",pa,getpid(),getppid());
 //waitpid(PID, estado, 0);
 waitpid(pa, &estado, 0);
 //sleep(1);
 printf("PADRE: Ha finalizado HIJO:%d con estado: %d \n",pa, estado);
 if((pb = fork()) == 0){ //Proceso Hijo B
  printf("PB: Soy el proceso Hijo PID: %d, PPID:%d \n",getpid(),getppid());
 }
 else{//Proceso Padre
 printf("PADRE: Cree proceso HIJO:%d, PID:%d PPID:%d \n",pb,getpid(),getppid());
 waitpid(pb, &estado, 0);
 printf("PADRE: Ha finalizado HIJO:%d con estado: %d \n",pb, estado); 
 
 }

}

return 0;
}

