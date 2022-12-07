// cabeçalho do TAD

typedef struct TMat TMat;

TMat *mat_create(int nrow, int ncol);

int mat_free(TMat *mat);

int vet_free(double *vet);

int mat_set_value(TMat *mat, int i, int j, double val);

int mat_get_value(TMat *mat, int i, int j, double *val);

int mat_preenche(TMat *mat);

TMat *mat_soma(TMat *m1, TMat *m2);

TMat *mat_multiplica(TMat *m1, TMat *m2);

TMat *mat_mult_esc(TMat *m1, double num);

double mat_traco(TMat *mat);

double *mat_somalinhas(TMat *mat);
