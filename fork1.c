#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t phijoa,phijob,pnieto;
  int estado;
  if((phijoa = fork()) == 0){// Hijo A
     if((pnieto =fork()) == 0){
     printf("N.A->HOLA MUNDO: PID:%d, PPID:%d \n",getpid(),getppid());
    }
    else{// Hijo - Padre
      //sleep(1);
      waitpid(pnieto,&estado,0);
      printf("H.A->HOLA MUNDO: PID:%d, PPID:%d \n",getpid(),getppid()); 
    }
  }
  else{// Padre
    waitpid(phijoa,NULL,0);
    if((phijob = fork()) == 0){// Hijo B
      printf("H.B->HOLA MUNDO: PID:%d, PPID:%d \n",getpid(),getppid());
    }
    else{ // Padre - MAIN
      waitpid(phijob,&estado,0);
      printf("P->HOLA MUNDO: PID:%d, PPID:%d \n",getpid(),getppid());
      //sleep(2);
    }
  }
return 0;
}
