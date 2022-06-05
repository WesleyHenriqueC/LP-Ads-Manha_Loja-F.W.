struct carrinho {
    char dataCompra[100];
    double valorTCompra;

    struct produto {
        char nome[61];
        int quantidade;
        double preco;
    };
};

typedef struct carrinho Carrinho;
typedef struct produto Produto;

void inicializarC(Carrinho* p[], int tamanho);

void inicializarP(Produto* p[], int tamanho);

void abrirCarrinho(Carrinho* p[], int tamanho);

void adcionarProduto(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void opcFogao(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void adcionarOpcFogao(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho);

void adcionarOpcFerroPassar(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho);

void opcFerro(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void adcionarOpcMicro(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho);

void opcMicro(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void adcionarOpcMaquinaLavar(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho);

void opcMaquinaLavar(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void adcionarOpcGeladeira(Produto* p[], int opcFogo, int posicao, Carrinho* p_c[], int tamanho);

void opcGeladeira(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);

void verificarCompras(Produto* p[], int posicao, Carrinho* p_c[], int tamanho);






