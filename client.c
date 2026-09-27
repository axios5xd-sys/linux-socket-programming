#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0){
       perror("socket");return 1;
    }

    struct sockaddr_in server;
    memset(&server , 0 , sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    //127.0.0.1 = LOcalhost
    if(inet_pton (AF_INET,"127.0.0.1",&server.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
    }

    //SETUZOKU
    if(connect(sockfd,(struct sockaddr*)&server,sizeof(server)) < 0) {
     perror("connect");
     return 1;
    }

    printf("Connected to server\n");

   //HTTPrequest
    const char *request =
         "GET /HTTP/1.1 \r\n"
         "Host: localhost \r\n"
         "\r\n";

    send(sockfd, request,strlen(request),0);

    //Response
    char buffer[4096];
    int n;

    while((n = recv(sockfd,buffer,sizeof(buffer) -1,0)) > 0) {
       buffer[n] ='\0';
       printf("%s",buffer);
    }

    close(sockfd);
    return 0;
}



































