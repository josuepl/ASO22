#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/type.h>
#include <string.h>

int main(int argc, char *argv[]){
 int sock, tam, n;
 socklen_t origenTam;
 struct sockaddr_in origen;
 struct sockaddr_in servidor;
 char buffer[1024];
 
 if(argc < 2){
  printf("Error en la cantidad de parametros, se requiere establecer un puerto \n");
  exit(0);
  return 0;
 }
 
sock = socket()
 return 0;
}
