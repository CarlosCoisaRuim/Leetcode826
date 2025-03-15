
typedef struct {
    int difficulty;
    int profit;
} trabalho;

void mergeSort(trabalho arr[], int esquerda, int direita);
void merge(trabalho arr[], int esquerda, int meio, int direita, trabalho EsquerdaLista[], trabalho DireitaLista[]);

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    
    trabalho* trabalhos = (trabalho*)malloc(difficultySize * sizeof(trabalho));
    for (int i = 0; i < difficultySize; i++) {
        trabalhos[i].difficulty = difficulty[i];
        trabalhos[i].profit = profit[i];
    }

    // Ordenar os jobs por dificuldade usando Merge Sort
    mergeSort(trabalhos, 0, difficultySize - 1);

    int resultado = 0;

    // Para cada worker, encontrar o job mais lucrativo que ele pode realizar
    for (int i = 0; i < workerSize; i++) {
        int maiorProfit = 0;
        for (int j = 0; j < difficultySize; j++) {
            if (trabalhos[j].difficulty <= worker[i] && trabalhos[j].profit > maiorProfit) {
                maiorProfit = trabalhos[j].profit;
            }
        }
        resultado += maiorProfit;
    }

    free(trabalhos);
    return resultado;
}

//dividir todo o problema, ordená-lo e ir comparando a menor habilidade dos trabalhadores com a menor dificuldade de task. Começar a atribuir as task a partir da menor habilidade e esquecer o resto;
//Tem que comparar as duas arrays, porque não precisa ser igual, um worker 5 pode pegar um trabalho 4.

void mergeSort(trabalho arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = (esquerda + direita)/2;

        int meio1 = meio - esquerda + 1;
        int meio2 = direita - meio;

        // Cria arrays temporários
        trabalho* EsquerdaLista = (trabalho*)malloc(meio1 * sizeof(trabalho));
        trabalho* DireitaLista = (trabalho*)malloc(meio2 * sizeof(trabalho));

        // Copia os dados para os arrays temporários
        for (int i = 0; i < meio1; i++)
        EsquerdaLista[i] = arr[esquerda + i];
        for (int i = 0; i < meio2; i++)
        DireitaLista[i] = arr[meio + 1 + i];

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Mescla as duas metades ordenadas
        merge(arr, esquerda, meio, direita, EsquerdaLista, DireitaLista);

        free(EsquerdaLista);
        free(DireitaLista);
    }
}

// Função para mesclar duas partes ordenadas de um array de jobs
void merge(trabalho arr[], int esquerda, int meio, int direita, trabalho EsquerdaLista[], trabalho DireitaLista[]) {

    int meio1 = meio - esquerda + 1;
    int meio2 = direita - meio;

    // Mescla os arrays temporários de volta ao array original
    int i = 0, j = 0, k = esquerda;
    while (i < meio1 && j < meio2) {
        if (EsquerdaLista[i].difficulty <= DireitaLista[j].difficulty) {
            arr[k] = EsquerdaLista[i];
            i++;
        } else {
            arr[k] = DireitaLista[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L (se houver)
    while (i < meio1) {
        arr[k] = EsquerdaLista[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R (se houver)
    while (j < meio2) {
        arr[k] = DireitaLista[j];
        j++;
        k++;
    }

}



