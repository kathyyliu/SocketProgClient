#ifndef DNS_H
#define DNS_H

char* getHostByName(char*);
void changeToDnsNameFormat(unsigned char*, char*);
unsigned char* readName(unsigned char*, unsigned char*, int*);
void getDnsServers();

#endif
