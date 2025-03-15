typedef struct{
    int difficulty;
    int profit;
}job;

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    job* jobs = (job*)malloc(difficultySize * sizeof(job));
    for(int i = 0; i < difficultySize; i++){
        jobs[i].difficulty = difficulty[i];
        jobs[i].profit = profit[i];
    }

    //ordernar jobs por dificuldade
    mergeSort(jobs, 0, difficultySize - 1);

    //ordernar workers
    mergeSort(worker, 0, workerSize -1);
    
    int maxProfit = 0;
    int bestProfit = 0;
    int jobIndex = 0;

    for(int i = 0; i < workerSize; i++){
        while (jobIndex < difficultySize && jobs[jobIndex].difficulty <= worker[i]){ //Percorre os workers e para cada worker, percorre os jobs e atribui o mais lucrativo pra cada worker
            if(jobs[jobIndex].profit > bestProfit){
            bestProfit = jobs[jobIndex].profit;
            }
            jobIndex++;
        }
    
    maxProfit += bestProfit; //Vai acumulando pra no fim do loop retornar
   }
free(jobs);
return maxProfit;
}

    
//dividir todo o problema, ordená-lo e ir comparando a menor habilidade dos trabalhadores com a menor dificuldade de task. Começar a atribuir as task a partir da menor habilidade e esquecer o resto;
//O idel é começar pelo meio ao invés do inicio para diminuir a complexidade algoritmica;
//Tem que comparar as duas arrays, porque não precisa ser igual, um worker 5 pode pegar um trabalho 4.

mergeSort(job arr[], int left, int right){
    if(left < right){ //caso base da recursão, left começa 0.
      int mid = (left + right)/2; 

      //usar essa função apenas para chamar as recursões
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);

    }
}

merge(job arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid; //calcula número de elementos no array de forma inclusiva

    //arrays temporárias aqui e não no mergeSort;
    job* L = (job*)malloc(n1 * sizeof(job));
    job* R = (job*)malloc(n2 * sizeof(job));

    //copia os dados aqui e não no mergeSort
    for(int i = 0; i < n1; i++)
    L[i] = arr[left+i];
    
    for(int i=0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i].difficulty <= R[j].difficulty){
            arr[k] = L[i];
            i++;
        } else {                //vai comparando as duas metades e copiando ordenado pro array principal
            arr[k] = R[j];
            j++;
        }
        k++;
    };
    
    //copia as sobras, se houver

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

}


