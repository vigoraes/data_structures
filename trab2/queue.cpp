#include <iostream>
#include <cstring>
using namespace std;

int round = 1, nTeams, nInputs, teams[1000][1000], queue[1000000], queueSize = 0, tmp;

int team(int element){
	if(element < 0 || element > 1000000) return -1;
	int team;

	for(team = 0; team < 1000; team++){
		for(tmp = 0; tmp < 1000; tmp++){
			if(teams[team][tmp] == element){
				return team;
			}
		}
	}

	return -1;
}

void enqueue(int element){
	int i;
	bool pass = true;
	for(i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			if(teams[i][j] == element){
				pass = false;
				break;
			}
		}
		if(!pass)
			break;
	}
	
	for(int x = 0; x < queueSize + 1; x++){
		if(queue[x] == -1){
			queue[x] = element;
			break;
		}
		else if(team(queue[x]) == i){
			x++;
			while(team(queue[x]) == i){
				x++;
			}
			if(queue[x] != -1){
				for(tmp = queueSize; tmp > x; tmp--)
					queue[tmp] = queue[tmp - 1];
			}
			queue[x] = element;
			break;
		}
	}
	queueSize++;
}

void dequeue(){
	for(int j = 0; j < queueSize; j++){
		if(queue[j] != -1){
			cout << queue[j] << endl;
			for(tmp = j; tmp < queueSize; tmp++)
				queue[tmp] = queue[tmp + 1];
			queueSize--;
			break;
		}
	}
}



int main(int argc, char const **argv){

	while (true){
		for(int i = 0; i < 1000; i++) for(int j = 0; j < 1000; j++) teams[i][j] = -1;
		for (int i = 0; i < 1000000; i++) queue[i] = -1;
		cin >> nTeams;

		if (nTeams == 0) break;

		cout << "Scenario #" << round << endl;

		for (int i = 0; i < nTeams; i++){
			cin >> nInputs;
			for (int j = 0; j < nInputs; j++){
				cin >> teams[i][j];
			}
		}

		string action;
		while(true){
			cin >> action;
			if(action == "STOP") break;
			else if (action == "ENQUEUE"){
				int id;
				cin >> id;
				enqueue(id);
			}
			else if(action == "DEQUEUE"){
				dequeue();
			}
			else
				continue;
		}
		round++;
		cout << "\n";
	}

	return 0;
}
