#include <stdio.h>

void quadratica(int *array, int tamanho){
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


int main(int argc, char const *argv[]){
    int numeros_desordenados[] = {43,54,10,13,6324,123};
	
	quadratica(numeros_desordenados, 6);
    
	
	for(int i = 0; i < 6; i++) printf("%d\n", numeros_desordenados[i]);
    
    return 0;
}