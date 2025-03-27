#include <stdio.h>
#include <stdlib.h>

int main(){
    int jogada = 1, l, c, verif = 0;
    char jogo[3][3];
    for(int ind = 0; ind < 3; ind++){
        for(int ind2 = 0; ind2 < 3; ind2++){
            jogo[ind][ind2] = '_';
        }
    }
    system("cls");
    while(jogada <= 9){
        if(jogada % 2 == 1){
            printf("\nJogador 1 (X): \n\n");
        }else{
            printf("\nJogador 2 (O): \n\n");
        }
        do{
            printf("Digite as coordenadas onde deseja inserir o seu simbolo: \n");
            printf("Digite a linha (1, 2 ou 3): \n");
            scanf("%d", &l);
            printf("Digite a coluna (1, 2 ou 3): \n");
            scanf("%d", &c);
            if(jogo[l - 1][c - 1] != '_'){
                printf("\nJogada invalida, informe outras coordenadas.\n\n");
            }
        }while(jogo[l - 1][c - 1] != '_');
        if(jogada % 2 == 1){
            jogo[l - 1][c - 1] = 'X';
        }else{
            jogo[l - 1][c - 1] = 'O';
        }
        system("cls");
        for(int ind = 0; ind < 3; ind++){
            for(int ind2 = 0; ind2 < 3; ind2++){
                if(ind2 == 2){
                    printf("%c\n", jogo[ind][ind2]);
                }else{
                    printf("%c  ", jogo[ind][ind2]);
                }
            }
        }
        while(verif != 2){
            for(int linha = 0; linha < 3; linha++){
                verif = 0;
                for(int coluna = 0; coluna < 2; coluna++){
                    if(jogo[linha][coluna] == jogo[linha][coluna + 1] && jogo[linha][coluna] != '_' && jogo[linha][coluna + 1] != '_'){
                        verif++;
                    }
                }
                if(verif == 2){
                    break;
                }
            }
            if(verif == 2){
                break;
            }
            for(int coluna = 0; coluna < 3; coluna++){
                verif = 0;
                for(int linha = 0; linha < 2; linha++){
                    if(jogo[linha][coluna] == jogo[linha][coluna + 1] && jogo[linha][coluna] != '_' && jogo[linha][coluna + 1] != '_'){
                        verif++;
                    }
                }
                if(verif == 2){
                    break;
                }
            }
            if(verif == 2){
                break;
            }
            verif = 0;
            for(int coluna = 0; coluna < 2; coluna++){
                if(jogo[coluna][coluna] == jogo[coluna + 1][coluna + 1] && jogo[coluna][coluna] != '_' && jogo[coluna + 1][coluna + 1] != '_'){
                    verif++;
                }
            }
            if(verif == 2){
                break;
            }
            verif = 0;
            for(int coluna = 0; coluna < 2; coluna++){
                if(jogo[coluna][2 - coluna] == jogo[coluna + 1][1 - coluna] && jogo[coluna][2 - coluna] != '_' && jogo[coluna + 1][1 - coluna] != '_'){
                    verif++;
                }
            }
            break;
        }
        if(verif == 2){
            break;
        }
        jogada++;
    }
    printf("\nFim de Jogo!\n");
}