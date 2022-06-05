#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "desafio.h"
#define T 500

void inicializarC(Carrinho* p[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        p[i] = NULL;
    }
}

void inicializar(Produto* p[], int tamanho){
        for(int i = 0; i < tamanho; i++){
            p[i] = NULL;
        }
}

typedef struct carrinho Carrinho;
typedef struct produto Produto;

void abrirCarrinho(Carrinho* p[], int tamanho){
    p[tamanho] = (Carrinho*)malloc(sizeof(struct carrinho));

    time_t agora;
    char datahora[100];
    agora = time(NULL);
    strftime( datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime( &agora ) );
    strcpy(p[tamanho]->dataCompra, datahora);

    int posicaoP = 0;

    Produto* vet_produtos[T];
    int *p_posicaoP = &posicaoP;

    inicializar(vet_produtos, T);
    adcionarProduto(vet_produtos, p_posicaoP, p, tamanho);
}

void adcionarProduto(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    int opcProdutos;
    int *p_posicao = posicao;

    do{
        printf("\t\t===================================================================\n");
        printf("\t\t| #                                    #######       #     #      |\n");
        printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
        printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
        printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
        printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
        printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
        printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
        printf("\t\t===================================================================\n");
        printf("\n");
        printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
        printf("\n");
        printf("\t\t\t      --Selecione o produto que deseja comprar-- \n");
        printf("\n");
        printf("\t\t\t\t\t1 - Fogao; \n");
        printf("\t\t\t\t\t2 - Geladeira; \n");
        printf("\t\t\t\t\t3 - Maquina de lavar; \n");
        printf("\t\t\t\t\t4 - Microondas; \n");
        printf("\t\t\t\t\t5 - Ferro de passar; \n");
        printf("\t\t\t\t\t6 - Verificar Compras; \n");
        printf("\t\t\t\t\t7 - Finalizar Compra; \n");
        scanf("%d", &opcProdutos);
        system("cls");

        switch (opcProdutos){
            case 1:
                opcFogao(p, p_posicao, p_c, tamanho);
                break;
            case 2:
                opcGeladeira(p, p_posicao, p_c, tamanho);
                break;
            case 3:
                opcMaquinaLavar(p, p_posicao, p_c, tamanho);
                break;
            case 4:
                opcMicro(p, p_posicao, p_c, tamanho);
                break;
            case 5:
                opcFerro(p, p_posicao, p_c, tamanho);
                break;
            case 6:
                verificarCompras(p, p_posicao, p_c, tamanho);
                break;
            case 7:
                finalizarCompra(p, p_posicao, p_c, tamanho);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
    }while(opcProdutos != 7);
}

void finalizarCompra(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int pagamento;
    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");
    printf("\t\t\t\t      --Encerrar Compra-- \n");
    printf("\n");
    for(int i=0; i<*p_posicao; i++){
        p_c[tamanho]->valorTCompra = p_c[tamanho]->valorTCompra + (p[i]->preco * p[i]->quantidade);
    }

    printf("\t\t\t\t    Valor da Compra: %.2lf\n", p_c[tamanho]->valorTCompra);
     do{
    printf("\t\t\t    Selecione os metodos de pagamento: \n");
    printf("\t\t\t    1 Cartao\n");
    printf("\t\t\t    2 PIX\n");
    printf("\t\t\t    3 Boleto\n");

    scanf("%d", &pagamento);

            if(pagamento == 1 || pagamento == 2 || pagamento == 3){
        printf("\t\t\t    Agradecemos a Compra\n");
            printf("\t\t\t    ");
            system("pause");
            system("cls");
            exit(2);
    }
    else{
        printf("\t\t\t    codigo invalido\n");

    }
    }while(pagamento<1 || pagamento>0);



}

void verificarCompras(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");
    printf("\t\t\t\t      --Produtos do carrinho-- \n");
    printf("\n");
    for(int i=0; i<*p_posicao; i++){
        printf("\t\t\t\t ID: %d\n", i);
        printf("\t\t\t\t Nome: %s\n", p[i]->nome);
        printf("\t\t\t\t Quantidade: %d\n", p[i]->quantidade);
        printf("\t\t\t\t preco: %.2lf\n", p[i]->preco);
        printf("\t\t\t\t -------------------------------------\n");
    }
    printf("\t\t\t    ");
    system("pause");
    system("cls");
}

void opcFogao(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    FILE *fp;
    int *p_posicao = posicao;
    int opcFogo;
    char ch;

    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");

    if((fp= fopen("marcasFogao.txt", "r"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }
    printf("\t\t\t--Selecione um dos itens acima para efetuar a compra--\n\n");

    fp = fopen("marcasFogao.txt", "r");
    while( (ch=fgetc(fp))!= EOF )
        putchar(ch);
    fclose(fp);
    printf("\n");

    scanf("%d", &opcFogo);

    adcionarOpcFogao(p, opcFogo, p_posicao, p_c, tamanho);
}


void adcionarOpcFogao(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int posi_cadastro = *p_posicao;
    FILE *fp;

    char nomeF[61];
    int auxilio;
    double precoF;

    if((fp= fopen("marcasFogao.txt", "a+"))==NULL){
        printf("Impossivelabrir arquivo");
        exit(2);
    }

    while(fscanf(fp, "%d %s %lf", &auxilio, nomeF, &precoF)!=EOF){
        if(auxilio == opcFogo){
            switch(opcFogo){
            case 1:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 2:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 3:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcao invalida.");
            }
        }
    }
}

void opcGeladeira(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    FILE *fp;
    int *p_posicao = posicao;
    int opcGelada;
    char ch;

    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");

    if((fp= fopen("marcasGeladeira.txt", "r"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }
    printf("\t\t\t--Selecione um dos itens acima para efetuar a compra--\n\n");

    fp = fopen("marcasGeladeira.txt", "r");
    while( (ch=fgetc(fp))!= EOF )
        putchar(ch);
    fclose(fp);
    printf("\n");

    scanf("%d", &opcGelada);

    adcionarOpcGeladeira(p, opcGelada, p_posicao, p_c, tamanho);
}
void adcionarOpcGeladeira(Produto* p[], int opcGelada, int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int posi_cadastro = *p_posicao;
    FILE *fp;

    char nomeF[61];
    int auxilio;
    double precoF;

    if((fp= fopen("marcasGeladeira.txt", "a+"))==NULL){
        printf("Impossivelabrir arquivo");
        exit(2);
    }

    while(fscanf(fp, "%d %s %lf", &auxilio, nomeF, &precoF)!=EOF){
        if(auxilio == opcGelada){
            switch(opcGelada){
            case 1:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 2:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 3:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcao invalida.");
            }
        }
    }
}



void opcMaquinaLavar(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    FILE *fp;
    int *p_posicao = posicao;
    int opcMaquina;
    char ch;

    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");

    if((fp= fopen("marcasMaquina.txt", "r"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }
    printf("\t\t\t--Selecione um dos itens acima para efetuar a compra--\n\n");

    fp = fopen("marcasMaquina.txt", "r");
    while( (ch=fgetc(fp))!= EOF )
        putchar(ch);
    fclose(fp);
    printf("\n");

    scanf("%d", &opcMaquina);

    adcionarOpcMaquinaLavar(p, opcMaquina, p_posicao, p_c, tamanho);
}
void adcionarOpcMaquinaLavar(Produto* p[], int opcMaquina, int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int posi_cadastro = *p_posicao;
    FILE *fp;

    char nomeF[61];
    int auxilio;
    double precoF;

    if((fp= fopen("marcasMaquina.txt", "a+"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }

    while(fscanf(fp, "%d %s %lf", &auxilio, nomeF, &precoF)!=EOF){
        if(auxilio == opcMaquina){
            switch(opcMaquina){
            case 1:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 2:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 3:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcao invalida.");
            }
        }
    }
}

void opcMicro(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    FILE *fp;
    int *p_posicao = posicao;
    int opcMicroOndas;
    char ch;

    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");

    if((fp= fopen("marcasMicro.txt", "r"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }
    printf("\t\t\t--Selecione um dos itens acima para efetuar a compra--\n\n");

    fp = fopen("marcasMicro.txt", "r");
    while( (ch=fgetc(fp))!= EOF )
        putchar(ch);
    fclose(fp);
    printf("\n");

    scanf("%d", &opcMicroOndas);

    adcionarOpcMicro(p, opcMicroOndas, p_posicao, p_c, tamanho);
}

void adcionarOpcMicro(Produto* p[], int opcMicroOndas, int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int posi_cadastro = *p_posicao;
    FILE *fp;

    char nomeF[61];
    int auxilio;
    double precoF;

    if((fp= fopen("marcasMicro.txt", "a+"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }

    while(fscanf(fp, "%d %s %lf", &auxilio, nomeF, &precoF)!=EOF){
        if(auxilio == opcMicroOndas){
            switch(opcMicroOndas){
            case 1:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 2:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 3:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcao invalida.");
            }
        }
    }
}


void opcFerro(Produto* p[], int posicao, Carrinho* p_c[], int tamanho){
    FILE *fp;
    int *p_posicao = posicao;
    int opcFerroPassa;
    char ch;

    printf("\t\t===================================================================\n");
    printf("\t\t| #                                    #######       #     #      |\n");
    printf("\t\t| #         ####        #    ##        #             #  #  #      |\n");
    printf("\t\t| #        #    #       #   #  #       #             #  #  #      |\n");
    printf("\t\t| #        #    #       #  #    #      #####         #  #  #      |\n");
    printf("\t\t| #        #    #       #  ######      #        ###  #  #  #  ### |\n");
    printf("\t\t| #        #    #  #    #  #    #      #        ###  #  #  #  ### |\n");
    printf("\t\t| #######   ####    ####   #    #      #        ###   ## ##   ### |\n");
    printf("\t\t===================================================================\n");
    printf("\n");
    printf("\t\t\t\tData da compra: %s\n", p_c[tamanho]->dataCompra);
    printf("\n");

    if((fp= fopen("marcasFerroPassar.txt", "r"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }
    printf("\t\t\t--Selecione um dos itens acima para efetuar a compra--\n\n");

    fp = fopen("marcasFerroPassar.txt", "r");
    while( (ch=fgetc(fp))!= EOF )
        putchar(ch);
    fclose(fp);
    printf("\n");

    scanf("%d", &opcFerroPassa);

    adcionarOpcFerroPassar(p, opcFerroPassa, p_posicao, p_c, tamanho);
}
void adcionarOpcFerroPassar(Produto* p[], int opcFerroPassa, int posicao, Carrinho* p_c[], int tamanho){
    int *p_posicao = posicao;
    int posi_cadastro = *p_posicao;
    FILE *fp;

    char nomeF[61];
    int auxilio;
    double precoF;

    if((fp= fopen("marcasFerroPassar.txt", "a+"))==NULL){
        printf("Impossivel abrir arquivo");
        exit(2);
    }

    while(fscanf(fp, "%d %s %lf", &auxilio, nomeF, &precoF)!=EOF){
        if(auxilio == opcFerroPassa){
            switch(opcFerroPassa){
            case 1:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 2:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            case 3:
                p[posi_cadastro] = (Produto*)malloc(sizeof(struct produto));
                strcpy(p[posi_cadastro]->nome, nomeF);
                printf("\n\t\t\t\t\tQuantos deseja comprar: ");
                scanf("%d", &p[posi_cadastro]->quantidade);
                p[posi_cadastro]->preco = precoF;
                *p_posicao = *p_posicao + 1;
                printf("\n\t\t\t\t\tCompra realizada com sucesso.\n");
                printf("\n\t\t\t\t");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcao invalida.");
            }
        }
    }
}

