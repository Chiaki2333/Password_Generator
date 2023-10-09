#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char seed[32+1];
    int len, i, seed_n=0, tmp;
    printf("[INPUT]Please input the seed of your password(32 at most):");
    scanf("%32s", seed);
    printf("The seed of password is:%s\n", seed);   
    for(i=0; i<strlen(seed); i++){
        seed_n += (unsigned int)(seed[i%strlen(seed)])*(unsigned int)pow(128, i);
    }
    srand(seed_n);
	
    printf("====================\n");
    printf("[INPUT]Please input the length of the new password you want:");
    scanf("%d", &len);
    printf("The length of the new password is %d.", len);
    printf("\n");
    printf("====================\n");
    printf("[*]The new password is:");
    for(i=0; i<len; i++){
        printf("%c", rand()%('~'-' ')+' ');
    }
    printf("\n");
    printf("[*]The new password without special string is:");
    for(i=0; i<len; ){
        tmp = rand()%('~'-' ')+' ';
        if((tmp>='0' && tmp<='9') || (tmp>='A' && tmp<='Z') || (tmp>='a' && tmp<='z')){
            printf("%c", tmp);
            i++;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
