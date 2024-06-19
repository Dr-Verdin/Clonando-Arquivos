#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void arquivo(char *n){
    FILE *fp1, *fp2;
    unsigned char buffer[MAX];

    fp1 = fopen(n, "rb");
    if(fp1 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    fp2 = fopen("ladygaga.bin", "wb");
    if(fp2 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    int tam;
    while((tam = fread(buffer, 1, sizeof(buffer), fp1)) > 0){
        fwrite(buffer, 1, tam, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    fp2 = fopen("ladygaga.bin", "rb");
    if(fp2 == NULL){
        printf("Erro de leitura de arquivo\n");
        exit(1);
    }

    while((tam = fread(buffer, 1, sizeof(buffer), fp2)) > 0){
        fwrite(buffer, 1, tam, stdout);
    }
    printf("\n");

    fclose(fp2);
}

int main(){
    char n[14];
    scanf(" %s", n);

    arquivo(n);

    return 0;
}