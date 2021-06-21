#include <iostream>

using namespace std;

void quadratica(int array[], int tamanho){
	int aux;
	for(int i = 0; i < tamanho - 1; i++){
		for(int j = i + 1; j < tamanho; j++){
			if(array[i] > array[j]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
}

void quick_sort(int array[], int inicio, int fim){
    int pivo = array[(inicio + fim) / 2], i = inicio, j = fim - 1, aux;

    while(i <= j){
        while(array[i] < pivo && i < fim) i++;

        while(array[j] > pivo && j > inicio) j--;

        if(i <= j){
        	aux = array[i];
        	array[i] = array[j];
        	array[j] = aux;
        	i++;
        	j--; 
        }

    }
    if(j > inicio) quick_sort(array, inicio, j + 1);
    if(i < fim) quick_sort(array, i, fim);
}

void merge(int array[], int inicio, int meio, int fim, int aux[]){
	int esquerda = inicio, direita = meio;
	
	for(int i = inicio; i < fim; i++){
		if((esquerda < meio) && ((direita >= fim) || (array[esquerda] < array[direita]))){
			aux[i] = array[esquerda];
			esquerda++;
		}else{
			aux[i] = array[direita];
			direita++;
		}
	}
	for (int i = inicio; i < fim; i++) {
        array[i] = aux[i];
        //cout << "array[" << i << "] = " << aux[i] << "\n";
    }

}

void merge_sort(int array[], int inicio, int fim, int aux[]){
	if((fim - inicio) < 2) return;
	
	int meio = (inicio + fim) / 2;

	merge_sort(array, inicio, meio, aux);
	merge_sort(array, meio, fim, aux);
	merge(array, inicio, meio, fim, aux);
	
}

void merge_sort(int array[], int tamanho){
	int aux[tamanho];
	merge_sort(array, 0, tamanho, aux);
} 


int main(int argc, char const *argv[]){
    int tamanho = 0, numeros_desordenados[10000];	
    while(cin >> numeros_desordenados[tamanho]){
        tamanho++;     
    }
    if(argc == 1){
    	quadratica(numeros_desordenados, tamanho);
    }else{
	    string argumento = argv[1];
	    if(argumento == "-q") quick_sort(numeros_desordenados, 0, tamanho);
	        
	   	else if(argumento == "-m") merge_sort(numeros_desordenados, tamanho);
    }
	
	for(int i = 0; i < tamanho; i++) cout << numeros_desordenados[i] << endl;
    
    return 0;
}