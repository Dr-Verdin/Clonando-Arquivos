#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void arquivo(char *n){
    FILE *fp1, *fp2;
    unsigned char *buffer = (unsigned char *)malloc(MAX * sizeof(unsigned char));
    if(buffer == NULL){
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    fp1 = fopen(n, "rb");
    if(fp1 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    fp2 = fopen("ladygaga.bin", "wb");
    if(fp1 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    int tam;
    while(tam = fread(buffer, 1, sizeof(buffer), fp1)){
        fwrite(buffer, 1, tam, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    fp2 = fopen("ladygaga.bin", "rb");
    if(fp1 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    while((tam = fread(buffer, 1, sizeof(buffer), fp1)) > 0){
        fwrite(buffer, tam, 1, stdout);
    }

    free(buffer);
    fclose(fp2);
}

int main(){
    char n[14];
    scanf(" %s", n);

    arquivo(n);

    return 0;
}