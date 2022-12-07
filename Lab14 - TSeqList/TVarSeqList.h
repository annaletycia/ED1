// .h

struct aluno{

    char nome[30];
    int mat;
    float n1,n2,n3;
};

typedef struct lista Lista;

Lista *cria_lista(int tam_inicial);

int free_lista(Lista *li);

int insere_lista_ordenada(Lista *li, struct aluno a);

int insere_lista_inicio(Lista *li, struct aluno a);

int insere_lista_fim(Lista *li, struct aluno a);

int imprime_lista(Lista *li);

int remove_lista_fim(Lista *li);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int lista_cheia(Lista *li);

int remove_lista_inicio(Lista *li);

int remove_lista(Lista *li, int mat);

int remove_lista_otimizado(Lista *li, int mat);

int consulta_lista_pos(Lista *li, int pos, struct aluno *a);

int consulta_lista_mat(Lista *li, int mat, struct aluno *a);

int compactar_lista(Lista *li);
