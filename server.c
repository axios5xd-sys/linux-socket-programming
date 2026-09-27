#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0){
      perror("socket");
      return 1;
    }

    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port =htons(8000);
    addr.sin_addr.s_addr = INADDR_ANY;

   if(bind(sockfd,(struct sockaddr*)&addr,sizeof(addr)) < 0){
      perror("bind");
      return 1;
    }

   if( listen(sockfd,5) < 0){
     perror("listen");
     return 1;
    }

    int client_fd = accept(sockfd,NULL,NULL);
    if(client_fd < 0){
      perror("accept");
      return 1;
    }

    char buf[1024];
    read(client_fd,buf,sizeof(buf));
    printf("%s\n",buf);

   const char *msg =
      "HTTP/1.1 200 OK\r\n"
      "Content-Length: 5\r\n"
      "\r\n"
      "Hello";

    write(client_fd,msg,strlen(msg));

    close(client_fd);
    close(sockfd);
    return 0;
}
