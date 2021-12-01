#ifndef DNS_H
#define DNS_H

char* getHostByName(char* host);
void changeToDnsNameFormat(unsigned char* dns, char* host);
unsigned char* readName(unsigned char* reader,unsigned char* buffer,int* count);
void getDnsServers();

#endif
