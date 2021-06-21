#include <iostream>

using namespace std;

class Graph{

private:
	int *parents, n;
public:
	
	Graph(int x){
		parents = new int[x];
		n = x;
		for(int i = 0; i < x; i++){
			parents[i] = i + 1;
		}
	}
	
	int find(int i){
		return parents[i - 1];
	}	
	
	void union_(int root, int child){
		parents[child - 1] = find(root);
		for(int i = 0; i < n; i++) if(parents[i] == child) parents[i] = find(root);
	}

	void print(){
		for(int i = 0; i < n; i++) cout << "Pai: " << parents[i] << " Filho: "<< i + 1 << endl;
		cout << "\n";
	}

	int count(){
		int count = 0;
		for(int i = 1; i < n + 1; i++){
			if(i == find(i)) count++; 
		} 
		return count;
	}
};


int main(int argc, char const *argv[]){
	int n, m, i, j, caso = 1;	
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		Graph graph(n);
		
		for(int cont = 0; cont < m; cont++){
			cin >> i >> j;
			graph.union_(i, j);
		}
		cout << "Case " << caso << ": " << graph.count() << endl;
		caso++;
	}
	
	return 0;
}