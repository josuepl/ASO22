#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int pidA, pidB, pidA1, pidB1, pidB2;

if((pidA = fork()) == 0 ){// Proceso Hijo A 
  if((pidA1 = fork()) == 0){ // Proceso Hijo A1 - Nieto A1
   printf("PA1-> HOLA MUNDO, PID:%d PPID:%d, PIDA1: %d \n",getpid(),getppid(),pidA1);
  }
  else{// Proceso Hijo A - Padre A
   sleep(1); 
   printf("PA-> HOLA MUNDO, PID:%d PPID:%d, PIDA1: %d \n",getpid(),getppid(),pidA1);
 
  } 
}
else // Proceso Padre - main()
{
  sleep(1);
  printf("PP-> HOLA MUNDO, PID:%d PPID:%d, PIDA: %d \n",getpid(),getppid(),pidA);
  if((pidB = fork()) > 0)// Proceso Padre
  {
   sleep(1);
   printf("PP-> HOLA MUNDO, PID:%d PPID:%d, PIDB: %d \n",getpid(),getppid(),pidB); 
  }
  else{ // Proceso Hijo B
    printf("PB-> HOLA MUNDO, PID:%d PPID:%d, PIDB: %d \n",getpid(),getppid(),pidB);
  
  }
}
return 0; // Se regresa el valor de 0 al finalizar una ejecucion
	  // de manera exitosa
}
