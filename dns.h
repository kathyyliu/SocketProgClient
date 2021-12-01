#ifndef DNS_H
#define DNS_H

char* ngethostbyname (unsigned char*, int);
void ChangetoDnsNameFormat (unsigned char*, unsigned char*);
unsigned char* ReadName (unsigned char*, unsigned char*, int*);
void get_dns_servers();

#endif
