int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    int *trabalhos[] = malloc(int *)(sizeof(int) * workerSize);

    mergesort(difficulty);
    trabalhos = compareskill(); 
    
}
//dividir todo o problema, ordená-lo e ir comparando a menor habilidade dos trabalhadores com a menor dificuldade de task. Começar a atribuir as task a partir da menor habilidade e esquecer o resto;
//O idel é começar pelo meio ao invés do inicio para diminuir a complexidade algoritmica;
//Tem que comparar as duas arrays, porque não precisa ser igual, um worker 5 pode pegar um trabalho 4.

mergesort(){
    if(difficultySize <= 1){
        return;
    }

    int meio = difficultySize/2;
    int meio2 = difficultySize - meio;

    int *esquerda[] = malloc(int *)(sizeof(int) * meio);
    int *direita[] = malloc(int *)(sizeof(int) * meio2);

    for(int i=0; i < meio; i++){
        esquerda[i] = difficulty[i];
    }

    for(int i = meio2; i > meio; i++){
        direita[i] = difficulty[i];
    }

    esquerda = mergesort(esquerda);
    direita = mergesort(direita);
    resultado = compareskill(esquerda, direita, meio, meio2); //talvez compareskill faça mais sentido como   função auxiliar dentro do merge
    
    return resultado;


    


}



compareskill(esquerda, direita, tamanhoesquerda, tamanhodireita){
    int meio, i=0, j=1, k=0;
    meio = difficultySize/2;
    meio2 = difficultySize - meio;
    
    int *resultado[] = malloc(int *)(sizeof(int) * workerSize);

    if(difficulty[meio]==worker[i] && difficulty[meio+1]>worker[i]){
        resultado[k] = difficulty[meio];
        worker[i] = worker[j]; 
        i++;
        j++;
    }
    
    else if(difficulty[meio]<=worker[0] && difficulty[meio+1]>worker[0]){
     
    }

