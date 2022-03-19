#include <stdio.h>
#include <pthread.h>

#define N 2
#define M 4

const char *mensaje[2] = {"HOLA - ASO","BIENVENIDOS A HILOS"};
			//[0] = HOLA -ASO
			//[1] = BIENVENIDOS A HILOS
const int cantidad[2] = {N,M};
			//[0] = 2
			//[1] = 4

void imprime_texto(void *ptr){
 int idMensaje;
 int contador;
 idMensaje = *(int *)ptr;
 for(contador = 0; contador < cantidad[idMensaje]; contador++)
	printf("%s \n",mensaje[idMensaje]);
	return;
}
int main(){
 
 pthread_t msg0, msg1;
 int pos[2]= {0,1};
 // crear hilos
 printf(" ------ CODIGO DE HILOS ------ \n ");
 pthread_create(&msg0, NULL, (void *)&imprime_texto,(void *)&pos[0]);
 pthread_create(&msg1, NULL, (void *)&imprime_texto,(void *)&pos[1]);

 // se espera la finalizacion de los hilos creados

 pthread_join(msg0, NULL);
 pthread_join(msg1, NULL);
 return 0;
}
