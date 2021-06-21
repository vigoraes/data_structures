#include <iostream>

using namespace std;

void altera(string &v){
	v += " alterou";
}

int main(int argc, char const *argv[]){
	string v = "teste";
	altera(v);
	cout << v << endl;
	return 0;
}