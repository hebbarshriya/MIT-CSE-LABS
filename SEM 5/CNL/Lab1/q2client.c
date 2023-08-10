#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int len,result,sockfd,n=1;
    
    while (1) {
        struct sockaddr_in address;
    char ch[256]="Start",buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("127.0.0.1"); 
    address.sin_port=htons(10200);
    len = sizeof(address);

    result=connect(sockfd,(struct sockaddr *)&address,len);
    if(result==-1){
        perror("\nCLIENT ERROR");
        exit(1);
    }
        printf("\nENTER MESSAGE\t");
        gets(ch);
        ch[strlen(ch)]='\0';
     
        if(strcmp(ch,"Stop")==0){
            printf("Terminating");
            break;
        }
        write(sockfd,ch,strlen(ch));
    

        printf("STRING SENT BACK FROM SERVER IS ..... ");
        while(n){
            n=read(sockfd,buf,sizeof(buf));
            puts(buf);
        }
    }
    close(sockfd);
}
