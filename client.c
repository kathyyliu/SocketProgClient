// Client side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "dns.h"
#define PORT 80

int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char* hostname;

    // Get requested domain name from user
    printf("Please enter a domain name: ");
    scanf("%s", hostname);

    // Create custom HTTP request
    // Having trouble adding 'hostname' into the middle of
    char* request = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    strcat(request, "%s\r\nUser-Agent: curl/7.64.1\r\nAccept: */*\r\nConnection: close\r\n\r\n");

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    // 172.217.14.110
    // 23.185.0.3
    char* addr;
    addr = getHostByName(hostname);
    if(inet_pton(AF_INET, addr, &serv_addr.sin_addr)<=0)
    {
        printf("Invalid address/ Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed");
        return -1;
    }
    send(sock, request, strlen(request), 0);
    printf("Hello message sent");
    valread = read(sock, buffer, 1024);
    printf("%s", buffer);
    return 0;
}