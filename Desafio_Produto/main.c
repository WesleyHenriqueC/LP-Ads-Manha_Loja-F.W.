#include <stdio.h>
#include <stdlib.h>
#include "desafio.h"
#define D 1

int main(){
    Carrinho* vet_carrinhos[D];

    int opc;
    printf("====================================================================================================\n");
    printf("| ######                                                                          #######  #     # |\n");
    printf("| #     #  ######  #    #      #    #  #  #    #  #####    ####         ##        #        #  #  # |\n");
    printf("| #     #  #       ##  ##      #    #  #  ##   #  #    #  #    #       #  #       #        #  #  # |\n");
    printf("| ######   #####   # ## #      #    #  #  # #  #  #    #  #    #      #    #      #####    #  #  # |\n");
    printf("| #     #  #       #    #      #    #  #  #  # #  #    #  #    #      ######      #        #  #  # |\n");
    printf("| #     #  #       #    #       #  #   #  #   ##  #    #  #    #      #    #      #        #  #  # |\n");
    printf("| ######   ######  #    #        ##    #  #    #  #####    ####       #    #      #         ## ##  |\n");
    printf("====================================================================================================\n");
    printf("\t\t\tDeseja iniciar compra?(1. Sim / 2. Nao): ");
    scanf("%d", &opc);
    system("cls");
    if(opc == 1){
        inicializar(vet_carrinhos, D);
        abrirCarrinho(vet_carrinhos, D);
    }else{
        printf("Tchau tenha um otimo dia. :D \n");
    }

    return 0;
}
