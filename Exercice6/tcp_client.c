// tcp_client.c

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define PORT 10000

int main(void) {

  int sock;
  struct sockaddr_in sin;

  /* Creation de la socket */
  sock = socket(AF_INET, SOCK_STREAM, 0);
 
  /* Configuration de la connexion */
  sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
 
  /* Tentative de connexion au serveur */
  char buffer3[32]="";
  connect(sock, (struct sockaddr*)&sin, sizeof(sin));
  printf("Connexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
         htons(sin.sin_port));
  	char buffer[32]="";
	recv(sock, buffer, 32, 0);
	printf("%s\n", buffer);
	char buffer2[32]="Merci";
	send(sock, buffer2, 32, 0);
	while(1){
		printf("Saisir une chaine: ");
		char buffer3[32]="";
		fgets(buffer3, 32, stdin);
		send(sock, buffer3, 32, 0);
		//if(buffer3[0]=='a')break;
	}
  /* Fermeture de la socket client */
  close(sock);
  return EXIT_SUCCESS;

}//main
