/*
 * ./commandExtractor payloadFile type
 *
 * type: 1 getL
 *       2 retL
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define DEC_KEY 0x66747032 // Encryption/Decryption key 'ftp2'

unsigned char payload[500];


void XORdecrypt(unsigned char *buff, int bytes){
    
    int i;
    unsigned int * num;
    unsigned int key = DEC_KEY;

    for(i=0; i<bytes; i++){
        num = (unsigned int *) &buff[i];
        *num ^= key;
        key = key<<1 | key>>31;    // no idea why this. Probably to remove!
    }

}

int read_getL(unsigned char * payload,int size){

    int i;

    for(i=0;i<size;i++){
        printf("<0x%x> ", payload[i]);
        if((i%10)==0 && i!=0) printf("\n");
    }


}

int main(int argc, char* argv[]){

    char * fileName = argv[1];
    int type = atoi(argv[2]);
    int i = 0;
    int fd;
    int size;

    fd = open(fileName, O_RDONLY);

    while(read(fd,payload+i,1)!=0){
        i++;
    }
    size=i;

    XORdecrypt(payload,size);

    read_getL(payload,size);

    return 1;


}


