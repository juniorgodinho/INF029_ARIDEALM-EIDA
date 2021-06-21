#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10

int criarEstruturaAuxiliar(int size, int position);   // ========================= OK
int inserirNumeroEmEstrutura(int size, int position); // ========================= OK
int excluirNumeroDoFinaldaEstrutura(int position);    // ========================= OK
int excluirNumeroEspecificoDeEstrutura(int value, int position); // ============== OK
int getDadosEstruturaAuxiliar(int position, int vetorAux[]);     // ============== OK
int getDadosOrdenadosEstruturaAuxiliar(int position, int vetorAux[]); // ========= OK
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]); // ====================== OK
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]); // ============= OK
int modificarTamanhoEstruturaAuxiliar(int position, int new_size); // ============ OK
int getQuantidadeElementosEstruturaAuxiliar(int position); // ==================== OK
void start_program();  // ======================================================== OK
void end_program();    // ======================================================== OK
void show_menu(); // ============================================================= OK
void info_status(int value); // ================================================== OK
void clear_screen();  // ========================================================= OK
void get_value(int *value); // =================================================== OK
void get_position(int *position); // ============================================= OK
void get_size(int *size); // ===================================================== OK
void get_new_size(int *new_size); // ============================================= OK
int test_position(int position); // ============================================== OK
int search_number(int value, int position); // =================================== OK
void delete_number(int position, int position_search); // ======================== OK
void print_struct(int position, int *vetorAux); // =============================== OK
void dobrar(int *x); // ========================================================== OK
void insertionSort(int *array, int size); // ===================================== OK