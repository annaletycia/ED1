typedef struct TMat2D TMat2D; 

TMat2D *mat2D_create(int nrows, int ncolumns);
int mat2D_free(TMat2D *mat);

int mat2D_set_value(TMat2D *mat, int i, int j, double val);
int mat2D_get_value(TMat2D *mat, int i, int j, double *val);
int matriz_aleatoria(TMat2D *mat, int min, int max);
int matriz_sum(TMat2D *mat1, TMat2D *mat2, TMat2D *sum, int i, int j);
int matriz_multiplication(TMat2D *mat1, TMat2D *mat2, TMat2D *mult, int i, int j);
int matriz_multiplication_escalar(TMat2D *mat, TMat2D *mult, double val);
int matriz_traco(TMat2D *mat, double *sum);
int matriz_soma_linhas(TMat2D *mat, double *sum);
int matriz_soma_colunas(TMat2D *mat, double *sum);
int return_nrows(TMat2D *mat, int i);
int return_ncolumns(TMat2D *mat, int j);
void print_matriz(TMat2D *mat);