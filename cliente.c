#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
 int sock, tam, n;
 socklen_t origenTam;
 struct hostent *huesped;
 struct sockaddr_in origen, servidor;
 char buffer[1024];
 
 if(argc < 3){
  printf("Error en la cantidad de parametros, se requiere establecer un puerto \n");
  printf("Sintaxis: ./prog servidor puerto\n");
  exit(0);
  return 0;
 }
 
 sock = socket(AF_INET, SOCK_DGRAM, 0);
 tam = sizeof(struct sockaddr_in);
 bzero(&servidor,tam);
 huesped = gethostbyname(argv[1]);
 if( huesped <= 0){
  printf("El servidor no existe\n");
  return 0;
 }
 bzero(buffer,1024);
 bcopy((char *)huesped->h_addr,(char *)&servidor.sin_addr,huesped->h_length);
 servidor.sin_family = AF_INET;
 servidor.sin_port = htons(atoi(argv[2]));
 printf("Ingresa una cadena: \n");
 fgets(buffer,1024,stdin);
 printf("Cadena: %s\n",buffer);

 n = sendto(sock, buffer,strlen(buffer),0, (struct sockaddr *)&servidor, tam);
  if(n < 0){
   printf("error al enviar el mensaje \n");
   exit(0);  
  } 

 origenTam = sizeof(struct sockaddr_in);
  n = recvfrom(sock,buffer,1024,0,(struct sockaddr *)&origen,&tam);
  if(n < 0){
   printf("error recibir datos \n");
   exit(0);
  }
  write(1, "Se ha enviado un mensaje\n",27);
  write(1,buffer,n);
  close(sock);
 
 return 0;
}

