#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WUSER "wrong username\n"
#define WPASS "wrong password\n"

char * account = "\x7e\x7a\x67\x7d\x7a\x70\x78";
char * password = "\x67\x7b\x76\x70\x7c\x7d\x77\x7c\x61";
char * secret = "\x7a\x7b\x72\x67\x76\x60\x7b\x7a\x7e\x7c\x7e\x66\x61\x72";
char key = '\x13';

char * decription(char * str){

    int len = strlen(str);
    char * decr = (char *)malloc(len+1);
    int i;
    for(i=0;i<len;i++){
        decr[i] = str[i] ^ key;
    }
    decr[i] = '\0';

    return decr;

}

int main(int argc,char * argv[]){

    char * res;
    res = decription(account);
    if(strcmp(res,argv[1])!=0){
        printf(WUSER);
        return 0;
    }
    res = decription(password);
    if(strcmp(res,argv[2])!=0){
        printf(WPASS);
        return 0;
    }
    res=decription(secret);
    printf("Well done! Your secret is:  %s\n",res);
    return 1;

}
