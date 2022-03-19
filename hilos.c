#include <stdio.h>
#include <pthread.h>

#define N 8
#define M 16

const char *mensaje[2] = {"HOLA - ASO","BIENVENIDOS A HILOS"};
			//[0] = HOLA -ASO
			//[1] = BIENVENIDOS A HILOS
const int cantidad[2] = {N,M};
			//[0] = 8
			//[1] = 16

void imprime_texto(void *ptr){
 int idMensaje;
 int contador;
 idMensaje = *(int *)ptr;
 for(contador =0; contador < cantidad[idMensaje])
	printf("%s \n",mensaje[idMensaje])
	return 0;
}
int main(){
 
 pthread_t msg0, msg1;
 int pos[2]= {0,1};
 // crear hilos
 pthread_create(&msg0, NULL, (void *)imprime_texto,(void *)pos[0]);
 pthread_create(&msg1, NULL, (void *)imprime_texto,(void *)pos[1]);

 // se espera la finalizacion de los hilos creados

 pthread_join(msg0, NULL);
 pthread_join(msg1, NULL);
 return 0;
}
