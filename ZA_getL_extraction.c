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
#include <stdint.h>

#define DEC_KEY 0x66747032 // Encryption/Decryption key 'ftp2'

unsigned char payload[500];

typedef struct {
	uint32_t crc;
	uint32_t cmd; //getL
	uint32_t flag; // value 0
	uint32_t data; // peer identifier
}getLStr;


void XORdecrypt(unsigned char *buff, int bytes){
    
    int i;
    uint32_t * num =(uint32_t *) buff;;
    uint32_t key = DEC_KEY;
    uint32_t cont = bytes /4; 

    while(cont){
        *num ^= key;
        key = key<<1 | key>>31;    // roll the key
        num++;
        --cont;
    }

}

int read_getL(unsigned char * payload,int size){

    int i;
    getLStr * pack = (getLStr *)payload;
    printf("CRC 0x%x (%c) \n",pack->crc,(char )pack->crc);
    printf("cmd 0x%x (%c%c%c%c) \n",pack->cmd,((char *)&pack->cmd)[3],((char *)&pack->cmd)[2],((char *)&pack->cmd)[1],((char *)&pack->cmd)[0]);
    printf("flag 0x%x (%c) \n",pack->flag,(char )pack->flag);
    printf("data 0x%x (%c) \n",pack->data,(char )pack->data);
    //for(i=0;i<size;i++){
    //    printf("<0x%x> (%s), ", payload.crc,payload[i]);
    //    if((i%3)==0 && i!=0) printf("\n");
    //}


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


