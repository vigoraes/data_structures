#include <iostream>

using namespace std;

class Heap{
private:
	int *data, size, capacity;
public:
	Heap(int capacity){
		this->capacity = capacity;
		this->size = 0;
		this->data = new int[capacity];
	}
	
	int parent(int i){ return (i-1)/2;} 
	int leftSon(int i){ return i*2 + 1;}
	int rightSon(int i){ return i*2 + 2;}

	void goingDown(int i){
		int minor = i;
		int left = leftSon(i), right = rightSon(i);

		if(left < size && data[minor] > data[left]){
			minor = left;
		}
		if(right < size && data[minor] > data[right]){
			minor = right;
		}
		if(minor != i){
			int tmp = data[i];
			data[i] = data[minor];
			data[minor] = tmp;
			goingDown(minor);
		}
	}

	void insert(int key){
		int tmp;
		if(size == capacity){
			cout << "Overflow" << endl;
			return;
		} 
		size++;
		int i = size - 1;
		data[i] = key;

		while(i != 0 && data[parent(i)] > data[i]){
			tmp = data[parent(i)];
			data[parent(i)] = data[i];
			data[i] = tmp;
			i = parent(i);
		}
	}

	void vectorToHeap(int *array, int size){
		for(int i = 0; i < size; i++){
			insert(array[i]);
		}
	}

	void removeMinKey(){
		if(size == 0) cout << "Impossivel remover: lista vazia\n";
		else if(size == 1){
			size--;
			return;
		}
		
		data[0] = data[size-1];
		size--;
		goingDown(0);

		
	}

	void print(){
		for(int i = 0; i < size; i++) cout << data[i] << " ";
		cout << "\n";
	}
};

int main(int argc, char const *argv[]){
	int array[] = {15, 8, 5, 6, 22, 13};
	int array2[] = {20, 7, 11, 18};
	Heap heap(12);
	heap.vectorToHeap(array, sizeof(array) / sizeof(int));
	
	heap.print();
	cout << "\n";
	
	for(int i = 0; i < 4; i++) heap.insert(array2[i]);
	heap.print();
	cout << "\n";
	
	heap.removeMinKey();
	heap.print();
	return 0;
}